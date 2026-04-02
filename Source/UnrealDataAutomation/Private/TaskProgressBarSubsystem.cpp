// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskProgressBarSubsystem.h"
#include "Misc/ScopedSlowTask.h" // Core Module
#include "Misc/FeedbackContext.h" // Core Module

void UTaskProgressBarSubsystem::SingleTaskProgressBar(int NumIterations, FCheckStatusDelegate Delegate, bool& bOutSuccess, FString& OutMessage)
{
	FScopedSlowTask SlowTask = FScopedSlowTask(NumIterations, NSLOCTEXT("SubsystemSlowTask", "SlowTask", "Processing..."), true, *GWarn);

	// Show popup
	SlowTask.MakeDialog(true);

	// Execute task
	for (int i = 0; i < NumIterations; i++)
	{
		//Update text pop up
		SlowTask.EnterProgressFrame(1.0f, FText::Format(NSLOCTEXT("SubsystemSlowTask", "SlowTask", "Processing {0} / {1}"), FText::AsNumber(i), FText::AsNumber(NumIterations)));

		// Simulate work
		UE_LOG(LogTemp, Display, TEXT("Run Single Task Delegate"), i);
		bool ResultDelegate = Delegate.Execute();

		// Check if user canceled the task
		if (GWarn->ReceivedUserCancel())
		{
			bOutSuccess = false;
			OutMessage = "Task Canceled by User";
			return;
		}

		if (!ResultDelegate)
		{
			// Ask user if they want to continue after an errror in the delegate
			bool ShouldContinue = GWarn->YesNof(NSLOCTEXT("SubsystemSlowTask", "SlowTaskQuestion", "Some kind of error: SHOULD CONTINUE?"));

			if (!ShouldContinue)
			{
				bOutSuccess = false;
				OutMessage = "User DIDN'T want to continue";
				return;
			}
		}
	}

	bOutSuccess = true;
	OutMessage = "Success";
}

TArray<FString> UTaskProgressBarSubsystem::GetAllProperties(UClass* Class)
{
	TArray<FString> Ret;
	if (Class != nullptr)
	{
		for (TFieldIterator<FProperty> It(Class); It; ++It)
		{
			FProperty* Property = *It;
			if (Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Edit))
			{
				Ret.Add(Property->GetName());
			}
		}
	}

	return Ret;
}
