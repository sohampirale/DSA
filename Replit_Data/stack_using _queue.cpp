// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//   int data;
//   struct node *next;
// };
// typedef struct node node;
// node *front=NULL,*rear=NULL,*p,*q;
// int dq,count=1;
// int top();
// void enqueue(int ele);
// int dequeue();
// //void top();
// void traverse();

// int main(){
//   int ch,ele;
//   do{
//     printf("1.Enqueue\n2.Dequeue\n3.Top\n4.traverse\n5.Exit\n");
//     printf("Enter choice ");
//     scanf("%d",&ch);

//     switch(ch){
//       case 1: 
//         printf("Enter element\n");
//         scanf("%d",&ele);
//         enqueue(ele);
//       break;
//     case 2:{
//       printf("%d is dequeued ,hi line remove kru shkto apn karan function madhe already taklya",dequeue());
//       break;

//       }
// 			case 3:
//         {
//           int t=top();
//           printf("%d is at the top ,hi line remove kru shkto apn karan function madhe already taklya\n",t);
//           break;
//         }
//       case 4:{
//         traverse();
//         break;
//       }
//       case 5: {
//         q = front;
//             while (q != NULL) {
//               p = q; 
//               q = q->next; 
//               free(p);
//               front=q;
//         } 
//         break;
//       }
//       default: printf("Invalid choice\n");
//     }
//   }while(ch!=5);
// return 0;
// }

// void enqueue(int ele){
// p= (node*)malloc(sizeof(node));
// p->data=ele;
//    if(front==NULL){
//     front=p;
//     rear=p;
//     rear->next=NULL;
//     ;
//    }
//    else{
//     rear->next=p;
//     rear=p;
//     p->next=NULL;
//     count++;
//    }	
// }

// int dequeue(){
//   if(front==NULL){
//     printf("Dequeue Can not perform");
//     return -1;
//   }
//   else{
//     p=front;
//     q=front;
//     rear->next=front;
//     while(p!=rear){
//       q=p;
//       p=p->next;
//     }
//     q->next=NULL;
//     rear=q;
//     q=p;
//     printf("%d is dequeued\n",q->data);
//     int d=q->data;
//     p=p->next;
//     front=p;
//     free(q);
//     return d;
//   }
// }

// void traverse(){
//   if (front==NULL){
//     printf("Queue is empty\n");
//   }
//   else{
//     q=front;
//     printf("Elements are :");
//     while(q!=NULL){
//       printf("%d\t",q->data);
//       q=q->next;
//     }
//   }
//   printf("\n");
// }

// int top(){
//   if(front==NULL){
//     printf("Queue is empty so nothing at the top\n");
//     return -1;
//   }
//   else{
//     p=front;
//     q=front;
//     rear->next=front;
//     while(p!=rear){
//       q=p;
//       p=p->next;
//     }
//     q->next=NULL;
//     rear=q;
//     q=p;
//     printf("%d is at the top\n",q->data);
//     int t=q->data;
//     int top=q->data;
//     rear->next=p;
//     front=p->next;
//     p->next=NULL;
//     return t;
//   }
// }