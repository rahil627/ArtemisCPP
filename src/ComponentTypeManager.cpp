#include "ComponentTypeManager.h"

namespace artemis {
	ComponentType & ComponentTypeManager::getTypeFor(const std::type_info &t) {
		ComponentType * type = componentTypes[t.hash_code()];

		if(type == nullptr) {
			type = new ComponentType();
			componentTypes[t.hash_code()] = type;
		}

		return *type;
	};

	std::unordered_map<size_t,ComponentType*>ComponentTypeManager::componentTypes;
}
