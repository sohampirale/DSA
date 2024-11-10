// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// bool full(int start,int end){
//     return start==end;
// }
// bool empty(int start){
//     return start==-1;
// }
// int main(){
//     int n=0;
//     int *stack=(int*)malloc(sizeof(int)*n);
//     int choice=1,start=-1,end=0;
//     while(choice!=0){
//         printf("Enter your choice\n1 : Push\n2 : Pop\n3 : Display\n4 : Top\nYour choice : ");
//         scanf("%d",&choice);
//         if(choice==1){
//             stack=(int*)realloc(stack,sizeof(int)* (n+1));
//             n++;
//             printf("Enter new element : ");
//             scanf("%d",&stack[n-1]);
//             printf("%d is added\n",stack[n-1]);
//             printf("n = %d\n",n);
//         } else if(choice==2){
//             if(n==0){
//                 printf("Stack underflow\n");
//                 continue;
//             }
//             printf("%d is deleted\n",stack[n-1]);
//             n--;
//             stack=(int*)realloc(stack,sizeof(int)*n);
//             printf("n = %d\n",n);
//         } else if(choice==3){
//             if(n==0){
//                 printf("Stack is empty\n");
//                 continue;
//             }
//             printf("Stack is : ");
//             for(int i=0;i<n;i++)printf("%d ",stack[i]);
//         } else if(choice==4){
//             if(n==0){
//                 printf("Stack is empty\n");
//                 continue;
//             }
//             printf("Top : ",stack[n-1]);
//         }
//     }
//     return 0;
// }