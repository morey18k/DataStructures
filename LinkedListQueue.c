#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char datum;
    struct node* next;
} Node;

typedef struct queue{
    struct node * first;
    struct node * last;
} Queue;

void print(Queue *list);
char pop(Queue *list);
char peek(Queue *list);
void push(char letter, Queue * list);
void purge(Queue * list);


int main(void) {
    Queue * list=malloc(sizeof(Queue));
    list->first=NULL;
    list->last=NULL;
    for(int i=0;i<=20;i++){
        push(i+97,list);
        print(list);
    }
    print(list);       
    for(int i=0;i<=20;i++){
        pop(list);
        print(list);
    }
}

void print(Queue * list){
    Node * curr=list->first;
    printf("[");
    while (curr!=NULL){
        if(curr->next!=NULL){
            printf("%c, ",curr->datum);
        }
        else{printf("%c",curr->datum);}
        curr=curr->next;
    }
    printf("]");
    printf("\n");
}

char pop(Queue *list){
    Node * firsty=list->first;
    char letter=firsty->datum;
    list->first=firsty->next;
    free(firsty);
    return letter;
}

char peek(Queue *list){
    Node * firsty=list->first;
    char letter=firsty->datum;
    return letter;
}

void push(char letter, Queue *list){
    Node * new=malloc(sizeof(Node));
    new->next=NULL;
    new->datum=letter;
    if(list->first==NULL){
        list->first=new;
        list->last=new;
        return;
    }
    list->last->next=new;
    list->last=new;
}

void purge(Queue * list){
    Node * curr=list->first;
    Node * temp;
    while (curr!=NULL){
        temp=curr;
        curr=temp->next;
        free(temp);
    }
}
