// 利用数组实现固定大小单端队列

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <cstddef>

class Queue {
public:
	// 构造函数
	Queue(int sz) : nums(sz), front(0), back(0), size(sz) { }
	// 入队
	void in(int);
	// 出队
	void out();
	// 查看队头
	int front_get();

private:
	std::vector<int> nums;
	// 头指针
	std::size_t front;
	// 尾指针
	std::size_t back;
	// 队列大小
	std::size_t size;
};

#endif