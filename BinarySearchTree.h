#pragma once
#include "BinaryTree.h"
#include <fstream>
using namespace std;

class BinarySearchTree : public BinaryTree
{
private:
    int GetHeightPrivate(TreeNode* node);
    void DeleteTreePrivate(TreeNode* node);

    int Serialize(ofstream& fp, TreeNode* root); 
    TreeNode* DeserializeHelper(ifstream& fp);


public:
    BinarySearchTree();
    void GetHeight();

    int Serialize(ofstream& OutFile);
    TreeNode* Deserialize(ifstream& InFile);

    ~BinarySearchTree();
};
