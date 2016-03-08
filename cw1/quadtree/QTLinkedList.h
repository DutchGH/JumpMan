typedef struct lnode
{
	struct qnode *node;
	struct lnode *nextLeaf;
}LinkedListNode;
extern LinkedListNode *leafHead;

void enterForList(LinkedListNode **node, Node *quadnode);
void scanForLeaves(LinkedListNode *listNode, Node *node);
void writeLeaves();
void makeChildrenFromLeaves(Node *head);
void deleteNode(LinkedListNode *linkedNode);

