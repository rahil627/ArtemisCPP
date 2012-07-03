#ifndef _WORLD_H_
#define _WORLD_H_

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
				int getDelta();
				void setDetla(int delta);
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
				int delta;
				artemis::util::Bag<Entity*> refreshed;
				artemis::util::Bag<Entity*> deleted;



		};
	};
};
#endif // $(Guard token)
