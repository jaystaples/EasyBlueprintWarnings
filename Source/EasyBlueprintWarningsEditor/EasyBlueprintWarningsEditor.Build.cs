using UnrealBuildTool;

public class EasyBlueprintWarningsEditor : ModuleRules
{
	public EasyBlueprintWarningsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"ApplicationCore",
			"InputCore",
			"Slate",
			"SlateCore",
			"UnrealEd",
			"EasyBlueprintWarnings"
		});
	}
}
