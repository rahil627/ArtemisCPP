#include "SystemManager.h"
#include "World.h"
#include "EntitySystem.h"
#include "SystemBitManager.h"

namespace artemis {
	
		SystemManager::SystemManager(World* world) {
			this->world = world;
			bagged = new Bag<EntitySystem*>();
		}

		Bag<EntitySystem*> * SystemManager::getSystems() {
			return bagged;
		}

		void SystemManager::initializeAll() {
			for(int i=0; i< bagged->getCount(); i++) {
				bagged->get(i)->initialize();
			}

		}

		EntitySystem* SystemManager::setSystem(EntitySystem* stm) {
			stm->setWorld(world);
			
			if(!bagged->contains(stm)){
				systems[typeid(stm).hash_code()]  = stm;
				bagged->add(stm);
			}
			
			stm->setSystemBit(SystemBitManager::getBitFor(typeid(*stm)));
			
			return stm;
		}
};
