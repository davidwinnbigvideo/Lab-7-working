#include "NodeInterface.h"
#include "Node.h"
#include "BST.h"
using namespace std;


	NodeInterface *BST::getRootNode() const {
    return root;
  }

	bool BST::add(int data) {
    add_function(root, data);
  }

	bool BST::add_function(Node*& n, int value) {
    if (n == NULL) {
		  n = new Node(value);
      return true;
    }

    if (n->data > value) {
      return add_function(n->leftChild, value);
    }

    if (n->data < value) {
      return add_function(n->rightChild, value);
    }
    return false;
  }

	bool BST::remove(int data) {
    return remove_function(root, data);
  }
  
  bool BST::remove_function(Node*& n, int value) {
    if (n == NULL) {
      return false;
    }
    if (n->data > value) {
      return remove_function(n->leftChild, value);
    }
    if (n->data < value) {
      return remove_function(n->rightChild, value);
    }
    if (n->rightChild == NULL && n->leftChild == NULL) {
      delete n;
      n = NULL;
      return true;
    }
    if (n->rightChild == NULL || n->leftChild == NULL) {
      Node* temp;
      temp = n->leftChild;
      if (n->leftChild == NULL) {
        temp = n->rightChild;
      }
      delete n;
      n = temp;
      return true;
    }
    Node* temp = n->leftChild;
    Node* parent = n;
    while (temp->rightChild != NULL) {
      parent = temp;
      temp = temp->rightChild;
    }
		if (n->data != parent->data) {
    parent->rightChild = temp->leftChild;
	  }
	  else 
    parent->leftChild = temp->leftChild;
		n->data = temp->data;
    delete temp;
    return true;
  }

	void BST::clear() {
    clear_function(root);
    root = NULL;
  }

  void BST::clear_function(Node* n) {
    if (n == NULL) {
      return;
    }
    if (n->leftChild != NULL) {
        clear_function(n->leftChild);
    }
    if (n->rightChild != NULL) {
      clear_function(n->rightChild);
    }
    delete n;
    return;
  }