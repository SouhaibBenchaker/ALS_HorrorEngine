

using UnrealBuildTool;
using System.Collections.Generic;

public class HorrorEngineToALSTarget : TargetRules
{
	public HorrorEngineToALSTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "HorrorEngineToALS" } );
	}
}
