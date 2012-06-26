#include "EntitySystem.h"

namespace artemis {
	namespace system {
		int SystemBitManager::POS = 0;
		bitset<BITSIZE> SystemBitManager::dummy_set(1);
		unordered_map<size_t, bitset<BITSIZE>*> SystemBitManager::systemBits;
	};
};
