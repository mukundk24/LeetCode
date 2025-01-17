class MinStack
{
public:
    stack<int> st;
    stack<int> temp;
    int mini;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            temp.push(val);
        }
        if (val <= mini)
        {
            mini = val;
            temp.push(mini);
        }
        st.push(val);
    }

    void pop()
    {
        if (st.top() == mini)
        {
            if (!temp.empty())
            {
                temp.pop();
                mini = temp.top();
            }
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};
