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

AActor* UForcePullPush::TraceTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent)
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
			GetOwner()->GetActorLocation() + cameraComponent->GetForwardVector() * range, //end is forward of owner * range
			radius,
			traceChannel,
			false, // traceComplex
			actorsToIgnore,
			EDrawDebugTrace::ForDuration,
			hitResult,
			true //bIgnoreSelf
		);

		// get actor from hitResult
		return hitResult.GetActor();
	}
	return nullptr;
}

// Called every frame
void UForcePullPush::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//find target to pull/push
void UForcePullPush::FindTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent)
{
	TargetActor = TraceTarget(range, radius, traceChannel, cameraComponent); //trace for target actor
	if (TargetActor)
	{
		TargetActor->GetComponentByClass<UStaticMeshComponent>()->SetSimulatePhysics(false);
	}
}

//pull target actor if not null
void UForcePullPush::PullTarget(float speed, float deltaTime)
{
	if (!TargetActor) return; //no target to pull
	if (FVector::Dist(GetOwner()->GetActorLocation(), TargetActor->GetActorLocation()) > 0.1)
	{
		TargetActor->SetActorLocation(
			FMath::Lerp(
			TargetActor->GetActorLocation(), //end
			GetOwner()->GetActorLocation(), //start
			speed * deltaTime //alpha
		));
	}
	else
	{
		TargetActor->SetActorLocation(GetOwner()->GetActorLocation());
	}
}

void UForcePullPush::StopPulling()
{
	if (TargetActor)
	{
		//re-enable physics on target actor
		TargetActor->GetComponentByClass<UStaticMeshComponent>()->SetSimulatePhysics(true);
	}
	TargetActor = nullptr;
}

void UForcePullPush::PushTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent, float pushForce)
{
	AActor* actorToPush = TraceTarget(range, radius, traceChannel, cameraComponent);
	//no avaibale pushing actor
	if (!actorToPush)
	{
		return;
	}
	//if the actor is the same that we are pulling, stop pulling
	if (actorToPush == TargetActor)
	{
		StopPulling();
	}
	//push actor
	actorToPush->GetComponentByClass<UStaticMeshComponent>()->AddImpulseAtLocation(cameraComponent->GetForwardVector() * pushForce, actorToPush->GetActorLocation());
}