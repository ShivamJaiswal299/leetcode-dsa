class Solution {
public:
    int singleNumber(vector<int>& a) {
      //XOR OF 2 NO. IS ZERO AND XOR OF X AND 0 IS X.
      int result=0;
      for(auto x : a) result^=x;
      return result;
    }
};