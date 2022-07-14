// 数组实现大小固定的以栈

#ifndef STACK_H
#define STACK_H
#include <vector>
#include <cstddef>

class Stack {
public:
	// 构造函数
	Stack(int sz) : nums(sz), top(-1), size(0), maxSize(sz) { }
	// 压栈
	void push(int);
	// 出栈
	void pop();
	// 查看栈顶元素
	int front();
	// 修改栈顶元素
	void modify(int);
	// 查看栈的大小
	inline std::size_t size_get() { return size; }
	// 查看栈的最大大小
	inline std::size_t maxSize_get() { return maxSize; }
	
private:
	// 存储数据数组
	std::vector<int> nums;
	// 存储栈顶的位置
	int top;
	// 栈目前的大小
	std::size_t size;
	// 栈的最大大小
	std::size_t maxSize; 
};

#endif