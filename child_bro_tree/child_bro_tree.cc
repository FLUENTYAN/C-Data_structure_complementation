#include <iostream>
#include "child_bro_tree.h"

// 插入孩子
void child_bro_tree::insert(int num) {
	if (this->child == nullptr) { // 孩子指针为空，插入孩子处
		auto temp = new child_bro_tree(num);
		this->child = temp;
	} else  { // 否则插入兄弟处
		auto temp = new child_bro_tree(num);
		temp->bro = this->child->bro;
		this->child->bro = temp; 
	}
	
}
// 遍历
void child_bro_tree::traversal(void) {
	if (this->child != nullptr)
		this->child->traversal();
	if (this->bro != nullptr)
		this->bro->traversal();
	std::cout << this->num << " ";
}