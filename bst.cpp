#include "bst.h"

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

node* bst::getRoot(){

	return root;
	
}

void bst::inOrderTraversal(node* root){
	if(root == NULL){
		return;
	}
	else{
		inOrderTraversal(root -> left);
		cout << root -> data << ", " << endl;
		inOrderTraversal(root -> right);
	}


}

void bst::add_new(node* &root, node* current, node* parent, int number)
{
  if (current == NULL)
    {
      node* newNode = new node();
      newNode->data = number;
      current = newNode;
      current->left = NULL;
      current->right = NULL;
      if (number >= parent->data)
	{
	  parent->right = current;
	}
      else if (number < parent->data)
	{
	  parent->left = current;
	}

    }
  else
    {
      parent = current;
      if (number < current->data)
	{
	  current = current->left;
	}
      else if (number >= current->data)
	{
	  current = current->right;
	}
      add_new(root, current, parent, number);
    }
}

bool bst::search(node* root, int val){
	if(root == NULL){
		return false;
		cout << "false" << endl;
	}
	else if(root -> data == val){
		return true;
		cout << "true" << endl;
	}
	else if(val > root -> data){
		return search(root -> right, val);
	}
	else{
		return search(root -> left, val);
	}
}

void bst::findMinAdd(node* root){
	if(root -> left == NULL){
		int number = root -> data;
		cout << number << endl;
		
		node* newNode = new node();
		newNode -> data = number-1;
		newNode -> left = newNode -> right = NULL;
		
		root -> left = newNode;
		return;
	}
	else{
		findMinAdd(root -> left);
		return;
	}
}

void bst::removeSmallest(node* root){
	if(root -> left -> left == NULL){
		int number = root -> left -> data;
		root -> left = NULL;
		return;
	}
	else{
		removeSmallest(root -> left -> left);
	}
}

void bst::deleteTree(node* root, node* ori)
{
    if (root == NULL ) return;
 
    /* first delete both subtrees */
    deleteTree(root->left, ori);
    deleteTree(root->right, ori);
	
    if(root == ori){
    	return;
    }else{
     
    /* then delete the node */
    cout << "\n Deleting node: " << root->data;
    delete root;
    }
	    
}
 
