typedef struct node
{
	int level;
	double xy[2];
	struct node *child[4];
	struct node *currentLeaf;
	struct node *nextLeaf;
}Node;

Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent);
void printOut( FILE *fp, Node *qnode );
void writeNode(FILE *fp, Node *qnode);
void writeTree(Node *head);
void destroyTree(Node *qnode);

void enterForList(Node**leafHead, Node *qnode);
void scanForLeaves(Node *leafHead, Node *parent);
void writeLeaves(Node *leafHead);
void writeLeaf(FILE *fp, Node *node);
void writeAllLeaves(Node *headLeaf);




