#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char datum;
    struct node* next;
} Node;

void printList(Node *list);
char get(int i, Node *list);
void set(int i,char letter, Node* list);
void append(char letter, Node **list);
void clearList(Node * listy);
void rem(char letter, Node*list);
void del(int i, Node*list);
void insert(int i,char datum, Node**listy);


int main(void) {
    Node * listy;
    listy=NULL;
    printList(listy);
    append('c',&listy);
    printList(listy);
    for (int i=0;i<=40;i++){
        append('a',&listy);
    }
    printList(listy);
    set(5,'x',listy);
    printList(listy);
    rem('x',listy);
    printList(listy);
    del(0,listy);
    printList(listy);
    insert(1,'!',&listy);
    printList(listy);
    printf("%c\n",get(1,listy));
    clearList(listy);
}

void rem(char letter, Node*list){
    Node *curr=list;
    Node *temp;
    if (curr->datum==letter){
        temp=list->next;
        *list=*temp;
        free(temp);
        return;
    }
    while(curr->next->datum!=letter){
        curr=curr->next;
        if (curr->next==NULL)
            break;
    }
    temp=curr->next;
    curr->next=temp->next;
    free(temp);
}
void insert(int i, char letter, Node **list){
    Node *curr=*list;
    Node *new=malloc(sizeof(Node));
    Node *temp;
    if (i==0){
        new->next=curr;
        new->datum=letter;
        *list=new;
        return;
    }
    for(int k=0;k<i-1;k++){
        curr=curr->next;
    }
    temp=curr->next;
    curr->next=new;
    new->next=temp;
    new->datum=letter;
}
void del(int i, Node*list){
    Node *curr=list;
    Node *temp;
    if (i==0){
        temp=list->next;
        *list=*temp;
        free(temp);
        return;
    }
    for(int k=0;k<i-1;k++){
        curr=curr->next;
    }
    temp=curr->next;
    curr->next=temp->next;
    free(temp);
}
void printList(Node *list){
    Node * curr=list;
    while (curr!=NULL){
        printf("%c ",curr->datum);
        curr=curr->next;
    }
    printf("\n");
}

char get(int i, Node *list){
    Node * curr = list;
    for(int k=0;k<i;k++){
        curr=curr->next;
    }
    return curr->datum;
}


void set(int i,char letter, Node* list){
    Node * curr = list;
    for(int k=0;k<i;k++){
        curr=curr->next;
    }
    curr->datum=letter;
}

void append(char letter, Node **list){
    Node * first;
    first=*list;
    Node * curr= first;
    Node* new=malloc(sizeof(Node));
    if (first==NULL){
        *list=new;
        new->datum=letter;
        new->next=NULL;
        return;
    }
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=new;
    new->datum=letter;
    new->next=NULL;
}

void clearList(Node * listy){
    Node * curr=listy;
    Node * temp;
    while (curr!=NULL){
        temp=curr;
        curr=temp->next;
        free(temp);
    }
}
