// Binary Tree Level Order Traversal
// Link - https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector <int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                level.push_back(node -> val);
            } ans.push_back(level);
        }
        return ans;
    }
};




// Level order traversal
// Link - https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

class Solution {
public:
    vector<int> levelOrder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue <Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {

                Node* node = q.front();
                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                ans.push_back(node -> data);
            }
        }
        return ans;
    }
};