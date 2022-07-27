#include <iostream>
#include "Queue.h"

int main(void) {
	// 初始化一个大小为6的队列，只能存5个数，一个空着用于判断队满
	auto queue = new Queue(6);

	queue->in(0);
	queue->in(1);
	queue->in(2);
	queue->in(3);
	queue->in(4);

	// 堆满，报错
	queue->in(5);

	std::cout << queue->front_get() << std::endl; // 0
	queue->out();
	// 此时队满
	queue->in(5);

	// 依次输出队列元素
	std::cout << queue->front_get() << std::endl; // 1
	queue->out();
	// 此时队满
	queue->in(6);
	std::cout << queue->front_get() << std::endl; // 2
	queue->out();
	std::cout << queue->front_get() << std::endl; // 3
	queue->out(); 
	std::cout << queue->front_get() << std::endl; // 4
	queue->out();
	std::cout << queue->front_get() << std::endl; // 5
	queue->out();
	std::cout << queue->front_get() << std::endl; // 6
	std::cout << queue->front_get() << std::endl; // 6

	return 0;
}