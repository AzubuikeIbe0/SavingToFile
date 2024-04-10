#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() : BinaryTree() {}


int BinarySearchTree::GetHeightPrivate(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int LeftHeight = GetHeightPrivate(node->left);

    int RightHeight = GetHeightPrivate(node->right);

    int Total = 1 + max(LeftHeight, RightHeight);

    return Total;
}



void BinarySearchTree::GetHeight()
{
    cout << GetHeightPrivate(root) << endl;
}


void BinarySearchTree::DeleteTreePrivate(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    DeleteTreePrivate(node->left);

    DeleteTreePrivate(node->right);

    delete node;
}

int BinarySearchTree::Serialize(ofstream& OutFile)
{
    if (!OutFile.is_open())
        return -1;
    return Serialize(OutFile, root);
}

int BinarySearchTree::Serialize(ofstream& fp, TreeNode* root)
{
    if (root == nullptr) {
        fp << "# ";
        return 0;
    }
    fp << root->data << " ";
    Serialize(fp, root->left);
    Serialize(fp, root->right);
    return 0;
}

TreeNode* BinarySearchTree::Deserialize(ifstream& InFile)
{
    if (!InFile.is_open())
        return nullptr;
    return DeserializeHelper(InFile);
}

TreeNode* BinarySearchTree::DeserializeHelper(ifstream& fp)
{
    string val;
    fp >> val;
    if (val == "#")
        return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = DeserializeHelper(fp);
    node->right = DeserializeHelper(fp);
    return node;
}




BinarySearchTree::~BinarySearchTree()
{
    DeleteTreePrivate(root);
}
