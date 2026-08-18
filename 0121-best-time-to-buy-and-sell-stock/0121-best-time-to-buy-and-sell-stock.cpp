class Solution {
public:
    int maxProfit(vector<int>& a) {
      int maxProfit=INT_MIN,minPrice=a[0];
      for(int i=1;i<a.size();i++){
        maxProfit=max(maxProfit,a[i]-minPrice);
        minPrice=min(minPrice,a[i]);
      }
      if(maxProfit<=0) return 0;
      return maxProfit;
    }
};