#include <stdio.h>
#include "quadtree.h"
#include "QTLinkedList.h"

int main(int argc, char **argv)
{
	int i;
	//create the headnode at level 0
	QuadtreeNode *head = makeNode(0.0, 0.0, 0);

	//split to level 1
	makeChildren(head);

	//split one node to level 2
	makeChildren(head->child[0]);
	//split another node to level 2
	makeChildren(head->child[2]);
	
	//Scan tree for leaves
	scanForLeaves(leafHead,head);
	//printf("SCANNED FOR LEAVES\n");
	
	//split all leaves in quadtree to another level
	makeChildrenFromLeaves(head);
	
	//write those leaves so they can be plotted on a grid.
	writeLeaves(leafHead);
	
	/* TEST FUNCTIONS FROM EARLIER VERSIONS*/
	//printf("SET IT TO NEXT LEAF\n");
	//printf("WRITING LEAVES\n");
	
	//writeTree(head);
	//destroyNode(head);
	//writeTree(head);
	
	printf("Process Completed\n");
	return(0);
}
