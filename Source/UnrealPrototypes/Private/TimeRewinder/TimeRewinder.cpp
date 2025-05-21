#include "TimeRewinder/TimeRewinder.h"

UTimeRewinder::UTimeRewinder()
{
	PrimaryComponentTick.bCanEverTick = true;
	MaxSnapshots = 10;
	RewindSpeed = 3.0f;
}

void UTimeRewinder::BeginPlay()
{
	Super::BeginPlay();
}

void UTimeRewinder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTimeRewinder::RegisterSnapshot()
{
	if (AActor* Owner = GetOwner())
	{
		if (UWorld* World = GetWorld())
		{
			const FVector CurrentPosition = Owner->GetActorLocation();
			const double Timestamp = World->GetTimeSeconds();
			FRotator CurrentRotation = Owner->GetActorRotation();

			Snapshots.EmplaceLast(Timestamp, CurrentPosition, CurrentRotation);
			if (Snapshots.Num() > MaxSnapshots)
			{
				Snapshots.PopFirst();
			}

			UE_LOG(LogTemp, Warning, TEXT("Snapshot registered: %f, %s"), Timestamp, *CurrentPosition.ToString());
			//DrawDebugSphere(World, Snapshots.Last().Position, 5.0f, 32, FColor::Red, false, 2.0f);
		}
	}
}

//when press the button to start rewind save also the actual location and timestamp
void UTimeRewinder::PrepareRewind()
{
	if (AActor* Owner = GetOwner())
	{
		if (UWorld * World = GetWorld())
		{
			StartRewindRotation = Owner->GetActorRotation();
			StartRewindPosition = Owner->GetActorLocation();
			StartRewindTimestamp = World->GetTimeSeconds();
		}
	}
}

void UTimeRewinder::Rewind(float DeltaTime, float DeltaTimeSnap)
{
	RewindAccumulator += RewindSpeed / DeltaTimeSnap * DeltaTime;
	RewindPosition();
	RewindRotation();
	if (RewindAccumulator >= 1)
	{
		Snapshots.PopLast();
		RewindAccumulator = 0.0f;
	}
}

void UTimeRewinder::RewindPosition()
{
	if (AActor* Owner = GetOwner())
	{
		FVector PreviousPosition = Snapshots.Last().Position;
		Owner->SetActorLocation(FMath::Lerp(StartRewindPosition, PreviousPosition, RewindAccumulator));
		/* in this case we arrive in the final position so the position of player is previous, also the new start*/
		if (RewindAccumulator >= 1.0f)
		{
			Owner->SetActorLocation(PreviousPosition);
			StartRewindPosition = PreviousPosition;
		}
	}
}

void UTimeRewinder::RewindRotation()
{
	if (AActor* Owner = GetOwner())
	{
		if (UWorld* World = GetWorld())
		{
			if (APlayerController* PlayerController = World->GetFirstPlayerController())
			{

				FRotator PreviousRotation = Snapshots.Last().Rotation;
				// create the rotation to make
				FRotator FinalRotator = FQuat::Slerp(StartRewindRotation.Quaternion(), PreviousRotation.Quaternion(), RewindAccumulator).Rotator();
				// rotate the player controller and the owner
				PlayerController->SetControlRotation(FinalRotator);
				Owner->SetActorRotation(FinalRotator);
				if (RewindAccumulator >= 1)
				{
					PlayerController->SetControlRotation(PreviousRotation);
					Owner->SetActorRotation(PreviousRotation);
					StartRewindRotation = PreviousRotation;
				}
			}
		}
	}
}

bool UTimeRewinder::CanRewind()
{
	return Snapshots.Num() > 0;
}