/*
 * Program:		world.txx
 * Author:		Chris Langford
 * Date:		2014/05/12
 * Description:		Template function definitions for the World class
 */

template <typename T> bool World::RemoveSystem() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i){
		if(&typeid(*(*i)) == &typeid(T)) {
			//the System was found; erase it and return
			delete *i;
			systems.erase(i);
			return true;
		}
	}
	//the System was not found
	return false;
}


