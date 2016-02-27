typedef struct qnode
{
	int level;
	double xy[2];
	struct qnode *child[4];
	struct qnode *nextNode;
}QuadtreeNode;
extern QuadtreeNode *head;

QuadtreeNode *makeNode(double x, double y, int level);
void makeChildren(QuadtreeNode *parent);
void printOut( FILE *fp, QuadtreeNode *node );
void writeNode(FILE *fp, QuadtreeNode *node);
void writeTree(QuadtreeNode *head);
void destroyNode(QuadtreeNode *node);
