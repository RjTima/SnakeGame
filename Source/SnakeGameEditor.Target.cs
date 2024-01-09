// Snake Game Copyright @RjTima

using UnrealBuildTool;
using System.Collections.Generic;

public class SnakeGameEditorTarget : TargetRules
{
	public SnakeGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SnakeGame" } );
	}
}
