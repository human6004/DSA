#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char  KeyType;
struct Node
{
    KeyType key;
    struct Node *left;
    struct Node *right;
};
typedef struct Node* Tree;
Tree T; //struct Node* T;

// khoi tao rong
void makenull(Tree *pT){
    (*pT) = NULL;
}

int emptytree(Tree  T){
    return T == NULL;
}

Tree create2 (KeyType v, Tree l, Tree r){
    Tree N;
    N = (struct Node*) malloc(sizeof(struct Node));
    N->key = v;
    N->left = l;
    N->right = r;
    return N;
}

Tree leftChild(Tree n){
    if(n != NULL) return n->left;
    else return NULL;
}

Tree rightChild(Tree n){
    if(n != NULL) return n->right;
    else return NULL;
}

//check if a node a ledf or not
int isLeaf(Tree n){
    if(n != NULL)
    return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    else return 0;
}

void NLR(Tree root){
    if(root != NULL){
        printf("%c ", root->key);//N
        NLR(root->left);          //L
        NLR(root->right);         //R
    }
}

void LNR(Tree root){
    if(root != NULL){
        NLR(root->left);          //L
        printf("%c ", root->key);//N
        NLR(root->right);         //R
    }
}

void LRN(Tree root){
    if(root != NULL){
        NLR(root->left);          //L
        NLR(root->right);         //R
        printf("%c ", root->key);//N
    }
}

//xác định số nút trong cây
int nb_nodes(Tree root){
    if(emptytree(root))
    // if(root != NULL)
        return 0;
    else
        return 1
            + nb_nodes(leftChild(root))
            + nb_nodes(rightChild(root));
}

int nb_leaf(Tree root){
    if(!emptytree(root)){
        return 1;
    }
    else{
        return nb_leaf(root->left) + nb_leaf(root->right);
    }
    return 0;
}

Tree sreach(KeyType x, Tree T){// trên bảng là cây nhị phân: o(n);
    if(T == NULL) return NULL;
    else if(T->key == x) return T;
    else{
        Tree N = sreach(x, T->left);
        if(T != null) return N;
        else return sreach(x, T->right);
    }
}




int main(){
    Tree T;
    makenull(&T);
    int check = emptytree(T);
    printf("check empty: %d\n", check);

    T = create2('+',create2('*',create2('3',NULL,NULL),create2('5',NULL,NULL)),create2('7',NULL,NULL));

    Tree T1, T2, T3, T4, T5, T6, T7;
	makenull(&T1);
	T1 = create2('+', create2('a', NULL, NULL), create2('b', NULL, NULL));
	T2 = create2('+', create2('d', NULL, NULL), create2('e', NULL, NULL));
	T3 = create2('+', create2('g', NULL, NULL), create2('8', NULL, NULL));
	T4 = create2('*', create2('c', NULL, NULL), T2);
	T5 = create2('+', T1, T4);
	T6 = create2('+', T5,create2('f', NULL, NULL));
	T7 = create2('*', T6, T3);

    printf("Prefix:\n");
    NLR(T);
    printf("\nInfix:\n");
    LNR(T);
    printf("\nPostfix:\n");
    LRN(T);
    int  count= nb_nodes(T);
    printf("\nso nut cua cay: %d", count);
    return 0;
}
