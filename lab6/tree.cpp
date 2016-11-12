#include <iostream>
#include "tree.h"
using namespace std;

TreeNode::TreeNode(int value){
	data = value;
	left = right = NULL;
}

Tree::Tree(){
//	cout <<"Enter Tree default constructor " << endl;
	root = NULL;
}

Tree::Tree(const Tree &it){

}

Tree::~Tree(){
	delete root;
}

bool Tree::insert(int value){
	return _insert(root, value);
}

bool Tree::_insert (TreeNode *&iter, int value){
	if (!iter){
		iter = new TreeNode(value);
	}
	
	if (value == iter->data){
		return false;
	}

	if (value < iter->data){
		return _insert(iter->left, value);
	}else{
		return _insert(iter->right, value);
	}
}

TreeNode* Tree::find(int value){
	return _find(root, value);
}


TreeNode* Tree::_find(TreeNode *&iter, int value){
	if (iter == NULL){
		return NULL;
	}
	if (value == iter->data){
		return iter;
	}
	if (value < iter->data){
		if (iter->left == NULL){
			return NULL;
		}else{
			return _find(iter->left, value);
		}
	}else{
		if (iter->right == NULL){
			return NULL;
		}else{
			return _find(iter->right, value);
		}
	}
}


bool Tree::remove(int value){
	return _remove(root, value);
}

bool Tree::_remove(TreeNode *&iter, int value){
	if (!iter) return false;

	if (value == iter->data) return removeNode(iter);
	if (value < iter->data) return _remove(iter->left,value);
	if (value > iter->data) return _remove(iter->right,value);

}


bool Tree::removeNode (TreeNode *&iter){
	if (iter->left == NULL && iter->right == NULL)
		return removeCase1(iter);
	if (iter->left != NULL && iter->right !=NULL)
		return removeCase3(iter);
	return removeCase2(iter);
}

bool Tree::removeCase1(TreeNode *&iter){
	TreeNode *parent = findParent(root,iter);
	if(parent ->left == iter){
		delete parent ->left;
		parent->left = NULL;
	}else{
		delete parent ->right;
		parent->right = NULL;
	}
	return true;
}

bool Tree::removeCase3(TreeNode *&iter){
	TreeNode *tmp;
	tmp = findRightSmallest(iter);
	iter -> data  = tmp ->data;
	removeNode(tmp);
	return true;
}

bool Tree::removeCase2(TreeNode *&iter){
	if (iter == root){
		if (iter->right){
			root = iter->right;
		}else{
			root = iter->left;
		}
		return true;
	}

	if (iter->right){
		TreeNode *parent = findParent(root,iter);
		if (parent ->right ==iter)
			parent->right = iter->right;	
		else{
			parent -> left = iter->right;
		}
	}else{
		TreeNode *parent = findParent(root,iter);
		if (parent ->right == iter)
			parent ->right = iter->left;
		else{
			parent->left = iter->left;
		}
	}
	return true;
}


TreeNode* Tree::findRightSmallest(TreeNode *node){
	node = node->right;
	while(node->left){
		node = node->left;
	}
	return node;
}

TreeNode* Tree::findParent(TreeNode* rt, TreeNode *node){

	if (rt->left == node || rt->right == node){
		return rt;
	}

	if (node->data < rt ->data){
		return findParent(rt->left, node);
	}else {
		return findParent(rt->right, node);
	}
}


