#include "adjacency_matrix.h"

int main(void) {
	// { �ڵ㣬{{��ָ�ڵ㣬Ȩ��}}��{{��ָ�ڵ㣬Ȩ��}} ... }
	auto graph = new adjacency_matrix({ { 2, {{4, 1}, {5, 4}, {6, 1}} },
										{ 4, {{3, 1}}	  			   },
										{ 3, {{6, 2}}		  		   },
										{ 6, {{5, 3}}				   }, 
										{ 5, {{4, 2}, {3, 3}}		   }  });
	graph->traverse();
	return 0;
}