AtermisCPP is an attempt to port the Artemis framework, written in Java, to C++
>[The Artemis Java framework](http://gamadu.com/artemis/ "Title")


![alt text](https://dl.dropbox.com/u/12043338/11check_mark.png "check")0/25  
[ ]"Component"  
[ ]"ComponentMapper"  
[ ]"ComponentType"  
[ ]"ComponentTypeManager"  
[ ]"Entity"  
[ ]"EntityProcessingSystem"  
[ ]"EntitySystem"  
[ ]"SystemBitManager"  
[ ]"ImmutableBag"  
[ ]"EntityManager"  
[ ]"DelayedEntityProcessingSystem"  
[ ]"DelayedEntitySystem"  
[ ]"GroupManager"  
[ ]"IntervalEntityProcessingSystem"  
[ ]"IntervalEntitySystem"  
[ ]"Manager"  
[ ]"SystemManager"  
[ ]"TagManager"  
[ ]"utils"  
[ ]"World"  
[ ]"Bag"  
[ ]"FastMath"  
[ ]"Timer"  
[ ]"TrigLUT"  
[ ]"Utils" 
 
***

>Note:  
>This project is created with CodeLite.   
>Working with GCC(mingw) 4.6.2; Enabled experimental c++0x with -std=c++0x (It requires the new standard features)  
>Documentation and whatnot will be done when every component is in place and working.

***

example:

Our Movement component ( should probably called VelocityComponent) And our Position component.  

	class MovementComponent : public artemis::Component
	{
	public:
		float velocityX;
		float velocityY;
		
		MovementComponent(float velocityX, float velocityY)
		{
			this->velocityX = velocityX;
			this->velocityY = velocityY;
		};
	};
	
	class PositionComponent : public artemis::Component
    {
		
	public:
		float posX;
		float posY;
		PositionComponent(float posX, float posY)
		{
			this->posX = posX;
			this->posY = posY;
		};
	};
	
Our system that allows for he positions to be updated  
				
	class MovementSystem : public artemis::EntityProcessingSystem
	{
	private:
		artemis::ComponentMapper<MovementComponent> * velocityMapper;
		artemis::ComponentMapper<PositionComponent> * positionMapper;
	
	public:
		MovementSystem() 
		{
			setComponentTypes<MovementComponent,PositionComponent>();
		};
	
		virtual void initialize() 
		{
			velocityMapper = new artemis::ComponentMapper<MovementComponent>(world);
			positionMapper = new artemis::ComponentMapper<PositionComponent>(world);
		};
	
		virtual void work(artemis::Entity* e) 
		{
			positionMapper->get(e).posX += velocityMapper->get(e).velocityX * world->getDelta();
			positionMapper->get(e).posY += velocityMapper->get(e).velocityY * world->getDelta();
		};
	
		~MovementSystem() 
		{
			delete velocityMapper;
			delete positionMapper;
		};
	};

Our test run  

	int main(int argc, char **argv) {
		
		artemis::World world;
		artemis::SystemManager * sm = world.getSystemManager();
		MovementSystem * movementsys = (MovementSystem*)sm->setSystem(new MovementSystem());
		artemis::EntityManager * em = world.getEntityManager();
		
		sm->initializeAll();
		
		artemis::Entity * player = em->create();
		
		
		
		player->addComponent(new MovementComponent(2,4));
		player->addComponent(new PositionComponent(0,0));
		player->refresh();
		
		PositionComponent * comp = (PositionComponent*)player->getComponent<PositionComponent>();
		
		while(true){
			
			world.loopStart();
			world.setDelta(0.0016f);
			movementsys->process();
			
			std::cout << "X:"<< comp->posX << std::endl;
			std::cout << "Y:"<< comp->posY << std::endl;
			Sleep(160);
		}
		
		
		//std::cin.get();
		//delete ent;
		return 0;
	}
***


Sidar Talei 2012