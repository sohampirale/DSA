#include<iostream>
using namespace std;
int find(int st,int end){
    int mid,choice,cnt=0,guess;
    while(st<=end){
        cnt++;
        mid=st+(end-st)/2;
        cout<<"Was it "<<mid<<" ?\n1 : Yes\n0 : No\nYour choice : ";
        cin>>guess;
        if(guess==1){
            return cnt;
        } else {
            cout<<"Is "<<mid<<" 'greater' than secret number ?\n1 : Yes\n0 : No\nYour choice : " ;
            cin>>choice;
            if(choice==1)end=mid-1;
            else st=mid+1;
        }
    }
    cout<<"It seems like you have entered some wrong input"<<endl;
    return -1;
}
int main(){
    int n;
    cout<<"Enter a secret number : ";
    cin>>n;
    int guess,choice,choice_right;
    int st=0,end=4,mid,cnt=0,ans=-1;
    while(st<=end){
        cnt++;
        mid=st+(end-st)/2;
        cout<<"Was it "<<end<<"?\n1 : Yes & 0 : No\nYour choice : ";
        cin>>guess;
        if(guess==1)break;
        else {
            cout<<"Is the secret number greater than "<<end<<" ?\n1 : Yes & 0 : No\nYour choice : ";
            cin>>choice;
            if(choice==1){
                int temp=end;
                end=end+(end-st+1);
                st=temp;
            } else {
                ans=find(st,end);
                cout<<"Inner count = "<<cnt<<endl;
                cnt+=ans;
                break;
            }
        }
    }
    if(ans!=-1){
        cout<<"Mid = "<<mid<<endl;
        cout<<"We found the number in "<<cnt<<" tries"<<endl;
    } else {
        cout<<"Some input mistake happend by user"<<endl;
    }
    return 0;
}

// Enter a secret number : 7
// Was it 4?
// 1 : Yes & 0 : No
// Your choice : 0
// Is the secret number greater than 4 ?
// 1 : Yes & 0 : No
// Your choice : 1
// Was it 9?
// 1 : Yes & 0 : No
// Your choice : 0
// Is the secret number greater than 9 ?
// 1 : Yes & 0 : No
// Your choice : 0
// Was it 6 ?
// 1 : Yes
// 0 : No
// Your choice : 0
// Is 6 'greater' than secret number ?
// 1 : Yes
// 0 : No
// Your choice : 0
// Was it 8 ?
// 1 : Yes
// 0 : No
// Your choice : 0
// Is 8 'greater' than secret number ?
// 1 : Yes
// 0 : No
// Your choice : 1
// Was it 7 ?
// 1 : Yes
// 0 : No
// Your choice : 1
// Inner count = 2
// Mid = 6
// We found the number in 5 tries