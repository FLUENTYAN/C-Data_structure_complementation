#include <iostream>
#include <vector>
#include "Stack.h"

int main(void) {
	// 创建一个大小为5的栈
	Stack* stack = new Stack(5);

	// 栈为空，出栈失败，报错
	stack->pop();
	// 栈为空，查看栈顶失败，报错
	int top = stack->front();
	// 栈为空，修改栈顶失败，报错
	stack->modify(9);

	stack->push(0);
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	// 栈满，入栈失败，报错
	stack->push(5);

	// 第5个元素
	std::cout <<   " Top element: " << stack->front()
			  << "\tCurrent size: " << stack->size_get()
			  << "\tMaximum size: " << stack->maxSize_get() << std::endl;
	// 第4个元素
	stack->pop();
	std::cout << " Top element: " << stack->front()
			  << "\tCurrent size: " << stack->size_get()
			  << "\tMaximum size: " << stack->maxSize_get() << std::endl;
	// 第3个元素
	stack->pop();
	std::cout << " Top element: " << stack->front()
			  << "\tCurrent size: " << stack->size_get()
			  << "\tMaximum size: " << stack->maxSize_get() << std::endl;
	// 第2个元素
	stack->pop();
	std::cout << " Top element: " << stack->front()
			  << "\tCurrent size: " << stack->size_get()
			  << "\tMaximum size: " << stack->maxSize_get() << std::endl;
	// 第1个元素
	stack->pop();
	std::cout << " Top element: " << stack->front()
			  << "\tCurrent size: " << stack->size_get()
			  << "\tMaximum size: " << stack->maxSize_get() << std::endl;
	return 0;
}