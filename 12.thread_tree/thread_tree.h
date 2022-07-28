// 线索二叉树

#ifndef THREAD_TREE_H
#define THREAD_TREE_H

class thread_tree {
public:
	thread_tree() = default;
	thread_tree(int num) 
	: value(num), left(nullptr), right(nullptr), right_tag(0), left_tag(0) { }
	// 插入
	void insert(thread_tree*&, int);
	// 线索化
	void threadrize(thread_tree*&);
	// 迭代遍历输出
	void traverse(thread_tree*);

private:
	// 数据
	int value;
	// 左子树
	thread_tree* left;
	// 右子树
	thread_tree* right;
	// 左标记，0 for left node, 1 for previous node
	int left_tag;
	// 右标记，0 for right node, 1 for next node
	int right_tag;
	// 前一个节点
	static thread_tree* prev;
};

#endif