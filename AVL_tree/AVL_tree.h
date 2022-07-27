// 二叉平衡树

#ifndef AVL_TREE_H
#define AVL_TREE_H

class AVL_tree {
public:
	AVL_tree() = default;
	AVL_tree(int num) 
		: value(num), left(nullptr), right(nullptr), height(0) { }
	
	// 插入节点
	void insert(AVL_tree*&, int);
	// 删除节点
	void remove(AVL_tree*&, int);
	// 插入失衡调整
	void insert_balance(AVL_tree*&, int);
	// 删除失衡调整
	void remove_balance(AVL_tree*&);
	// 右旋
	AVL_tree* right_rotation(AVL_tree*);
	// 左旋
	AVL_tree* left_rotation(AVL_tree*);
	// 中序遍历输出
	void inorder_traversal(void);
	// 返回高度
	int Height(AVL_tree*);
	// 查找节点
	AVL_tree* find_node(int);
	// 找左子树最大值
	AVL_tree* left_max(AVL_tree*);

private:
	// 数据
	int value;
	// 左节点
	AVL_tree* left;
	// 右节点
	AVL_tree* right;
	// 高度
	int height;
};

#endif