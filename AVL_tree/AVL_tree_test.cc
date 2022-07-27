#include <iostream>
#include <vector>
#include "AVL_tree.h"

int main(void) {
	auto tree = new AVL_tree(0);
	// ����˳�����
	std::vector<int> arr{ 7, 3, 5, 8, 9, 2, 4, 1, 6  };
	
	// ������������ƽ�������������ת�������߶Ȳ���
	for (auto i = 0; i < arr.size(); ++i) {
		tree->insert(tree, arr[i]);
	}
	// ����������
	/* 0 1 2 3 4 5 6 7 8 9 */
	tree->inorder_traversal();
	std::cout << std::endl;

	// ���ɾ��
	tree->remove(tree, 3);
	// ����������
	/* 0 1 2 4 5 6 7 8 9 */
	tree->inorder_traversal();
	std::cout << std::endl;
	return 0;
}