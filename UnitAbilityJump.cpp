#include "Project1_precompiled.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "AzFramework/Physics/PhysicsComponentBus.h"
#include "AzFramework/Physics/PhysicsSystemComponentBus.h"

#include "UnitAbilityJump.h"

using namespace Project1;

void UnitAbilityJump::Reflect(AZ::ReflectContext * reflectContext)
{
	AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflectContext);

	if (serializeContext)
	{
		serializeContext->Class<UnitAbilityJump, UnitAbilities>()
			->Version(1)
			->Field("Impulse", &UnitAbilityJump::m_Impulse)
			->Field("Period", &UnitAbilityJump::m_period)
			->Field("Elapsed", &UnitAbilityJump::m_elapsed)
			;

		AZ::EditContext* editContext = serializeContext->GetEditContext();

		if (editContext)
		{
			editContext->Class<UnitAbilityJump>("Unit Ability Jump", "")
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityJump::m_Impulse, "Impulse", "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityJump::m_period, "Period", "")
				->Attribute(AZ::Edit::Attributes::AutoExpand, true)
				->Attribute(AZ::Edit::Attributes::ContainerCanBeModified, true)
				;
		}
	}
}

UnitAbilityJump::UnitAbilityJump()
{

}

UnitAbilityJump::~UnitAbilityJump()
{

}

void UnitAbilityJump::InvokeAbility(const AZ::EntityId & entity, float deltaTime)
{
	if (!m_enabled) return;

	if (m_elapsed >= m_period)
	{
		m_elapsed = 0.0f;

		AzFramework::PhysicsComponentRequestBus::Event(entity, &AzFramework::PhysicsComponentRequestBus::Events::AddImpulse, AZ::Vector3(0.0f, 0.0f, m_Impulse));
		
		AZ_Printf("UnitAbilityJump", "InvokeAbility");
	}
	else
	{
		m_elapsed += deltaTime;
	}
}
