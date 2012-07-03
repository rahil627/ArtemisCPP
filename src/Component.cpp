#include "Component.h"
#include "World.h"

using namespace std;
using namespace artemis::system;

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

		int ComponentType::getId() const {
			return id;
		}

		bitset<BITSIZE> ComponentType::nextBit(1);
		int ComponentType::nextId = 1;
		unordered_map<size_t,ComponentType*>ComponentTypeManager::componentTypes;

		//===================================================

		ComponentType & ComponentTypeManager::getTypeFor(const type_info &t) {
			ComponentType * type = componentTypes[t.hash_code()];

			if(type == nullptr) {
				type = new ComponentType();
				componentTypes[t.hash_code()] = type;
			}

			return *type;
		};
		
	};
};
