// 十字链表
#ifndef CROSS_LINKED_LIST_H
#define CROSS_LINKED_LIST_H
#include <vector>
#include <unordered_map>

// 邻接节点
struct adjvertex {
	adjvertex() = default;
	adjvertex(int wei, int ind, int i, adjvertex* ptr)
		: weight(wei), indThis(ind), ind(i), out(ptr), in(nullptr) { };
	// 节点权重
	int weight;
	// 本节点的下标
	int indThis;
	// 指向本节点的下标
	int ind;
	// 被指向
	adjvertex* in;
	// 指出
	adjvertex* out;
};
// 节点集合
struct vertices {
	vertices() = default;
	vertices(int val) : val(val), in(nullptr), out(nullptr) { }
	// 数据
	int val;
	// 被指向
	adjvertex* in;
	// 指出
	adjvertex* out;
};

class cross_linked_list {
public:
	cross_linked_list() = default;
	~cross_linked_list() = default;
	cross_linked_list(std::unordered_map<int, std::vector<std::vector<int>>>);
	// 遍历输出
	void traverse(void);
private:
	std::vector<vertices> graph;
};

#endif