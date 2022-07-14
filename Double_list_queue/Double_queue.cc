#include <iostream>	// std::cerr std::endl
#include "double_queue.h"

// static 成员的定义
double_queue* double_queue::mid = new double_queue();
double_queue* double_queue::left = new double_queue();
double_queue* double_queue::right = new double_queue();

// 左入
void double_queue::left_in(int num) {
	auto temp = new double_queue();
	temp->num = num;
	right->next = temp;
	temp->pre = right;
	temp->next = nullptr;
	right = temp;
}
// 右入
void double_queue::right_in(int num) {
	auto temp = new double_queue();
	temp->num = num;
	left->pre = temp;
	temp->next = left;
	temp->pre = nullptr;
	left = temp;
}
// 左出
void double_queue::left_out() {
	// 左侧插入的非空
	if (right == mid) {
		if (left == mid) {
			std::cerr << "Queue is empty, left_out failed!" << std::endl;
		} else if (left->next != mid) { // 大小大于一
			auto temp = mid->pre;
			mid->pre = mid->pre->pre;
			mid->pre->next = mid;
			delete temp;
		} else { // 大小等于一
			auto temp = mid->pre;
			mid->pre = nullptr;
			delete temp;
		}
	} else {
		auto temp = right;
		right = right->pre;
		right->next = nullptr;
		delete temp;
	}
}
// 右出
void double_queue::right_out() {
	// 右侧插入的非空
	if (left == mid) {
		if (right == mid) {
			std::cerr << "Queue is empty, right_out failed!" << std::endl;
		} else if (right->pre != mid) { // 大小大于一
			auto temp = mid->next;
			mid->next = mid->next->next;
			mid->next->pre = mid;
			delete temp;
		} else { // 大小等于一
			auto temp = mid->next;
			mid->next = nullptr;
			delete temp;
		}
	} else {
		auto temp = left;
		left = left->next;
		left->pre = nullptr;
		delete temp;
	}
	
}
// 查看左边
int double_queue::left_get() {
	if (right == mid) {
		if (left == mid) {
			std::cerr << "Queue is empty, left_get failed! -1 returned" << std::endl;
			return -1;
		} else {
			return mid->pre->num;
		}
	} else {
		return right->num;
	}
}
// 查看右边
int double_queue::right_get() {
	if (left == mid) {
		if (right == mid) {
			std::cerr << "Queue is empty, right_get failed! -1 returned" << std::endl;
			return -1;
		} else {
			return mid->next->num;
		}
	} else {
		return left->num;
	}
}