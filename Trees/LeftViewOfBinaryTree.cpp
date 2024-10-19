void leftViewUtil(vector<int>&vec,struct Node *root, int level,int *max_level)
{
    if (root==NULL)  return;
    if (*max_level < level)
    {
        vec.push_back(root->data);
        *max_level = level;
    }
    leftViewUtil(vec,root->left, level+1, max_level);
    leftViewUtil(vec,root->right, level+1, max_level);
}
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> vec;
    leftViewUtil(vec,root, 1, &max_level);
    return vec;
}
