// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "TaskProgressBarSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTaskProgressBarUpdate, bool, Success);

DECLARE_DYNAMIC_DELEGATE_RetVal(bool, FCheckStatusDelegate);


/**
 * 
 */
UCLASS()
class UNREALDATAAUTOMATION_API UTaskProgressBarSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
	

public:

	FOnTaskProgressBarUpdate OnTaskProgressBarUpdate;

	/*
		Single progress bar
	*/

	UFUNCTION(BlueprintCallable, Category = "TaskProgressBar")
	void SingleTaskProgressBar(int NumIterations, FCheckStatusDelegate Delegate, bool& bOutSuccess, FString& OutMessage);

	UFUNCTION(Category = "TaskProgressBar", BlueprintPure, BlueprintCallable)
	TArray<FString> GetAllProperties(UClass* Class);
};
