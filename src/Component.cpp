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
	};
};
