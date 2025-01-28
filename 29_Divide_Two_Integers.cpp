class Solution
{
public:
    int divide(long dividend, long divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (dividend == 1 && divisor == 1)
            return 1;
        bool sign = true;

        if (dividend > 0 && divisor < 0)
            sign = false;
        if (dividend < 0 && divisor > 0)
            sign = false;
        long n = abs(dividend);
        long d = abs(divisor);
        long ans = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
                cnt++;
            ans += 1 << cnt;
            n -= d * (1 << cnt);
        }
        cout << ans << endl;
        if (ans > INT_MAX && sign)
            return INT_MAX;
        if (ans > INT_MAX && !sign)
            return INT_MIN;

        return sign ? ans : ans * (-1);
    }
};