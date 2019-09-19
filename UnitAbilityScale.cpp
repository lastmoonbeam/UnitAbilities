#include "Project1_precompiled.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include <AzCore/Component/TransformBus.h>

#include "UnitAbilityScale.h"

using namespace Project1;

void UnitAbilityScale::Reflect(AZ::ReflectContext * reflectContext)
{
	AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflectContext);

	if (serializeContext)
	{
		serializeContext->Class<UnitAbilityScale, UnitAbilities>()
			->Version(1)
			->Field("minUniformScale", &UnitAbilityScale::m_minUniformScale)
			->Field("maxUniformScale", &UnitAbilityScale::m_maxUniformScale)
			->Field("period", &UnitAbilityScale::m_period)
			->Field("elapsed", &UnitAbilityScale::m_elapsed)
			;

		AZ::EditContext* editContext = serializeContext->GetEditContext();

		if (editContext)
		{
			editContext->Class<UnitAbilityScale>("Unit Ability Scale", "")
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityScale::m_minUniformScale, "minUniformScale", "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityScale::m_maxUniformScale, "maxUniformScale", "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityScale::m_period, "period", "")
				->Attribute(AZ::Edit::Attributes::AutoExpand, true)
				->Attribute(AZ::Edit::Attributes::ContainerCanBeModified, true)
				;
		}
	}
}

UnitAbilityScale::UnitAbilityScale()
{
}

UnitAbilityScale::~UnitAbilityScale()
{
}

void UnitAbilityScale::InvokeAbility(const AZ::EntityId & entity, float deltaTime)
{
	if (!m_enabled) return;


	if (m_elapsed >= m_period)
	{
		m_elapsed = 0.0f;

		float rndUniformScale = m_randomGenerator.GetRandomFloat() * m_maxUniformScale;
		rndUniformScale = AZ::GetClamp<float>(rndUniformScale, m_minUniformScale, m_maxUniformScale);
		AZ::TransformBus::Event(entity, &AZ::TransformBus::Events::SetLocalScale, AZ::Vector3(rndUniformScale));



		AZ_Printf("UnitAbilityScale", "InvokeAbility");
	}
	else
	{
		m_elapsed += deltaTime;
	}
}
