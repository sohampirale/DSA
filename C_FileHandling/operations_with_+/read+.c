//r+
//read and write mode
//overwrites the old content
//file must exist


#include<stdio.h>
#include<stdio.h>
int main(){
    FILE* ptr=fopen("read+.txt","r+");
    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");

        char ch;

        while(ch!=EOF){
            ch=fgetc(ptr);
            printf("%c,",ch);
         }

        fprintf(ptr,"new data\n");

        fclose(ptr);
    }
}













// #include<stdio.h>
// #include<stdio.h>
// int main(){
//     FILE* ptr=fopen("alphabets.txt","r+");
//     if(ptr==NULL){
//         printf("Error opening the file\n");
//         return 1;
//     } 

//     printf("File opened successfully\n");

//     //reading for the first time

//     char ch=' ';

//     while(ch!=EOF){
//         printf("%c",ch);
//         ch=fgetc(ptr);
//     }

    
//     printf("\nData read successfully\n");

//     fprintf(ptr,"new data1\n");

//     rewind(ptr);

//     fprintf(ptr,"new data2\n");


//     //reading for the second time

//     ch=' ';

//     while(ch!=EOF){
//         ch=fgetc(ptr);
//         printf("%c",ch);
//     }


//     fclose(ptr);
// }














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