#include <iostream>
#include "Binary_search_tree.h"

int main(void) {

	/* 				树及其节点删除顺序

							7	二、
						  /   \
					一、	3		9	
					  /	  \	  /   \
					1     5   8   10
				   /     / \  
			三、  0     4   6
	*/
	Binary_search_tree* tree = new Binary_search_tree(7);

	// 插入建立二叉搜索树
	tree->insert(3);
	tree->insert(9);
	tree->insert(1);
	tree->insert(5);
	tree->insert(8);
	tree->insert(10);
	tree->insert(0);
	tree->insert(4);
	tree->insert(6);
	/* 0 1 3 4 5 6 7 8 9 10 */
	tree->inorder_traversal();
	std::cout << std::endl;
	// 验证三种种删除
	// 待删除节点左孩子的右孩子不存在
	/* 0 1 4 5 6 7 8 9 10 */
	tree->remove(3);
	tree->inorder_traversal();
	std::cout << std::endl;
	// 待删除节点左孩子的右孩子存在
	/* 0 1 4 5 6 8 9 10 */
	tree->remove(7);
	tree->inorder_traversal();
	std::cout << std::endl;
	// 待删除节点只有一个或没有孩子
	/* 0 1 5 6 8 9 10 */
	tree->remove(4);
	tree->inorder_traversal();
	std::cout << std::endl;
	return 0;
}