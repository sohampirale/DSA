/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> helper_ZigZagTraversal103(stack<TreeNode*>&loc,stack<TreeNode*>&newLoc,bool takeFromLeft){
            vector<int>LevelAns;
            while(!loc.empty()){
                auto it=loc.top();
                if(takeFromLeft){
                    if(it->left){
                        LevelAns.push_back(it->left->val);
                        newLoc.push(it->left);
                    }
                    if(it->right){
                            LevelAns.push_back(it->right->val);
                            newLoc.push(it->right);
                    }
                } else {
                    if(it->right){
                            LevelAns.push_back(it->right->val);
                            newLoc.push(it->right);
                    }
                    if(it->left){
                        LevelAns.push_back(it->left->val);
                        newLoc.push(it->left);
                    }
                }
                loc.pop();
            }
            return LevelAns;
        }

    vector<vector<int>> ZigZagTraversal103(stack<TreeNode*>&loc,vector<vector<int>>&answer,bool takeFromLeft){
                if(loc.empty())return answer;
                stack<TreeNode*>newLoc;
                vector<int>LevelAns=helper_ZigZagTraversal103(loc,newLoc,takeFromLeft);
                if(!LevelAns.empty())answer.push_back(LevelAns);
                return ZigZagTraversal103(newLoc,answer,!takeFromLeft);
        }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if(!root)return answer;
        vector<int>temp;
        temp.push_back(root->val);
        answer.push_back(temp);
        stack<TreeNode*>loc;
        loc.push(root);
        return ZigZagTraversal103(loc,answer,false);
    }
};