class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num == 0)
                zeroCount++;
            else
                product *= num;
        }
        vector<int> res;
        for (int num : nums) {
            if (zeroCount > 1) {
                res.push_back(0);
            } else if (zeroCount == 1) {
                if (num == 0)
                    res.push_back(product);
                else
                    res.push_back(0);
            } else {
                res.push_back(product / num);
            }
        }

        return res;
    }
};