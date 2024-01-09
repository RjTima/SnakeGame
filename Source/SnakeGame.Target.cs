// Snake Game Copyright @RjTima

using UnrealBuildTool;
using System.Collections.Generic;

public class SnakeGameTarget : TargetRules
{
	public SnakeGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SnakeGame" } );
	}
}
