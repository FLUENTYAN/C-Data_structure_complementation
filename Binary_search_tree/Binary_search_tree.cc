#include <iostream>
#include "Binary_search_tree.h"

// 类内static成员的定义
Binary_search_tree* Binary_search_tree::root = nullptr;

// 插入
void Binary_search_tree::insert(int num, Binary_search_tree* node) {
	while (true) {
		if (num < node->num && node->left == nullptr) { // 放左边
			auto temp = new Binary_search_tree();
			node->left = temp; 
			temp->num = num;
			return;
		} else if (num > node->num && node->right == nullptr) { // 放右边
			auto temp = new Binary_search_tree();
			node->right = temp;
			temp->num = num; 
			return;
		} else if (num < node->num) { // 左边放不下
			node = node->left; continue;
		} else if (num > node->num) { // 右边放不下
			node = node->right; continue;
		} else {
			std::cerr << "Integer the same, insert failed!" << std::endl; return;
		}
	}
}
// 删除
void Binary_search_tree::remove(int num, Binary_search_tree* node) { // 递归查找与删除结合
	if (node->num == num) {
		// 要删节点左右都有孩子
		// 将要删节点值变为左边最大的，再删掉左边最大的
		if (node->left != nullptr && node->right != nullptr) {
			auto toRemove = node;
			node = node->left;
			// 待删除节点左孩子的右孩子不存在
			if (node->right == nullptr) {
				auto temp = node;
				toRemove->num = node->num;
				toRemove->left = node->left;
				delete temp;
				return;
			}
			// 待删除节点左孩子的右孩子存在
			while (true) {
				if (node->right == nullptr) {
					auto pre = prev(node->num, root);
					auto temp = node;
					toRemove->num = node->num; 
					pre->right = nullptr;
					delete temp;
					return;
				} else {
					node = node->right;
				}
			}
		} else { // 只有一个孩子或没有
			auto pre = prev(num, root);
			// 要删除节点为根节点
			if (node == root) {
				auto temp = node;
				root = (node->left != nullptr) ? node->left : node->right;
				delete temp; 
			} else { // 要删的不是根节点
				auto temp = node;
				auto& Node = (pre->left == node) ? pre->left : pre->right;
				Node = (node->left != nullptr) ? node->left : node->right;
				delete temp;
			}
		}
	} else if (num < node->num) { // 向左递
		remove(num, node->left);
	} else if (num > node->num) { // 向右递
		remove(num, node->right);
	}
}
// 中序遍历
void Binary_search_tree::inorder_traversal(Binary_search_tree* node) {
	// 向左递
	if (node != nullptr && node->left != nullptr) {
		inorder_traversal(node->left);
	}
	// 输出
	std::cout << node->num << " ";
	// 向右递
	if (node != nullptr && node->right != nullptr) {
		inorder_traversal(node->right);
	}
}
// 找前一个节点
Binary_search_tree* Binary_search_tree::prev(int num, Binary_search_tree* node) {
	if (node->num == num && node == root) {
		return node;
	} else if (node->left->num == num) {
		return node;
	} else if (node->right->num == num) {
		return node;
	} else if (num < node->num) { // 向左递
		prev(num, node->left);
	} else if (num > node->num) { // 向右递
		prev(num, node->right);
	}
}