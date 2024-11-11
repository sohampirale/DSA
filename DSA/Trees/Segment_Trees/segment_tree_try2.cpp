#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
        int sum;
        long long multiplication;
        node*left,*right;
        vector<int>interval;

        node(int data,int st,int end){
            this->sum=data;
            this->multiplication=data;
            interval.resize(2);
            interval[0]=st;
            interval[1]=end;
        }

        ~node(){
            cout<<"Deleting "<<sum<<endl;
        }
};

int cnt=0; 
void createSegmentTree1(node*one_node,int st,int end,vector<int>&nums){
    if(st==end){
        one_node->sum=nums[st];
        cout<<nums[st]<<" is assigned as sum to interval "<<st<<"-"<<end<<endl;
        return;
    }
    int mid=st+(end-st)/2;
    one_node->left=new node(1,st,mid);
    one_node->right=new node(1,mid+1,end);
    createSegmentTree1(one_node->left,st,mid,nums);
    createSegmentTree1(one_node->right,mid+1,end,nums);
    one_node->sum=one_node->left->sum+one_node->right->sum;
    cout<<"Sum for interval "<<one_node->interval[0]<<"-"<<one_node->interval[1]<<" is set to "<<one_node->sum<<endl;
}

node* createSegmentTree2(node*&one_node,vector<int>&nums,int st,int end){
    if(st==end){
        one_node=new node(nums[st],st,end);
        return one_node;
    }
    one_node=new node(1,st,end);
    int mid=st+(end-st)/2;
    one_node->left=createSegmentTree2(one_node->left,nums,st,mid);
    one_node->right=createSegmentTree2(one_node->right,nums,mid+1,end);
    one_node->sum=one_node->left->sum+one_node->right->sum;
    one_node->multiplication=one_node->left->multiplication*one_node->right->multiplication;
    return one_node;
}

void preetyDisplayRightSum(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRightSum(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->sum<<endl;
    } else cout<<one_node->sum<<endl;
    if(one_node->left)preetyDisplayRightSum(one_node->left,level+1);
}

void preetyDisplayRightMul(node*&one_node,int level=0){
    if(!one_node)return;
    if(one_node->right)preetyDisplayRightMul(one_node->right,level+1);
    if(level!=0){
        for(int i=0;i<level-1;i++)cout<<"|\t";
        cout<<"|----->"<<one_node->multiplication<<endl;
    } else cout<<one_node->multiplication<<endl;
    if(one_node->left)preetyDisplayRightMul(one_node->left,level+1);
}

void delete_nodes(node*&one_node){
    if(!one_node)return;
    delete_nodes(one_node->left);
    delete_nodes(one_node->right);
    delete one_node;
}

int findSum(node*&one_node,int st,int end){
    int leftInterval=one_node->interval[0];
    int rightInterval=one_node->interval[1];
    if(rightInterval<st||leftInterval>end){
        cout<<"Returning 0 from "<<leftInterval<<"-"<<rightInterval<<endl;
        return 0;
    } else if(leftInterval>=st&&rightInterval<=end){
        cout<<"Returning found sum "<<one_node->sum<<endl;
        return one_node->sum;
    } else {
        int sum=0;
        int mid=st+(end-st)/2;
        sum+=findSum(one_node->left,st,end);
        sum+=findSum(one_node->right,st,end);
        return sum;
    }
}

long long findMul(node*&one_node,int st,int end){
    int leftInterval=one_node->interval[0];
    int rightInterval=one_node->interval[1];
    if(rightInterval<st||leftInterval>end){
        cout<<"Returning 1 from "<<leftInterval<<"-"<<rightInterval<<endl;
        return 1;
    } else if(leftInterval>=st&&rightInterval<=end){
        cout<<"Returning found sum "<<one_node->sum<<endl;
        return one_node->multiplication;
    } else {
        long long mul=1;
        mul*=findMul(one_node->left,st,end);
        mul*=findMul(one_node->right,st,end);
        return mul;
    }
}

void modify1(node*&one_node,int data,int index){
    int leftInterval=one_node->interval[0];
    int rightInterval=one_node->interval[1];
    if(leftInterval==rightInterval&&leftInterval==index){
        // cout<<"Sum modified from "<<one_node->sum<<" to ";
        one_node->sum=data;
        one_node->multiplication=data;
        // cout<<one_node->sum<<" for the interval "<<leftInterval<<"-"<<rightInterval<<endl;
        return;
    } else {
        int mid=leftInterval+(rightInterval-leftInterval)/2;
        if(index<=mid){
            modify1(one_node->left,data,index);
        } else {
            modify1(one_node->right,data,index);
        }
        // cout<<"Sum of parent modified from "<<one_node->sum<<" to ";
        one_node->sum=one_node->left->sum+one_node->right->sum;
        one_node->multiplication=one_node->left->multiplication*one_node->right->multiplication;
        // cout<<one_node->sum<<" for the interval "<<leftInterval<<"-"<<rightInterval<<endl;
    }
}

int modify2(node*&one_node,int data,int index){
    int leftInterval=one_node->interval[0];
    int rightInterval=one_node->interval[1];
    if(leftInterval==rightInterval&&leftInterval==index){
        cout<<"Sum modified from "<<one_node->sum<<" to ";
        one_node->sum=data;
        cout<<one_node->sum<<endl;
        cout<<"Multiplication modified from "<<one_node->multiplication<<" to ";
        one_node->multiplication=data;
        cout<<one_node->multiplication<<endl;
        cout<<" for the interval "<<leftInterval<<"-"<<rightInterval<<endl;
        return one_node->sum;
    } else {
        int mid=leftInterval+(rightInterval-leftInterval)/2;
        if(index<=mid){
            one_node->sum =modify2(one_node->left,data,index)+one_node->right->sum;
            one_node->multiplication=one_node->right->multiplication*one_node->left->multiplication;
        } else {
            one_node->sum=modify2(one_node->right,data,index)+one_node->left->sum;
            one_node->multiplication=one_node->right->multiplication*one_node->left->multiplication;
        }
        return one_node->sum;        
    }
}

int main(){
    int n;
    cout<<"Enter how many numbers you have : ";
    cin>>n;
    node*root=nullptr;
    vector<int>nums(n);
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)cin>>nums[i];
    int m=1;
    cout<<"Create segment tree by \n1 : Method1 (assigning ptr)\n2 : Method2 (returning ptr)\nYour choice : ";
    cin>>m;
    if(m==1){
        root=new node(1,0,n-1);
        try{
            createSegmentTree1(root,0,n-1,nums);
        } catch(...){
            cout<<"Error ouccured"<<endl;
            delete_nodes(root);
        }
    } else if(m==2){
        try{
            root=createSegmentTree2(root,nums,0,n-1);
        } catch(...){
            cout<<"Error occured"<<endl;
            delete_nodes(root);
        }
    }
    
    preetyDisplayRightSum(root);
    cout<<"--------------------------"<<endl;
    preetyDisplayRightMul(root);

    int choice=1,index,data;
    while(choice){
        cout<<"1 : Find sum between an interval \n2 : Modify\n3 : Display\n4 : Find multiplication within a range\nYour choice : ";
        cin>>choice;
        if(choice==1){
            int st,end;
            cout<<"Enter interval strating point : ";
            cin>>st;
            cout<<"Enter interval ending pointing : ";
            cin>>end;
            int ans=findSum(root,st,end);
            cout<<"Sum received between interval "<<st<<"-"<<end<<" is : "<<ans<<endl;
        } else if(choice==2){
            cout<<"WHich method to use for modification\n1 : Method 1 (assigning data to index-void return type)\n2 : Method 2 (returning modified value from int type func)\nYour choice :";
            cin>>m;
            cout<<"Enter the index you want to insert : ";
            cin>>index;
            if(index<root->interval[0]||index>root->interval[1]){
                cout<<"Invalid index"<<endl;
                continue;
            }
            cout<<"Enter the new data : ";
            cin>>data;
            if(m==1){
                modify1(root,data,index);
            } else if(m==2){
                root->sum=modify2(root,data,index);
                root->multiplication=root->left->multiplication*root->right->multiplication;
            }
        } else if(choice==3){
            cout<<"Displaying sum"<<endl;
            preetyDisplayRightSum(root);
            cout<<"Displaying multiplcation"<<endl;
            preetyDisplayRightMul(root);
        } else if(choice==4){
            int st,end;
            cout<<"ENter strating point : ";
            cin>>st;
            cout<<"Enter ending point : ";
            cin>>end;
            long long mul=findMul(root,st,end);
            cout<<"Answer recived is : "<<mul<<endl;
        }
    }
    delete_nodes(root);
}