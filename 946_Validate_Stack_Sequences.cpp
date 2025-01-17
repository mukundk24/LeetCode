class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int i = 0, j = 0;
        st.push(pushed[i++]);
        while (i < pushed.size() && j < popped.size())
        {
            if (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            else
                st.push(pushed[i++]);
        }
        while (j < popped.size())
        {
            if (popped[j] == st.top())
            {
                st.pop();
                j++;
            }
            else
                return false;
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};