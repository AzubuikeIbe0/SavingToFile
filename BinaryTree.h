#pragma once
#include "TreeNode.h"
using namespace std;

class BinaryTree
{
	friend class TreeNode;
protected:
	TreeNode* root;
private:
	TreeNode* DeleteNodePrivate(TreeNode*& node, int val);
	TreeNode* InsertNodePrivate(TreeNode* node, int val);
	TreeNode* FindMin(TreeNode* node);
	void InOrderPrivate(TreeNode* node) const;
	void PreOrderPrivate(TreeNode* node) const;
	void PostOrderPrivate(TreeNode* node) const;
public:
	BinaryTree();
	void DeleteNode(int data);
	void InsertNode(int data);
	void InOrder();
	void PreOrder();
	void PostOrder();
	~BinaryTree();
};

