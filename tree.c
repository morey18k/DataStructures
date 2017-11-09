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
    
    for(int i=0;i<30;i++){
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
    if (first==NULL)
        puts("");
    else{
        printTree(first->right,depth+1);
        for(int k=0;k<depth;k++)
            printf("    ");
        printf("%c\n",first->datum);
        printTree(first->left, depth+1);
    }
}









