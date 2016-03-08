#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include  "quadtree.h"
#include  "QTLinkedList.h"
#include  "valueTree.h"

#define MAX(a,b) ( ((a)>(b)) ? (a):(b) )
#define MIN(a,b) ( ((a)<(b)) ? (a):(b) )

// Define a function that is computed
// on the quadtree grid
//
// Given a location (x,y) return a value
//
// Choice allows different functions  
// to be selected

double dataFunction( double x, double y, int choice ){
  double value;

  if( choice == 0 )
    value = exp(-(y-x)*(y-x)/0.01) + exp(-(x-y)*(x-y)/0.01);

  else if( choice == 1 )
    value = exp(-(x-0.5)*(x-0.5)/0.01) + exp(-(y-0.5)*(y-0.5)/0.01);

  else if( choice == 2 )
    value = exp(-((x-0.72)*(x-0.72)+(y-0.23)*(y-0.23))/0.01);

  // default uniform data
  else
    value = 1.0;
    
  return value;
}

// Compute the max and min values 
// of the data on the quadtree node 
//
// If the difference is too big request 
// the node is split into children

bool indicator( QuadtreeNode *node, double tolerance, int choice ) {

  double v[4],vmin,vmax;
  double h = pow(2,-node->level);

  v[0] = dataFunction(node->xy[0],node->xy[1], choice);
  v[1] = dataFunction(h+node->xy[0],node->xy[1], choice);
  v[2] = dataFunction(node->xy[0],h+node->xy[1], choice);
  v[3] = dataFunction(h+node->xy[0],h+node->xy[1], choice);

  vmin = MIN( MIN( MIN(v[0],v[1]), v[2]), v[3]); 
  vmax = MAX( MAX( MAX(v[0],v[1]), v[2]), v[3]); 

  if( (vmax-vmin) < tolerance )
    return true;
  else
    return false;
}

int splitDecision(QuadtreeNode *head, double tolerance, int choice)
{
	int falseCounter = 0;
	LinkedListNode *walkNode;
	walkNode = leafHead;
	while(walkNode!=NULL)
	{
		if(indicator(walkNode->node, tolerance, choice) == false)
		{
			makeChildren(walkNode->node);
			++falseCounter;
			printf("false counter at: %d\n", falseCounter);
		}
		walkNode = walkNode->nextLeaf;
	}
	if(falseCounter != 0)
	{
		scanForLeaves(leafHead, head);
		splitDecision(head, tolerance, choice);
	}


}

void splitDecisionControl(QuadtreeNode *head, double tolerance, int choice)
{
	int falseNotifier = 0;
	LinkedListNode *walkNode;
	QuadtreeNode *temp;
	walkNode = leafHead;
	while(falseNotifier == 0)
	{
		int falseCounter = 0;
		for(walkNode->node; walkNode!=NULL; walkNode = walkNode->nextLeaf)
		{
			if (indicator(walkNode->node, tolerance, choice) == false)
			{
				makeChildren(walkNode->node);
				falseCounter++;
				printf ("%d\n", falseCounter);
			}
		}
		if (falseCounter == 0)
		{
			falseNotifier = 1;
		}
		deleteNode(walkNode);
		scanForLeaves(leafHead,head);
		splitDecisionControl(head, tolerance, choice);
	}
		

}


	
	

