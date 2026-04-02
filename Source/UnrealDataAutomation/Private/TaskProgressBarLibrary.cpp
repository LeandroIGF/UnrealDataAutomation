// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskProgressBarLibrary.h"
#include "Misc/ScopedSlowTask.h" // Core Module
#include "Misc/FeedbackContext.h" // Core Module


void UTaskProgressBarLibrary::ExecuteSingleTaskProgressBar(bool& bOutSuccess, FString& OutMessage)
{
	// Iterations
	int IttCount = 100000;

	FScopedSlowTask SlowTask = FScopedSlowTask(IttCount, NSLOCTEXT("ProjectSlowTask", "SlowTask", "Processing..."), true, *GWarn);

	// Show popup
	SlowTask.MakeDialog(true);

	// Execute task
	for(int i = 0; i < IttCount; i++)
	{
		//Update text pop up
		SlowTask.EnterProgressFrame(1.0f, FText::Format(NSLOCTEXT("ProjectSlowTask", "SlowTask", "Processing {0} / {1}"), FText::AsNumber(i), FText::AsNumber(IttCount)));

		// Simulate work
		UE_LOG(LogTemp, Display, TEXT("Counting [%d]"), i);

		// Check if user canceled the task
		if(GWarn->ReceivedUserCancel())
		{
			bOutSuccess = false;
			OutMessage = "Task Canceled by User";
			return;
		}

		if (i % (IttCount / 2) == 0)
		{
			// Ask user if they want to continue at 50% progress
			bool ShouldContinue = GWarn->YesNof(NSLOCTEXT("ProjectSlowTask", "SlowTaskQuestion", "Do you want to continue?"));
			
			if (!ShouldContinue)
			{
				bOutSuccess = false;
				OutMessage = "User DIDN'T want to continue";
				return;
			}
		}
	}

}


void UTaskProgressBarLibrary::ExecuteNestedTaskProgressBar(bool& bOutSuccess, FString& OutMessage)
{
	// Iterations
	int FirstIttCount = 5;

	FScopedSlowTask FirstSlowTask = FScopedSlowTask(FirstIttCount, 
		NSLOCTEXT("ProjectSlowTask", "FirstSlowTask", "Processing..."), true, *GWarn);

	FirstSlowTask.MakeDialog(true);

	for (int i = 0; i < FirstIttCount; i++)
	{
		// Update text
		FirstSlowTask.EnterProgressFrame(1.f,
			FText::Format(NSLOCTEXT("ProjectSlowTask", "FirstSlowTask", "Processing {0} / {1}"), FText::AsNumber(i), FText::AsNumber(FirstIttCount)));
		//WORK FIRST TASK
		UE_LOG(LogTemp, Display, TEXT("FIRST TASK: [%d]"), i);

		//FirstSlowTask.TickProgress();

		//Execute Second Slow Task
		int SecondIttCount = 100000;
		FScopedSlowTask SecondSlowTask = FScopedSlowTask(SecondIttCount,
			NSLOCTEXT("ProjectSlowTask", "SecondSlowTask", "Processing..."), true, *GWarn);

		SecondSlowTask.MakeDialog(true);

		for (int j = 0; j < SecondIttCount; j++)
		{
			SecondSlowTask.EnterProgressFrame(1.f,
				FText::Format(NSLOCTEXT("ProjectSlowTask", "SecondSlowTask", "Processing {0} / {1}"), FText::AsNumber(j), FText::AsNumber(SecondIttCount)));
			//WORK SECOND TASK
			UE_LOG(LogTemp, Display, TEXT("SECOND TASK: [%d]"), i);

			if (GWarn->ReceivedUserCancel())
			{

				break;
			}
		}
	}
}