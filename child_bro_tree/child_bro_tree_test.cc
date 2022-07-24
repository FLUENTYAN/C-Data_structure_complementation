#include "child_bro_tree.h"

int main(void) {
	auto tree = new child_bro_tree(0);

	/*		所构建的树
	第一层：			0
			   	   /
	第二层：		  1——2——3
			  	    /
	第三层：		   4——5				
	*/
	tree->insert(1);
	tree->insert(3);
	tree->insert(2);
	tree->child->bro->insert(4);
	tree->child->bro->insert(5);

	/* 5 4 3 2 1 0*/
	tree->traversal();
}