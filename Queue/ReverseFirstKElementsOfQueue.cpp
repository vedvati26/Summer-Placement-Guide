class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        queue<int> qq;
        while (k-- > 0) {
            int a = q.front();
            q.pop();
            s.push(a);
        }
        while (!s.empty()) {
            int a = s.top();
            s.pop();
            qq.push(a);
        }
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            qq.push(a);
        }
        return qq;
    }
};
