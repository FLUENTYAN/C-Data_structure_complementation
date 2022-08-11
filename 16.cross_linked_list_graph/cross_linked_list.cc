#include <iostream>
#include <unordered_map>
#include "cross_linked_list.h"

cross_linked_list::cross_linked_list(std::unordered_map<int, std::vector<std::vector<int>>> map) {
	// 存储节点集合
	for (const auto& p : map) {
		auto temp = new vertices(p.first);
		graph.emplace_back(*temp);
	}
	// 合成指向的节点
	auto i = 0;
	for (const auto& p : map) {
		for (auto j = 0; j < (p.second).size(); ++j) {
			for (auto k = 0; k < graph.size(); ++k) {
				if ((p.second)[j][0] == graph[k].val) {
					auto temp = new adjvertex((p.second)[j][1], k, i, graph[i].out);
					graph[i].out = temp;						
				}
			}
		}
		++i;
	}
	// 合成指向该节点的节点
	for (auto i = 0; i < graph.size(); ++i) {
		for (auto j = 0; j < graph.size(); ++j) {
			auto temp = graph[j].out;
			while (temp != nullptr) {
				if (temp->indThis == i) {
					temp->in = graph[i].in;
					graph[i].in = temp;
				}
				temp = temp->out;
			}
		}
	}
}
// 遍历输出
void cross_linked_list::traverse(void) {
    for (const auto& p : graph) {
        std::cout << p.val << " has out adjacecnt vertex ";
        auto out = p.out;
        while (out != nullptr) {
            std::cout << graph[out->indThis].val
                      << " of weight " << out->weight << "   ";
			out = out->out;
        }
        std::cout << std::endl;
    }
	std::cout << std::endl;
	for (const auto& p : graph) {
		std::cout << p.val << " has in adjacecnt vertex ";
		auto in = p.in;
		while (in != nullptr) {
			std::cout << graph[in->ind].val
				<< " of weight " << in->weight << "   ";
			in = in->in;
		}
		std::cout << std::endl;
	}
}