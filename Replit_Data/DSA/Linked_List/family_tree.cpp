// #include<iostream>
// using namespace std;
// class person{
//   public :
//     string name;
//     person*up;
//     int n=1;
//     person *child[5]={nullptr};
//     // for(int i=0;i<5;i++){child[i]=nullptr;}
//     person(int n,string name="",person*parent=nullptr){
//       // if(n!=0)person *child[n];
//       this->name=name;
//       this->up=parent;
//     }
// };
// // int level=1;
// void work(string parent_name,int n_child,person*parent_pointer,int level=1){
//   int temp;
//   string child_name;
//   for(int i=0;i<n_child;i++){
//     cout<<"Enter name of child no - "<<i+1<<" of "<<parent_name<<" : "<<endl;
//     cin>>child_name;
//     cout<<"How many children does "<<child_name<<" has : ";
//     cin>>temp;
//     person* children=new person(temp,child_name,parent_pointer);
//     cout<<"A child of "<<parent_name<<"is created whose name is "<<child_name<<" who has "<<temp<<" children"<<endl;
//     // parent_pointer->child[i]=
//     parent_pointer->child[i]=children;
//     if(temp==0)continue;
//     else {
//       work(child_name,temp,children,level+1);
//     }
//   }
//   cout<<"Came here"<<endl;
// }
// void display(person*start){
//   int i=0;
//   person*temp=start;
//   if(temp->child[0]==nullptr){
//     cout<<temp->name<<" has no childre further"<<endl;
//     return;
//   }
//   cout<<"Children of "<<temp->name<<" are : "<<endl;
//   while(temp->child[i]!=nullptr){
//     cout<<i<<". "<<temp->child[i]->name<<endl;
//     i++;
//   }
//   cout<<temp->name<<" has "<<i<<" children : "<<endl;
//   cout<<"\n\n\n\n";
//   for(int j=0;j<i;j++){
//     display(temp->child[j]);
//   }
// }
// int main(){
//   string head;
//   int n_child;
//   cout<<"Enter name of th ehead of the family : ";
//   cin>>head;
//   cout<<"How many child does "<<head<<" has : ";
//   cin>>n_child;
//   person *start=new person(n_child,head,nullptr);
//   work(head,n_child,start,0);
//   cout<<"Came out"<<endl;
//   cout<<"lets see what we have stored"<<endl;
//   display(start);
//   return 0;
// }