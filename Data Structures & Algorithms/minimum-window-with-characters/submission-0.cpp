class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m > n || n == 0 || m == 0) {
            return "";
        }

        int count = 0;
        vector<int> hash(256, 0);
        int l = 0, r = 0;
        int sIndex = -1;
        int minLen = INT_MAX;

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};
