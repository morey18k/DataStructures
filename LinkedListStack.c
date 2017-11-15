#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char datum;
    struct node* next;
} Node;

typedef struct stack{
    struct node * first;
} Stack;

void print(Stack *list);
char pop(Stack *list);
char peek(Stack *list);
void push(char letter, Stack * list);
void purge(Stack * list);


int main(void) {
    Stack* list=malloc(sizeof(Stack));
    list->first=NULL;
    for(int i=0;i<=20;i++){
        push(i+97,list);
        print(list);
    }
    print(list);       
    for(int i=10;i<=20;i++){
        pop(list);
        print(list);
    }
    purge(list);
}

void print(Stack * list){
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

char pop(Stack *list){
    Node * firsty=list->first;
    char letter=firsty->datum;
    list->first=firsty->next;
    free(firsty);
    return letter;
}

char peek(Stack *list){
    Node * firsty=list->first;
    char letter=firsty->datum;
    return letter;
}

void push(char letter, Stack *list){
    Node * new=malloc(sizeof(Node));
    new->datum=letter;
    if(list->first==NULL){
        list->first=new;
        new->next=NULL;
        return;
    }
    new->next=list->first;
    list->first=new;
    return;
}

void purge(Stack * list){
    Node * curr=list->first;
    Node * temp;
    while (curr!=NULL){
        temp=curr;
        curr=temp->next;
        free(temp);
    }
}
