#include <iostream>
#include "Stack.h"

// 压栈
void Stack::push(int num) {
	// 判断栈是否已满
	if (this->size >= this->maxSize) {
		std::cerr << "Stack is full, push failed!" << std::endl;
	} else {
		++this->top;
		this->nums[top] = num;
		++this->size;
	}
}

// 出栈
void Stack::pop() {
	// 判断栈是否为空
	if (this->size == 0) {
		std::cerr << "Stack is empty, pop failed!" << std::endl;
	} else {
		--this->size;
		--this->top;
	}
}

// 查看栈顶元素
int Stack::front() {
	// 判断栈是否为空
	if (this->size == 0) {
		std::cerr << "Stack is empty, front failed! -1 returned" << std::endl;
		return -1;
	} else {
		return this->nums[top];
	}
}

// 修改栈顶元素
void Stack::modify(int num) {
	// 判断栈是否为空
	if (this->size == 0) {
		std::cerr << "Stack is empty, modify failed!" << std::endl;
	} else {
		this->nums[top] = num;
	}
}
