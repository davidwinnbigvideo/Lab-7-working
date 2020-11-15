#include "NodeInterface.h"
#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST: public BSTInterface {
public:
	Node* root;
	BST() {
		root = NULL;
	}
	~BST() {
    clear();
  }

	NodeInterface* getRootNode() const;

	bool add(int data);
	bool add_function(Node*& n, int value);

	bool remove(int data);
	bool remove_function(Node*& n, int value);

	void clear();
	void clear_function(Node* n);
};