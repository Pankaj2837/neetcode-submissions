class Solution {
   public:
    string filString = "";
    bool isPalindrome(string s) {
        if (s.size() == 1) {
                return true;
          
        }
        for (char c : s) {
            if (isalnum(c)) {
                filString += c;
            }
        }
        cout << s;
        int n = filString.size();
        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 < ptr2) {
            if (tolower(filString[ptr1]) != tolower(filString[ptr2])) return false;

            ptr1++;
            ptr2--;
        }
        return true;
    }
};
