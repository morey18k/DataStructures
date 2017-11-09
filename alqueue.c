#include<stdio.h>
#include<stdlib.h>

typedef struct alist{
    int capacity;
    int size;
    char* data;
} ArrayList;

void printList(ArrayList*listy);
void purge(ArrayList *listy);
void proliferate(ArrayList*listy);
void push(char letter,ArrayList*listy);
void prepare(ArrayList *listy);
void peek(ArrayList *listy);
char pop(ArrayList *listy);


int main (void){
    ArrayList * listy=malloc(sizeof(ArrayList));
    init(listy);
    for (int i=0;i<36;i++){
        append(i%26+97,listy);
        printf("Size: %3d, Capacity%3d ",listy->size,listy->capacity);
        printList(listy);
    }
    printList(listy);
    rem('a',listy);
    printList(listy);
    set(4,'!',listy);
    printList(listy);
    printf("%c\n",get(24,listy));
    insert(3,'6',listy);
    printList(listy);
    clearList(listy);
}

char pop(ArrayList *listy){
    listy->size--;
    for (int k=i;k<listy->size;k++){
        listy->data[k]=listy->data[k+1];       
    }
    return listy->data[listy->size-1];
}

char peek(ArrayList *listy){
    listy->size--;
    for (int k=i;k<listy->size;k++){
        listy->data[k]=listy->data[k+1];       
    }
}

void prepare(ArrayList *listy){
    listy->capacity=1;
    listy->size=0;
    listy->data=malloc(sizeof(char)*(listy->capacity));
}

void push(char letter,ArrayList *listy){
    if (listy->size==listy->capacity)
        reSize(listy);
    listy->size++;
    listy->data[listy->size-1]=letter;
}

void proliferate(ArrayList *listy){
    listy->capacity*=2;
    char* new=malloc(sizeof(char)*(listy->capacity));
    for(int i=0;i<listy->size;i++){
        new[i]=listy->data[i];
    }
    free(listy->data);
    listy->data=new;
}

void insert(int i,char letter,ArrayList*listy){
    if(listy->size==listy->capacity)
        reSize(listy);
    int lencpy=(listy->size)-i;
    char cpy[lencpy];
    for (int k=i;k<listy->size;k++){
        cpy[k-i]=listy->data[k];
    }
    listy->size++;
    listy->data[i]=letter;
    for (int k=i+1;k<listy->size;k++){
        listy->data[k]=cpy[k-i-1];
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
void purge(ArrayList*listy){
    free(listy);
}
