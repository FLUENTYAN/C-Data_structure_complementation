// 双端队列是为了同时实现 栈 和 队列 两种数据结构
// 因此只需测试这两种数据结构即可

#include <iostream>
#include "double_queue.h"

int main(void) {
	int size = 5;
	// 初始化一个大小为6的栈，只能存5个数，一个空着用于判断满
	auto stack = new double_queue(size+1);
	// 初始化一个大小为6的队列，只能存5个数，一个空着用于判断满
	auto queue = new double_queue(size+1);

	
	/* 左插左删的栈 */
	// 将栈填满
	for (auto i = 0; i < size; ++i) {
		stack->left_in(i);
	}
	// 栈已满，操作无效，会报错
	stack->left_in(size);
	// 将栈依次输出并弹出
	for (auto i = 0; i < size; ++i) {
		std::cout << stack->left_get() << "	"; 
		stack->left_out();
	}
	std::cout << std::endl;
	/*
		期望输出：
		Queue is full! left_in failed!
		4	3	2	1	0
	*/

	/* 右插右删的栈 */
	// 将栈填满
	for (auto i = 0; i < size; ++i) {
		stack->right_in(i);
	}
	// 栈已满，操作无效，会报错
	stack->right_in(size);
	// 将栈依次输出并弹出
	for (auto i = 0; i < size; ++i) {
		std::cout << stack->right_get() << "	";
		stack->right_out();
	}
	std::cout << std::endl;
	/*
		期望输出：
		Queue is full! right_in failed!
		4	3	2	1	0
	*/

	
	/* 左插右删队列 */
	// 将队列填满
	for (auto i = 0; i < size; ++i) {
		queue->left_in(i);
	}
	// 队列已满，操作无效，会报错
	queue->left_in(size);
	// 将队头元素依次输出并出队
	for (auto i = 0; i < size; ++i) {
	 	std::cout << queue->right_get() << "	";
		queue->right_out();
	}
	std::cout << std::endl;
	/*
		期望输出：
		Queue is full! left_in failed!
		0	1	2	3	4
	*/

	/* 右插左删队列 */
	// 将队列填满
	for (auto i = 0; i < size; ++i) {
		queue->right_in(i);
	}
	// 队列已满，操作无效，会报错
	queue->left_in(size);
	// 将队头元素依次输出并出队
	for (auto i = 0; i < size; ++i) {
		std::cout << queue->left_get() << "	";
		queue->left_out();
	}
	std::cout << std::endl;
	/*
		期望输出：
		Queue is full! right_in failed!
		0	1	2	3	4
	*/

	return 0;
}