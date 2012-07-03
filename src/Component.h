#ifndef COMPONENT_H
#define COMPONENT_H

#include <bitset>
#include "BitSize.h"

#include <unordered_map>
#include <typeinfo>
#include <string>
#include <iostream>
#include <assert.h>

namespace artemis {
	namespace component {


		class Component {
			public:
				virtual ~Component() = 0;
			protected:
				Component(){};
		};

////========================================================
		/**
		 * Identifies a bitset and id for a component object
		 * Do not instantiate a ComponentType, instead use the ComponentTypeManager.
		 * */
		class ComponentType {

			public:
				ComponentType();
				//==================================
				std::bitset<BITSIZE> getBit() const;
				int getId() const;
			private:
				//
				static std::bitset<BITSIZE> nextBit;
				static int nextId;
				//==================================
				std::bitset<BITSIZE> bit;
				int id;
				void init();

		};

////========================================================
//Surpress unused variable warnning. Might need to rewrite it
//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored  "-Wunused-variable"
		/**
		 * Manages the id and bitset for every component based on their type.
		 * */

		class ComponentTypeManager {

			private:
				ComponentTypeManager();
				static std::unordered_map<size_t,ComponentType*> componentTypes;

	

		public:


				/**
				 *
				 **/
				static ComponentType & getTypeFor(const std::type_info &t);
				
				/**
				* Gets the component type object
				**/
				template<typename c>
				static ComponentType & getTypeFor() {

					//Check if we are being legal with components and shizzle
					//Component * c = (component*)0;

					assert((std::is_base_of< Component, c >::value == true));

					return getTypeFor(typeid(c));
				}

				/**
				* Gets the bit set of a component
				**/
				template<typename c>
				static std::bitset<BITSIZE> getBit() {

					//Check if we are being legal with components and shizzle
					//Component * c = (component*)0;

					assert((std::is_base_of< Component, c >::value == true));

					ComponentType & type = getTypeFor(typeid(c));
					return type.getBit();
				}
				/**
				 * Gets the component id
				 **/
				template<typename c>
				static int getId() {

					//Check if we are being legal with components and shizzle

					assert((std::is_base_of< Component, c >::value == true));

					ComponentType & type = getTypeFor(typeid(c));
					return type.getId();
				};



				//typedef getCompBit bitset<BITSIZE>(*getBit<Component>)();

		};
//#pragma GCC diagnostic pop

////========================================================

		

		/*template<typename T>
		class ComponentMapper {

			private:
				//ComponentType * type;
				artemis::system::EntityManager * em;

			public:

				ComponentMapper(artemis::system::World &world) {
					em = world.getEntityManager();
					//type = ComponentTypeManager::getTypeFor<T>();
				}

				~ComponentType() {
					type = nullptr;
					em = nullptr;
				}

				T & get(artemis::system::Entity * e) {
					return &(T)em->getComponent<T>(e);
				}

		};*/

	};
};

#endif
