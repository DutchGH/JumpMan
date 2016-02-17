typedef struct qnode
{
	int level; //level of subtree
	double xy[2]; //bottom-left co-ordinates of quadtree
	struct qnode *child[4]; //Child nodes of quadtree
}Node;