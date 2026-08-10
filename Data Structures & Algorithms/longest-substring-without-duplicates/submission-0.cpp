class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // Rule 2: Duplicate milne par shrink karo
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            // Rule 1: Set mein add karo aur maxLen update karo
            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
