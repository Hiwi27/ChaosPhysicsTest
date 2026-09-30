// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DMA_ChaosPhysicsTarget : TargetRules
{
	public DMA_ChaosPhysicsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "DMA_ChaosPhysics" } );
	}
}
