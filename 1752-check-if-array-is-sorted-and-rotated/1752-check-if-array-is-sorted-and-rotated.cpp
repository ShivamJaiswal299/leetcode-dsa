class Solution {
public:
    bool check(vector<int>& a) {
      int breaks = 0;
      for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]) breaks++;
      }
      if(a[a.size()-1]>a[0]) breaks++;
      if(breaks<=1) return true;
      else return false;
    
    // BRUTE FORCE
    // ----------------------------------------------
    //   for(int i=0;i<a.size();i++){
    //     bool issorted = true;
    //     for(int j=i;j<a.size()-1;j++){
    //       if(a[j]>a[j+1]){
    //         issorted = false;
    //         continue;
    //       }
    //     }
    //     if(i){
    //       if(a[a.size()-1]>a[0]) {
    //         issorted = false;
    //         continue;
    //       }
    //       for(int j=0;j<i-1;j++){
    //       if(a[j]>a[j+1]) {
    //         issorted = false;
    //         continue;
    //       }
            
    //       }
    //     }
    //     if(issorted) return true; 
    //   }  
    // return false;
    // ----------------------------------------------
    }
};