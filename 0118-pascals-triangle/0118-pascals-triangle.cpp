class Solution {
public:
// THE nCr METHOD-
    // long long ncr(int n, int r){
    //   long long ans = 1;
    //   for(int i=0;i<r;i++) {
    //     ans*=n-i;
    //     ans/=i+1;
    //   }
    //   return ans;
    // }
    // vector<vector<int>> generate(int n) {
    //     vector<vector<int>> matrix;
    //     for(int i=1;i<=n;i++){
    //       vector<int> temp;
    //       for(int j=1;j<=i;j++) temp.push_back(ncr(i-1,j-1));
    //       matrix.push_back(temp);
    //     }
    //     return matrix;
    // }
// THE OPTIMIZED FORMULA METHOD-
    vector<vector<int>> generate(int n) {
        vector<vector<int>> matrix;
        for(int i=1;i<=n;i++){
          vector<int> temp;
          int ans=1;
          for(int j=1;j<=i;j++){
            if(j==1) temp.push_back(1);
            else{
              temp.push_back(ans=(ans*(i-j+1))/(j-1));
            }
          }
          matrix.push_back(temp);
        }
        return matrix;
    }
};