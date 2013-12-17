#include <string>
namespace Model {
  class Node {
  protected:
	std::string name;
	bool selected;
	Node* parent;
	
  public:
	Node(std::string name, Node* parent, bool selected = false) {
	  this->name = name;
	  this->parent = parent;
	  this->selected = selected;
	}
	
	Node(std::string name, bool selected = false) {
	  Node(name, NULL, selected);
	}
	
	~Node();
	Node& getParent() const;
	std::string getName() const;
	void setName(std::string);
  };
}