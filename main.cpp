#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST
        
    node* root = object.getRoot();
    object.inOrderTraversal(root);
    object.insert(root, 19);
    //bool result = object.search(root, 12);



    object.display();	//displays again after!
   
    return 0;
}
