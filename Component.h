#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <bitset>
#include "BitSize.h"
#include <unordered_map>
#include <typeinfo>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;


namespace artemis {
	namespace component {


		class Component {
			public:
				virtual ~Component() = 0;
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
				bitset<BITSIZE> getBit() const;
				int getID() const;
			private:
				//
				static bitset<BITSIZE> nextBit;
				static int nextId;
				//==================================
				bitset<BITSIZE> bit;
				int id;
				void init();

		};
////========================================================
//Surpress unused variable warnning. Might need to rewrite it
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored  "-Wunused-variable"
		/**
		 * Manages the id and bitset for every component based on their type.
		 * Currently any object can be passed. Keep types relevant. Make sure they are Components.
		 * */

		class ComponentTypeManager {

			private:
				ComponentTypeManager();
				static unordered_map<size_t,ComponentType*> componentTypes;

				/**
				 *
				 **/
				static ComponentType & getFor(const type_info &t) {
					ComponentType * type = componentTypes[t.hash_code()];

					if(type == NULL) {
						type = new ComponentType();
						componentTypes[t.hash_code()] = type;
					}

					return *type;
				};

			public:

				/**
				* Gets the component type object
				**/
				template<typename component>
				static ComponentType & getTypeFor() {

					//Check if we are being legal with components and shizzle
					Component * c = (component*)0;
					return getFor(typeid(component));
				}

				/**
				* Gets the bit set of a component
				**/
				template<typename component>
				static bitset<BITSIZE> getBit() {

					//Check if we are being legal with components and shizzle
					Component * c = (component*)0;

					ComponentType & type = getFor(typeid(component));
					return type.getBit();
				}
				/**
				 * Gets the component id
				 **/
				template<typename component>
				static int getId() {

					//Check if we are being legal with components and shizzle
					Component * c = (component*)0;

					ComponentType & type = getFor(typeid(component));
					return type.getID();
				};



				//typedef getCompBit bitset<BITSIZE>(*getBit<Component>)();

		};
#pragma GCC diagnostic pop

	};
};

#endif
