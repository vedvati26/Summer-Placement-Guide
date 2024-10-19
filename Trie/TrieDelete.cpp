/*Complete the function below
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};*/
class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
    //Code heretr
    trie_node_t* temp = root;
    int n = 0;
    bool find = true;
    while(key[n]!='\0'){
        int ind = key[n]-'a';
        if(temp->children[ind]!=NULL){
            temp  = temp ->children[ind];
            n++;
        }
        else{
            find = 0;
            break;
        }
    }
    if(find && temp->value > 0){
        temp->value = 0;
    }
    
  }
};