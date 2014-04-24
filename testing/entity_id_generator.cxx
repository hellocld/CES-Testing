/*
 * Program:	Entity ID Generator
 * Writer:	Chris Langford
 * Created:	04/24/14
 * Description:	Testing a way of auto-generating entity IDs (ints) and 
 * 				recycling IDs once they're no longer used
 */

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

//----------------------------------------------------------------------

class EntityGenerator {
	public:
		EntityGenerator() {};
		~EntityGenerator() = default;
		
		int addEntity(string s);
		void removeEntity(int e);
		string getEntityString(int e);
		
	private:
		int entityIndex = 0;
		vector<int> entityBuffer;
		//normally a "world" object would contain these functions and
		//the unordered_map of entities, but for this test we can keep
		//it in a dummy EntityGenerator class
		unordered_map<int, string> entities;
};

//----------------------------------------------------------------------

int EntityGenerator::addEntity(string s) {
	
	int e = 0;
	
	if(entityBuffer.size() == 0) {
		e = entityIndex;
		entityIndex++;
	} else {
		e = entityBuffer.back();
		entityBuffer.pop_back();
	}
	
	entities[e] = s;
	return e;
}

//----------------------------------------------------------------------

void EntityGenerator::removeEntity(int e) {
	if(entities.count(e) != 0) {
		entities.erase(e);
		entityBuffer.push_back(e);
	}
}

//----------------------------------------------------------------------

string EntityGenerator::getEntityString(int e) {
	if(entities.count(e) != 0) {
		return entities[e];
	} else {
		return nullptr;
	}
}

//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
	EntityGenerator generator;
	
	int a = generator.addEntity("entity a");
	int b = generator.addEntity("entity b");
	int c = generator.addEntity("entity c");
	
	cout<<"a\tid="<<a<<"\tstring="<<generator.getEntityString(a)<<endl;
	cout<<"b\tid="<<b<<"\tstring="<<generator.getEntityString(b)<<endl;
	cout<<"c\tid="<<c<<"\tstring="<<generator.getEntityString(c)<<endl;
	
	generator.removeEntity(a);
	
	int d = generator.addEntity("entity d");
	int e = generator.addEntity("entity e");
	cout<<"d\tid="<<d<<"\tstring="<<generator.getEntityString(d)<<endl;
	cout<<"e\tid="<<e<<"\tstring="<<generator.getEntityString(e)<<endl;
	
	return 0;
}
