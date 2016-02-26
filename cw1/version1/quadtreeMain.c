#include <stdio.h>
#include "quadtree.h"
#include "quadtreeFunctions.h"

int main(int argc, char **argv)
{
	//create the headnode at level 0
	Node *head = makeNode(0.0, 0.0, 0);
	LNode *leafHead = createEmptyNode();
	LNode *leafList = NULL;

	//split to level 1
	makeChildren(head);

	//split one node to l5evel 2
	makeChildren(head->child[0]);
	makeChildren(head->child[2]);
	scanForLeaves(leafHead,head);
	printf("SCANNED FOR LEAVES\n");
	leafList = leafHead->nextLeaf;
	printf("SET IT TO NEXT LEAF\n");
	writeLeaves(leafList);
	printf("WRITING LEAVES\n");
	//writeTree(head);
	//destroyNode(head);
	//writeTree(head);
	
	//destroyNode(head);
	printf("Process Completed\n");
	return(0);
}

