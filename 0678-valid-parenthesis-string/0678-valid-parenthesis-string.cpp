class Solution {
public:
    bool checkValidString(string s) {
      // here instead of just keeping 1 variable cnt, we use 2 variable low and high to track the range of the possible ans. logic is that, whenever the high is negative we return false, and whenever the low becomes -ve we skip that possiblity and make it 0.
      int low = 0;
      int high = 0;
      for(char &x:s){
        if(x=='('){
          low++;
          high++;
        }
        else if(x==')') {
          low--;
          high--;
        }
        else if(x=='*') {
          low--;
          high++;
        }
        if(high<0) return false;//high is the one that is adding all +ve , if still it cant keep up being >=0 then string not valid.
        if(low<0) low=0;//this skips the case where low is taking extra closing brackets ie its skipping that possiblity by making the -1 to 0.
      }
      // if(low==0) return true;
      // else return false;
      // or
      return low==0;
    }
};