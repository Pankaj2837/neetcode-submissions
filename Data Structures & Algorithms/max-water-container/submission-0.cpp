class Solution {
   public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int left =0;
        int right =n - 1;
        int currArea = 0;
        int maxArea = 0;
        while (left < right) {
            int width = right - left;
            int hight = min(h[left], h[right]);
            currArea = width * hight;
            maxArea = max(currArea, maxArea);
            if(h[left]< h[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};
