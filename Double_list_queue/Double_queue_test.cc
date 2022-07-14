// 双端队列是为了同时实现 栈 和 队列 两种数据结构
// 因此只需测试这两种数据结构即可

#include <iostream>
#include "double_queue.h"

int main(void) {
	auto constexpr size = 5;
	// 初始化一个栈
	auto stack = new double_queue(0);
	// 初始化一个队列
	auto queue = new double_queue(0);

	
	/* 测试以左边为顶的栈 */
	// 将栈填满
	for (auto i = 0; i < size; ++i) {
		stack->left_in(i);
	}
	// 将栈依次输出并弹出
	for (auto i = 0; i < size; ++i) {
		std::cout << stack->left_get() << "	"; 
		stack->left_out();
	}
	std::cout << std::endl;
	// 期望输出：4	3	2	1	0


	/* 测试以右边为顶的栈 */
	// 将栈填满
	for (auto i = 0; i < size; ++i) {
		stack->right_in(i);
	}
	// 将栈依次输出并弹出
	for (auto i = 0; i < size; ++i) {
		std::cout << stack->right_get() << "	";
		stack->right_out();
	}
	std::cout << std::endl;
	// 期望输出：4	3	2	1	0

	
	/* 左进右出队列 */
	// 将队列填满
	for (auto i = 0; i < size; ++i) {
		queue->left_in(i);
	}
	// 将队头元素依次输出并出队
	for (auto i = 0; i < size; ++i) {
	 	std::cout << queue->right_get() << "	";
		queue->right_out();
	}
	std::cout << std::endl;
	// 期望输出：0	1	2	3	4
	

	/* 右进左出队列 */
	// 将队列填满
	for (auto i = 0; i < size; ++i) {
		queue->right_in(i);
	}
	// 将队头元素依次输出并出队
	for (auto i = 0; i < size; ++i) {
		std::cout << queue->left_get() << "	";
		queue->left_out();
	}
	std::cout << std::endl;
	// 期望输出：0	1	2	3	4

	return 0;
}