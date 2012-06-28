#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

#include <bitset>
#include "BitSize.h"
#include "Component.h"
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <bitset>

namespace artemis {
	namespace system {

		class EntitySystem {

			public:

				EntitySystem() {

				}

				void printTypeFlag() {
					std::cout << typeFlags;
				}


				/**
				 * Call this in the constructor of the derived system
				 */
				//TODO move to protected after testing
				template<typename...components>
				void setComponentTypes() {
					addToTypeFlag(typelist<components...>());
				}

			protected:


				/*override these functions*/
				virtual void initialize() {};
				virtual void begin() {};
				virtual void end() {};

				//TODO Can't add these methods until further development
				//virtual void removed(Entity &e)
				//virtual void added(Entity &e){};
				//virtual void processEntities() = 0;
				//virtual bool checkProcessing() = 0;
				//void change(Entity &e){};
				//setWorld(World &world){};

				void setSystemBit(bitset<BITSIZE> bit) {
					systemBit = bit;
				}
			private:
				bitset<BITSIZE> systemBit;
				bitset<BITSIZE> typeFlags;

				//TODO Can't add these private methods untill further development
				//remove(Entity e){};


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

		class SystemBitManager {
			private:
				static int POS;
				static unordered_map< size_t, bitset<BITSIZE>* > systemBits;

			public:
				template<typename system>
				static bitset<BITSIZE> & getBitFor() {

					assert((std::is_base_of< EntitySystem, system >::value == true));

					size_t hash = typeid(system).hash_code();

					bitset<BITSIZE> * bit = systemBits[hash];

					if(bit == NULL) {

						bit = new bitset<BITSIZE>(1);
						(*bit)  <<=  POS++;

						systemBits[hash] = bit;
					}

					return *bit;
				}
		};


	};
};


#endif
