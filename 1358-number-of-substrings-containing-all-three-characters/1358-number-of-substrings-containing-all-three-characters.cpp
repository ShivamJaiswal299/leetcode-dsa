class Solution {
public:
    int numberOfSubstrings(string s) {
      //we will iterate while increasing freq and check when condition is meet and then update the cnt.
      int n = s.length();
      int low = 0, high =0;
      int cnt=0;
      vector<int> freqABC(3,0);//freq of a, b, c
      while(high<n){
        freqABC[s[high]-'a']++;
        while(freqABC[0]>=1 && freqABC[1]>=1 && freqABC[2]>=1){
          freqABC[s[low]-'a']--;
          low++;
          //cnt will be updated at last of this iteration
        }
        high++;
        cnt+=low;//here cnt is cnt + low not just cnt+1 cuz , in this way we are including all the possible strings till curr high.
        //EG -for "abcabc" at high = 3, low = 2. index 0 and 1 are also valid ("abca", "bca"), so we add 2.
      }
      return cnt;
    }
};