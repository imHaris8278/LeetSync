class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1.0;
        }

        if (n < 0)
        {
            x = 1 / x;
            if (n == INT_MIN) {
                n += 2;
            }
            n = -n;
        }

        double result = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            n /= 2;
        }

        return result;
    }
};