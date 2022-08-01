#include <map>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include "huffman_tree.h"

// 建立哈夫曼树
std::vector<node*> huffman_tree::make_tree(void) {
	std::vector<node*> copy;
	for (auto& i : tree)
		copy.emplace_back(&i);
	auto beg = copy.begin(), end = copy.end();
	int i = 2;
	while (end-beg > 1) {
		// 排序
		std::sort(beg, end, [](node* n1, node* n2) { return n1->weight > n2->weight; });
		// 构造节点
		node* p1 = *(end-1), * p2 = *(end-2);
		auto temp = new node('\0', (p1->weight)+(p2->weight), p1, p2);
		p1->father = temp; p2->father = temp;
		// 新建节点插入，之前最小两个去除
		copy.emplace(end-2, temp);
		beg = copy.begin(); end = copy.end()-i;
		i += 2;;
	}
	return copy;
}
// 获取哈夫曼编码
void huffman_tree::get_code(std::vector<node*> copy) {
	for (auto i = 0; i < copy.size(); ++i) {
		std::deque<int> code;
		// 根据每个符号逆向推编码
		auto fa = copy[i]->father;
		auto ch = copy[i]->character;
		auto preW = copy[i]->weight;
		while (fa != nullptr) {
			std::cout << ch;
			if (fa->left->weight == preW) {
				code.emplace_front(0);
			} else if (fa->right->weight == preW) {
				code.emplace_front(1);
			}
			preW = fa->weight;
			fa = fa->father;
			if (fa != nullptr)
				ch = fa->character;
		}
		if (copy[i]->character != '\0') {
			std::cout << ": ";
			for (auto c : code)
				std::cout << c;
			std::cout << std::endl;
		}
	}
}