class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
      // Step 1: XOR all numbers. Pairs cancel, so xorofa = x ^ y (the two single numbers)
      int xorofa=0;
      for(int i=0;i<a.size();i++) xorofa = xorofa^a[i];

      int idx = 0;
      while(xorofa){
        // Step 2: find any set bit in xorofa -> x and y differ at this bit
        if(((xorofa>>idx)&1) == 1){
          // Step 3: split numbers into 2 groups by this bit
          // (pairs stay together, x and y go to different groups)
          vector<vector<int>> grpAB(2);
          for(int x:a){
            int bit = (x>>idx)&1;
            if(bit == 0) grpAB[0].push_back(x);
            else grpAB[1].push_back(x);
          }
          // Step 4: XOR each group -> pairs cancel, one single number is left
          int xorgrpA = 0;
          for(int x: grpAB[0]) xorgrpA=xorgrpA^x;
          int xorgrpB = 0;
          for(int x: grpAB[1]) xorgrpB=xorgrpB^x;
          return {xorgrpA,xorgrpB};
        }
        idx++; // move to next bit
      }
      return {}; // never reached, since x != y means xorofa != 0
    }
};