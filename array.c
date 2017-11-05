#include<stdio.h>
#include<stdlib.h>
typedef struct alist{
    int capacity;
    int size;
    char* data;
} ArrayList;

void printList(ArrayList*listy);
char get(int i, ArrayList * listy);
void clearList(ArrayList *listy);
void set(int i,char letter,ArrayList*listy);
void insert(int i,char letter,ArrayList*listy);
void reSize(ArrayList*listy);
void append(char letter,ArrayList*listy);
void init(ArrayList *listy);
void rem(char letter, ArrayList *listy);
void del(int i,ArrayList *listy);


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

void rem(char letter, ArrayList *listy){
    int i;
    for (i=0;i<listy->size;i++){
        if (listy->data[i]==letter)
            break;
    }
    del(i,listy);
}

void del(int i,ArrayList *listy){
    listy->size--;
    for (int k=i;k<listy->size;k++){
        listy->data[k]=listy->data[k+1];       
    }
}

void init(ArrayList *listy){
    listy->capacity=1;
    listy->size=0;
    listy->data=malloc(sizeof(char)*(listy->capacity));
}
void append(char letter,ArrayList *listy){
    if (listy->size==listy->capacity)
        reSize(listy);
    listy->size++;
    listy->data[listy->size-1]=letter;
}

void reSize(ArrayList *listy){
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
void set(int i, char letter, ArrayList* listy){
    char *curr = listy->data;
    curr[i] = letter;

}
char get(int i, ArrayList * listy){
    if (i<listy->size){
        return listy->data[i];
    }
    printf("Error: List index exceeds size of list\n");
    return 0;
}

void printList(ArrayList*listy){
    for(int i=0;i<listy->size;i++){
        printf("%c ",(listy->data)[i]);
    }
    printf("\n");
}
void clearList(ArrayList*listy){
    free(listy);
}
