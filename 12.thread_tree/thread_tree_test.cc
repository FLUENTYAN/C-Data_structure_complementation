#include "thread_tree.h"

int main(void) {
	auto tree = new thread_tree(6);

	// 插入测试
	tree->insert(tree, 8);
	tree->insert(tree, 3);
	tree->insert(tree, 7);
	tree->insert(tree, 4);
	tree->insert(tree, 1);
	tree->insert(tree, 2);
	tree->insert(tree, 9);
	tree->insert(tree, 5);
	tree->insert(tree, 0);
	tree->insert(tree, 7.5);
	tree->insert(tree, 6.5);
	// 线索化检测
	tree->threadrize(tree);
	// 迭代遍历输出检测
	// 由于线索树的特点，7、 7.5、 6.5 迭代遍历不到
	/* 0 1 2 3 4 5 6 8 9 */
	tree->traverse(tree);
	return 0;
}