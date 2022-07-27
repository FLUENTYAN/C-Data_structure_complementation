#include <iostream>
#include <vector>
#include "AVL_tree.h"

int main(void) {
	auto tree = new AVL_tree(0);
	// 数字顺序随机
	std::vector<int> arr{ 7, 3, 5, 8, 9, 2, 4, 1, 6  };
	
	// 检验插入操作、平衡操作、左、右旋转操作、高度操作
	for (auto i = 0; i < arr.size(); ++i) {
		tree->insert(tree, arr[i]);
	}
	// 中序遍历输出
	/* 0 1 2 3 4 5 6 7 8 9 */
	tree->inorder_traversal();
	std::cout << std::endl;

	// 检查删除
	tree->remove(tree, 3);
	// 中序遍历输出
	/* 0 1 2 4 5 6 7 8 9 */
	tree->inorder_traversal();
	std::cout << std::endl;
	return 0;
}