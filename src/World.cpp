#include "World.h"
#include "Entity.h"

namespace artemis {
	namespace system {
		World::World() {
			//TODO add more managers
			this->systemManager = new SystemManager(this);
			this->entityManager = new EntityManager(this);
		}

		void World::deleteEntity(Entity* e) {
			if(!deleted.contains(e))
				deleted.add(e);
		}

		int World::getDelta() {
			return this->delta;
		}

			SystemManager* World::getSystemManager() {
				return systemManager;
			}

		void World::loopStart() {
			if(!refreshed.isEmpty()) {
				for(int i=0; i<refreshed.getCount(); i++) {
					//TODO ADD  MANAGERs
					entityManager->refresh(refreshed.get(i));
				}

				refreshed.clear();

			}

			if(!deleted.isEmpty()) {
				for(int i=0; i<deleted.getCount(); i++) {
					Entity * e = deleted.get(i);
					//groupManager.remove(e);
					entityManager->remove(e);
					//tagManager.remove(e);
				}

				deleted.clear();
			}

		}

		void World::refreshEntity(Entity* e) {
			refreshed.add(e);
		}

		void World::setDetla(int delta) {
			this->delta = delta;
		}

		World::~World() {
			delete systemManager;
			delete entityManager;
		}


	};
};
