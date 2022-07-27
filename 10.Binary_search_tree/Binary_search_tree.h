// 二叉排序树

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Binary_search_tree {
public:
	Binary_search_tree(int num) : num(num), left(nullptr), right(nullptr) { }
	Binary_search_tree() = default;
	// 插入
	void insert(int, Binary_search_tree*& node);
	// 删除
	void remove(int, Binary_search_tree*& node);
	// 中序遍历
	void inorder_traversal(void);
	// 查找节点
	Binary_search_tree* find_node(int);
	// 找左子树最大值
	Binary_search_tree* left_max(Binary_search_tree*);

private:
	// 数据
	int num;
	// 左孩子
	Binary_search_tree* left;
	// 右孩子
	Binary_search_tree* right;
	// 查找节点
};

#endif