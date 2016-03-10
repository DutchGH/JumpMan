#include <stdio.h>
#include <stdbool.h>
#include "quadtree.h"
#include "qtLinkedList.h"
#include "valueTree.h"

int main(int argc, char **argv)
{
	//create the headnode at level 0
	QuadtreeNode *head = makeNode(0.0, 0.0, 0);

	//split to level 1
	makeChildren(head);

	//split one node to level 2
	makeChildren(head->child[0]);
	
	//split another node to level 2
	//makeChildren(head->child[2]);
	
	//Scan tree for leaves
	scanForLeaves(leafHead,head);
	//printf("SCANNED FOR LEAVES\n");
	
	//split all leaves in quadtree to another level
	makeChildrenFromLeaves(head);
	//scanForLeaves(leafHead,head);
	//makeChildrenFromLeaves(head);
	//scanForLeaves(leafHead,head);
	
	//Go through the leaf nodes and decide whether they should be split
	splitDecision(head, 0.4, 0);

	//write those leaves so they can be plotted on a grid.
	writeLeaves(leafHead);
	
	/* TEST FUNCTIONS FROM EARLIER VERSIONS*/
	//printf("SET IT TO NEXT LEAF\n");
	//printf("WRITING LEAVES\n");
	
	//writeTree(head);
	
	//clear the tree from memory now that the leaves have been written
	destroyNode(head);
	//writeTree(head);
	
	printf("Process Completed\n");
	return(0);
}

