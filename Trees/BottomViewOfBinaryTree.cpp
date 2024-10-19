class Solution {
  public:
    vector <int> bottomView(Node *root)
    {
        vector <int> res;
        if (root == NULL)
            return res;
        int hd = 0;
        map<int, int> m;
        map<Node  *, int> mh;
        queue<Node *> q;
        mh[root] = hd;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            hd = mh[temp];
            m[hd] = temp->data;
            if (temp->left != NULL)
            {
                mh[temp->left] = hd-1;
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                mh[temp->right] = hd+1;
                q.push(temp->right);
            }
        }
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            res.push_back (i->second);
        return res;
    }
};
