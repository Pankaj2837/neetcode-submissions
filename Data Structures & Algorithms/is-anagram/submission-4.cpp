class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> ms, mt;
        for (char c : s) ms[c]++;
        for (char c : t) {
                mt[c]++;
                
        }
        for (char c : t) {
            if (ms[c] != mt[c]) return false;
        }
        return true;
    }
};
