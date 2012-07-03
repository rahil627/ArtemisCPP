#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H


#include "Entity.h"
#include "ImmutableBag.h"
#include "Component.h"


namespace artemis {
	namespace system {

		class World;
		
		class EntityManager {

			public:
				EntityManager(World * world);
				Entity * create();
				void remove(Entity * e);
				void removeComponentsOfEntity(Entity * e);
				bool isActive(int entityID);
				void addComponent(Entity *e, artemis::component::Component * c);
				void refresh(Entity* e);

				void removeComponent(Entity * e, artemis::component::ComponentType & type);

				template<typename c>
				void removeComponent(Entity * e) {
					removeComponent(e,artemis::component::ComponentTypeManager::getTypeFor<c>());
				}

				template<typename c>
				artemis::component::Component * getComponent(Entity * e) {
					artemis::component::ComponentType type = artemis::component::ComponentTypeManager::getTypeFor<c>();
					artemis::util::Bag<artemis::component::Component*>* bag = componentsByType.get(type.getId());
					if(bag != nullptr && e->getId() < bag->getCapacity())
						return bag->get(e->getId());
					return nullptr;
				}

				Entity * getEntity(int entityId);
				int getEntityCount();
				long getTotalCreated();
				long getTotalRemoved();

				artemis::util::Bag<artemis::component::Component*> getcomponents(Entity * e);


			private:
				World * world;
				artemis::util::Bag<Entity*> activeEntities;
				artemis::util::Bag<Entity*> removedAndAvailable;
				int nextAvailableId;
				int count;
				long uniqueEntityId;
				long totalCreated;
				long totalRemoved;

				artemis::util::Bag<artemis::util::Bag<artemis::component::Component*>*> componentsByType;
				artemis::util::Bag<artemis::component::Component*> entityComponents;

		};


	};
};
#endif // $(Guard token)
