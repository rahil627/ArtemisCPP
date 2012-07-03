#ifndef COMPONENTMAPPER_H
#define COMPONENTMAPPER_H

#include "EntityManager.h"
#include "World.h"

namespace artemis {
	namespace component {
		
		template<typename c>
		class ComponentMapper {

			private:
				artemis::system::EntityManager * em;

			public:

				ComponentMapper(artemis::system::World * world) {
					em = world->getEntityManager();
				}

				~ComponentMapper() {
					em = nullptr;
				}

				c & get(artemis::system::Entity * e) {
					return *(c*)em->getComponent<c>(e);
				}

		};
	};
};
#endif // $(Guard token)
