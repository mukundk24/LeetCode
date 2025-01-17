class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        else
        {
            int temp = q1.back();
            if (q1.size() == 1)
            {
                q1.pop();
                return temp;
            }
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1 = q2;
            while (!q2.empty())
                q2.pop();
            return temp;
        }
    }

    int top()
    {
        if (q1.empty())
            return -1;
        else
            return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};
