#include "Node.h"

namespace Model {
  
  class EvalNode: public Node {
	std::string eval;
	
  public:
	EvalNode(std::string name, Node* parent) : Node(name, parent) {}
	bool isNumber();
	void setEvaluation(std::string);
  };
}