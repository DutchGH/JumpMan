#include <stdio.h>
#include "quadtree.h"
#include "quadtreeFunctions.h"

int main(int argc, char **argv)
{
	//create the headnode at level 0
	Node *head = makeNode(0.0, 0.0, 0);
	//LNode *leafHead = NULL;
	
	//split to level 1
	makeChildren(head);

	//split one node to level 2
	makeChildren(head->child[0]);
	makeChildren(head->child[2]);
	scanForLeaves(head);
	writeLeaves(leafHead);
	//writeTree(head);
	//destroyNode(head);
	//writeTree(head);
	
	//destroyNode(head);
	printf("Process Completed\n");
	return(0);
}

