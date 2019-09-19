#include "Project1_precompiled.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "UnitAbilities.h"
#include "UnitWithAbilities.h"

using namespace Project1;

void UnitWithAbilitiesComponent::Reflect(AZ::ReflectContext * context)
{
	UnitAbilities::Reflect(context);

	AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context);

	if (serializeContext)
	{
		serializeContext->Class<UnitWithAbilitiesComponent, AZ::Component>()
			->Version(1)
			->Field("Unit Abilities", &UnitWithAbilitiesComponent::m_unitAbilities)
			;

		AZ::EditContext* editContext = serializeContext->GetEditContext();

		if (editContext)
		{
			editContext->Class<UnitWithAbilitiesComponent>("Unit With Abilities Component", "")
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->Attribute(AZ::Edit::Attributes::Category, "Project1")
				->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"))
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitWithAbilitiesComponent::m_unitAbilities, "Unit Abilities", "List of actions to take when this entity is killed.")
				->Attribute(AZ::Edit::Attributes::AutoExpand, true)
				->Attribute(AZ::Edit::Attributes::ContainerCanBeModified, true)
				;
		}
	}
}

UnitWithAbilitiesComponent::UnitWithAbilitiesComponent()
{
}

UnitWithAbilitiesComponent::~UnitWithAbilitiesComponent()
{
	for (UnitAbilities* unitAbility : m_unitAbilities)
	{
		delete unitAbility;
	}
}

void UnitWithAbilitiesComponent::Init()
{
}

void UnitWithAbilitiesComponent::Activate()
{
	//UnitAbilityBus::Handler::BusConnect(GetEntityId());
	AZ::TickBus::Handler::BusConnect();
}

void UnitWithAbilitiesComponent::Deactivate()
{
	//UnitAbilityBus::Handler::BusDisconnect();
	AZ::TickBus::Handler::BusDisconnect();
}

void UnitWithAbilitiesComponent::InvokeAllAbilities(const AZ::EntityId & entity, float deltaTime)
{
	for (UnitAbilities* unitAbility : m_unitAbilities)
	{
		unitAbility->InvokeAbility(entity, deltaTime);
	}
}

void UnitWithAbilitiesComponent::OnTick(float deltaTime, AZ::ScriptTimePoint time)
{
	InvokeAllAbilities(GetEntityId(), deltaTime);
}
