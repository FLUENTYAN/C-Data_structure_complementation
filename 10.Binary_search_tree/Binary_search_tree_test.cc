#include <iostream>
#include "Binary_search_tree.h"

int main(void) {

	/* 				树及其节点删除顺序

							7	
						  /   \
					二、	3		9	
					  /	  \	  /   \
					1     5   8   10
				   /     / \  
			一、  0     4   6
	*/
	Binary_search_tree* tree = new Binary_search_tree(7);

	// 插入建立二叉搜索树
	tree->insert(3, tree);
	tree->insert(9, tree);
	tree->insert(1, tree);
	tree->insert(5, tree);
	tree->insert(8, tree);
	tree->insert(10, tree);
	tree->insert(0, tree);
	tree->insert(4, tree);
	tree->insert(6, tree);
	/* 0 1 3 4 5 6 7 8 9 10 */
	tree->inorder_traversal();
	std::cout << std::endl;
	// 验证三种种删除
	// 待删除节点只有一个孩子
	/* 1 3 4 5 6 7 8 9 10 */
	tree->remove(0, tree);
	tree->inorder_traversal();
	std::cout << std::endl;
	// 待删除节点左、右孩子都存在
	/* 1 4 5 6 8 9 10 */
	tree->remove(3, tree);
	tree->inorder_traversal();
	std::cout << std::endl;
	
	return 0;
}