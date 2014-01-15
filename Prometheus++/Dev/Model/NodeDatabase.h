#include "Node.h"
#include <map>
#include <vector>
#include <string>

namespace Model {
  class NodeDatabase {
	std::map< std::string, std::vector<Node*>* > nodes;
	
  public:
	NodeDatabase();
	~NodeDatabase();
	
	void insertNode(Node&);
	bool removeNode(Node&);
	std::vector<Node*>* parentQuery(std::string) const;
	
  private:
	std::vector<Node*>* findParentVector(Node&) const;
  };
}