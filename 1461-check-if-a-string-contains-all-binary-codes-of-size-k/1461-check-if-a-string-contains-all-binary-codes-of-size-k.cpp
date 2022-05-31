class Solution {
public:
    bool hasAllCodes(string s, int k) {
         bitset<(1 << (20 + 2))> bs;
        int cnt, val, i;
        cnt = val = 0;
        for (i = 0; i < s.size(); i++)
        {

            if (i >= k)
            {
                if (s[i - k] == '1')
                    val--;
                val /= 2;
            }

            if (s[i] == '1')
                val += 1 << min(i, k - 1);
            if (i + 1 >= k && !bs[val])
            {
                bs[val] = 1;
                cnt++;
            }
        }

        if (cnt >= (1 << k))
            return true;
        else
            return false;
    }
};