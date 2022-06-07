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

node* bst::insert(node* root, int val){
	if(root == NULL){
		node* newNode = new node();
		newNode -> data = val;
		newNode -> left = NULL;
		newNode -> right = NULL;
	}
	
	else if(val > root -> data){
		root -> right = insert(root -> right, val);
	}
	else{
		root -> left = insert(root -> left, val);
	}
	return root;
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

