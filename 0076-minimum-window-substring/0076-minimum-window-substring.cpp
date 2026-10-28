class Solution {
public:
    string minWindow(string s, string t) {
      int m = s.size(), n = t.size();
      int low = 0, high = 0 , minlen = INT_MAX,startIdx = -1, cnt = 0;
      vector<int>freqoft(128,0);
      for(int i = 0; i<n;i++) freqoft[t[i]]++;
      while(high<m){
        if(freqoft[s[high]]>0) cnt++; //as this char of string s is in t.
        freqoft[s[high]]--;
        while(cnt==n){
          if(high-low+1 < minlen){
            minlen= high-low+1;
            startIdx=low;
          }
          //lets remove extra from low side.
          freqoft[s[low]]++;
          if(freqoft[s[low]]>0) cnt--;
          low++;
        }
        high++;
      }
      return startIdx == -1 ? "" : s.substr(startIdx,minlen);
    }
};