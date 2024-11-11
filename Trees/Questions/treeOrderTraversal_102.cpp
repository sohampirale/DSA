
class Solution {
public:

    void addAddrInQueue(TreeNode*& one_node,queue<TreeNode*>&loc){
        if(one_node->left){
            loc.push(one_node->left);
        }
        if(one_node->right){
            loc.push(one_node->right);
        }
    }

    void levelOrderTraversal(queue<TreeNode*>&loc,vector<vector<int>>&answer){
          
            if(loc.empty()){
                return;
            }
            int size=loc.size();
            auto it=loc.front();
            vector<int>level;
            for(int i=0;i<size;i++){
                it=loc.front();
                addAddrInQueue(it,loc);
                level.push_back(it->val);
                loc.pop();
            }
            answer.push_back(level);
            levelOrderTraversal(loc,answer);
        }

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if(root==nullptr){
            return answer;
        }
        queue<TreeNode*>loc;
        loc.push(root);
        levelOrderTraversal(loc,answer);
        return answer;
    }
};