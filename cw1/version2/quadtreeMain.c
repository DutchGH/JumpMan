#include <stdio.h>
#include "quadtree.h"
#include "quadtreeFunctions.h"

int main(int argc, char **argv)
{
	int i;
	//create the headnode at level 0
	QuadtreeNode *head = makeNode(0.0, 0.0, 0);

	//split to level 1
	makeChildren(head);

	//split one node to level 2
	makeChildren(head->child[0]);
	//makeChildren(head->child[1]);
	makeChildren(head->child[2]);
	//makeChildren(head->child[3]);
	scanForLeaves(leafHead,head);
	//printf("SCANNED FOR LEAVES\n");
	LinkedListNode *lNode;
	lNode = leafHead;
	while(lNode)
	{
		makeChildren(lNode->node);
		lNode = lNode->nextLeaf;
	}
	scanForLeaves(leafHead,head);
	writeLeaves(leafHead);
	//printf("SET IT TO NEXT LEAF\n");
	//printf("WRITING LEAVES\n");
	//writeTree(head);
	//destroyNode(head);
	//writeTree(head);
	
	printf("Process Completed\n");
	return(0);
}

