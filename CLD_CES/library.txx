/*
 * Program:		library.txx
 * Author:		Chris Langford
 * Date:		2014/05/12
 * Description:		Template function definitions for the Library class
 */

//---------------------------------------------------------------------------------------

/*
 * Function:		removeComponent()
 * Description:		Removes an existing Component from an existing Entity.
 * Arguments:
 * 	typename T:	Component type to be removed
 * 	int e:		Entity ID containing Component of type T
 * Returns:
 * 	bool:		True if successful; False if no such Component/Entity
 */

template <typename T> bool Library::removeComponent(int e) {
	//check to see if Entity e exists
	if(entities.count(e) != 0) {
		//check for the Component
		if(entities[e].count(&typeid(T)) != 0) {
			//it exists, so remove the Component
			entities[e].erase(&typeid(T));
			return true;
		} else {
			//the Component was not found
			std::cerr<<"removeComponent() ERROR: could not find component of type "<<typeid(T).name()<<std::endl;
			return false;
		}
	} else {
		//ERROR: e is not a valid Entity ID
		std::cerr<<"removeComponent() ERROR: entity does not exist\n";
		return false;
	}
}

//---------------------------------------------------------------------------------------

/*
 * Function:		getComponent()
 * Description:		Provides a pointer to a particular Component in a particular Entity
 * Arguments:
 * 	typename T:	Component type to find
 * 	int e:		ID of Entity to search
 * Returns:
 * 	T*:		Pointer to Component
 */

template <typename T> T* Library::getComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			//return a pointer to the Component
			return static_cast<T*>(entities[e][&typeid(T)]);
		} else {
			//ERROR: no such Component exists in Entity e
			std::cerr<<"getComponent() ERROR: could not get component of type "<<typeid(T).name()<<std::endl;
			return nullptr;
		}
	} else {
		//ERROR: no such Entity exists
		std::cerr<<"getComponent() ERROR: entity does not exist\n";
		return nullptr;
	}
}

//---------------------------------------------------------------------------------------

/*
 * Function:		hasComponent()
 * Description:		Determines if an Entity contains a Component of type T
 * Arguments:
 * 	typename T:	Component type to find
 * 	int e:		ID of Entity to search
 * Returns:
 * 	bool:		True if Component is found
 */

template <typename T> bool Library::hasComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			return true;
		} else {
			std::cerr<<"hasComponent() ERROR: entity has no component of type "<<typeid(T).name()<<std::endl;
			return false;
		}
	}
	std::cerr<<"hasComponent() ERROR: entity does not exist\n";
	return false;
}


