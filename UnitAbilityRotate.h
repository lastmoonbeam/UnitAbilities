#pragma once

#ifndef UNITABILITYROTATE_H
#define UNITABILITYROTATE_H

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/ReflectContext.h>

#include "UnitAbilities.h"

namespace Project1
{
	class UnitAbilityRotate
		: public UnitAbilities
	{
	public:
		AZ_RTTI(UnitAbilityRotate, "{07224EC2-0640-4618-BA1C-EE0C19EA6ACB}", UnitAbilities);
		AZ_CLASS_ALLOCATOR(UnitAbilityRotate, AZ::SystemAllocator, 0);
		static void Reflect(AZ::ReflectContext* reflectContext);

		UnitAbilityRotate();
		virtual ~UnitAbilityRotate();

		void InvokeAbility(const AZ::EntityId& entity, float deltaTime) override;

	public:
		float m_Impulse = 1000;
		float m_period = 3.0f;
		float m_elapsed = 0.0f;

	};
}

#endif