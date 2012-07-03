#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <typeinfo>
#include <unordered_map>

#include "ImmutableBag.h"

namespace artemis {
	namespace system {
		
		class World;
		class EntitySystem;
		
		class SystemManager {
			public:
				SystemManager(artemis::system::World *world);
				void initializeAll();
				artemis::util::Bag<artemis::system::EntitySystem*> * getSystems();
				artemis::system::EntitySystem * setSystem(artemis::system::EntitySystem * stm);

				template<typename eSystem>
				artemis::system::EntitySystem* getSystem() {
					return (eSystem)(systems[typeid(eSystem).hash_code()]);
				}

			private:
				artemis::system::World * world;
				std::unordered_map<size_t, artemis::system::EntitySystem*> systems;
				artemis::util::Bag<artemis::system::EntitySystem*> * bagged;
		};
	};
};
#endif // $(Guard token)
