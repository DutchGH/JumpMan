typedef struct node
{
	int level;
	double xy[2];
	struct node *child[4];
	struct node *leafHead;
	struct node *nextLeaf;
}Node;



Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent);
void printOut( FILE *fp, Node *qnode );
void writeNode(FILE *fp, Node *qnode);
void writeTree(Node *head);
void destroyNode(Node *qnode);

//void enterForList(Quadtree **leaf, Node *qnode);
//void scanForLeaves(Quadtree *leafNode, Node *qnode);
//~ void writeLeaves();
//~ void makeChildrenFromLeaves(Node *head);
//~ void deleteNode(LinkedListNode *linkedNode);
