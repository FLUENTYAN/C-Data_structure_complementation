#include <iostream>
#include "adjacency_list.h"

// 遍历输出
void adjacency_list::traverse(void) {
	for (const auto& p : graph) {
		std::cout << p.val;
		auto temp = p.adj;
		while (temp != nullptr) {
			std::cout << " has adjacecnt vertex " << temp->val
					  << " of weight " << temp->weight << "   ";
			temp = temp->adj;
		}
		std::cout << std::endl;
	}
}