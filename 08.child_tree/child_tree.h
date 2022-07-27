// 数组+链表实现树的孩子表示法

#ifndef CHILD_TREE_H
#define CHILD_TREE_H

#include <vector>
#include <cstddef>

struct Node {
	Node() = default;
	Node(int key) : num(key), child(nullptr), next(nullptr) {	};

	// 表示节点数据
	int num;
	// 表示子节点的指针
	Node* child;
	// 表示下一个子点的指针
	Node* next;	
};

class child_tree {
public:
	child_tree() = default;
	child_tree(int key) : node(key) { };

	// 插入节点，参数为该节点的值
	void insert_node(int);
	// 插入子节点，参数为父节点和子节点的下标，须保证下标存在
	void insert_child(child_tree*, std::size_t, std::size_t);
	// 遍历树
	void traversal();

	std::vector<Node> node;
	
};

#endif