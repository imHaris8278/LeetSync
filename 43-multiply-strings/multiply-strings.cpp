class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;

                int sum = product + result[p2];

                result[p1] += sum / 10;
                result[p2] = sum % 10;

            }
        }

        int i = 0;
        while (i < n1 + n2 && result[i] == 0)
        {
            i++;
        }

        string ans = "";
        for (; i < n1 + n2; i++)
        {
            ans += to_string(result[i]);
        }

        return ans;
    }
};