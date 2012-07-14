#ifndef DMOVEMENT_SYSTEM_H
#define DMOVEMENT_SYSTEM_H


#include "DelayedEntityProcessingSystem.h"
#include "MovementComponent.h"
#include "ComponentMapper.h"
#include <stdlib.h>//needs these three lines


class DMovementSystem : public artemis::DelayedEntityProcessingSystem {

	private:
		artemis::ComponentMapper<MovementComponent> * velocityMapper;
		artemis::ComponentMapper<PositionComponent> * positionMapper;

	public:
		DMovementSystem() {
			setComponentTypes<MovementComponent,PositionComponent>();
		};

		virtual void begin(){
			system("cls");
			std::cout << "Starting MovementSystem======================" <<  std::endl;
		}

		virtual void end(){
				
			std::cout << "Ending MovementSystem======================" <<  std::endl;
		}

		virtual void initialize() {
			velocityMapper = new artemis::ComponentMapper<MovementComponent>(world);
			positionMapper = new artemis::ComponentMapper<PositionComponent>(world);
		};

		virtual void processEntity(artemis::Entity &e, float accumulatedDelta) {
			
			std::cout << accumulatedDelta << "\n";
			PositionComponent & p = *positionMapper->get(e);
			MovementComponent & v = *velocityMapper->get(e);
			
			p.posX += v.velocityX * world->getDelta();
			p.posY += v.velocityY * world->getDelta();
			
			std::cout <<  std::endl;
			std::cout << "X:"<< p.posX << std::endl;
			std::cout << "Y:"<< p.posY << std::endl;
			std::cout <<  std::endl;
			
		};

		~DMovementSystem() {
			delete velocityMapper;
			delete positionMapper;
		};


};


#endif // $(Guard token)
