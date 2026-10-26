class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();
      int freq[256]={0};
      int currlen = 0, maxlen = 0;
      int high = 0, low = 0;
      while(high<n){
        if(freq[s[high]] == 0){
          freq[s[high]]++;
          currlen++;
        }else{
          // remove from the left until we reach the old duplicate
          while(s[low] != s[high]){
            freq[s[low]] = 0;
            currlen--;
            low++;
          }
          // skip the old duplicate itself.
          // old one removed, new one added, so currlen stays the same
          low++;
        }
       
        maxlen=max(maxlen,currlen);
        high++;
      }
      return maxlen;
    }
};