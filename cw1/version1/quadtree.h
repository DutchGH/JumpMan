typedef struct qnode
{
	int level;
	double xy[2];
	struct qnode *child[4];
	//struct qnode *nextLeaf;
}Node;
extern Node *head;

typedef struct lnode
{
	struct qnode *node;
	struct lnode *nextLeaf;
}LNode;
extern LNode *leafHead;
