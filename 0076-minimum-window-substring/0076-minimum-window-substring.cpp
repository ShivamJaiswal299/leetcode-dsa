class Solution {
public:
    string minWindow(string s, string t) {
      int m = s.size(), n = t.size();
      int low = 0, high = 0 , minlen = INT_MAX,startIdx = -1, cnt = 0;//cuz we will generate the string from startindex and len of that string using .substr(), and cnt is for counting number of char that has been satisfied.
      vector<int>freqoft(128,0);
      for(int i = 0; i<n;i++) freqoft[t[i]]++; //hashing the string t with freq. in this hashmap is the value is positive this means u need that char from s.
      while(high<m){
        if(freqoft[s[high]]>0) cnt++; //it means char from s exist in t. so cnt increases.
        freqoft[s[high]]--; //cuz we need less or none of this char now.
        while(cnt==n){ //when string is valid but large , we shorten it.
          if(high-low+1 < minlen){
            minlen= high-low+1;
            startIdx=low;
          }
          
          freqoft[s[low]]++;//dont get confuse here, ++ means char at low is removed. cuz when its value increases this means u need more of this character from s.
          if(freqoft[s[low]]>0) cnt--;
          low++;
        }
        high++;
      }
      return startIdx == -1 ? "" : s.substr(startIdx,minlen);
    }
};