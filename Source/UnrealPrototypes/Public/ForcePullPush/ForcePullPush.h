#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ForcePullPush.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROTOTYPES_API UForcePullPush : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UForcePullPush();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	AActor* FindTarget(float range, float radius, ETraceTypeQuery traceChannel);
};
