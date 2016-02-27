#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "quadtree.h"

LinkedListNode *leafHead = NULL;
//LNode *leafHead = createBlankNode();
QuadtreeNode *makeNode(double x, double y, int level)
{
	int i; //Integer used for looping
	//allocate the data structure
	QuadtreeNode *node = (QuadtreeNode *)malloc(sizeof(QuadtreeNode));

	//set the node data
	node->level = level;
	node->xy[0] = x;
	node->xy[1] = y;

	for (i = 0; i < 4; ++i)
		node->child[i] = NULL;

	return node;
}

void makeChildren(QuadtreeNode *parent)
{
	//parent data 
	double x = parent->xy[0];
	double y = parent->xy[1];
	int level = parent->level;

	//child edge length
	double hChild = pow(2.0, -(level + 1));

	//create children at the next level
	parent->child[0] = makeNode(x, y, (level + 1));
	parent->child[1] = makeNode(x + hChild, y, level + 1);
	parent->child[2] = makeNode(x + hChild, y + hChild, level + 1);
	parent->child[3] = makeNode(x, y + hChild, level + 1);

	return;
}

void printOut( FILE *fp, QuadtreeNode *node ) {

  // node data
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

void writeNode(FILE *fp, QuadtreeNode *node)
{
	int i;
	if (node->child[0] == NULL)
	{
		printOut(fp, node);
	}
	else
	{
		for (i = 0; i < 4; ++i)
		{
			writeNode(fp, node->child[i]);
		}
	}
}

void writeTree(QuadtreeNode *head)
{
	FILE *fp = fopen("quad.out", "w");
	writeNode(fp, head);
	fclose(fp);
	return;
}

void destroyNode(QuadtreeNode *node)
{
	int i;
	if (node->child[0] == NULL)
	{
		free(node);
	}
	else
	{
		for (i = 0; i < 4; ++i)
		{
			destroyNode(node->child[i]);
		}
	}
}

void enterForList(LinkedListNode **node, QuadtreeNode *quadnode)
{
	int result; //result of string comparison
	//char *add_node(char *);

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
	enterForList(&(*node)->nextLeaf, quadnode); //stick it in the right tree if its a "greater value"
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


void writeLeaves(/*LinkedListNode *leafHead*/)
{
	FILE *fp = fopen("quad.out", "w");
	//printf("File opened\n");
	LinkedListNode *temp; //make a temporary pointer
	//printf("Temp allocated\n");  
	temp = leafHead; //set temp pointer will head of documet, so printing process will start 
	//printf ("temp assigned\n");
	while(temp) //while there are words in the list
	{
		printOut(fp, temp->node);
		//printf("added Node\n"); //print that word and its # of occurence
		//fflush(stdout);
		temp = temp->nextLeaf;//move to next word in list.
	}
	fclose(fp);
}


