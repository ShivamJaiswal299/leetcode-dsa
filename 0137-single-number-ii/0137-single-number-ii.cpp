class Solution {
public:
//logic: first we will count all the set bits on each index of all elements then for every index's cnt we will divide it by 3 as the same number have same bit at same index so they will add up in multiple of 3.the extra will be the value of that bit of the single appearing number.similary we will do it for all 32 bits.
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit = 0; bit<32 ; bit++){
          int cnt = 0;
          for(auto x: nums){
            cnt+=(x>>bit)&1;
          }
          if(cnt%3) ans= ans | 1<<bit;//ans + 1(with correct shifting of 1 )
        }
        return ans;
    }
};