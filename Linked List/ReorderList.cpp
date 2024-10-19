class Solution {
public:
    
    void reorderList(struct Node* head) {
        int r = 0, c;
        struct Node* temp, *temp1, *temp2, *p;
        temp = head;
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;

        while (temp != NULL) {
            r++;
            temp = temp->next;
        }

        c = (r + 1) / 2;

        temp = head;
        while (c--) {
            p = temp;
            temp = temp->next;
        }

        p->next = NULL;

        temp1 = NULL;
        temp2 = temp;
        while (temp2 != NULL) {
            p = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = p;
        }

        p = temp1;
        Node *a, *b;
        while (p) {
           a = head->next;
           b = p->next;
           
           head->next=p;
           p->next=a;
           
           head=a;
           p=b;
        }
    }
};
