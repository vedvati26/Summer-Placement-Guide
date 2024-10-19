
void MyQueue:: push(int a)
{
    if (rear==NULL)
    {
        rear= new QueueNode(a);
        front = rear;
    }
   else
   {
        QueueNode *temp = new QueueNode(a);
        rear->next =temp;
        rear = temp;
    }
}
int MyQueue :: pop()
{
       
    QueueNode *temp;
    temp=front;
    if(temp ==NULL)
        return -1;
    if(temp->next !=NULL)
    {
        temp=temp->next;
        int k = front->data;
        delete(front);
        front = temp;
        return k;
    }
    else
    {
        int k=front->data;
        delete(front);
        front=rear=NULL;
        return k;
    }


}
