#include <iostream>
#include "Double_queue.h"

int main(void) {
	// 初始化一个大小为6的队列，只能存5个数，一个空着用于判断队满
	Double_queue* queue = new Double_queue(6);

	queue->left_in(0);
	queue->left_in(1);
	queue->left_in(2);
	queue->left_in(3);
	queue->left_in(4);

	// 堆满，报错
	queue->left_in(5);

	std::cout << queue->left_get() << std::endl; // 0
	queue->left_out();
	// 此时队满
	queue->left_in(5);

	// 依次输出队列元素
	std::cout << queue->left_get() << std::endl; // 1
	queue->left_out();
	// 此时队满
	queue->left_in(6);
	std::cout << queue->left_get() << std::endl; // 2
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 3
	queue->left_out(); 
	std::cout << queue->left_get() << std::endl; // 4
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 5
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 6

	/*queue->left_in(0);
	queue->left_in(1);
	queue->left_in(2);
	queue->left_in(3);
	queue->left_in(4);

	// 堆满，报错
	queue->left_in(5);

	std::cout << queue->left_get() << std::endl; // 0
	queue->left_out();
	// 此时队满
	queue->left_in(5);

	// 依次输出队列元素
	std::cout << queue->left_get() << std::endl; // 1
	queue->left_out();
	// 此时队满
	queue->left_in(6);
	std::cout << queue->left_get() << std::endl; // 2
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 3
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 4
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 5
	queue->left_out();
	std::cout << queue->left_get() << std::endl; // 6*/

	return 0;
}