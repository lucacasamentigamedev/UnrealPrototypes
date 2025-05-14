#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Deque.h"
#include "TimeRewinder.generated.h"

struct FSnapshot
{
	double Timestamp;
	FVector Position;
	FRotator Rotation;

	FSnapshot(double InTimestamp, FVector InPosition, FRotator InRotation)
		: Timestamp(InTimestamp), Position(InPosition), Rotation(InRotation) {}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROTOTYPES_API UTimeRewinder : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	UTimeRewinder();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void RegisterSnapshot();

	UFUNCTION(BlueprintCallable)
	void Rewind(float DeltaTime, float DeltaTimeSnap);

	UFUNCTION(BlueprintCallable)
	void PrepareRewind();

	UFUNCTION(BlueprintCallable)
	bool CanRewind();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxSnapshots = 20;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RewindSpeed;


private:
	FVector StartRewindPosition;
	double StartRewindTimestamp;
	FRotator StartRewindRotation;
	float RewindAccumulator;
	TDeque<FSnapshot> Snapshots;
	void RewindPosition();
	void RewindRotation();
};
