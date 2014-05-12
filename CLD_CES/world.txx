/*
 * Program:		world.txx
 * Author:		Chris Langford
 * Date:		2014/05/12
 * Description:		Template function definitions for the World class
 */

/*
 * Function:		removeSystem()
 * Description:		Removes a System from systems
 * Arguments:
 * 	typename T:	The type of the System you want to remove
 * Returns:		none
 */

template <typename T> void World::removeSystem() {
	//a simple iterator for looping through systems
	std::vector<System*>::iterator i;
	//loop through systems, checking for a System of type T
	for(i = systems.begin(); i < systems.end(); ++i){
		if(&typeid(*(*i)) == &typeid(T)) {
			//the System was found; erase it and return
			systems.erase(i);
			return;
		}
	}
}


