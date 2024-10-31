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
//          printf("Size of queue = %d & start = %d & end = %d\n",n,start,end);
//         printf("Enter your choice\n1 : Push\n2 : Pop\n3 : Display\n4 : Top\nYour choice : ");
//         scanf("%d",&choice);
//         if(choice==1){
//             if(start==-1){
//                 printf("Starting th equeue\n");
//                 start=0;
//             }
//             if(full(start,end)){
//                 printf("Queue is full so reallocating\n");
//             stack=(int*)realloc(stack,sizeof(int)* (n+1));
//             printf("Queue size increases by 1 size=%d\n",n+1);

//             if(end!=0){

//         //         printf("Stack is : ");
//         //     int i=start;
//         //   do{  printf("at i=%d ",i);
//         //       printf("%d \n",stack[i]);
//         //       i=(i+1)%n;
//         //   }while(i!=end);

//             for(int i=n;i>start;i--){
//                 printf("i = %d\n",i);
//                 printf("stack[%d-1] = %d\n",stack[i-1]);
//                 stack[i]=stack[i-1];
//                  printf("stack[%d] is set to : %d\n",i,stack[i]);
//             }

//              if(end!=0){

//         //         printf("Stack is : ");
//         //     int i=start;
//         //   do{  printf("at i=%d ",i);
//         //       printf("%d \n",stack[i]);
//         //       i=(i+1)%n;
//         //   }while(i!=end);


//                 printf("Enter new element : ");
//             scanf("%d",&stack[end]);
//             n++;
//             end=(end+1)%n;
//             start=(start+1)%n;
//             continue;
//             printf("hi\n");
//             }}
//             n++;
//             if(end==0)end=n-1;
//             } 
//             printf("Enter new element : ");
//             scanf("%d",&stack[end]);
//             end=(end+1)%n;
//          }else if(choice==2){
//             if(n==0){
//                 printf("Stack underflow\n");
//                 continue;
//             }
//             printf("%d is deleted\n",stack[start]);
//             start=(start+1)%n;
//             printf("n = %d\n",n);
//             if(start==end){
//                 printf("You have dequeued whole queue\n");
//                 start=-1;
//                 end=0;
//             }
//         } else if(choice==3){
//             if(n==0){
//                 printf("Stack is empty\n");
//                 continue;
//             }
//             printf("Stack is : ");
//             int i=start;
//            do{
//                printf("%d ",stack[i]);
//                i=(i+1)%n;
//            }while(i!=end);
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
