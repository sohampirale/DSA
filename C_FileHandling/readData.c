#include<stdio.h>
#include<stdio.h>
int main(){
    FILE* ptr=fopen("example.txt","r");
    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");
       char ch;
       while(ch!=EOF){
        ch=fgetc(ptr);
        printf("%c,",ch);
       }
    }
}















// #include<stdio.h>
// #include<stdio.h>
// int main(){
//     FILE* ptr=fopen("example.txt","r");
//     if(ptr==NULL){
//         printf("Error opening the file\n");
//     } else {
//         printf("File opened successfully\n");
//        char ch;
//        while((ch=fgetc(ptr))!=EOF){
//         printf("%c,",ch);
//        }
//     }
// }