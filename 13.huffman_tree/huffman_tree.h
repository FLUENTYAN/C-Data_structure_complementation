// 哈夫曼树

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include <map>
#include <vector>
#include <algorithm>

struct node {
	node() = default;
	node(char c, int num, node* p1, node* p2) 
	: character(c), weight(num), left(p1), right(p2), father(nullptr) { }
	// 符号
	char character;
	// 权重	
	int weight;
	// 左子树
	node* left;
	// 右子树
	node* right;
	// 父节点
	node* father;
};

class huffman_tree {
public:
	huffman_tree() = default;
	huffman_tree(std::map<char, int> pair) {
		int i = 0;
		for (auto p : pair) {
			tree.emplace_back(p.first, p.second, nullptr, nullptr);
			++i;
			std::sort(tree.begin(), tree.end(), [](const node& n1, const node& n2) { return n1.weight > n2.weight; });
		}

	}
	~huffman_tree() = default;
	// 建立哈夫曼树
	std::vector<node*> make_tree(void);
	// 获取哈夫曼编码
	void get_code(std::vector<node*>);

private:
	std::vector<node> tree;
};

#endif