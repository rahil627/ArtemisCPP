#ifndef COMPONENTMAPPER_H
#define COMPONENTMAPPER_H

#include "EntityManager.h"
#include "World.h"

namespace artemis {
	
		template<typename c>
		class ComponentMapper {

			private:
				EntityManager * em;

			public:

				ComponentMapper(World * world) {
					em = world->getEntityManager();
				}

				~ComponentMapper() {
					em = nullptr;
				}

				c & get(Entity * e) {
					return *(c*)em->getComponent<c>(e);
				}

		};
};
#endif // $(Guard token)
