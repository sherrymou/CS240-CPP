#include <iostream>
using namespace std;


class TreeNode{
	public:
		int data;
		TreeNode *right;
		TreeNode *left;
		TreeNode (int value);
};


class Tree{
	private:
		TreeNode *root;
	public:
		Tree();
		Tree(const Tree &it);
		~Tree();
		bool insert (int value);
		TreeNode* find(int value);
		bool remove(int value);
		bool _insert(TreeNode *&iter, int value);
		TreeNode* _find(TreeNode *&iter, int value);
		bool _remove(TreeNode *&iter, int value);
		TreeNode* findRightSmallest(TreeNode *node);
		TreeNode* findParent(TreeNode *rt, TreeNode *node);
		bool removeCase1(TreeNode *&iter);
		bool removeCase2(TreeNode *&iter);
		bool removeCase3(TreeNode *&iter);
		bool removeNode(TreeNode *&iter);

};
