#pragma once
class TreeNode
{
	friend class BinaryTree;
	friend class BinarySearchTree;
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int val);
};

