class Solution {
public:
    int numberOfSubarrays(vector<int>&a, int k) {
      int n = a.size();
      //first convert in binary form 
      for(int i = 0 ;i<n;i++) a[i]%=2;
      //now it is in form of binary array
      int low =0, high = 0, cnt1=0,cnt2=0,sum=0;
      //phase 1 
      while(high<n){
        sum+=a[high];
        while(sum>k){
          sum-=a[low++];
        }
        cnt1+=high-low+1;
        high++;
      }
      
      //phase 2
      low=0,high=0,sum=0;
      while(high<n){
        sum+=a[high];
        while(sum>k-1){
          sum-=a[low++];
        }
        cnt2+=high-low+1;
        high++;
      }

      return cnt1-cnt2;
    }
};