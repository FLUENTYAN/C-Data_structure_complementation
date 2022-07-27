// 用孩子和兄弟表示树

#ifndef CHILD_BRO_TREE_H
#define CHILD_BRO_TREE_H

class child_bro_tree {
public:
	child_bro_tree() = default;
	child_bro_tree(int num) : num(num), child(nullptr), bro(nullptr) { }
	// 插入孩子
	void insert(int);
	// 遍历
	void traversal(void);
	
private:
	// 数据
	int num;
public:
	// 孩子
	child_bro_tree* child;
	// 兄弟
	child_bro_tree* bro;
	
};

#endif