#include <iostream>	// std::cerr std::endl
#include "double_queue.h"

// static 成员的定义
double_queue* double_queue::mid = new double_queue();
double_queue* double_queue::left_side = new double_queue();
double_queue* double_queue::right_side = new double_queue();

// 左入队, 尾插
void double_queue::left_in(int num) {
	auto temp = new double_queue();
	left_side->left = temp;
	temp->right = left_side;
	temp->left = nullptr;
	right_side = temp;
	temp->num = num;
}
// 右入队，尾插
void double_queue::right_in(int num) {
	auto temp = new double_queue();
	right_side->right = temp;
	temp->left = right_side;
	temp->right = nullptr;
	right_side = temp;
	temp->num = num;
}
// 左出队，头删
void double_queue::left_out() {
	// 非空
	if (left_side == mid) {
		std::cerr << "Queue is empty, left_out failed!" << std::endl;
	} else if (mid->left->left != nullptr) { // 要删除节点左边有节点
		auto temp = mid->left;
		mid->left = mid->left->left;
		mid->left->left->right = mid;
		delete temp;
	} else {
		auto temp = mid->left;
		mid->left = nullptr;
		delete temp;
	}
}
// 右出队，头删
void double_queue::right_out() {
	// 非空
	if (right_side == mid) {
		std::cerr << "Queue is empty, right_out failed!" << std::endl;
	} else if (mid->right->right != nullptr) { // 要删除节点右边有节点
		auto temp = mid->right;
		mid->right = mid->right->right;
		mid->right->right->left = mid;
		delete temp;
	} else {
		auto temp = mid->right;
		mid->right= nullptr;
		delete temp;
	}
	
}
// 查看左队头
int double_queue::left_get() {
	if (left_side == mid) {
		std::cerr << "Queue is empty, left_get failed! -1 returned" << std::endl;
		return -1;
	} else {
		return mid->left->num;
	}
}
// 查看右队头
int double_queue::right_get() {
	if (right_side == mid) {
		std::cerr << "Queue is empty, right_get failed! -1 returned" << std::endl;
		return -1;
	} else {
		return mid->right->num;
	}
}