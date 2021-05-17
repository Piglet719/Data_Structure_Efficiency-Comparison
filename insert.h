#define TEST_DATA_CNT 1000000

//bst
struct tNode{
    int key;
    struct tNode *Lchild, *Rchild;
};

struct tNode *BST_insert(struct tNode *T, int key);

//bs
int compare(const void *a, const void *b);
void BS_insert(int *insert_data, int N);

//arr
void ARR_insert(int *arr, int *insert_data, int N);

//ll
struct lnode{
    int key;
    struct lnode *next;
};

struct lnode *LL_insert(struct lnode *L, int key);

//hash_ll
struct dNode
{
    int key;
    struct dNode *next;
};
struct dNode *chain[TEST_DATA_CNT];

void init(int N);
void Hashll_insert(int key, int size);

//hash
struct dNode2{
   int key;
};
struct hashtable{
   struct dNode2 *item;
};
struct hashtable *arr;

void Hash_insert(int key, int size);