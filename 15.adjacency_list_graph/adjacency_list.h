// 邻接表

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H
#include <unordered_map>
#include <vector>

// 相邻的节点
struct adjvertex {
	adjvertex() = default;
	adjvertex(int val, int weight, adjvertex* ptr) : val(val), weight(weight), adj(ptr) { }
	// 数据
	int val;
	// 权重
	int weight;
	// 指向其他相邻节点
	adjvertex* adj;
};

// 节点集合
struct vertex {
	vertex() = default;
	vertex(int val) : val(val), adj(nullptr) { }
	// 数据
	int val;
	// 指向相邻节点
	adjvertex* adj;
};

class adjacency_list {
public:
	adjacency_list() = default;
	~adjacency_list() = default;
	adjacency_list(std::unordered_map<int, std::vector<std::vector<int>>> map) {
		// 存储所有节点
		for (const auto& p : map) {
			auto temp = new vertex(p.first);
			graph.emplace_back(*temp);
		}
		// 生成邻接节点并合并
		auto i = 0;
		for (const auto& p : map) {
			for (auto j = 0; j < (p.second).size(); ++j) {
				auto temp = new adjvertex((p.second)[j][0], (p.second)[j][1], graph[i].adj);
				graph[i].adj = temp;
			}
			++i;
		}
	}
	// 遍历输出
	void traverse(void);
private:
	// 节点数组
	std::vector<vertex> graph;
};

#endif