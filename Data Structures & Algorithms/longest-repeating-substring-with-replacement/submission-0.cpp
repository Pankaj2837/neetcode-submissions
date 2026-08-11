class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxLen = 0;
        int maxFreq = 0;
        int p1 = 0;

        for (int p2 = 0; p2 < s.size(); p2++) {
            count[s[p2] - 'A']++;
            maxFreq = max(maxFreq, count[s[p2] - 'A']);

            while ((p2 - p1 + 1) - maxFreq > k) {
                count[s[p1] - 'A']--;
                p1++;
            }

            maxLen = max(maxLen, p2 - p1 + 1);
        }

        return maxLen;
    }
};
