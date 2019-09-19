#pragma once

#ifndef UNITABILITYJUMP_H
#define UNITABILITYJUMP_H

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/ReflectContext.h>

#include "UnitAbilities.h"

namespace Project1
{
	class UnitAbilityJump 
		: public UnitAbilities
	{
	public:
		AZ_RTTI(UnitAbilityJump, "{C7DA270C-3C8A-4EE1-88A4-A02E535F4D60}", UnitAbilities);
		AZ_CLASS_ALLOCATOR(UnitAbilityJump, AZ::SystemAllocator, 0);
		static void Reflect(AZ::ReflectContext* reflectContext);

		UnitAbilityJump();
		virtual ~UnitAbilityJump();

		void InvokeAbility(const AZ::EntityId& entity, float deltaTime) override;

	public:
		float m_Impulse;
		float m_period = 3.0f;
		float m_elapsed = 0.0f;
	};
}

#endif