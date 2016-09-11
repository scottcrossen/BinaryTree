#include "BST.h"


BST::BST(void){
	root=nullptr;
}


BST::~BST(void){
	BST::clear();
}


//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface* BST::getRootNode(){
	return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
	if (root != nullptr)
		return BST::add_this(root, data);
	else{
		root = new Node(data);
		return true;
	}
}
bool BST::add_this(Node* current, int value){
	if (current->value == value) return false;
	else if (value < current->value && current->left_child == nullptr){
		Node* new_node=new Node(value);
		current->left_child=new_node;
		return true;
	}
	else if (value > current->value && current->right_child == nullptr){
		Node* new_node=new Node(value);
		current->right_child=new_node;
		return true;
	}
	else if (value < current->value && current->left_child != nullptr) return add_this(current->left_child,value);
	else if (value > current->value && current->right_child != nullptr) return add_this(current->right_child,value);
	else return false;
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
	return BST::remove_this(root, data);
}
bool BST::remove_this(Node* &current, int value){
	if (current==nullptr) return false;
	else if (value < current->value) return remove_this(current->left_child,value);
	else if (value > current->value) return remove_this(current->right_child,value);
	else if (current->left_child == nullptr){
		Node* temp = current;
		current = current->right_child;
		delete temp;
		return true; }
	else if (current->right_child == nullptr){
		Node* temp=current;
		current=current->left_child;
		delete temp;
		return true;
	}
	else {
		current->value=BST::find_max(current->left_child);
		return BST::remove_this(current->left_child,current->value);
	}
}
int BST::find_max(Node* current){
	if (current->right_child==nullptr) return current->value;
	else return BST::find_max(current->right_child);
}
/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
	if (root != nullptr) BST::clear_this(root);
	root=nullptr;
	return;
}
void BST::clear_this(Node* current){
	if(current->left_child != nullptr)
		BST::clear_this(current->left_child);
	if(current->right_child != nullptr)
		BST::clear_this(current->right_child);
	delete current;
	return;
}