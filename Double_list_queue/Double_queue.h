// 链表实现双端队列--由于是链表，空间无限

#ifndef DOUBLE_QUEUE_H
#define DOUBLE_QUEUE_H

#include <cstddef>	// std::size_t

class double_queue {
public:
	double_queue(int num) : num(num), pre(nullptr), next(nullptr) {
		auto temp1 = mid, temp2 = left, temp3 = right;
		// 开始时，左右指针都指向中间指针
		mid = this;
		left = this;
		right = this;
		delete temp1, temp2, temp3;
	}
	// 左入队
	void left_in(int);
	// 右入队
	void right_in(int);
	// 左出队
	void left_out();
	// 右出队
	void right_out();
	// 查看左队头
	int left_get();
	// 查看右队头
	int right_get();

private:
	// 默认构造函数
	double_queue() = default;
	int num;
	// 中间指针
	static double_queue* mid;
	// 队列左队头指针
	static double_queue* left;
	// 队列右队头指针
	static double_queue* right;
	// 节点的左指针
	double_queue* pre;
	// 节点的右指针
	double_queue* next;
};

#endif