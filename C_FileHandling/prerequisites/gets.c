#include<stdio.h>
#include<stdlib.h>
int main(){
    char str[200];
    printf("Enter your name : ");
    gets(str);
    printf("Line you entered is : %s\n",str);
    return 0;
}