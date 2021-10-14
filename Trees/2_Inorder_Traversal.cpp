// Inorder Traversal
// Link - https://practice.geeksforgeeks.org/problems/inorder-traversal/1



class Solution {
public:
    vector <int> solve(Node* root, vector <int> &v) {
        if (root == NULL) return v;

        solve(root->left, v);

        v.push_back(root->data);

        solve(root->right, v);

        return v;
    }


    vector<int> inOrder(Node* root) {
        vector <int> v;
        return solve(root, v);
    }
};