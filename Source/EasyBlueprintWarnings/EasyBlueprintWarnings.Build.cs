using UnrealBuildTool;

public class EasyBlueprintWarnings : ModuleRules
{
	public EasyBlueprintWarnings(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"DeveloperSettings"
		});
	}
}
