#include<stdio.h>
#include<stdio.h>
int main(){
    FILE* ptr=fopen("append+.txt","a+");
    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");

        fprintf(ptr,"New Data2\n");

        // rewind(ptr);

        char ch;

        while(ch!=EOF){
            ch=fgetc(ptr);
            printf("%c",ch);
        }

        fprintf(ptr,"new data2\n");

        fclose(ptr);
    }
}