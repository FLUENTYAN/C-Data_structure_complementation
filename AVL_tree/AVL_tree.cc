#include <algorithm>
#include <iostream>
#include "AVL_tree.h"

// 插入节点
void AVL_tree::insert(AVL_tree*& node, int num) {
	if (node == nullptr) {
		node = new AVL_tree(num);
	} else if (num < node->value) { // 向左递
		insert(node->left, num);
		insert_balance(node, num); // 失衡调节
	} else if (num > node->value) { // 向右递
		insert(node->right, num);
		insert_balance(node, num); // 失衡调节
	} else {	
		std::cerr << "Integer the same, insert failed!" << std::endl; return;
	}
	// 更新各个节点的高度
	// 由于递归，每个受插入影响的节点都会被执行
	node->height = std::max(Height(node->left), Height(node->right)) + 1;
}
// 删除节点
void AVL_tree::remove(AVL_tree*& node, int num) {
	// 查看要删的节点是否存在
	auto temp1 = node->find_node(num); 
	if (temp1 == nullptr) {
		std::cerr << "Node not exist, remove failed!" << std::endl;
		return;
	}
	if (num < node->value) { // 往左找
		remove(node->left, num);
		remove_balance(node); // 平衡节点
	} else if (num > node->value) { // 往右找
		remove(node->right, num);
		remove_balance(node); // 平衡节点
	} else {
		if (node->left && node->right) { // 左右子树都有
			auto temp2 = left_max(node->left);
			remove(node, temp2->value);
			temp1->value = temp2->value;
		} else { // 只有一个子树或没有
			auto temp = (node->left != nullptr) ? node->left : node->right;
			node = temp;
			delete temp;
		}
	}
	if (node != nullptr) // 更新各个节点的高度
		node->height = std::max(Height(node->left), Height(node->right)) + 1;
}
// 插入失衡调整
void AVL_tree::insert_balance(AVL_tree*& node, int num) {
	if (Height(node->left) - Height(node->right) == 2) { // node失衡，左边多
		if (num < node->left->value) { // 在左子树的左子树
			node = right_rotation(node); // 右旋
			/*
				用赋值原因：以便旋转后，转上去的节点依然与树相连
				下同
			*/
		} else if (num > node->left->value) { // 在左子树的右子树
			node->left = left_rotation(node->left); // 先左旋
			node = right_rotation(node);	  // 再右旋
		}
	} else if (Height(node->right) - Height(node->left) == 2) { // node失衡，右边多
		if (num > node->right->value) { // 在右子树的右子树
			node = left_rotation(node); // 左旋
		} else if (num < node->right->value) { // 在右子树的左子树
			node->right = right_rotation(node->right); // 先右旋
			node = left_rotation(node);		 // 再左旋
		}
	}
}

// 删除失衡调整
void AVL_tree::remove_balance(AVL_tree*& node) {
	if (Height(node->left) - Height(node->right) == 2) { // node失衡，左边多
		if (node->left->left) { // 在左子树的左子树
			node = right_rotation(node); // 右旋
			/*
				用赋值原因：以便旋转后，转上去的节点依然与树相连
				下同
			*/
		} else if (node->left->right) { // 在左子树的右子树
			node->left = left_rotation(node->left); // 先左旋
			node = right_rotation(node);	  // 再右旋
		}
	} else if (Height(node->right) - Height(node->left) == 2) { // node失衡，右边多
		if (node->right->right) { // 在右子树的右子树
			node = left_rotation(node); // 左旋
		} else if (node->right->left) { // 在右子树的左子树
			node->right = right_rotation(node->right); // 先右旋
			node = left_rotation(node);		 // 再左旋
		}
	}
}
// 右旋
AVL_tree* AVL_tree::right_rotation(AVL_tree* node) {
	auto temp = node->left;
	node->left = node->left->right;
	temp->right = node;
	// 高度调整
	node->height = std::max(Height(node->left), Height(node->right)) + 1;
	temp->height = std::max(Height(temp->left), Height(temp->right)) + 1;
	return temp;
}
// 左旋
AVL_tree* AVL_tree::left_rotation(AVL_tree*node) {
	auto temp = node->right;
	node->right = node->right->left;
	temp->left = node;
	// 高度调整
	node->height = std::max(Height(node->left), Height(node->right)) + 1;
	temp->height = std::max(Height(temp->left), Height(temp->right)) + 1;
	return temp;
}
// 中序遍历输出
void AVL_tree::inorder_traversal(void) {
	if (this->left != nullptr)
		this->left->inorder_traversal();
	if (this != nullptr)
		std::cout << this->value << " ";
	if (this->right != nullptr)
		this->right->inorder_traversal();
}
// 返回高度
int AVL_tree::Height(AVL_tree* node) {
	return (node != nullptr) ? node->height : -1;
}
// 查找节点
AVL_tree* AVL_tree::find_node(int num) {
	if (this == nullptr || this->value == num) {
		 return this;
	} else if (num < this->value) {
		this->left->find_node(num);
	} else if (num > this->value) {
		this->right->find_node(num);
	}
}
// 找左子树最大值
AVL_tree* AVL_tree::left_max(AVL_tree* node) {
	while (node->right != nullptr)
		node = node->right;
	return node;
}