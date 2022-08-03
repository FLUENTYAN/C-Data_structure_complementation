// 邻接矩阵
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include <map>
#include <vector>

class adjacency_matrix {
public:
	adjacency_matrix() = default;
	~adjacency_matrix() = default;
	// 构造的同时生成邻接矩阵
	adjacency_matrix(std::map<int, std::vector<int>> map) {
		mat.resize(map.size(), std::vector<int>(map.size()));
		int i = 0;
		for (const auto& p : map) {
			for (auto j = 0; j < (p.second).size(); ++j) {
				mat[i][(p.second)[j]]++;
			}
			++i;
		}
	} 
	// 遍历输出节点及其相邻节点
	void traverse(void);
private:
	// 矩阵
	std::vector<std::vector<int>> mat;
};

#endif