#include <vector>
#include <iostream>
#include "father_tree.h"

// 插入节点
void father_tree::insert(int num1, int num2) {
	for (auto i = 0; i < this->node.size(); ++i) {
		if ((this->node)[i].num == num2) {
			auto temp = new element(num1, i);
			(this->node).emplace_back(*temp);
			return;
		}
	}
	std::cerr << "Insert failed!" << std::endl;
}
