class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int maxcount=0,count=0;
        for(auto x: a){
          if(x) maxcount=max(maxcount,++count);
          else count=0;
        }
        return maxcount;
    }
};