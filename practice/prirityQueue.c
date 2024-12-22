#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node{
    int data;
}node;
typedef struct stack{
    node** arr;
    int top;
    int size;
} stack;

void setSize(stack* st,int size){
    st->arr=(node**)malloc(sizeof(node*)*size);
    printf("Array of size %d is created\n",size);
    st->top=-1;
    st->size=size;
}
bool isFull(stack* st){
    return st->top+1==st->size;
}

bool isEmpty(stack* st){
    return st->top==-1;
}
void push(stack*st,int data){
    if(!isFull(st)){
        st->top++;
        st->arr[st->top]=(node*)malloc(sizeof(node));
        st->arr[st->top]->data=data;
        printf("Node created with data : %d\n",st->arr[st->top]->data);
    } else {
        printf("Stack is full\n");
    }
}

node* pop(stack* st){
    if(!isEmpty(st)){
        node* ret = st->arr[st->top];
        st->top--;
        return ret;
    } else {
        printf("Stack is empty\n");
        return NULL;
    }
}

int top(stack* st){
    if(!isEmpty(st)){
        int ret=st->arr[st->top]->data;
        return ret;
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
int main(){
    stack st;
    int choice=1,size,data;
    printf("Select size of the stack : ");
    scanf("%d",&size);
    setSize(&st,size);
    while(choice){
        printf("Enter your choice :\n1 : Push\n2 : Pop\n3 : Top\nYour choice : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter new data : ");
            scanf("%d",&data);
            push(&st,data);
        } else if(choice==2){
            node* popped=pop(&st);
            if(popped!=NULL){
                printf("%d is popped lets delete it also\n",popped->data);
                free(popped);
            }
        } else if(choice==3){
            int topE=top(&st);
            if(topE!=-1){
                printf("Topmost element is %d\n",topE);
            }
        }
    }
    free(st.arr);
}