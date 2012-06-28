#include <stdio.h>
#include <string>
#include <iostream>
#include "Component.h"
#include <tuple>
#include "EntitySystem.h"
#include "ImmutableBag.h"

using namespace artemis::component;
using namespace artemis::system;
using namespace artemis::util;

class ComponentA : public Component{
public: 
	std::string name;
	};
class ComponentB : public Component{};
class ComponentC : public Component{};
class ComponentD : public Component{};
class ComponentE : public Component{};
class ComponentF : public Component{};
class ComponentG : public Component{};


class Ent2 : public EntitySystem{};

int main(int argc, char **argv)
{
	Bag<ComponentA*> bagA;
	
	ComponentA * A = new ComponentA();
	A->name = "LOL";
	bagA.add(A);
	std::cout << bagA.get(0)->name << std::endl;
	delete bagA.remove(0);
	std::cout << bagA.getObjCount()<< std::endl;
	std::cout << bagA.length()<< std::endl;
	//bagA.add(new ComponentA());
	
	//createObject<ComponentA,ComponentC,ComponentD,ComponentE,ComponentF,ComponentG>();
	EntitySystem* ent = new EntitySystem();
	ent->setComponentTypes<ComponentD,ComponentE,ComponentB,ComponentC>();
	
	ComponentTypeManager::getId<ComponentA>() ;
	ComponentTypeManager::getId<ComponentD>() ;
	ComponentTypeManager::getId<ComponentF>() ;
	ComponentTypeManager::getId<ComponentC>() ;
	ComponentTypeManager::getBit<ComponentB>() ;
	
	
	ent->printTypeFlag();
	std::cout << std::endl;
	//E was set in the setComponentType of the entitiSystem
	std::cout <<ComponentTypeManager::getBit<ComponentE>()  << std::endl;
	
	std::cout << std::endl;
	std::cout << SystemBitManager::getBitFor<EntitySystem>() << std::endl;
	std::cout << SystemBitManager::getBitFor<Ent2>() << std::endl;

	//std::cout << ent.getTypeFlags()<< "\n";*/
	
	
	std::cin.get();
	delete ent;
	return 0;
}
