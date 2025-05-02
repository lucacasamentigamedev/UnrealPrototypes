#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "ForcePullPush.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROTOTYPES_API UForcePullPush : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	AActor* TargetActor; //actor to pull/push
	AActor* TraceTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent);

public:	
	// Sets default values for this component's properties
	UForcePullPush();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void FindTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent);

	UFUNCTION(BlueprintCallable)
	void PullTarget(float speed, float deltaTime);

	UFUNCTION(BlueprintCallable)
	void StopPulling();

	UFUNCTION(BlueprintCallable)
	void PushTarget(float range, float radius, ETraceTypeQuery traceChannel, UCameraComponent* cameraComponent, float pushForce);

};
