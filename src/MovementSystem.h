#ifndef MOVEMENT_SYSTEM
#define MOVEMENT_SYSTEM
#include "EntitySystem.h"
#include "MovementComponent.h"
#include "ComponentMapper.h"
//#include "Entity.h"


class MovementSystem : public artemis::system::EntityProcessingSystem {

	private:
		artemis::component::ComponentMapper<MovementComponent> * velocityMapper;
		artemis::component::ComponentMapper<PositionComponent> * positionMapper;

	public:
		MovementSystem() {
			setComponentTypes<MovementComponent,PositionComponent>();
		}

		virtual void initialize() {
			velocityMapper = new artemis::component::ComponentMapper<MovementComponent>(world);
			positionMapper = new artemis::component::ComponentMapper<PositionComponent>(world);
		}

		virtual void work(artemis::system::Entity* e) {
			positionMapper->get(e).posX += velocityMapper->get(e).velocityX * world->getDelta();
			positionMapper->get(e).posY += velocityMapper->get(e).velocityY * world->getDelta();
		}

		~MovementSystem() {
			delete velocityMapper;
			delete positionMapper;
		}


};


#endif // $(Guard token)
