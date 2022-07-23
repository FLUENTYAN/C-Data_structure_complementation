#include <iostream>
#include "child_tree.h"

int main(void) {
	auto tree = new child_tree(0);

	// 插入节点1---9
	for (auto i = 1; i < 10; ++i) {
		tree->insert_node(i);
	}
	// 插入子节点
	tree->insert_child(tree, 0, 1);
	tree->insert_child(tree, 0, 2);
	tree->insert_child(tree, 1, 3);
	tree->insert_child(tree, 1, 4);
	tree->insert_child(tree, 1, 7);
	tree->insert_child(tree, 2, 5);
	tree->insert_child(tree, 2, 6);
	tree->insert_child(tree, 2, 8);
	/*			插入效果			
					1
				  /   \
			     2     3
			    /|\   /|\
			   4 5 8 6 7 9

	*/

	// 遍历输出
	tree->traversal();
	/*	输出效果
		1 with child 3 2
		2 with child 8 5 4
		3 with child 9 7 6
		4 with child
		5 with child
		6 with child
		7 with child
		8 with child
		9 with child
	*/
	return 0;
}