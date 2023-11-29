// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CS3520Final : ModuleRules
{
	public CS3520Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
