//structure for link list node
struct node
{
	int data;
	struct node *next;
};

//structure for doubly linked list node
struct DLNode
{
	int data;
	struct DLNode *next;
	struct DLNode *prev;
};

//structure for stack
struct stackNode
{
    int data;
    struct sNode *next;
};

//structure for queue
struct queue
{
    struct stackNode *stack1;
    struct stackNode *stack2;
};

//structure for tree

//structure for map

//structure for 