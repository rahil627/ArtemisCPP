#ifndef WORLD_H
#define WORLD_H

#include "SystemManager.h"
#include "EntityManager.h"
#include "ImmutableBag.h"

namespace artemis {
	namespace system {
		
	class Entity;
	
		class World {
			public:
				World();
				~World();
				SystemManager * getSystemManager();
				EntityManager * getEntityManager();
				//TagManager *   getTagManager();
				//GroupManager * getGroupManager();
				float getDelta();
				void setDelta(float delta);
				void deleteEntity(Entity *e);
				void refreshEntity(Entity *e);
				//Entity* createEntity();
				//Entity* getEntity(int entityID);
				void loopStart();



			private:
				SystemManager * systemManager;
				EntityManager * entityManager;
				//TagManager * tagManager;
				//GroupManager * grouManager;
				float delta;
				artemis::util::Bag<Entity*> refreshed;
				artemis::util::Bag<Entity*> deleted;



		};
	};
};
#endif // $(Guard token)
