#include<stdio.h>
#include<stdlib.h>
int main(){
    char ch;
    printf("Enter a char : ");
    ch=fgetc(stdin);
    printf("You enetered : %c\n",ch);
    return 0;
}