#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H


#include "EntityProcessingSystem.h"
#include "MovementComponent.h"
#include "ComponentMapper.h"


class MovementSystem : public artemis::EntityProcessingSystem {

	private:
		artemis::ComponentMapper<MovementComponent> * velocityMapper;
		artemis::ComponentMapper<PositionComponent> * positionMapper;

	public:
		MovementSystem() {
			setComponentTypes<MovementComponent,PositionComponent>();
		};

		virtual void initialize() {
			velocityMapper = new artemis::ComponentMapper<MovementComponent>(world);
			positionMapper = new artemis::ComponentMapper<PositionComponent>(world);
		};

		virtual void work(artemis::Entity* e) {
			positionMapper->get(e).posX += velocityMapper->get(e).velocityX * world->getDelta();
			positionMapper->get(e).posY += velocityMapper->get(e).velocityY * world->getDelta();
		};

		~MovementSystem() {
			delete velocityMapper;
			delete positionMapper;
		};


};


#endif // $(Guard token)
