// Preorder Traversal
// Link - https://practice.geeksforgeeks.org/problems/preorder-traversal/1#



vector <int> solve(Node* root, vector <int> &v) {
    if (root == NULL) return v;

    v.push_back(root->data);

    solve(root->left, v);
    solve(root->right, v);

    return v;
}

vector <int> preorder(Node* root) {
    vector <int> v;
    return solve(root, v);
}