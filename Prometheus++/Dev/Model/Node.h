#include <string>
namespace Model {
  class Node {
	std::string name;
	bool selected;
	Node* parent;
	
  protected:
	Node(std::string name, Node* parent, bool selected = false) {
	  this->name = name;
	  this->parent = parent;
	  this->selected = selected;
	}
  };
}