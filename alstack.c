#include<stdio.h>
#include<stdlib.h>

typedef struct alist{
    int capacity;
    int size;
    char* data;
} ArrayList;

void printList(ArrayList*listy);
void purge(ArrayList **listy);
void proliferate(ArrayList*listy);
void push(char letter,ArrayList*listy);
void prepare(ArrayList *listy);
char peek(ArrayList *listy);
char pop(ArrayList *listy);


int main (void){
    ArrayList * listy=malloc(sizeof(ArrayList));
    prepare(listy);
    char current;
    for (int i=0;i<=20;i++){
        push(i+97,listy);
        current=i+97;
        printList(listy);
    }
    for (int i=10;i<=20;i++){
        current=pop(listy);
        printList(listy);
    }
    purge(&listy);
}

char pop(ArrayList *listy){
    listy->size--;
    char letter = listy->data[listy->size];
    return letter;
}

char peek(ArrayList *listy){
    return listy->data[(listy->size)-1];
}

void prepare(ArrayList *listy){
    listy->capacity=1;
    listy->size=0;
    listy->data=malloc(sizeof(char)*(listy->capacity));
}

void push(char letter,ArrayList *listy){
    proliferate(listy);
    listy->size++;
    listy->data[listy->size-1]=letter;
}

void proliferate(ArrayList *listy){
    if(listy->size==listy->capacity){
        listy->capacity*=2;
        char* new=malloc(sizeof(char)*(listy->capacity));
        for(int i=0;i<listy->size;i++){
            new[i]=listy->data[i];
        }
        free(listy->data);
        listy->data=new;
    }
}

void printList(ArrayList*listy){
    printf("[");
    for(int i=0;i<listy->size;i++){
        if(i!=listy->size-1)
            printf("%c, ",(listy->data)[i]);
        else
            printf("%c",(listy->data)[i]);
    }
    printf("]");
    printf("\n");
}
void purge(ArrayList**listy){
    free(*listy);
    *listy=NULL;
}
