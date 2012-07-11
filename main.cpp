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
#include "TagManager.h"

int main(int argc, char **argv) {

	artemis::World w;
	
	artemis::SystemManager & sm = *w.getSystemManager();
	artemis::EntityManager & em = *w.getEntityManager();
	artemis::TagManager	   & tm = *w.getTagManager();
	
	
	MovementSystem * movementsys = (MovementSystem*)sm.setSystem(new MovementSystem());
	sm.initializeAll();

	

	artemis::Entity & player  = em.create();
	artemis::Entity & player2 = em.create();
	artemis::Entity & player3 = em.create();
	artemis::Entity & player4 = em.create();
	std::cout << "Entity count:" <<  em.getEntityCount() << "\n";


	player.addComponent(new MovementComponent(2,4));
	player.addComponent(new PositionComponent(0,0));
	player.refresh();
	
	player2.addComponent(new MovementComponent(2,4));
	player2.addComponent(new PositionComponent(0,0));
	player2.refresh();
	
	player3.addComponent(new MovementComponent(2,4));
	player3.addComponent(new PositionComponent(0,0));
	player3.refresh();
	
	player4.addComponent(new MovementComponent(2,4));
	player4.addComponent(new PositionComponent(0,0));
	player4.refresh();
	
	tm.subscribe("player1",player);
	artemis::Entity & playerRef = tm.getEntity("player1");
	
	
	
	std::cout << (tm.isSubscribed("player1") ? "Player 1 is subscribed": "Player 1 is not subscribed") << "\n";
	std::cin.get();
	
	 tm.remove(player);
	
	std::cout << (tm.isSubscribed("player1") ? "Player 1 is subscribed": "Player 1 is not subscribed") << "\n";
	std::cin.get();
	
	std::cout << (playerRef.isActive() ? "Player 1 Active": "Player 1 is Not Active") << "\n";
	std::cin.get();
	
	
	int i = 0;
	w.loopStart();
	while(i < 10000)
	{
		++i;
		player.getComponent<MovementComponent>();
	}
	
	PositionComponent * comp = (PositionComponent*)player.getComponent<PositionComponent>();

	while(true) {

		w.loopStart();
		w.setDelta(0.0016f);
		movementsys->process();
		Sleep(160);
		//end++;
	}

	std::cout << "Entity count in Movementsystem:" << sm.getSystem<MovementSystem>()->getEntityCount()<< "\n";
	em.removeComponent<PositionComponent>(player);
	player.refresh();
	comp = (PositionComponent*)player.getComponent<PositionComponent>();

	if(comp == nullptr) {
		std::cout << "Component is deleted\n";
	}
	
	em.remove(player);
	std::cout << "Entity count in Movementsystem:" << sm.getSystem<MovementSystem>()->getEntityCount()<< "\n";


	std::cin.get();

	return 0;
}
