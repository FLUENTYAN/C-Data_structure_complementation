#include <iostream>
#include <vector>
#include "child_tree.h"


// 插入节点，参数为该节点的值
void child_tree::insert_node(int key) {
	auto temp = new Node(key);
	(this->node).emplace_back(*temp);
}
// 插入子节点，参数为父节点和子节点的下标，须保证下标存在
void child_tree::insert_child(child_tree* node, std::size_t father, std::size_t child) {
	auto temp = (node->node)[father].child;
	(node->node)[father].child = &(node->node)[child];
	(node->node)[child].next = temp;
}
// 遍历树
void child_tree::traversal() {
	auto hasChild = false;
	for (auto i = 0; i < (this->node).size(); ++i) {
		std::cout << (this->node)[i].num << " with child ";
		if ((this->node)[i].child != nullptr) {
			hasChild = true;
			std::cout << (this->node)[i].child->num << " ";
		}
		auto temp = (this->node)[i].child;
		while (hasChild) {
			if (temp->next != nullptr) {
				std::cout << temp->next->num << " ";
				temp = temp->next;
			} else {
				hasChild = false;
			}
		}
		std::cout << std::endl;
	}
}