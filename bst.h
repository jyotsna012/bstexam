//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied
	node* getRoot();
	void inOrderTraversal(node* root);
	bool search(node* root, int val);
	void add_new(node* &root, node* current, node* parent, int number);
	void findMinAdd(node* root);
	void removeSmallest(node* root);
	void deleteTree(node* node);

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
 
 	private:
 		node * root;
		void display_tree(node*, int);
};
  
