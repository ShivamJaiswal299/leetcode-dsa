class Solution {
public:
    void moveZeroes(vector<int>& a) {
        for(int zerohater=0,i=0;i<a.size();i++){
          if(a[zerohater]!=0) zerohater++;
          else if(a[zerohater]==0 && a[i]==0) continue;//seperate case for removing unnecessary zero-zero swap
          else swap(a[zerohater++],a[i]);
        }
    }
};