class Solution {
public:
// Space: O(1) , Time: O(n³)
    vector<vector<int>> fourSum(vector<int>& a, int key) {
// 2 pointer approach - also using long long cuz test case has overflowing inputs
        int n = a.size();
        if(n<4) return {};
        vector<vector<int>> result;
        sort(a.begin(),a.end());
        for(int i = 0; i < n-3 ; i++){
          if(i>0 && a[i-1]==a[i]) continue;
          for(int j = i+1 ; j < n-2 ; j++){
            if(j>i+1 && a[j-1]==a[j]) continue;

            long long comp = (long long)key - a[i] - a[j];
            // 2 SUM NOW - by 2 pointer starts here
            int left = j+1, right = n - 1;
            while(left < right){
              if((long long)a[left]+a[right]<comp) left++;
              else if((long long)a[left]+a[right]>comp) right--;
              else if((long long)a[left]+a[right]==comp){
                while(left<right && a[left]==a[left+1]) left++;//SKIPPING ALL DUPLICATE
                while(left<right && a[right]==a[right-1]) right--;//SKIPPING ALL DUPLICATE
                result.push_back({a[i],a[j],a[left++],a[right--]});
              }
            }
          }
        }
        return result;
    }
};