#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "quadtree.h"

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
	if (node->child[0] == NULL)//if the child of the node is empty
	{
		printOut(fp, node); //print out the parent
	}
	else
	{
		for (i = 0; i < 4; ++i)
		{
			//recurse through its children and find the leaves
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




