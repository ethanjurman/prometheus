#include <string>
namespace Model {
  class Node {
  protected:
	std::string name;
	bool selected;
	Node* parent;
	
	Node(std::string name, Node* parent, bool selected = false) {
	  this->name = name;
	  this->parent = parent;
	  this->selected = selected;
	}
	
	~Node { delete parent; }
  };
}