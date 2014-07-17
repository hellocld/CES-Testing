/*
 * Program:		library.txx
 * Author:		Chris Langford
 * Date:		2014/05/12
 * Description:		Template function definitions for the Library class
 */

//---------------------------------------------------------------------------------------

template <typename T> bool Library::RemoveComponent(int e) {
	//check to see if Entity e exists
	if(entities.count(e) != 0) {
		//check for the Component
		if(entities[e].count(&typeid(T)) != 0) {
			//it exists, so remove the Component
			delete *entities[e][&typeid(T)];
			entities[e].erase(&typeid(T));
			return true;
		} else {
			//the Component was not found
			return false;
		}
	} else {
		//ERROR: e is not a valid Entity ID
		return false;
	}
}

//---------------------------------------------------------------------------------------

template <typename T> T* Library::GetComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			//return a pointer to the Component
			return dynamic_cast<T*>(entities[e][&typeid(T)]);
		} else {
			//ERROR: no such Component exists in Entity e
			return nullptr;
		}
	} else {
		//ERROR: no such Entity exists
		return nullptr;
	}
}

//---------------------------------------------------------------------------------------

template <typename T> bool Library::HasComponent(int e) {
	if(entities.count(e) != 0) {
		if(entities[e].count(&typeid(T)) != 0) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}
