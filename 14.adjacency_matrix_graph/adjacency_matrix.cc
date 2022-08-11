#include <iostream>
#include "adjacency_matrix.h"

// 遍历输出节点及其相邻节点
void adjacency_matrix::traverse(void) {
	for (auto i = 0; i < mat[0].size(); ++i) {
		std::cout << node[i] << " has adjacet vertices ";
		for (auto j = 0; j < mat[0].size(); ++j) {
			if (mat[i][j] >= 1)
				std::cout << node[j] << " of weight " << mat[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}