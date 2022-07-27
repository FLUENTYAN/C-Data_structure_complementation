#include <vector>
#include <iostream>
#include "father_tree.h"

int main(void) {
	auto tree = new father_tree(0);
	tree->insert(1, 0);  // 1，父节点值为0
	tree->insert(2, 0);  // 2，父节点值为0
	tree->insert(3, 1);  // 3，父节点值为1
	tree->insert(4, 1);  // 4，父节点值为1


	// 输出所有节点的值以及其父节点的值
	std::cout << (tree->node)[0].num << std::endl;
	for (auto i = 1; i < (tree->node).size(); ++i) {
		std::cout << (tree->node)[i].num << " " 
				  << (tree->node)[(tree->node)[i].father].num << std::endl;
	}

	return 0;
}