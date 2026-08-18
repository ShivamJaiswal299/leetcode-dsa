class Solution {
public:
    void nextPermutation(vector<int>&a) {
        //THROUGH INBUILD FUNCTION
        // next_permutation(a.begin(),a.end());
      int pivot=-1;
      for(int i=a.size()-2;i>=0;i--){
        if(a[i]<a[i+1]){
          pivot=i;
          break;
        }
      }
      for(int i=a.size()-1;i>=0;i--){
        if(pivot!=-1 && a[pivot]<a[i]){
          swap(a[pivot],a[i]);
          break;
        }
      }
      reverse(a.begin()+pivot+1,a.end());
    }
};