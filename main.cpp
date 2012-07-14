#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"
#include "MovementSystem.h"
#include "DMovementsystem.h"
#include "MovementComponent.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "Entity.h"
#include <unistd.h>
#include <windows.h>
#include "TagManager.h"
#include "GroupManager.h"

int main(int argc, char **argv) {

	artemis::World w;
	
	artemis::SystemManager & sm = *w.getSystemManager();
	artemis::EntityManager & em = *w.getEntityManager();
	//artemis::TagManager	   & tm = *w.getTagManager();
	//artemis::GroupManager  & gm = *w.getGroupManager();
	
	
	//MovementSystem * movementsys = (MovementSystem*)sm.setSystem(new MovementSystem());
	DMovementSystem * movementsys = (DMovementSystem*)sm.setSystem(new DMovementSystem());
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
	
	/*tm.subscribe("player1",player);
	player4.setGroup("LOL");
	player4.setTag("AAA");
	
	artemis::Entity & playerRef = tm.getEntity("player1");
	
	gm.set("Test",player);
	
	std::cout << (gm.isGrouped(player) ? "Player is grouped": "Player is not grouped") << "\n";
	std::cout << (gm.isGrouped(player4) ? "Player4 is grouped": "Player is not grouped") << "\n";
	std::cin.get();
	
	std::cout << (gm.isInGroup("Test",player) ? ("Player is in group " + gm.getGroupOf(player)): "Player is not grouped") << "\n";
	std::cout << (gm.isInGroup("LOL",player4) ? ("Player is in group " + gm.getGroupOf(player)): "Player is not grouped") << "\n";
	std::cout << tm.getEntity("AAA").getId() << " " <<  player4.getId();
	std::cin.get();
	
	gm.remove(player);
	
	std::cout << (gm.isGrouped(player) ? "Player is grouped": "Player is not grouped") << "\n";
	std::cin.get();
	
	std::cout << (gm.isInGroup("Test",player) ? ("Player is in group " + gm.getGroupOf(player)): "Player is not grouped") << "\n";
	std::cin.get();
	
	
	
	std::cout << (tm.isSubscribed("player1") ? "Player 1 is subscribed": "Player 1 is not subscribed") << "\n";
	std::cin.get();
	
	 tm.remove(player);
	
	std::cout << (tm.isSubscribed("player1") ? "Player 1 is subscribed": "Player 1 is not subscribed") << "\n";
	std::cin.get();
	
	std::cout << (playerRef.isActive() ? "Player 1 Active": "Player 1 is Not Active") << "\n";
	std::cin.get();*/
	
	
	int i = 0;
	w.loopStart();
	while(i < 10000)
	{
		++i;
		player.getComponent<MovementComponent>();
	}
	
	PositionComponent * comp = (PositionComponent*)player.getComponent<PositionComponent>();

	movementsys->start(100000.0f);

	while(true) {

		w.loopStart();
		w.setDelta(0.0016f);
		movementsys->process();

		//Sleep(160);
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
