#include <stdio.h>
#include <iostream>
#include "Component.h"

using namespace artemis::component;

class ComponentA : public Component{};
class ComponentB : public Component{};
class ComponentC : public Component{};
class ComponentD : public Component{};
class ComponentE : public Component{};
class ComponentF : public Component{};
class ComponentG : public Component{};




template<class T>
void doSomething(){
	std::cout << typeid(T).hash_code() << "\n";
}

int main(int argc, char **argv)
{


	std::cout << ComponentTypeManager::getTypeFor<ComponentB>().getID() << "\n";
	std::cout << ComponentTypeManager::getId<ComponentA>() << "\n";
	std::cout << ComponentTypeManager::getId<ComponentB>() << "\n";
	std::cout << ComponentTypeManager::getId<ComponentD>() << "\n";
	std::cout << ComponentTypeManager::getId<ComponentF>() << "\n";
	std::cout << ComponentTypeManager::getBit<ComponentA>() << "\n";

	
	std::cin.get();
	return 0;
}
