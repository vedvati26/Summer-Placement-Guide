void QueueStack ::push(int num){
    while(!q1.empty())
    {
        int k = q1.front();
        q1.pop();
        q2.push(k);
    }
    q1.push(num);
    while(!q2.empty())
    {
        int k = q2.front();
        q2.pop();
        q1.push(k);
    }
} 
int QueueStack ::pop(){
    if(!q1.empty())
    {
        int r = q1.front();
        q1.pop();
        return r;
    }
    return -1;
}
