#include<stdio.h>
#include<stdio.h>
int main(){

    FILE* ptr=fopen("example.txt","a");

    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");
        fprintf(ptr,"writing into file");
        fclose(ptr);
    }
}
