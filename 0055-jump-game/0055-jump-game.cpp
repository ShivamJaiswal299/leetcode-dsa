class Solution {
public:
//NOTE - here only 0 is creating ressistence , if we cant jump over it then we fail.
    bool canJump(vector<int>& a) {
      int jump = a[0];
      for(int i=1;i<a.size();i++){
        if(jump<=0) return false;
        if(jump-1<=a[i]) jump=a[i];
        else{
          jump--;
        }
      }
      //also if last elemnt is 0 then also its true cuz its the last index so no need to jump.
      return true;
    }
};