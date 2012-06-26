#include <stdio.h>
#include <iostream>
#include "Component.h"
#include <tuple>
#include "EntitySystem.h"

using namespace artemis::component;
using namespace artemis::system;

class ComponentA : public Component{};
class ComponentB : public Component{};
class ComponentC : public Component{};
class ComponentD : public Component{};
class ComponentE : public Component{};
class ComponentF : public Component{};
class ComponentG : public Component{};


class Ent2 : public EntitySystem{};

int main(int argc, char **argv)
{
	
	
	
	//createObject<ComponentA,ComponentC,ComponentD,ComponentE,ComponentF,ComponentG>();
	
	ComponentTypeManager::getId<ComponentA>() ;
	ComponentTypeManager::getId<ComponentD>() ;
	ComponentTypeManager::getId<ComponentF>() ;
	ComponentTypeManager::getId<ComponentC>() ;
	ComponentTypeManager::getBit<ComponentB>() ;
	EntitySystem* ent = new EntitySystem();
	ent->setComponentTypes<ComponentD,ComponentE,ComponentB,ComponentC>();
	ent->printTypeFlag();
	
	std::cout << std::endl;
	std::cout << SystemBitManager::getBitFor<EntitySystem>() << std::endl;
	std::cout << SystemBitManager::getBitFor<Ent2>() << std::endl;
	//std::cout << ent.getTypeFlags()<< "\n";*/
	
	
	std::cin.get();
	return 0;
}
