#include "DelayedEntitySystem.h"
#include "World.h"

namespace artemis {

	DelayedEntitySystem::DelayedEntitySystem(){
		acc = 0;
		delay = 0;
		running = false;
	}
	
	bool DelayedEntitySystem::checkProcessing() {
		if(running){
			acc += world->getDelta();
			if(acc >= delay){
				return true;
			}
		}
		return false;
	}

	float DelayedEntitySystem::getInitialTimeDelay() {
		return delay;
	}

	float DelayedEntitySystem::getRemainingTime() {
		if(running){
			return delay - acc;
		}
		return 0;
	}

	bool DelayedEntitySystem::isRunning() {
		return running;
	}

	void DelayedEntitySystem::processEntities(ImmutableBag<Entity*>& bag) {
		processEntities(bag, acc);
		stop();
	}

	void DelayedEntitySystem::start(float delay) {
		this->delay = delay;
		acc = 0.0f;
		running = true;
	}

	void DelayedEntitySystem::stop() {
		acc = 0;
		running = false;
	}

};
