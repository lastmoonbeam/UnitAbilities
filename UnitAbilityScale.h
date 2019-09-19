#ifndef UNITABILITYSCALE_H
#define UNITABILITYSCALE_H

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/ReflectContext.h>

#include "UnitAbilities.h"

namespace Project1
{
	class UnitAbilityScale
		: public UnitAbilities
	{
	public:
		AZ_RTTI(UnitAbilityScale, "{B6F924F4-BCC9-443D-BE80-CF734D45A3BF}", UnitAbilities);
		AZ_CLASS_ALLOCATOR(UnitAbilityScale, AZ::SystemAllocator, 0);
		static void Reflect(AZ::ReflectContext* reflectContext);

		UnitAbilityScale();
		virtual ~UnitAbilityScale();

		void InvokeAbility(const AZ::EntityId& entity, float deltaTime) override;

	public:
		float m_minUniformScale = 1.0f;
		float m_maxUniformScale = 10.0f;
		float m_period = 5.0f;
		float m_elapsed = 0.0f;
		AZ::SimpleLcgRandom m_randomGenerator;
	};
}

#endif