#include "EntitySystem.h"
#include "World.h"
#include "Entity.h"

using namespace std;
using namespace artemis::util;
namespace artemis {
	namespace system {

		int SystemBitManager::POS = 0;
		unordered_map<size_t, bitset<BITSIZE>*> SystemBitManager::systemBits;

		bitset<BITSIZE> & SystemBitManager::getBitFor(const type_info & type) {

			//assert((std::is_base_of< EntitySystem, system >::value == true));

			size_t hash = type.hash_code();

			bitset<BITSIZE> * bit = systemBits[hash];

			if(bit == nullptr) {

				bit = new bitset<BITSIZE>(1);
				(*bit)  <<=  POS++;

				systemBits[hash] = bit;
			}

			return *bit;

		}

		//======================================================================

		EntitySystem::~EntitySystem() {
			world = nullptr;
		}


		void EntitySystem::change(Entity& e) {
			bool contains = (systemBit & e.getSystemBits()) == systemBit;
			bool interest = (typeFlags & e.getTypeBits()) == typeFlags;

			if(interest && !contains && typeFlags.any()) {
				actives.add(&e);
				e.addSystemBit(systemBit);
				added(e);
			} else if(!interest && contains && typeFlags.any()) {
				//this->remove(e);
			}
		}


		void EntitySystem::process() {
			if(checkProcessing()) {
				begin();
				processEntities(&actives);
				end();
			}
		};

		void EntitySystem::setWorld(World *world) {
			this->world = world;
		};

		void EntitySystem::remove(Entity &e) {
			actives.remove(&e);
			e.removeSystemBit(systemBit);
			removed(e);
		};

		//======================================================================

		bool EntityProcessingSystem::checkProcessing() {
			return true;
		}

		void EntityProcessingSystem::processEntities(ImmutableBag<Entity*>* bag) {
			for(int i=0; i < bag->getCount(); i++) {work(*bag->get(i));}
		}
		
		void  EntitySystem::setSystemBit(bitset<BITSIZE> bit) {
			systemBit = bit;
		}


	};
};
