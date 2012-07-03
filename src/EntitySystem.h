#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include <bitset>
#include "BitSize.h"
#include "Component.h"
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <bitset>
#include "ImmutableBag.h"
//#include "Entity.h"


namespace artemis {
	namespace system {

		class Entity;
		class World;
		
		class EntitySystem {

			public:

				void printTypeFlag() {
					std::cout << typeFlags;
				}

				std::bitset<BITSIZE> getSystemBit() {
					return systemBit;
				}

				void setSystemBit(std::bitset<BITSIZE> bit);
				~EntitySystem();

				/*override these functions*/
				virtual void initialize() {};
				
				void setWorld(World *world);
				void change(Entity &e);
				void process();
				
			protected:
				EntitySystem() { this->world = nullptr; };
				artemis::system::World * world;
				/**
				* Call this in the constructor of the derived system
				*/
				template<typename...components>
				void setComponentTypes() {
					addToTypeFlag(typelist<components...>());
				}

				/*override these functions*/
				virtual void begin() {};
				virtual void end() {};
				virtual void removed(artemis::system::Entity &e) {};
				virtual void added(artemis::system::Entity &e) {};


				//Abstracts
				virtual void processEntities(artemis::util::ImmutableBag<Entity*> * bag) = 0;
				virtual bool checkProcessing() = 0;


			private:
				std::bitset<BITSIZE> systemBit;
				std::bitset<BITSIZE> typeFlags;
				artemis::util::Bag<Entity*> actives;

				void remove(Entity &e);


				//============================================================
				//Meta templates. Helps with passing each type from the variadic template
				/*
				 *Struct to pass rest the types
				 */
				template<typename...>
				struct typelist {};

				/*
				 * Recursively called. On each iteration  "component" is set to the next "typename" from rest pack set. .
				 * We pass this component into our ComponentManager.
				 */
				template<typename component, typename ... Rest>
				void addToTypeFlag(typelist<component,Rest...>) {

					//Add Bits to typeflags
					typeFlags |= artemis::component::ComponentTypeManager::getBit<component>();

					addToTypeFlag(typelist<Rest...>());
				};

				/**
				 * addToTypeFlag is called recursively. This defines the end condition.
				 * When our typelist has no types left from the pack, the call will end.
				 */
				void addToTypeFlag(typelist<>) { };
		};

		class EntityProcessingSystem : public EntitySystem {
			public:
				EntityProcessingSystem() {};
			protected:
				virtual void work(Entity *e) = 0;
				void processEntities(artemis::util::ImmutableBag<Entity*> * bag);
				virtual bool checkProcessing();
		};


		class SystemBitManager {
			private:
				static int POS;
				static std::unordered_map< size_t, std::bitset<BITSIZE>* > systemBits;

			public:

				static std::bitset<BITSIZE> & getBitFor(const std::type_info & type);

				template<typename system>
				static std::bitset<BITSIZE> & getBitFor() {

					assert((std::is_base_of< EntitySystem, system >::value == true));

					return getBitFor(typeid(system));

				}



		};


	};
};


#endif
