class Solution {
public:
    int majorityElement(vector<int>& a) {
      // BY MOORE'S VOTING ALGORITHM
      //hint- the king with most soldier will win , every number kills another number but not if the number is same , so at last only same numbers will only remain , thats majority!
      int count=0,element;
      for(int i=0;i<a.size();i++){
        if(count==0){
          element=a[i];
          count++;
        }
        else{
          if(a[i]==element) count++;
          else count--;
        }
      }
      return element;
    }
};