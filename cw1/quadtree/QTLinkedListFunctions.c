#include<stdio.h>
#include<stdlib.h>
#include "quadtree.h"
#include "QTLinkedList.h"

LinkedListNode *leafHead = NULL;

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
		//printf("New node created\n");
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
			if (node->child[i] == NULL)
			{
				continue;
			}
			else
			{
				leaf = 0;
				//printf("scanning for leaves\n");
				scanForLeaves(listNode, node->child[i]);
			}
		}
		if (leaf == 1)
		{
			enterForList(&leafHead, node);
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
	LinkedListNode *lNode;
	lNode = leafHead;
	while(lNode)
	{
		makeChildren(lNode->node);
		lNode = lNode->nextLeaf;
	}
	scanForLeaves(leafHead,head);
}
