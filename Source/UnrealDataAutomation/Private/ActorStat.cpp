// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorStat.h"

// Sets default values
AActorStat::AActorStat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AActorStat::BeginPlay()
{
	Super::BeginPlay();

	SCOPE_CYCLE_COUNTER(STAT_ActorStat_BeginPlay);

	for (int i = 0; i < LoopCount; i++)
	{
		for (int j = 0; j < LoopCount; j++)
		{
			int32 a = FMath::RandRange(0, 100);
			int32 b = FMath::RandRange(0, 100);
			int32 c = a + b;
			//UE_LOG(LogTemp, Display, TEXT("%i"), c);
		}		
	}	
}

// Called every frame
void AActorStat::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
}

