#include <iostream>
#include "thread_tree.h"

// 定义前一个节点
thread_tree* thread_tree::prev = nullptr;

// 插入
void thread_tree::insert(thread_tree*& node, int num) {
	if (node == nullptr)      // 插入新节点
		node = new thread_tree(num);
	else if (num < node->value) // 向左递
		insert(node->left, num);
	else if (num > node->value) // 向右递
		insert(node->right, num);
}
// 线索化
void thread_tree::threadrize(thread_tree*& node) {
	if (node != nullptr && node->left != nullptr)
		threadrize(node->left);
	// 修改前驱
	if (node->left == nullptr && node->left_tag == 0) {
		left_tag = 1;
		node->left = prev;
	}
	// 修改后继
	if (prev != nullptr && prev->right == nullptr && prev->right_tag == 0) {
		prev->right_tag = 1;
		prev->right = node;
	}
	prev = node;
	if (node != nullptr && node->right != nullptr)
		threadrize(node->right);
}
// 迭代遍历输出
void thread_tree::traverse(thread_tree* node) {
	if (!node)	// 树空
		return;
	while (node != nullptr && node->left != nullptr)
		node = node->left;
	while (node != nullptr) {
		std::cout << node->value << " ";
		node = node->right;
	}
	std::cout  << std::endl;
}