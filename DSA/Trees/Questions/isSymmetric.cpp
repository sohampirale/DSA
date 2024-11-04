typedef struct TreeNode node;
// class Solution {
// public:

//     void addAddrIsSymmetricLeft(node*&one_node,deque<node*>&temp){
//             if(!one_node)return;
//             if(one_node->left){
//                 temp.push_front(one_node->left);
//             }
//             if(one_node->right){
//                 temp.push_front(one_node->right);
//             }
//         }

//         void addAddrIsSymmetricRight(node*&one_node,deque<node*>&temp){
//             if(!one_node)return;
//             if(one_node->right){
//                 temp.push_back(one_node->right);
//             }
//             if(one_node->left){
//                 temp.push_back(one_node->left);
//             }
//         }

//         bool isSymettric_helper(node*&root){
//             if(!root->left&&!root->right){
//                 return true;
//             } else if(!root->left||!root->right){
//                 return false;
//             }

//             deque<node*>answer,temp;
//             answer.push_front(root->left);
//             answer.push_back(root->right);
//             while(!answer.empty()){
//                 int size=answer.size();
//                 auto left_it=answer.front(),right_it=answer.back();
//                 for(int i=0;i<size/2;i++){
//                     left_it=answer.front();
//                     right_it=answer.back();
//                     if(left_it->val!=right_it->val){
//                         return false;
//                     }
//                     addAddrIsSymmetricLeft(left_it,temp);
//                     addAddrIsSymmetricRight(right_it,temp);
//                     answer.pop_front();
//                     answer.pop_back();
//                 }
//                 answer=temp;
//                 cout<<"deque is : "<<endl;
//                 while(!temp.empty()){
//                     cout<<temp.front()->val<<" ";
//                     temp.pop_front();
//                 }
//                 cout<<endl;
//             }
//             return true;
//         }



//     bool isSymmetric(TreeNode* root) {
//         return isSymettric_helper(root);
//     }
// };