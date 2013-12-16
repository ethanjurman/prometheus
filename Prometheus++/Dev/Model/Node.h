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
	
  public:
	~Node() { delete parent; }
	Node& getParent() const;
	std::string getName() const;
	void setName(std::string);
  };
}