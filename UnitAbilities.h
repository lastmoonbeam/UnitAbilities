#pragma once

#ifndef MULTIPLAYERSAMPLE_DEATHACTIONS_DEATHACTION_H
#define MULTIPLAYERSAMPLE_DEATHACTIONS_DEATHACTION_H

#include <AzCore/base.h>
#include <AzCore/Component/EntityId.h>

namespace Project1
{
	class UnitAbilities
	{
	public:
		AZ_RTTI(UnitAbilities, "{4D9C4A97-559E-4288-8D89-25FF55DD69B0}");
		static void Reflect(AZ::ReflectContext* context);

		virtual ~UnitAbilities() = default;
		virtual void SetEnabled(bool IsItEnabled) { m_enabled = IsItEnabled; };
		virtual void InvokeAbility(const AZ::EntityId& entity, float deltaTime) = 0;
	protected:
		bool m_enabled;
	};
}

#endif