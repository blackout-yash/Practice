// Postorder Traversal
// Link - https://practice.geeksforgeeks.org/problems/postorder-traversal/1



vector <int> solve(Node* root, vector <int> &v) {
  if (root == NULL) return v;

  solve(root->left, v);
  solve(root->right, v);

  v.push_back(root->data);

  return v;
}


vector <int> postOrder(Node* root) {
  vector <int> v;
  return solve(root, v);
}