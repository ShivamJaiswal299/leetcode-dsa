class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit = 0; bit<32 ; bit++){
          int cnt = 0;
          for(auto x: nums){
            cnt+=(x>>bit)&1;
          }
          if(cnt%3) ans= ans | 1<<bit;
        }
        return ans;
    }
};