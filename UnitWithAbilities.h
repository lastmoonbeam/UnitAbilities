#pragma once

#ifndef MULTIPLAYERSAMPLE_COMPONENTS_DEATHACTIONCOMPONENT_H
#define MULTIPLAYERSAMPLE_COMPONENTS_DEATHACTIONCOMPONENT_H

#include <AzCore/Component/Component.h>
#include <AzCore/Component/TickBus.h>

#include "Include/Project1/Components/UnitAbilitiesBus.h"

namespace Project1
{
	class UnitAbilities;
	typedef AZStd::vector<UnitAbilities*> UnitAbilitiesList;

	class UnitWithAbilitiesComponent
		: public AZ::Component,
		public AZ::TickBus::Handler
	{
	public:
		AZ_COMPONENT(UnitWithAbilitiesComponent, "{6DE8F69C-5D0E-4112-898B-4B8988E7ABB0}", AZ::Component);
		static void Reflect(AZ::ReflectContext* context);

		UnitWithAbilitiesComponent();
		virtual ~UnitWithAbilitiesComponent();

		// AZ::Component
		void Init();
		void Activate();
		void Deactivate();

		// UnitAbilityBus
		//void OnAbilityInvoke(const AZ::EntityId& entity, float deltaTime) override;

		
		// AZ::TickBus 
		void OnTick(float deltaTime, AZ::ScriptTimePoint time);

		void InvokeAllAbilities(const AZ::EntityId & entity, float deltaTime);


	private:
		UnitAbilitiesList m_unitAbilities; 
	};
}

#endif