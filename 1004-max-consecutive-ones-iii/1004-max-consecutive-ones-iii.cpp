class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int low = 0, high = 0, maxlen = 0;

        while(high < a.size()) {
          //nothing for case where value is 1 cuz there we just have to increment high.
            if (a[high] == 0) k--; 
            while (k < 0) { //runs only when k finishes
                if (a[low] == 0) k++;
                low++;
            }
            maxlen = max(maxlen, high - low + 1);
            high++;//in both the cases we have to increment high
        }
        return maxlen;
    }
};