#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char datum;
    struct node* left;
    struct node*right;
} Node;

void create(Node ** first, char datum);
void clear(Node ** current);
void printTree(Node *first, int depth);

int main(void){
    srand(0);
    Node* first= NULL;
    
    for(int i=0;i<5;i++){
        create(&first,i+97);
    }
    printTree(first,0);
    clear(&first);
    return 0;
}


void create(Node ** first, char datum){
    if(*first==NULL){
        Node * new =malloc(sizeof(Node));
        new->datum=datum;
        new->left=NULL;
        new->right=NULL;
        *first=new;
    } else{
        if(rand() % 2) 
            create(&((*first)->right), datum);
        else 
            create(&((*first)->left),datum);
    }
}

void clear(Node ** current){
    if (*current==NULL) return;
    else{
        clear(&((*current)->left));
        clear(&((*current)->right));
        free(*current);
        *current=NULL;
    }
}

void printTree(Node * first, int depth){
    if (first==NULL){}
    else{
        if(first->right!=NULL){
            printTree(first->right,depth+2);
            for(int i=0;i<depth;i++){
                printf(" ");
            }
            puts("");
        }
        for(int k=0;k<depth-1;k++)
            printf(" ");
        printf("-%c\n",first->datum);
        if(first->left!=NULL){
            for(int i=0;i<depth;i++){
                printf(" ");
            }
            puts("|");
            printTree(first->left, depth+2);
        }
    }
}









