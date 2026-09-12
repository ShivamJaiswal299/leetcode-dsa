class Solution {
public:
    string longestPalindrome(string s) {
      //LOGIC- for every palindrome , it will have a center, so we iterate every element assuming it as center and expand it till the left and right pointer are coming same
      // we will handle even and odd case seperately
        string ans="";
        int ansLen=0;
        for(int i=0;i<s.length();i++){
          //odd case - if answer will be even substring then it will not run.
          int left=i,right=i;
          while((0<=left && right<s.length()) && s[left]==s[right]){
            if(ansLen<(right-left+1)){
              ans = s.substr(left,right-left+1);
              ansLen = right - left +1;
            }
            left--;
            right++;
          }
          //even- if answer will be odd substring then it will not run as odd case ran above and pointer are at boundary.
          left=i,right=i+1;  
          while((0<=left && right<s.length()) && s[left]==s[right]){
            if(ansLen<(right-left+1)){
              ans = s.substr(left,right-left+1);
              ansLen = right - left +1;
            }
            left--;
            right++;
          }  
        }
        return ans;
    }
};