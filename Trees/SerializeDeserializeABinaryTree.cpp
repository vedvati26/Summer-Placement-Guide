class Solution
{
    public:
    void serializeUtil(Node*root, vector<int>&a)
    {
        if (root == NULL) {
            a.push_back(-1);
            return;
        }
        a.push_back(root->data);
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }
    vector<int> serialize(Node *root)
    {
        vector<int> serialized;
        serializeUtil(root,serialized);
        return serialized;
    }
    Node *kewl(vector<int> &a, int *index) 
    {
        if (*index == a.size() or a[*index] == -1) {
            *index += 1;
            return NULL;
        }
        Node *root = new Node(a[*index]);
        *index += 1; 
        root->left = kewl(a, index);
        root->right = kewl(a, index);
        return root;
    }
    Node *deSerialize(vector<int> &a) 
    {
        int index = 0;
        return kewl(a, &index);
    }
};
