#include<stdio.h>
#include<stdio.h>
int main(){

    FILE* ptr=fopen("example.txt","w");

    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");
        fprintf(ptr,"writing into file \n");
        fclose(ptr);
    }
}










// #include<stdio.h>
// #include<stdio.h>
// int main(){
//     char data[100];
//     printf("ENter waht you want to write into file : ");
//     scanf("%s",data);
//     FILE* ptr=fopen("example.txt","w");
//     if(ptr==NULL){
//         printf("Error opening the file\n");
//     } else {
//         printf("File opened successfully\n");
//         fprintf(ptr,data);
//         fclose(ptr);
//     }
// }










// #include<stdio.h>
// #include<stdio.h>
// int main(){
    
//     FILE* ptr=fopen("example.txt","w");

//     if(ptr==NULL){
//         printf("Error opening the file\n");
//     } else {
//         printf("File opened successfully\n");
//         fprintf(ptr,"writing into file \n");
//         fclose(ptr);
//     }
// }





