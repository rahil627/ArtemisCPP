#ifndef ENTITY_H
#define ENTITY_H

#include <bitset>
#include <string>
#include <cstddef>
#include <typeinfo>
#include "BitSize.h"
#include "Component.h"
#include "ImmutableBag.h"
//#include "EntityManager.h"

namespace artemis {
	namespace system {

		class EntityManager;
		class World;
		
		class Entity {

			private:
				int id;
				long int uniqueId;
				std::bitset<BITSIZE> typeBits;
				std::bitset<BITSIZE> systemBits;
				artemis::system::World * world;
				EntityManager * entityManager;
			protected:

			public:
				Entity(World * world, int id);
				~Entity();
				int getId();
				void setUniqueId(long int uniqueId);
				long int getUniqueID();

				std::bitset<BITSIZE> getTypeBits();
				void addTypeBit(std::bitset<BITSIZE> bit);
				void removeTypeBit(std::bitset<BITSIZE> bit);
				std::bitset<BITSIZE> getSystemBits();
				void addSystemBit(std::bitset<BITSIZE> bit);
				void removeSystemBit(std::bitset<BITSIZE> bit);
				void setSystemBits(std::bitset<BITSIZE> systemBits);
				void setTypeBits(std::bitset<BITSIZE> typeBits);
				void reset();

				std::string toString();

				void addComponent(artemis::component::Component * c);

				//Might change to non template
				/*template<typename c>
				void removeComponent() {
					entityManager->removeComponent(this,artemis::component::ComponentTypeManager::getTypeFor<c>());
				}*/

				void removeComponent(artemis::component::ComponentType & type);


				artemis::component::Component * getComponent(artemis::component::ComponentType & type);

				/*template<typename c>
				artemis::component::Component * getComponent() {
					return (c)entityManager->getComponent(artemis::component::ComponentTypeManager.getTypeFor<c>());
				}*/

				artemis::util::ImmutableBag<artemis::component::Component*> * getComponents();
				
				bool isActive();
				void refresh();
				void remove();
				void setGroup(std::string group);
				void setTag(std::string tag);


		};
	};
};
#endif // $(Guard token)
