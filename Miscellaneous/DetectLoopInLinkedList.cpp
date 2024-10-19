/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node *temp=new Node(1);
        Node *curr=head;
        while(curr!=NULL){
            if(curr->next==NULL){
                return false;
            }
            if(curr->next==temp){
                return true;
            }
            Node *curr_nex=curr->next;
            curr->next=temp;
            curr=curr_nex;
        }
        
    }
};