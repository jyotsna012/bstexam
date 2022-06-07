#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST
        
    node* root = object.getRoot();
    object.removeSmallest(root);
    //object.add_new(root, root, root, 15);
    //object.inOrderTraversal(root);
    //bool result = object.search(root, 12);



    object.display();	//displays again after!
   
    return 0;
}
