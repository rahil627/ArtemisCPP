#include "Component.h"

namespace artemis {
	namespace component {
		Component::~Component() {

		}

		ComponentType::ComponentType() {
			init();
		}

		void ComponentType::init() {
			bit = nextBit;
			nextBit = nextBit << 1;
			id = nextId++;
		}

		bitset<BITSIZE> ComponentType::getBit() const {
			return bit;
		}

		int ComponentType::getID() const {
			return id;
		}

		bitset<BITSIZE> ComponentType::nextBit(1);
		int ComponentType::nextId = 1;
		unordered_map<size_t,ComponentType*>ComponentTypeManager::componentTypes;

		//===================================================

		ComponentType & ComponentTypeManager::getFor(const type_info &t) {
			ComponentType * type = componentTypes[t.hash_code()];

			if(type == NULL) {
				type = new ComponentType();
				componentTypes[t.hash_code()] = type;
			}

			return *type;
		};

	};
};
