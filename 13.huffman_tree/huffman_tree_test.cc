#include <iostream>
#include "huffman_tree.h"

int main(void) {
	auto tree = new huffman_tree({ {'A', 3},
								   {'B', 2},
								   {'C', 1},
								   {'D', 2},
								   {'E', 5},
								   {'F', 2} });
	// 建树
	auto copy = tree->make_tree();
	// 编码
	tree->get_code(copy);
	return 0;
}