#include "Project1_precompiled.h"

#include <AzCore/Serialization/EditContext.h>

#include "UnitAbilities.h"

// Temporary until the ability to reflect non-components in modules gets fixed up by Systems.
//#include "Components/DeathActions/AsteroidDeathAction.h"
//#include "Components/DeathActions/DropCollectibleDeathAction.h"
//#include "Components/DeathActions/SpawnSliceDeathAction.h"

#include "UnitAbilityJump.h"
#include "UnitAbilityRotate.h"
#include "UnitAbilityScale.h"

using namespace Project1;

void UnitAbilities::Reflect(AZ::ReflectContext* context)
{
	AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context);

	if (serializeContext)
	{
		serializeContext->Class<UnitAbilities>()
			->Version(1)
			->Field("Enabled", &UnitAbilities::m_enabled)
			;

		AZ::EditContext* editContext = serializeContext->GetEditContext();

		if (editContext)
		{
			editContext->Class<UnitAbilities>("UnitAbilities", "")
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilities::m_enabled, "Enabled", "")
				->Attribute(AZ::Edit::Attributes::AutoExpand, true)
				->Attribute(AZ::Edit::Attributes::ContainerCanBeModified, true)
				;
		}
	}

	// Reflect all of the UnitAbilities
	UnitAbilityJump::Reflect(context);
	UnitAbilityRotate::Reflect(context);
	UnitAbilityScale::Reflect(context);

}
