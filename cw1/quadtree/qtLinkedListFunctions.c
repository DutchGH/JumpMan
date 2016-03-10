#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "quadtree.h"
#include "qtLinkedList.h"
#include "valueTree.h"

LinkedListNode *leafHead = NULL;
void splitDecision(QuadtreeNode *head, double tolerance, int choice)
{//splitDecision
	int falseCounter;
	LinkedListNode *walkNode; //set a walknode for the linked list
	walkNode = leafHead; //set it to the leaf of the list so it can bein walking
	bool loop = true; //set a boolean to stop the loop when required
	while(loop == true)
	{//while loop = true
		scanForLeaves(leafHead, head); //scan for the leaves at the start of the loop
		falseCounter = 0; //start the false counter at 0
		while(walkNode->nextLeaf!=NULL)
		{//while nextleaf != NULL
			if(indicator(walkNode->node, tolerance, choice) == false)
			{
				makeChildren(walkNode->node); //make children 
				++falseCounter; //increment the false counter 
				//printf("false counter at: %d\n", falseCounter);
			}
			walkNode = walkNode->nextLeaf; //move to the next leaf
		}//while nextleaf !=NULL
		if(falseCounter == 0) //if it goes back to 0
		{
			loop = false; //end the loop when the falsecounter returns to 0
		}
	}//while loop = true
}//splitDecision


void enterForList(LinkedListNode **node, QuadtreeNode *quadnode)
{
	if ((*node) == NULL)//if we have readched the bottom of the tree...
	{//if *node == NULL
		(*node) = malloc(sizeof(quadnode));
		if ((*node) == NULL)
		{//if *node IS STILL EMPTY
			printf("Memory Error!\n");
			exit(8);
		}// if node is still empty
		(*node)->nextLeaf = NULL;
		(*node)->node = quadnode;
		
		//USE THIS TO TEST WHICH LEVEL THE GIVEN NODE IS PART OF.
		//printf("L(%d) ", (*node)->node->level);
		
		return;
	}// if *node == NULL
	enterForList(&(*node)->nextLeaf, quadnode); //recursive function - go to next leaf
};
	
void scanForLeaves(LinkedListNode *listNode, QuadtreeNode *node)
{
	int leaf = 1;
	int i;
	while(1)
	{
		for (i = 0; i < 4; ++i)
		{
			if (node->child[i] == NULL) //if the node is empty
			{
				continue;
			}
			else //if node is not empty
			{
				leaf = 0;
				//printf("scanning for leaves\n");
				scanForLeaves(listNode, node->child[i]); //search its children.
			}
		}
		if (leaf == 1)
		{
			enterForList(&leafHead, node); //enter the leaves into the linked list 
		}
		return;
	}
	
}


void writeLeaves()
{
	FILE *fp = fopen("quad.out", "w");
	//printf("File opened\n");
	LinkedListNode *temp; //make a temporary pointer
	//printf("Temp allocated\n");  
	temp = leafHead; //set temp pointer to leafHead, so printing process will start 
	//printf ("temp assigned\n");
	while(temp) //while there are leaves in the list
	{
		printOut(fp, temp->node);
		//printf("added Node\n"); 
		//fflush(stdout);
		temp = temp->nextLeaf;//move to next leaf in list.
	}
	fclose(fp);
}

void makeChildrenFromLeaves(QuadtreeNode *head)
{
	LinkedListNode *lNode; //create a node to traverse through
	lNode = leafHead; //start at the head
	while(lNode) //while a node exists
	{
		makeChildren(lNode->node); //make children for that node
		lNode = lNode->nextLeaf; //move to the next leaf
	}
	enterForList(&leafHead, head);
	scanForLeaves(leafHead,head); //scan for leaves when this is done.
}
