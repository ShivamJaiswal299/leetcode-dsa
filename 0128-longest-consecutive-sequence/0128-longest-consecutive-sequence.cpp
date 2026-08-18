class Solution {
public:
    int longestConsecutive(vector<int>& a) {
      unordered_set<int>st;
      int maxlen = 0;
      for(auto x:a) st.insert(x);
      for(auto x: st){
        if(!st.count(x-1)){
          int i=1,cnt=1;
          while(1){
            if(st.count(x+(i++))) cnt++;
            else break;
          }
          maxlen=max(maxlen,cnt);
        }
      }
      return maxlen;
    }
};