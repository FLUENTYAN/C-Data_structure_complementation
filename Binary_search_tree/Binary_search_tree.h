// 二叉排序树

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Binary_search_tree {
public:
	Binary_search_tree(int num) : num(num), left(nullptr), right(nullptr) {
		root = this;
	}
	Binary_search_tree() = default;
	// 插入
	void insert(int, Binary_search_tree* node = root);
	// 删除
	void remove(int, Binary_search_tree* node = root);
	// 中序遍历
	void inorder_traversal(Binary_search_tree* node = root);
	// 找前一个节点
	Binary_search_tree* prev(int, Binary_search_tree* node = root);

private:
	// 数据
	int num;
	// 左孩子
	Binary_search_tree* left;
	// 右孩子
	Binary_search_tree* right;
	// 指根节点的指针
	static Binary_search_tree* root;
};

#endif