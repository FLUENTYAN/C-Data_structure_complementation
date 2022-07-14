#include <iostream>
#include "Double_queue.h"

// 左入队
void Double_queue::left_in(int num) {
	// 非满
	if ((this->right + 1) % this->size == this->left) {
		std::cerr << "Queue is full! left_in failed!" << std::endl;	
	} else {
		// 先移，后插：left指向插入元素
		// 当左指针在最左端时移向最右端，否则直接左移一格
		this->left = (this->left==0) ? (this->size-1) : (this->left-1);
		this->nums[this->left] = num;
	}
}
// 右入队
void Double_queue::right_in(int num) {
	// 非满
	if ((this->right + 1) % this->size == this->left) {
		std::cerr << "Queue is full! right_in failed!" << std::endl;	
	} else {
		// 先插，后移：right的前一个指向插入元素
		this->nums[this->right] = num;
		// 当右指针在最右端时移向最左端，否则直接右移一格
		this->right = (this->right+1) % this->size;
	}
}
// 左出队
void Double_queue::left_out() {
	// 非空
	if (this->left == this->right) {
		std::cerr << "Queue is empty, left_out failed!" << std::endl;
	} else {
		// 当左指针在最右端时移向最左端，否则直接右移一格
		this->left = (this->left+1) % this->size;
	}
}
// 右出队
void Double_queue::right_out() {
	// 非空
	if (this->left == this->right) {
		std::cerr << "Queue is empty, right_out failed!" << std::endl;
	} else {
		// 当右指针在最左端时移向最右端，否则直接左移一格
		this->right = (this->right==0) ? (this->size-1) : (this->right-1);
	}
}
// 查看左队头
int Double_queue::left_get() {
	// 非空
	if (this->left == this->right) {
		std::cerr << "Queue is empty, left_out failed! -1 returned." << std::endl;
		return -1;
	} else {
		return this->nums[this->left];
	}
}
// 查看右对头
int Double_queue::right_get() {
	// 非空
	if (this->left == this->right) {
		std::cerr << "Queue is empty, right_out failed! -1 returned." << std::endl;
		return -1;
	} else {
		return this->nums[this->right-1];
	}
}