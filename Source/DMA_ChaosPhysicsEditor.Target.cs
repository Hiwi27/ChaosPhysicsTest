// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DMA_ChaosPhysicsEditorTarget : TargetRules
{
	public DMA_ChaosPhysicsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "DMA_ChaosPhysics" } );
	}
}
