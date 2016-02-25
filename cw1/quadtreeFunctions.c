#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "quadtree.h"

Node *makeNode(double x, double y, int level)
{
	int i; //Integer used for looping
	//allocate the data structure
	Node *node = (Node *)malloc(sizeof(Node));

	//set the node data
	node->level = level;
	node->xy[0] = x;
	node->xy[1] = y;

	for (i = 0; i < 4; ++i)
		node->child[i] = NULL;

	return node;
}

Node *head = NULL;

void makeChildren(Node *parent)
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


void printOut( FILE *fp, Node *node ) {

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

void writeNode(FILE *fp, Node *node)
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

LNode *leafHead = NULL;

	
void writeTree(Node *head)
{
	FILE *fp = fopen("quad.out", "w");
	writeNode(fp, head);
	fclose(fp);
	return;
}

void destroyNode(Node *node)
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

LNode *createFilledNode(Node *leaf)
{
	LNode *newLeaf = (LNode *) malloc(sizeof(LNode));
	
	newLeaf->node = leaf;
	newLeaf->nextLeaf = NULL;
	printf("Done\n");
	
	return newLeaf;
}
	
void scanForLeaves(Node *node)
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
				scanForLeaves(node->child[i]);
			}
		}
		if (leaf == 1)
		{
			createFilledNode(node);
		}
		return;
	}
	
}


void writeLeaves(LNode *leafList)
{
	FILE *fp = fopen("quad.out", "w");
	LNode *walkNode;
	walkNode = leafList;
		printf("printed\n");
		fflush(stdout);
		
	while(walkNode!=NULL)
    {
    printOut(fp, walkNode->node);
    printf("added node\n");
    walkNode=walkNode->nextLeaf;
    }

	fclose(fp);
	return;
}


