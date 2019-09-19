#include "Project1_precompiled.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include <AzCore/Component/TransformBus.h>

#include "AzFramework/Physics/PhysicsComponentBus.h"
#include "AzFramework/Physics/PhysicsSystemComponentBus.h"

#include "UnitAbilityRotate.h"


using namespace Project1;

void UnitAbilityRotate::Reflect(AZ::ReflectContext * reflectContext)
{
	AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflectContext);

	if (serializeContext)
	{
		serializeContext->Class<UnitAbilityRotate, UnitAbilities>()
			->Version(1)
			->Field("Angular Impulse", &UnitAbilityRotate::m_Impulse)
			->Field("Period", &UnitAbilityRotate::m_period)
			->Field("Elapsed", &UnitAbilityRotate::m_elapsed)

			;

		AZ::EditContext* editContext = serializeContext->GetEditContext();

		if (editContext)
		{
			editContext->Class<UnitAbilityRotate>("Unit Ability Rotate", "")
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityRotate::m_Impulse, "Angular Impulse", "")
				->DataElement(AZ::Edit::UIHandlers::Default, &UnitAbilityRotate::m_period, "Period", "")
				->Attribute(AZ::Edit::Attributes::AutoExpand, true)
				->Attribute(AZ::Edit::Attributes::ContainerCanBeModified, true)
				;
		}
	}
}

UnitAbilityRotate::UnitAbilityRotate()
{
}

UnitAbilityRotate::~UnitAbilityRotate()
{

}

void UnitAbilityRotate::InvokeAbility(const AZ::EntityId & entity, float deltaTime)
{
	if (!m_enabled) return;

	//AZ::Quaternion quat = AZ::Quaternion::CreateIdentity();
	//AZ::TransformBus::EventResult(quat, entity ,&AZ::TransformBus::Events::GetLocalRotationQuaternion);
	//AZ::Quaternion adjust = AZ::Quaternion::CreateFromAxisAngle(AZ::Vector3(0, 0, 1), m_speed * deltaTime);
	//AZ::TransformBus::Event(entity, &AZ::TransformBus::Events::SetLocalRotationQuaternion, quat * adjust);
	
	if (m_elapsed >= m_period)
	{
		m_elapsed = 0.0f;

		AzFramework::PhysicsComponentRequestBus::Event(entity, &AzFramework::PhysicsComponentRequestBus::Events::AddAngularImpulse, AZ::Vector3(0.0f, 0.0f, m_Impulse * deltaTime));
		

		AZ_Printf("UnitAbilityRotate", "InvokeAbility");
	}
	else
	{
		m_elapsed += deltaTime;
	}

}
