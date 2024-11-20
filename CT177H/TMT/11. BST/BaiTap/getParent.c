#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{
    KeyType key;
    struct Node *left; // bên trái lun nhỏ hơn bên phải
    struct Node *right;
};
typedef struct Node *Tree;


// khoi tao rong
void makenull(Tree *pT)
{
    (*pT) = NULL;
}

int emptytree(Tree T)
{
    return T == NULL;
}



Tree leftChild(Tree n)
{
    if (n != NULL)
        return n->left;
    else
        return NULL;
}

Tree rightChild(Tree n)
{
    if (n != NULL)
        return n->right;
    else
        return NULL;
}

// check if a node a ledf or not
int isLeaf(Tree n)
{
    if (n != NULL)
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    else
        return 0;
}

void NLR(Tree root)
{
    if (root != NULL)
    {
        printf("%d ", root->key); // N
        NLR(root->left);          // L
        NLR(root->right);         // R
    }
}

void LNR(Tree root)
{
    if (root != NULL)
    {
        NLR(root->left);          // L
        printf("%d ", root->key); // N
        NLR(root->right);         // R
    }
}

void LRN(Tree root)
{
    if (root != NULL)
    {
        NLR(root->left);          // L
        NLR(root->right);         // R
        printf("%d ", root->key); // N
    }
}

// xác định số nút trong cây
int nb_nodes(Tree root)
{
    if (emptytree(root))
        // if(root != NULL)
        return 0;
    else
        return 1 + nb_nodes(leftChild(root)) + nb_nodes(rightChild(root));
}

int nb_leaf(Tree root)
{
    if (!emptytree(root))
    {
        return 1;
    }
    else
    {
        return nb_leaf(root->left) + nb_leaf(root->right);
    }
    return 0;
}

// cây tìm kiếm nhị phân 0(h) = chiều cao của cây
Tree Search(KeyType x, Tree Root)
{
    if (Root == NULL)
        return NULL;         // không tìm thấy x
    else if (Root->key == x) // tìm thấy khoá x
        return Root;
    else if (Root->key < x)
        return Search(x, Root->right);
    else
        return Search(x, Root->left);
}

void insertNode(KeyType x, Tree *pT)
{
    if ((*pT) == NULL)
    {
        (*pT) = (struct Node *)malloc(sizeof(struct Node));
        (*pT)->key = x;
        (*pT)->left = NULL;
        (*pT)->right = NULL;
    }
    else if (x < (*pT)->key)
        insertNode(x, &((*pT)->left));
    else if (x > (*pT)->key)
        insertNode(x, &((*pT)->right));
}

Tree readTree()
{
    Tree T;
    makenull(&T);
    int n;
    printf("nhap so luong: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        insertNode(x, &T);
    }
    return T;
}

KeyType deleteMin( Tree *pRoot){
    KeyType K;
    Tree temp;
    if((*pRoot) ->left == NULL){
        temp = (*pRoot);
        K = (*pRoot) -> key;
        (*pRoot) = (*pRoot) -> right;
        free(temp);
        return K;
    }
    else
        return deleteMin(&((*pRoot) -> left));
}

KeyType deleteMax( Tree *pRoot){
    KeyType K;
    Tree temp;
    if((*pRoot) ->right == NULL){
        temp = (*pRoot);
        K = (*pRoot) -> key;
        (*pRoot) = (*pRoot) -> left;
        free(temp);
        return K;
    }
    else
        return deleteMin(&((*pRoot) -> right));
}

void deleteNode(KeyType x, Tree *pRoot){
    Tree temp;
    if((*pRoot) != NULL){//Kiem tra cay khac rong
        if(x < (*pRoot) ->key)//Hy vong x nam ben trai cua nut
            deleteNode(x,&((*pRoot) -> left));
        else if(x > (*pRoot) -> key)//Hy vong x nam ben phai cua nut
            deleteNode(x,&((*pRoot) -> right));
        else{// Tim thay khoa x x==(*pRoot)->key tren cay
            if(((*pRoot)->left == NULL) && ((*pRoot)->right == NULL)){// x là lá
                temp = (*pRoot);
                (*pRoot) = NULL;
                free(temp);
            }
            else if((*pRoot)->left == NULL){ //x có con phải
                temp = (*pRoot);
                (*pRoot) = (*pRoot)->right;
                free(temp);
            }
            else if((*pRoot)->right == NULL){// x có con trái
                temp = (*pRoot);
                (*pRoot) = (*pRoot)->left;
                free(temp);
            }
            else//x co 2 con
                (*pRoot)->key = deleteMin(&((*pRoot)->right));
        }
    }
}
int main()
{
    Tree T;
// makenull(&T);
    T = readTree();
    LRN(T);
    deleteMax(&T);
    printf("\n");
    LRN(T);
    printf("\n");
    deleteMin(&T);
    LRN(T);
    
    return 0;
}
