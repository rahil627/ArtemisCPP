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
log:  
[dd-mm-yyy]5-7-12:  

*  Needs memory management.  
*  Fixt circular dependencies for now.
*  Able to use  

        myEntity->getComponent<MyComponentClass>(); 

Instead of     

          myEntity>getComponent(artemis::ComponentTypeManager::getTypeFor<MyComponentClass>());  

+Flattened namespace to artemis:: instead of artemis::component:: etc.  
***
[dd-mm-yyy]3-7-12:  

* Needs a lot of refractoring. Classes need to be disected in to seperate files.  
* Having some Circular dependency issues. In Entity can't use template function:  

        myEntity->getComponent<MyComponentClass>();  

* For now this is the only solution:  

        myEntity->getComponent(artemis::component::ComponentTypeManager::getTypeFor<MyComponentClass>());  

* Need to reduce pointer usage.  


Sidar Talei 2012