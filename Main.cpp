#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <fstream>

using namespace std;

int main()
{
    BinaryTree T1;

    /* T1.InsertNode(1);
     T1.InsertNode(2);
     T1.InsertNode(3);
     T1.InsertNode(4);
     T1.InsertNode(5);
     T1.InsertNode(6);
     T1.InsertNode(7);

     T1.InOrder();

     T1.DeleteNode(7);
     T1.InOrder();

     T1.DeleteNode(3);
     T1.InOrder();*/

    BinarySearchTree T2;
    BinarySearchTree T3;

    T3.InsertNode(5);
    T3.InsertNode(2);
    T3.InsertNode(13);
    T3.InsertNode(4);
    T3.InsertNode(25);
    T3.InsertNode(16);
    T3.InsertNode(37);

    

   
    T3.PreOrder();
    cout << "Printing in Pre Order" << endl;
    
    T3.InOrder();
    cout << "Printing in In Order" << endl;
    
    T3.PostOrder();
    cout << "Printing in Post Order" << endl;

    // Serialize the BinarySearchTree object to a file
    ofstream outFile("A:/TU DUBLIN/Yr4/SEM_2/SavingToFile/bst.txt");
    if (outFile.is_open()) {
        int result = T3.Serialize(outFile);
        if (result == -1)
            cout << "Serialization failed." << endl;
        else
            cout << "Serialization successful." << endl;
        outFile.close();
    }
    else {
        cout << "Failed to open file for writing." << endl;
        return 1;
    }

    // Deserialize the BinarySearchTree object from the file
    ifstream inFile("A:/TU DUBLIN/Yr4/SEM_2/SavingToFile/bst.txt");
    if (inFile.is_open()) {
        T3.Deserialize(inFile); // Deserialize and set the tree for T3
        inFile.close();

        // Perform in-order traversal on the deserialized tree
        cout << "In-order traversal of deserialized BST: ";
        T3.InOrder();
        cout << endl;
    }
    else {
        cout << "Failed to open file for reading." << endl;
        return 1;
    }

    /*T2.InOrder();*/
   
    return 0;
}

