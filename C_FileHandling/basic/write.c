#include<stdio.h>
#include<stdlib.h>
int main(){
    char filename[20];
    printf("Enter filename : ");
    scanf("%s",filename);
    FILE* ptr=fopen(filename,"w");
    if(ptr==NULL){
        printf("File not opened successfully\n");
    } else {
        printf("File opened successfully\n");
    }
}