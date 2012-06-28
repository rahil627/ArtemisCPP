#include "EntitySystem.h"

namespace artemis {
	namespace system {
		int SystemBitManager::POS = 0;
		unordered_map<size_t, bitset<BITSIZE>*> SystemBitManager::systemBits;
	};
};
