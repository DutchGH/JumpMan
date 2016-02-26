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

LinkedListNode *createFilledNode(QuadtreeNode *leaf)
{
	LinkedListNode *newLeaf = (LinkedListNode *) malloc(sizeof(LinkedListNode));
	
	newLeaf->node = leaf;
	newLeaf->nextLeaf = NULL;
	//printf("Node Created\n");
	
	return newLeaf;
}

//~ void addNode(LinkedListNode *listNode, QuadtreeNode *quadNode)
//~ {
	//~ LinkedListNode *newNode = createFilledNode(quadNode);
	//~ while(1)
	//~ {
		//~ if(listNode->nextLeaf == NULL)
		//~ {
			//~ listNode->nextLeaf = newNode;
			//~ return;
		//~ }
		//~ else
		//~ {
			//~ listNode = listNode->nextLeaf;
		//~ }
	//~ }
//~ }
	

//~ LNode *createEmptyNode()
//~ {
	//~ LinkedListNode *newLeaf = (LNode *) malloc(sizeof(LNode));
	
	//~ newLeaf->node = NULL;
	//~ newLeaf->nextLeaf = NULL;
	//~ printf("Blank Node Created\n");
	
	//~ return newLeaf;
//~ }

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
				printf("scanning for leaves\n");
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
	printf("File opened\n");
	LinkedListNode *temp; //make a temporary pointer
	printf("Temp allocated\n");  
	temp = leafHead; //set temp pointer will head of documet, so printing process will start 
	printf ("temp assigned\n");
	while(temp) //while there are words in the list
	{
		printOut(fp, temp->node);
		printf("added Node\n"); //print that word and its # of occurence
		fflush(stdout);
		temp = temp->nextLeaf;//move to next word in list.
	}
	fclose(fp);
}




//~ void scan_for_list(QuadtreeNode *node)
//~ { //void scan
	//~ char word[200]; //current word being looked at
	//~ int index; //word index
	//~ int current_character; //current_character being looked at
	//~ FILE *in_file; //input file (argv[1] in this case)

	//~ in_file = fopen(file, "r"); //open file in read mode
	//~ if(in_file == NULL) //if file is empty/doesn't exist
	//~ {//if in_file == NULL
		//~ printf("ERROR, UNABLE TO OPEN %s\n", file); //DECLARE AN ERROR
		//~ exit(1); //exit the program
	//~ }//if in_file == NULL

	//~ while(1)
	//~ {//while(1)
		//~ while(1)
		//~ { //while(1)
			//~ current_character = fgetc(in_file); //use fgetc to scan through each character
			//~ if (current_character>64 && current_character<91)
            //~ {
                //~ current_character = (current_character+32);
                //~ break;
            //~ }
			//~ if (isalpha(current_character) || (current_character == EOF)) //if the character is in the alphabet and at the end of the file.
			//~ {
				//~ break; //break the loop
			//~ }
		//~ } //while(1)

			//~ if(current_character == EOF) //once you have reached the end of the file
			//~ {
				//~ break; //break the loop
			//~ }

			//~ word[0] = current_character;
			//~ for(index = 1; index<sizeof(word); index++) //loop through the word
			//~ { //for index
				//~ current_character = fgetc(in_file);
				//~ if (current_character == 39)
				//~ {
					//~ word[index] = current_character;
				//~ }
				//~ else if(!isalpha(current_character)) //the character is a symbol
				//~ {
					//~ break; //break the loop
				//~ }
				//~ if (current_character > 64  && current_character < 91) //if the character is uppercase
					//~ {
						//~ word[index] = (current_character+32); //shift everything to lowercase and add to index
					//~ }
				//~ else
				//~ {
					//~ word[index] = current_character; //add the word to the index
				//~ }
			//~ }
			
			//~ if(!isalpha(word[index-1])) //if the last word is not a character 
			//~ {
				//~ word[index-1] = '\0'; //replace that character to NULL
				//~ enter_for_list(&head,word); //add word to list
			//~ }
			//~ else
			//~ {
				//~ word[index] = '\0'; //add a null terminator to the end of the index
				//~ enter_for_list(&head, word); //enter the word into the list
			//~ }

	//~ }//while(1)
	//~ fclose(in_file); //close the file
//~ }; //void scan


