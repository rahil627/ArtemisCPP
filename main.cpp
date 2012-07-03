#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"
#include "MovementSystem.h"
#include "MovementComponent.h"
#include "EntityManager.h"
#include "Entity.h"


int main(int argc, char **argv) {
	
	artemis::system::World w;
	artemis::system::SystemManager * sm = w.getSystemManager();
	MovementSystem * movementsys = (MovementSystem*)sm->setSystem(new MovementSystem());
	artemis::system::EntityManager * em = w.getEntityManager();
	
	sm->initializeAll();
	
	artemis::system::Entity * player = em->create();
	
	
	
	player->addComponent(new MovementComponent(2,2));
	player->addComponent(new PositionComponent(0,0));
	player->refresh();
	
	PositionComponent * comp = (PositionComponent*)player->getComponent(artemis::component::ComponentTypeManager::getTypeFor<PositionComponent>());
	
	while(true){
		w.loopStart();
		w.setDelta(0.0016f);
		movementsys->process();
		
		std::cout << comp->posX << std::endl;
		std::cout << comp->posY << std::endl;

		
	}
	
	
	//std::cin.get();
	//delete ent;
	return 0;
}
