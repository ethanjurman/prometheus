#include "NodeDatabase.h"
using namespace std;
using namespace Model;

NodeDatabase::NodeDatabase() {}

NodeDatabase::~NodeDatabase() {}

void NodeDatabase::insertNode(Node& n) {
  auto it = nodes.find(n.getName());
  
  if(it == nodes.end()) {
	vector<Node*>* children = new vector<Node*>;
	nodes[n.getName()] = children; // creates the key-value pair
  } else {
	it->second->push_back(&n);
  }
}

bool NodeDatabase::removeNode(Node& n) {
  auto it = nodes.find(n.getName());
  
  if(it == nodes.end()) {
	return 0;
  } else {
	vector<Node*>* children = it->second;
	for(auto i = children->begin(); i != children->end(); ++i) {
	  if((*i)->getName() == n.getName()) {
		children->erase(i);
		return true;
	  }
	}
  }
}

vector<Node*>* NodeDatabase::parentQuery(string parent) const {
  auto it = nodes.find(parent);
  
  if(it == nodes.end()) {
	return NULL;
  } else {
	return it->second;
  }
}