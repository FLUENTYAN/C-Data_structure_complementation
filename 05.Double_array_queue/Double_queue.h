// 数组实现双端队列

#ifndef DOUBLE_QUEUE_H
#define DOUBLE_QUEUE_H

#include <vector>
#include <cstddef>

class double_queue {
public:
	double_queue(int sz) : nums(sz), left(0), right(0), size(sz) { };
	// 左入
	void left_in(int);
	// 左出
	void right_in(int);
	// 左删
	void left_out();
	// 右删
	void right_out();
	// 查看左边
	int left_get();
	// 查看右边
	int right_get();

private:
	std::vector<int> nums;
	// 左指针
	std::size_t left;
	// 右指针
	std::size_t right;
	// 队列大小
	std::size_t size;
};

#endif