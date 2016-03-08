#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "quadtree.h"

Node *makeNode(double x, double y, int level)
{
	int i; //Integer used for looping
	//allocate the data structure
	Node *qnode = (Node *)malloc(sizeof(Node));

	//set the node data
	qnode->level = level;
	qnode->xy[0] = x;
	qnode->xy[1] = y;

	for (i = 0; i < 4; ++i)
		qnode->child[i] = NULL;

	return qnode;
}

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

void printOut( FILE *fp, Node *qnode ) {

  // node data
  double x = qnode->xy[0];
  double y = qnode->xy[1];
  int level = qnode->level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

void writeNode(FILE *fp, Node *qnode)
{
	int i;
	if (qnode->child[0] == NULL)
	{
		printOut(fp, qnode);
	}
	else
	{
		for (i = 0; i < 4; ++i)
		{
			writeNode(fp, qnode->child[i]);
		}
	}
}

void writeTree(Node *head)
{
	FILE *fp = fopen("quad.out", "w");
	writeNode(fp, head);
	fclose(fp);
	return;
}

void destroyNode(Node *qnode)
{
	int i;
	if (qnode->child[0] == NULL)
	{
		free(qnode);
	}
	else
	{
		for (i = 0; i < 4; ++i)
		{
			destroyNode(qnode->child[i]);
		}
	}
}
/*--------------------------------LINKED LIST FUNCTIONS-----------------------------*/

//quadtreeGrid *firstLeaf = NULL;

//~ void enterForList(Quadtree**leaf, Node *qnode)
//~ {
	//~ if ((*leaf) == NULL)//if we have readched the bottom of the tree...
	//~ {//if *node == NULL
		//~ (*leaf) = malloc(sizeof(qnode));
		//~ if ((*leaf) == NULL)
		//~ {//if *node IS STILL EMPTY
			//~ printf("Memory Error!\n");
			//~ exit(8);
		//~ }// if node is still empty
		//~ (*leaf)->nextLeaf = NULL;
		//~ (*leaf)->currentLeaf = qnode;
		//~ //printf("New node created\n");
		//~ return;
	//~ }// if *node == NULL
	//~ enterForList(&(*leaf)->nextLeaf, qnode); //recursive function - go to next leaf
//~ };
	
//~ void scanForLeaves(Quadtree *listNode, Node *qnode)
//~ {
	//~ int leaf = 1;
	//~ int i;
	//~ while(1)
	//~ {
		//~ for (i = 0; i < 4; ++i)
		//~ {
			//~ if (qnode->child[i] == NULL) //if the node is empty
			//~ {
				//~ continue;
			//~ }
			//~ else //if node is not empty
			//~ {
				//~ leaf = 0;
				//~ //printf("scanning for leaves\n");
				//~ scanForLeaves(leaf, qnode->child[i]); //search its children.
			//~ }
		//~ }
		//~ if (leaf == 1)
		//~ {
			//~ enterForList(&firstLeaf, qnode); //enter the leaves into the linked list 
		//~ }
		//~ return;
	//~ }
	
//~ }

//~ void writeLeaves()
//~ {
	//~ FILE *fp = fopen("quad.out", "w");
	//~ //printf("File opened\n");
	//~ quadtreeGrid *temp; //make a temporary pointer
	//~ //printf("Temp allocated\n");  
	//~ temp = firstLeaf; //set temp pointer to leafHead, so printing process will start 
	//~ //printf ("temp assigned\n");
	//~ while(temp) //while there are leaves in the list
	//~ {
		//~ printOut(fp, temp->currentLeaf);
		//~ //printf("added Node\n"); 
		//~ //fflush(stdout);
		//~ temp = temp->nextLeaf;//move to next leaf in list.
	//~ }
	//~ fclose(fp);
//~ }

//~ void makeChildrenFromLeaves(Node *head)
//~ {
	//~ LinkedListNode *lNode; //create a node to traverse through
	//~ lNode = leafHead; //start at the head
	//~ while(lNode) //while a node exists
	//~ {
		//~ makeChildren(lNode->node); //make children for that node
		//~ lNode = lNode->nextLeaf; //move to the next leaf
	//~ }
	//~ enterForList(&leafHead, head);
	//~ scanForLeaves(leafHead,head); //scan for leaves when this is done.
//~ }

//~ void deleteNode(LinkedListNode *linkedNode)
//~ {
	//~ free(linkedNode->node);
	//~ free(linkedNode);
//~ }




