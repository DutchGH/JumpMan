Node *makenode(double x, double y, int level);
void makeChildren(Node *parent);
void printOut( FILE *fp, Node *node );
void writeNode(FILE *fp, Node *node);
void writeTree(Node *head);
void destroyNode(Node *node);
LNode *createFilledNode(Node *leaf);
void scanForLeaves(Node *node);
void writeLeaves(LNode *leafList);







