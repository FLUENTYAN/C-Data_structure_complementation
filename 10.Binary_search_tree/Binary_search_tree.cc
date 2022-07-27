#include <iostream>
#include "Binary_search_tree.h"

// 插入
void Binary_search_tree::insert(int num, Binary_search_tree*& node) {
		if (node == nullptr) { 
			node = new Binary_search_tree(num);
		} else if (num < node->num) { // 左递
			insert(num, node->left);
		} else if (num > node->num) { // 右递
			insert(num, node->right);
		} else {
			std::cerr << "Integer the same, insert failed!" << std::endl; return;
		}
}
// 删除
void Binary_search_tree::remove(int num, Binary_search_tree*& node) {
	// 查看要删的节点是否存在
	auto temp1 = node->find_node(num);
	if (temp1 == nullptr) {
		std::cerr << "Node not exist, remove failed!" << std::endl;
		return;
	} 
	if (num < node->num) { // 往左找
		remove(num, node->left);
	} else if (num > node->num) { // 往右找
		remove(num, node->right);
	} else {
		if (node->left && node->right) { // 左右子树都有
			auto temp2 = left_max(node->left);
			remove(temp2->num, node);
			temp1->num = temp2->num;
		} else { // 只有一个子树或没有
			auto temp = (node->left != nullptr) ? node->left : node->right;
			node = temp;
			delete temp;
		}
	}
}
// 中序遍历
void Binary_search_tree::inorder_traversal() {
	if (this != nullptr && this->left != nullptr)
		this->left->inorder_traversal();
	std::cout << this->num << " ";
	if (this != nullptr && this->right != nullptr)
		this->right->inorder_traversal();
}
// 查找节点
Binary_search_tree* Binary_search_tree::find_node(int num) {
	if (this == nullptr || this->num == num) {
		return this;
	}
	else if (num < this->num) {
		this->left->find_node(num);
	}
	else if (num > this->num) {
		this->right->find_node(num);
	}
}
// 找左子树最大值
Binary_search_tree* Binary_search_tree::left_max(Binary_search_tree* node) {
	while (node->right != nullptr)
		node = node->right;
	return node;
}