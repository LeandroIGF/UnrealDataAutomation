// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealDataAutomationTestTarget : TargetRules
{
    public UnrealDataAutomationTestTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("MyGame"); // Sostituisci con il nome del tuo modulo

        // --- Configurazione Playtest ---

        // Usiamo la base di Test (Performance ottimizzate)
        Configuration = UnrealTargetConfiguration.Test;

        // 1. Abilita la console a livello di Global Definition
        //ProjectDefinitions.Add("ALLOW_CONSOLE_IN_SHIPPING=1");

        // 2. Flags corretti per UE5
        bBuildDeveloperTools = true;
        bCompileAgainstEngine = true;
        bCompileAgainstCoreUObject = true;

        // Questo flag è quello che effettivamente sblocca la console in Test/Shipping
        // se impostato correttamente nel file Target.
        bOverrideBuildEnvironment = true;
    }
}
