// #include<iostream>
// using namespace std;

// class  box{
// public:
// int data,mark;
// box*up,*down,*left,*right;
// box(int data){
//   this->data=data;
//   this->up=nullptr;
//   this->down=nullptr;
//   this->right=nullptr;
//   this->left=nullptr;
//   this->mark=0;
// }
// };
// int n_soln=0;
// void display(box**p,int r,int c){
//   cout<<"Matrix is :"<<endl;
//   for(int i=0;i<r;i++){
//     box*temp=p[i];
//     for(int j=0;j<c;j++){
//       cout<<temp->data<<" ";
//       temp=temp->right;
//     }
//     cout<<endl;
//   }
//   cout<<"Matrix end"<<endl;
// }
// void add(box*start,int r,int c,int l){
  
// }
// void colomn_set(box**p,int r,int c){
//   for(int i=0;i<r-1;i++){
//     box*temp1=p[i],*temp2=p[i+1];
//     while(temp1!=nullptr){
//       temp1->down=temp2;
//       temp2->up=temp1;
//       temp1=temp1->right;
//       temp2=temp2->right;
//     }
//     cout<<"Row no-"<<i+1<<" & "<<i+2<<" connected vertically successfully"<<endl;
//   }
// }
// void row_set(box**p,int r,int c){
//   int temp;
//   box*ptr;
//   for(int i=0;i<r;i++){
//   cout<<"Enter "<<c<<" numbers of row no-"<<i+1<<endl;
//     for(int j=0;j<c;j++){
//       cout<<"Enter data for box "<<i+1<<"x"<<j+1<<" : ";
//       cin>>temp;
//       box*one_node=new box(temp);
//       if(p[i]==nullptr){
//         p[i]=one_node;
//         ptr=one_node;
//       }else {
//         ptr->right=one_node;
//         one_node->left=ptr;
//         ptr=one_node;
//       }
//     }
//   }
//   colomn_set(p,r,c);
// }
// void test(box**p,int r,int c,int rc,int cc){
//   if(rc>r||cc>c){
//     cout<<"Invalid input"<<endl;
//   }
//   box*temp=p[rc-1];
//   int i=1;
//   while(i<cc){
//     temp=temp->right;
//     i++;
//   }
//   if(temp==nullptr)
//   cout<<"Number present at row = "<<rc<<" & colomn = "<<cc<<" is : "<<temp->data<<endl;
//   if(temp->up!=nullptr)cout<<"Number above it is : "<<temp->up->data<<endl;
//   if(temp->down!=nullptr)cout<<"Number below it is : "<<temp->down->data<<endl;
//   if(temp->right!=nullptr)cout<<"Number after it is : "<<temp->right->data<<endl;
//   if(temp->left!=nullptr)cout<<"Number before it is : "<<temp->left->data<<endl;
// }
// void display_mark(box**p,int r,int c){
//   cout<<"Matrix with marks for backtracking is :"<<endl;
//   for(int i=0;i<r;i++){
//     box*temp=p[i];
//     for(int j=0;j<c;j++){
//       cout<<temp->mark<<" ";
//       temp=temp->right;
//     }
//     cout<<endl;
//   }
//   cout<<"Matrix end"<<endl;
// }
// void backtracking(box**p,int er,int ec,int r,int c,box*ptr,int sr=0,int sc=0,int cnt=1){
//   if(ptr==nullptr)return;
//   // cout<<"sr = "<<sr<<" & sc = "<<sc<<endl;
//   if(sr>r||sc>c||sr<0||sc<0){
//     cout<<"Went outside the matrix"<<endl;
//     return;
//   }
//   else if(ptr->mark!=0)return;
  
//   else if(sr==er&&sc==ec){
//     cout<<"Reached the destination"<<endl;
//     n_soln++;
//     ptr->mark=cnt;
//     display_mark(p,r,c);
//     ptr->mark=0;
//     return;
//   }
//   cout<<"Ptr is pointing at anode which has data ="<<ptr->data<<endl;
//   ptr->mark=cnt;
//   box*temp;
//   temp=ptr->right;
//   backtracking(p, er, ec, r,  c,temp,sr,sc+1,cnt+1);//right
//   temp=ptr->left;
//   backtracking(p, er, ec, r,  c,temp,sr,sc-1,cnt+1);//left
//   temp=ptr->up;
//   backtracking(p, er, ec, r,  c,temp,sr-1,sc,cnt+1);//up
//   temp=ptr->down;
//   backtracking(p, er, ec, r,  c,temp,sr+1,sc,cnt+1);//down
//   ptr->mark=0;
// }
// int main(){
//   int r,c;
//   cout<<"Enter number of rows : ";
//   cin>>r;
//   cout<<"Enter number of colomns : ";
//   cin>>c;
//   // box* p[r] = {nullptr};
//   box* row_start[r];
//   for(int i=0;i<r;i++)row_start[i]=nullptr;
//   row_set(row_start,r,c);
//   cout<<"Came out"<<endl;
//   display(row_start,r,c);
//   int rc,cc;
//   cout<<"Enter row and colomn of an element and i will tell all for element surrounding it : ";
//   cin>>rc>>cc;
//   test(row_start,r,c,rc,cc); 
//   display_mark(row_start,r,c);
//   cout<<"Let's call the backtracking function"<<endl;
//   int er,ec;
//   cout<<"Enter the row no. & colomn no. of destination we want to reach from (0,0) : ";
//   cin>>er>>ec;
//   backtracking(row_start, er-1, ec-1, r,  c, row_start[0]);
//   cout<<"Came out"<<endl;
//   cout<<"Number of ways to reach the destination are : "<<n_soln<<endl;
// }