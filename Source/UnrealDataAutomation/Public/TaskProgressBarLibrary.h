// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TaskProgressBarLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNREALDATAAUTOMATION_API UTaskProgressBarLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	/*
		Single progress bar	
	*/

	UFUNCTION(BlueprintCallable, Category = "TaskProgressBar")
	static void ExecuteSingleTaskProgressBar(bool& bOutSuccess, FString& OutMessaged);

	/*
		Single progress bar
	*/

	UFUNCTION(BlueprintCallable, Category = "TaskProgressBar")
	static void ExecuteNestedTaskProgressBar(bool& bOutSuccess, FString& OutMessagete);
};
