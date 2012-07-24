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
				
				/**
				 *Returns the component mapped to the Entity.
				 *If there is no such component associated with the entity
				 *nullptr is returned.
				 */
				c * get(Entity & e) {
					//ATTN perhaps pointing to the component bag is faster.
					return (c*)em->getComponent<c>(e);
				}

		};
};
#endif // $(Guard token)
