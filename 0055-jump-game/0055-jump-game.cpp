class Solution {
public:
    bool canJump(vector<int>& a) {
      int jump = a[0];
      for(int i=1;i<a.size();i++){
        if(jump<=0) return false;
        if(jump-1<=a[i]) jump=a[i];
        else{
          jump--;
        }
      }
      return true;
    }
};