#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char datum;
    struct node* left;
    struct node*right;
} Node;

int insert(Node ** first, char datum);
void clear(Node ** current);
void printTree(Node *first);
int delete(Node **tree,char datum);
int find(Node * tree, char letter);
Node* max(Node* tree);


int main(void){
    srand(0);
    Node* first= NULL;
   
    insert(&first,'k');
    
    insert(&first,'z');
    
    insert(&first,'a');
    
    insert(&first,'a');
    
    insert(&first,'c');
    
    printTree(first);
    
    for(int k=0;k<20;k++)
        printf("-");
    puts("");
    
    delete(&first,'k');
    
    printTree(first);
    
    for(int k=0;k<20;k++)
        printf("-");
    puts("");

    //delete(&first,'w');
    printTree(first);
    
    clear(&first);
    
    return 0;
}
int find(Node * tree, char letter){
    if(tree==NULL){
        return -1;
    }
    if(tree->datum==letter){
        return 0;
    }
    int out;
    if(tree->datum<letter){
        out=find(tree->right,letter);
    }
    else{
        out=find(tree->left,letter);
    }
    if (out==-1){
        return out;
    }
    return 1+out;
}

int delete(Node** tree, char letter){
    if (*tree ==NULL){
        return 0;
    }
    if (letter<(*tree)->datum){
        return delete(&((*tree)->left),letter);
    }
    if (letter>(*tree)->datum){
        return delete(&((*tree)->right),letter);
    }
    if (((*tree)->left==NULL) && ((*tree)->right==NULL)){
            free(*tree);
            *tree=NULL;
            return 1;
    }
    if (((*tree)->left==NULL)!=((*tree)->right==NULL)){
            Node * only;//(((*tree)->left)==NULL) ?(*tree)->left : (*tree)->right;
            if((*tree)->left==NULL)
                only=(*tree)->right;
            else
                only=(*tree)->left;
            Node *temp=*tree;
            free(temp);
            *tree=only;
            return 1;
    }
    Node * right=max((*tree)->left);
    (*tree)->datum=right->datum;
    delete(&right,right->datum);
    return 1;
}

int insert(Node ** first, char datum){
    if(*first==NULL){
        Node * new =malloc(sizeof(Node));
        new->datum=datum;
        new->left=NULL;
        new->right=NULL;
        *first=new;
        return 0;
    } else{
        if((*first)->datum<datum)
            return 1+insert(&((*first)->right),datum);
        else 
            return 1+insert(&((*first)->left),datum);
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

void printTree(Node * first){
    static int depth=0;
    
    int temp=depth;
    if (first==NULL){}
    else{
        if(first->right!=NULL){
            depth+=2;
            printTree(first->right);
            depth=temp;
            for(int i=0;i<depth;i++){
                printf(" ");
            }
            puts("|");
        }
        for(int k=0;k<depth-1;k++)
            printf(" ");
        printf("-%c\n",first->datum);
        if(first->left!=NULL){
            for(int i=0;i<depth;i++){
                printf(" ");
            }
            puts("|");
            depth+=2;
            printTree(first->left);
            depth=temp;
        }
    }
    depth++;
}

Node * max(Node* tree){
    if (tree->right==NULL){
        return tree;
    }
    return max(tree->right);
}







