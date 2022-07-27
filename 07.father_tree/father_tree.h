// 数据+父节点位 的不包含重复整数的树

#ifndef FATHER__TREE
#define FATHER__TREE

#include <vector>

struct element {
	element(int a, int b) : num(a), father(b) { };
	// 存储所以节点的数
	int num;
	// 父节点，以父节点的下标代表
	int father;
};

class father_tree {
public:
	// 初始化根节点
	father_tree(int num) { 
		auto temp = new element(num, -1);
		node.emplace_back(*temp);
	};
	// 插入节点
	void insert(int num1, int num2);

	std::vector<element> node;
};

#endif