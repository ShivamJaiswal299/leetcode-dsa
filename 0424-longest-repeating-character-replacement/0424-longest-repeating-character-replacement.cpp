class Solution {
public:
    int characterReplacement(string &s, int k) {
      int n = s.length();
      int low = 0, high=0;
      int maxlen = 0, maxfreq = 0;
      vector<int> freq(26,0);
      while(high<n){
        freq[s[high]-'A']++;
        maxfreq = max(maxfreq,freq[s[high]-'A']);
        //now we have to check that is the substring valid or not.
        // while((high-low+1) - maxfreq> k){ //this first make invalid to valid.
        //   //we have to trim down the substring.
        //   freq[s[low]-'A']--;//updating the freq
        //   maxfreq = 0; //as it will be calculated again now.
        //   for(int i=0;i<26;i++) maxfreq=max(maxfreq,freq[i]);
        //   low++;
        // }
        // //now we will surely have a valid substring.
        // maxlen=max(maxlen,high-low+1);
        // high++;


        if((high-low+1) - maxfreq> k){ 
          freq[s[low]-'A']--;
          for(int i=0;i<26;i++) maxfreq=max(maxfreq,freq[i]);
          low++;
        }
        
        if(high-low+1 - maxfreq <= k) maxlen=max(maxlen,high-low+1);
        high++;
        
        
      }
      return maxlen;
    }

};