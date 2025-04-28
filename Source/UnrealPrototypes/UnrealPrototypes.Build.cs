// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealPrototypes : ModuleRules
{
	public UnrealPrototypes(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
