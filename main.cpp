#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"
#include "MovementSystem.h"
#include "MovementComponent.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "Entity.h"
#include <unistd.h>
#include <windows.h>


int main(int argc, char **argv) {
	
	artemis::World w;
	artemis::SystemManager * sm = w.getSystemManager();
	MovementSystem * movementsys = (MovementSystem*)sm->setSystem(new MovementSystem());
	artemis::EntityManager * em = w.getEntityManager();
	
	sm->initializeAll();
	
	artemis::Entity * player = em->create();
	
	
	
	player->addComponent(new MovementComponent(2,4));
	player->addComponent(new PositionComponent(0,0));
	player->refresh();
	
	PositionComponent * comp = (PositionComponent*)player->getComponent<PositionComponent>();
	
	while(true){
		
		w.loopStart();
		w.setDelta(0.0016f);
		movementsys->process();
		
		std::cout << "X:"<< comp->posX << std::endl;
		std::cout << "Y:"<< comp->posY << std::endl;
		Sleep(160);
	}
	
	
	//std::cin.get();
	//delete ent;
	return 0;
}
