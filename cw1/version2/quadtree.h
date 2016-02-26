typedef struct qnode
{
	int level;
	double xy[2];
	struct qnode *child[4];
	//struct qnode *nextLeaf;
}QuadtreeNode;
extern QuadtreeNode *head;

typedef struct lnode
{
	struct qnode *node;
	struct lnode *nextLeaf;
}LinkedListNode;
extern LinkedListNode *leafHead;
