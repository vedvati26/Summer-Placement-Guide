class Solution{
  public:
    Node* addPolynomial(Node *p1, Node *p2)
    {
        Node *sum = NULL; 
        Node *ptr = NULL;
        
        while( p1 || p2 )
        {
            int p,c;
            
            if(p1==NULL)
            {
                p = p2->pow;
                c = p2->coeff;
                p2 = p2->next;
            }
            
            else if(p2==NULL)
            {
                p = p1->pow;
                c = p1->coeff;
                p1 = p1->next;
            }
            
            else
            {
                int pow1 = p1->pow, pow2 = p2->pow;
                
                p = max( pow1, pow2 );
                
                c = (p1->coeff)*(pow1 >= pow2) + (p2->coeff)*(pow2 >= pow1);
                
                if (pow1 >= pow2) p1 = p1->next;
                if (pow2 >= pow1) p2 = p2->next;
            }
            
            if(!ptr)
                sum = ptr = new Node(c,p);
            else
            {
                ptr->next = new Node(c,p);
                ptr = ptr->next;
            }
        }
        return sum;
    }


};
