#include <iostream>
#include "adjacency_matrix.h"

// 遍历输出节点及其相邻节点
void adjacency_matrix::traverse(void) {
	for (auto i = 0; i < this->mat[0].size(); ++i) {
		std::cout << i << " has adjacet vertices: ";
		for (auto j = 0; j < this->mat[0].size(); ++j) {
			if (this->mat[i][j] == 1)
				std::cout << j;
		}
		std::cout << std::endl;
	}
}