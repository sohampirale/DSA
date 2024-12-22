#include<iostream>
#include<stack>
#include<algorithm>
#include<cctype>
using namespace std;

int precedance(char present,char newChar){
    int ret;
    if(newChar==present||(newChar=='+'&&present=='-')||(newChar=='-'&&present=='+')||(newChar=='*'&&present=='/')||(newChar=='/'&&present=='*'))return 1; //pop apppend to result and push present
    else if((newChar=='+'||newChar=='-')&&(present=='*'||present=='/'))return 2;    //higher precendance already present at the top
    else if((newChar=='*'||newChar=='/')&&(present=='+'||present=='-'))return 3;    // lower precendance already present so can push anyway
    else return -1;
}

void infixToPostFix(stack<char>&st,string& infix,string & ans){
    if(infix.empty()){
        while(!st.empty()){
            char newChar=st.top();
            st.pop();
            ans+=newChar;
        }
        return;
    }
    char newChar=infix.front();
    infix.erase(infix.begin());
    if(isalpha(newChar)){
        ans+=newChar;
    } else if(newChar=='('){
        st.push(newChar);
    } else if(newChar==')'){
        while(!st.empty()){
            char newCharApp=st.top();
            if(newCharApp=='(')break;
            ans+=newCharApp;
            st.pop();
        }
        st.pop();
    } else {
        if(st.empty()){
            st.push(newChar);
        } else {
            while(!st.empty()){
                int ret=precedance(st.top(),newChar);
                if(ret==1){
                    char temp=st.top();
                    ans+=temp;
                    st.pop();
                } else if(ret==2){
                    char temp=st.top();
                    ans+=temp;
                    st.pop();
                } else if(ret==3){
                    st.push(newChar);
                    break;
                } else if(st.top()=='('){
                    st.push(newChar);
                    break;
                }
            }
            if(st.empty()){
                st.push(newChar);
            }
        }
    }
    infixToPostFix(st,infix,ans);
}

void changeParenthesis(string& infix){
    for(char & ch : infix){
        if(ch=='(')ch=')';
        else if(ch==')')ch='(';
    }
}
void postfixToInFix(stack<string>&st,string &postfix){
    if(postfix.empty())return;
    char newChar=postfix.front();
    postfix.erase(postfix.begin());
    if(isalpha(newChar)){
        st.push(string(1,newChar));
    } else {
        string str1=st.top();
        st.pop();
        string str2=st.top();
        st.pop();
        string temp="("+str1+newChar+str2+")";
        st.push(temp);
    }
    postfixToInFix(st,postfix);
}

// string postfixToInfix(string postfix) {
//     stack<string> st;
//     for (char ch : postfix) {
//         if (isalpha(ch)) {
//             st.push(string(1, ch));
//         } else {
//             string op2 = st.top(); st.pop();
//             string op1 = st.top(); st.pop();
//             string exp = "(" + op1 + ch + op2 + ")";
//             st.push(exp);
//         }
//     }
//     return st.top();
// }

int main(){
  
    int choice;
    cout<<"Enter your chocie :\n1 : Infix to PostFix\n2 : Infix to PreFix\nYour choice : ";
    cin>>choice;
    while(choice){
        if(choice==1){
            string infix,ans="";
            cout<<"Enter infix string : ";
            cin>>infix;
            string infixCopy=infix;
            stack<char>st;
            ans="";
            infixToPostFix(st,infix,ans);
            cout<<"After infix to PostFix convertion answer becomes : "<<ans<<endl;
            infix=infixCopy;
        } else if(choice==2){
            string infix,ans="";
            cout<<"Enter infix string : ";
            cin>>infix;
            string infixCopy=infix;
            stack<char>st;
            reverse(infix.begin(),infix.end());
            changeParenthesis(infix);
            cout<<"Reversed infix is : "<<infix<<endl;
            ans="";
            infixToPostFix(st,infix,ans);
            reverse(ans.begin(),ans.end());
            cout<<"After infix to PreFix convertion answer becomes : "<<ans<<endl;
            infix=infixCopy;
        } else if(choice==3){
            string postfix;
            stack<string>st;
            cout<<"Enter postfix expression : ";
            cin>>postfix;
            postfixToInFix(st,postfix);
            string ans=st.top();
            st.pop();
            // string ans = postfixToInfix(postfix);
            if(st.empty()){
                cout<<"Stack became empty"<<endl;
            }
            cout<<"After postfix to infix convertion answer becomes : "<<ans<<endl;
            cout<<"hello"<<endl;
        } else if(choice==4){
            string prefix;
            stack<string>st;
            cout<<"Enter prefix expression : ";
            cin>>prefix;
            reverse(prefix.begin(),prefix.end());
            postfixToInFix(st,prefix);
            string ans=st.top();
            st.pop();
            cout<<"After converting prefix to infix we get : "<<ans<<endl;
        }
    }
    return 0;
}