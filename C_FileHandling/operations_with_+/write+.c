//w+
//complete fresh start
//read + write 
//

// #include<stdio.h>
// #include<stdio.h>
// int main(){
//     FILE* ptr=fopen("write+.txt","w+");

//     if(ptr==NULL){
//         printf("Error opening the file\n");
//     } else {
//         printf("File opened successfully\n");

//         fprintf(ptr,"new data\n");



//         fclose(ptr);
//     }
// }




#include<stdio.h>
#include<stdio.h>
int main(){
    FILE* ptr=fopen("write+.txt","w+");

    if(ptr==NULL){
        printf("Error opening the file\n");
    } else {
        printf("File opened successfully\n");

        fprintf(ptr,"new data\n");

        rewind(ptr);

        char ch;
        while(ch!=EOF){
            printf("%c,",ch);
            ch=fgetc(ptr);
        }

        fclose(ptr);
    }
}