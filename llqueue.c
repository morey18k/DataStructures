#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char datum;
    struct node* next;
    struct node* last;
} Node;

void printList(Node*listy);
void purge(Node **listy);
void push(char letter,Node**listy);
char peek(Node*listy);
char pop(Node**listy);




int main(void) {
    Node * listy;
    listy=NULL;
    printList(listy);
    push('a',&listy);
    printList(listy);
    purge(&listy);
}
char peek(Node*listy){
    return listy->datum;
}
char pop(Node**list){
    char letter=(*list)->datum;
    Node *first=*list;
    Node *temp=(*list)->next;
    *list=temp;
    free(first);
    return letter;
}

void push(char letter, Node **list){
    Node * first = *list;
    Node * curr= first;
    Node* new=malloc(sizeof(Node));
    if (first==NULL){
        *list=new;
        new->datum=letter;
        new->next=NULL;
      //  new->last=new;
        return;
    }
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=new;
    new->datum=letter;
    new->next=NULL;
    //first->last=new;
}

void printList(Node *list){
    Node * curr=list;
    int size=0;
    while (curr!=NULL){
        curr=curr->next;
        size++;
        printf("%c ",curr->datum);
    }
    puts("");
}


void purge(Node ** list){
    Node * curr=*list;
    Node * temp;
    while (curr!=NULL){
        temp=curr;
        curr=temp->next;
        free(temp);
    }
    *list=NULL;
}
