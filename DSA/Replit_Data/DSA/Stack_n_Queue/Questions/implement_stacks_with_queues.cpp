// class MyQueue {
//     int top=0;
//     vector<int>stack;
// public:
//     MyQueue() {

//     }

//     void push(int x) {
//         stack.push_back(x);
//         top++;
//     }

//     int pop() {
//         if(!empty()){
//             MyQueue temp;
//            while(stack.size()!=0){
//                temp.stack.push_back(stack.back());
//                stack.pop_back();
//            }
//                 cout<<temp.stack.back()<<" is popped"<<endl;
//                 temp.stack.pop_back();
//             while(temp.stack.size()!=0){
//                 stack.push_back(temp.stack.back());
//                 temp.stack.po_back();
//             }
//             top=stack.size();
//         } else return -1;
//     }

//     int peek() {
//         if(!empty())return stack[top-1];
//         else return -1;
//     }

//     bool empty() {
//         return top==0;
//     }
// };

// class MyQueue {
//     int top=0;
//     vector<int>stack;
// public:
//     MyQueue() {

//     }

//     void push(int data) {
//         MyQueue temp;
//         while(!stack.empty()){
//             temp.stack.push_back(stack.back());
//             stack.pop_back();
//         }
//         stack.push_back(data);
//         cout<<stack.back()<<" is added"<<endl;
//         while(!temp.stack.empty()){
//             stack.push_back(temp.stack.back());
//             temp.stack.pop_back();
//         }
//     }

//     int pop() {
//         if(!empty()){
//             cout<<stack.back()<<" is popped"<<endl;
//             stack.pop_back();
//         } else return -1;
//     }

//     int peek() {
//         if(!empty())return stack.back();;
//         else return -1;
//     }

//     bool empty() {
//         return top==0;
//     }
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// class MyQueue {
//     int top=0;
//     vector<int>stack;
// public:
//     MyQueue() {

//     }

//     void push(int x) {
//         stack.push_back(x);
//         top++;
//     }

//     int pop() {
//         if(!empty()){
//             int ret=stack[0];
//             for(int i=1;i<top;i++)stack[i-1]=stack[i];
//             top--;
//             return ret;
//         }
//     }

//     int peek() {
//         if(!empty())return stack[0];
//     }

//     bool empty() {
//         return top==0;
//     }
// };

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */