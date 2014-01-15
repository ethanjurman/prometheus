#include "Node.h"
#include <map>
#include <vector>
#include <string>

//#define DEBUG

namespace Model {
  class NodeDatabase {
	std::map< std::string, std::vector<Node*>* > nodes;
	
  public:
	NodeDatabase();
	~NodeDatabase();
	
	void insertNode(Node&);
	void insertParentNode(Node&);
	bool removeNode(Node&);
	std::vector<Node*>* parentQuery(std::string) const;
	
#ifdef DEBUG
	std::map< std::string, std::vector<Node*>* > getMap() const;
#endif
	
  private:
	std::vector<Node*>* findParentVector(Node&) const;
  };
}