#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST
        
    node* root = object.getRoot();
    object.inOrderTraversal(root);
    bool result = object.search(root, 12);
    if(result == true){
        cout << "true" << endl;
    }


    object.display();	//displays again after!
   
    return 0;
}
