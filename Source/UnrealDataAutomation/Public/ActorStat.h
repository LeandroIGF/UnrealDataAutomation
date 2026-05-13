// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorStat.generated.h"

// Grop of stats for ActorStat, 
// used for grouping related stats together in the console and profiler. 
// The first parameter is the display name, the second is the internal name, 
// and the third is the category (optional).
DECLARE_STATS_GROUP(TEXT("ActorStat"), STATGROUP_ActorStat, STATCAT_Advanced); // console command line stat ActorStat

// Declare a cycle stat for the Tick function of AActorStat, 
// which will measure the time taken by the Tick function.
DECLARE_CYCLE_STAT(TEXT("ActorStat Tick"), STAT_ActorStat_Tick, STATGROUP_ActorStat);

DECLARE_CYCLE_STAT(TEXT("ActorStat BeginPlay"), STAT_ActorStat_BeginPlay, STATGROUP_ActorStat);

UCLASS()
class UNREALDATAAUTOMATION_API AActorStat : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorStat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	int32 LoopCount = 10000;

};
