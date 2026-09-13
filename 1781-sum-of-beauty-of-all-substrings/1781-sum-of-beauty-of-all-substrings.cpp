class Solution {
public:
    int beautySum(string s) {
      //this is a 26.n^2 time complexity soln , which makes it n^2 not n^3. u will understand ahead.
      int ans=0;
      for(int i=0;i<s.length();i++){
        int freq[26]={};
        for(int j=i;j<s.length();j++){
          //here the calculating beauty is a constant time task, as it doesnt depend on input string length, it just loop on freq array which is of constant length , thatswhy n^2.
          freq[s[j]-'a']++;
          //calculating beauty for this substring
          int minfreq=s.length(),maxfreq=0;
          for(int x:freq){
            maxfreq=max(maxfreq,x);
            if(x!=0) minfreq=min(minfreq,x);
          }
          ans+=maxfreq-minfreq;
        }
      }
    return ans;
    }
};