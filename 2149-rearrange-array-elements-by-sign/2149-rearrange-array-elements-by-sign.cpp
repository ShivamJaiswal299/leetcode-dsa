class Solution {
public:
    vector<int> rearrangeArray(vector<int>&a) {
      vector<int> temp(a.size());
      int posIdx=0,negIdx=1;
      for(int i=0;i<a.size();i++){
        if(a[i]>0) {
          temp[posIdx]=a[i];
          posIdx+=2;
          }else{
          temp[negIdx]=a[i];
          negIdx+=2;
          }
      }
      return temp;
    }
};