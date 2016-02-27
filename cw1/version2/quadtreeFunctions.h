QuadtreeNode *makeNode(double x, double y, int level);
void makeChildren(QuadtreeNode *parent);
void printOut( FILE *fp, QuadtreeNode *node );
void writeNode(FILE *fp, QuadtreeNode *node);
void writeTree(QuadtreeNode *head);
void destroyNode(QuadtreeNode *node);
LinkedListNode *createFilledNode(QuadtreeNode *leaf);
void addNode(LinkedListNode *listNode, QuadtreeNode *quadNode);
LinkedListNode *createEmptyNode();
void enterForList(LinkedListNode **node, QuadtreeNode *quadnode);
void scanForLeaves(LinkedListNode *listNode, QuadtreeNode *node);
void writeLeaves();








