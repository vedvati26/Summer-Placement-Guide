class Solution {
  public:
    unsigned int countNodes(struct Node* root) {
        if (root == NULL) return (0);
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    bool isValid(Node* tree, int level, int no) {
        if (tree == NULL) return true;
        if (level >= no) return false;
        return isValid(tree->left, 2 * level + 1, no) and
               isValid(tree->right, 2 * level + 2, no);
    }
    bool propHoldes(Node* root) {
        if (!root->left and !root->right) return true;
        if (root->right == NULL)
            return root->data > root->left->data;
        else {
            if (root->data >= root->left->data and
                root->data >= root->right->data)
                return propHoldes(root->left) and propHoldes(root->right);
            else
                return false;
        }
    }
    bool isHeap(struct Node* tree) {
        if (tree == NULL) return true;
        int no_of_nodes = countNodes(tree);
        if (isValid(tree, 0, no_of_nodes) and propHoldes(tree)) return true;
        return false;
    }
};
