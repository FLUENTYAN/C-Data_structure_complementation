#include "adjacency_matrix.h"

int main(void) {
	auto graph = new adjacency_matrix({ {0, {1, 2}}, 
										{1, {0, 3}}, 
										{2, {0, 3}}, 
										{3, {1, 2, 4}}, 
										{4, {3}}, });
	graph->traverse();
	return 0;
}