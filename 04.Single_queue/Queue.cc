#include <iostream>
#include "Queue.h"

// 入队
void Queue::in(int num) {
	// 判断是否队满
	// 队满时back和front相差1
	if ((this->back + 1) % this->size == this->front) {
		std::cerr << "Queue is full, in failed!" << std::endl;
	} else {
		this->nums[this->back] = num;
		// 当队列后侧满时，尾指针转到开头（如果开头有位置的话）
		this->back = (this->back+1) % this->size;
	}
}
// 出队
void Queue::out() {
	// 判断是否队空
	// 队空时front==back
	if (this->back == this->front) {
		std::cerr << "Queue is empty, out failed!" << std::endl;
	} else {
		// 当队列后侧满时，头指针转到开头
		this->front = (this->front+1) % this->size;
	}
}

// 查看队头
int Queue::front_get() {
	// 判断是否队空
	// 队空时front==back
	if (this->back == this->front) {
		std::cerr << "Queue is empty, front_get failed! return -1" << std::endl;
		return -1;
	} else {
		return this->nums[this->front];
	}
}