/* 
 * Program:	Entity Map Test
 * Writer:	Chris Langford
 * Created:	04/24/14
 * Description:	A quick test of a simple way to store components in
 * 		an unordered_map
 *
 */

#include <iostream>
#include <unordered_map>
#include <typeinfo>

using namespace std;

//
//base component object
//
class Component {
	public:
		Component() {cout<<"new Component created\n";}
		virtual ~Component() = default;
};

//
//a "thing" component
//
class Thing : public Component {
	public:
		Thing() {cout<<"new Thing created\n";}
};

//
//a "what" component
//
class What : public Component {
	public:
		What() {cout<<"new What created\n";}
}

//
//a basic entity component
//in later engine iterations much of this functionality will be moved
//to a "world" class, where entities would be key, value pairs in an
//"entities" unordered_map
//
class Entity {
	public:
		void addComponent(Component* c);
		template <typename T> T* getComponent();
		int componentCount();
	private:
		unordered_map<const type_info*, Component*> components;
};

//
//Takes a pointer to component c
//
void Entity::addComponent(Component* c) {
	//Places component c as a value in the map with the component's type
	//as the key. If the key already exists, this overwrites the old
	//component (which is baaaaaaaaad; a simple check would avoid
	//this future issue).
	components[&typeid(*c)] = c;
}

//
//Returns a pointer to the component searched for by type
//
template <typename T>
T* Entity::getComponent() {
	if(components.count(&typeid(T)) != 0) {
		return static_cast<T*>(components[&typeid(T)]);
	} else {
		return nullptr;
	}
}

//
//---
//
int Entity::componentCount() {
	return components.size();
}

//
//------
//
int main(int argc, char* argv[]) {
	Entity e;
	
	e.addComponent(new What());
	e.addComponent(new Thing());

	if(e.getComponent<Thing>() == nullptr) {
		cout<<"No Thing found\n";
	} else {
		cout<<"Thing found!\n";
	}

	cout<<"Number of entities: "<<e.componentCount()<<endl;

	return 0;
}
