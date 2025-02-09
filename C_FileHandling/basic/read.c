#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *ptr=fopen("exmaple.txt","r");
    if(ptr==NULL){
        printf("File does not exists\n");
    } else {
        printf("FIle opened successfully\n");
    }
}