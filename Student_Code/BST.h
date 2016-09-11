#pragma once
#include "BSTInterface.h"
#include "NodeInterface.h"
class BST :
	public BSTInterface
{
private:
	class Node : public NodeInterface {
		public:
			int value;
			Node* left_child;
			Node* right_child;
			Node(void){
				this->value=0;
				this->left_child=nullptr;
				this->right_child=nullptr;
			}
			Node(int value){
				this->value=value;
				this->left_child=nullptr;
				this->right_child=nullptr;
			}
			~Node(void){}
			int getData(){return value;}
			NodeInterface* getLeftChild(){return left_child;}
			NodeInterface* getRightChild(){return right_child;}
	};
	Node* root;
	bool add_this(Node* current, int value);
	bool remove_this(Node* &current, int value);
	int find_max(Node* current);
	void clear_this(Node* current);
public:
	BST(void);
	~BST(void);
	NodeInterface * getRootNode();
	bool add(int data);
	bool remove(int data);
	void clear();
};

