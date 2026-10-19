class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    if (s.size()==0) return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
  
    int happy = 0;
    int i = 0, j=0;
    while(i<g.size() && j<s.size()){
      if(g[i]<=s[j]){
        happy++;
        i++;
      }
      j++;
    }
    return happy;
    }
};


    //THIS BRUTE FORCE WILL GIVE TLE
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //   int happy = 0;
    //   sort(g.begin(), g.end());
    //   sort(s.begin(), s.end());
    //     for(int i=0;i<s.size();i++){
    //       int cookiesize = s[i];
    //       for(int j=0; j<g.size();j++){
    //         if(s[i]>=g[j]){
    //           happy++;
    //           g.erase(g.begin()+j);
    //           break;
    //         }
    //       } 
    //     }
    //   return happy;
    // }