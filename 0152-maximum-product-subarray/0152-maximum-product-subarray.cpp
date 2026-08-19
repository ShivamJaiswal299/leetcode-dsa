class Solution {
public:
    int maxProduct(vector<int>& a) {
        //if all are +ve - np
        //if -ve are in even  - np
        //if -ve are in odd  - then if we remove 1 -ve number , the left subarray and right subarray will always be either a prefix or a suffix
        int currprePro=1,currsufPro=1,maxprePro=a[0],maxsufPro=a[a.size()-1];
        for(int i=0;i<a.size();i++){
          currprePro*=a[i];
          currsufPro*=a[a.size()-i-1];
          //first calculating max before checking zero
          maxprePro=max(maxprePro,currprePro);
          maxsufPro=max(maxsufPro,currsufPro);
          if(a[i]==0) currprePro=1;
          if(a[a.size()-i-1]==0) currsufPro=1;
        }
        return max(maxprePro,maxsufPro);
    }
};