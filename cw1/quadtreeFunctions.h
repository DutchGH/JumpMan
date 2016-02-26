Node *makenode(double x, double y, int level);
void makeChildren(Node *parent);
void printOut( FILE *fp, Node *node );
void writeNode(FILE *fp, Node *node);
void writeTree(Node *head);
void destroyNode(Node *node);
LNode *createFilledNode(Node *leaf);
void addNode(LNode *listNode, Node *quadNode);
LNode *createEmptyNode();
void scanForLeaves(LNode *listNode, Node *node);
void writeLeaves(LNode *leafHead);








