#include "ForcePullPush/ForcePullPush.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UForcePullPush::UForcePullPush()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UForcePullPush::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UForcePullPush::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//find target to pull/push
AActor* UForcePullPush::FindTarget(float range, float radius, ETraceTypeQuery traceChannel)
{
	if (UWorld* world = GetOwner()->GetWorld())
	{
		//temp vars
		TArray<AActor*> actorsToIgnore;
		actorsToIgnore.Add(GetOwner()); //ignore owner actor
		FHitResult hitResult;

		// Perform the sphere trace
		UKismetSystemLibrary::SphereTraceSingle(
			world, //gaem world
			GetOwner()->GetActorLocation(), //start is location of owner compon
			GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * range, //end is forward of owner * range
			radius,
			traceChannel,
			false, // traceComplex
			actorsToIgnore,
			EDrawDebugTrace::ForDuration,
			hitResult,
			true //bIgnoreSelf
		);
	}

	return GetOwner();
}