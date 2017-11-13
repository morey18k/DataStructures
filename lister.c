#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char datum;
    struct node* next;
} Node;

void printList(Node *list);
char pop(Node *list);
char peek(Node *list);
void push(char letter, Node **list);
void purge(Node * listy);


int main(void) {
    Node * listy;
    listy=NULL;
    printList(listy);
    for(int i=0;i<24;i++){
        push(i+97,&listy);
    }
    printList(listy);
    printf("get returns %c\n",peek(listy));
    printList(listy);
    purge(listy);
}

void printList(Node *list){
    Node * curr=list;
    while (curr!=NULL){
        printf("%c ",curr->datum);
        curr=curr->next;
    }
    printf("\n");
}

char pop( Node *list){
    Node * curr = list;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    char letter=curr->next->datum;
    free(curr->next);
    curr->next=NULL;
    return letter;
}

char peek( Node *list){
    Node * curr = list;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    char letter=curr->next->datum;
    return letter;
}


void push(char letter, Node **list){
    Node * first;
    first=*list;
    Node* new=malloc(sizeof(Node));
    new->datum=letter;
    new->next=first;
    *list=new;
}

void purge(Node * listy){
    Node * curr=listy;
    Node * temp;
    while (curr!=NULL){
        temp=curr;
        curr=temp->next;
        free(temp);
    }
}
