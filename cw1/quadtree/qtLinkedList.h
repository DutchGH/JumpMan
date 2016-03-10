typedef struct lnode
{
	struct qnode *node;
	struct lnode *nextLeaf;
}LinkedListNode;
extern LinkedListNode *leafHead;

void splitDecision(QuadtreeNode *head, double tolerance, int choice);
void enterForList(LinkedListNode **node, QuadtreeNode *quadnode);
void scanForLeaves(LinkedListNode *listNode, QuadtreeNode *node);
void writeLeaves();
void makeChildrenFromLeaves(QuadtreeNode *head);
