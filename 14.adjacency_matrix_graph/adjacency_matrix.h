// 无权&有权邻接矩阵
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include <map>
#include <vector>

class adjacency_matrix {
public:
	adjacency_matrix() = default;
	~adjacency_matrix() = default;
	// 构造的同时生成邻接矩阵
	adjacency_matrix(std::map<int, std::vector<std::vector<int>>> map) {
		mat.resize(map.size(), std::vector<int>(map.size()));
		// 将节点放入节点数组
		for (const auto& p : map)
			node.emplace_back(p.first);
		// 补全邻接矩阵
		int i = 0;
		for (const auto& p : map) {
			for (auto j = 0; j < (p.second).size(); ++j) {
				for (auto k = 0; k < node.size(); ++k)
					if ((p.second)[j][0] == node[k])
						mat[i][k] = (p.second)[j][1];
			}
			++i;
		}
	} 
	// 遍历输出节点及其相邻节点
	void traverse(void);
private:
	// 节点集合
	std::vector<int> node;
	// 邻接矩阵
	std::vector<std::vector<int>> mat;
};

#endif