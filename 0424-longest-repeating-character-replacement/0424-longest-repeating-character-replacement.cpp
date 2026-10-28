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
        // now we have to check that is the substring valid or not.
        /* COMMENT THE BELOW OPTIMIZATION TO UNDERSTAND IT FIRST.
        while((high-low+1) - maxfreq> k){ //this first make invalid to valid.
          //we have to trim down the substring.
          freq[s[low]-'A']--;//updating the freq
          maxfreq = 0; //as it will be calculated again now.
          for(int i=0;i<26;i++) maxfreq=max(maxfreq,freq[i]);
          low++;
        }
        //now we will surely have a valid substring.
        maxlen=max(maxlen,high-low+1);
        high++;
        */

// Optimization: the window never shrinks in size, it only grows or slides.
// maxfreq is never decreased, so it may be stale (too large), but a stale value
// can never create a longer valid window than a real one would. The answer
// only improves when a new real maxfreq is found, so stale maxfreq is safe.
// Because of this, "if" is enough instead of "while", and no recalculation is needed.
  
        if((high-low+1) - maxfreq> k){ 
          freq[s[low]-'A']--;
          low++;
        }
        
        maxlen=max(maxlen,high-low+1);
        high++;
        
        
      }
      return maxlen;
    }

};