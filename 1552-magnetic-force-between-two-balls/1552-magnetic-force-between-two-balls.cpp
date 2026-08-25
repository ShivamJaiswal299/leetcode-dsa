class Solution {
public:
//doing this as it is aggressive cow problem
    int maxDistance(vector<int>& a, int cows) {
      int n = a.size(),minPos=a[0],maxPos=a[0];
      sort(a.begin(),a.end());
      for(int i=0;i<n;i++){
          minPos=min(minPos,a[i]);
          maxPos=max(maxPos,a[i]);
      }
      int low = 1, mid, high= maxPos-minPos-(cows-1)+1;
      int ans= -1;
      while(low<=high){
        mid = low + (high-low)/2;
        int tempDist=mid;
        int tempcows = cows;
        tempcows--; // first place fixed for 1 cow
        int prevPos=a[0];
        for(int i=1;i<n;i++){
          if((a[i]-prevPos)<tempDist) continue;
          else if ((a[i]-prevPos)>=tempDist) {
            tempcows--;
            prevPos=a[i];
            }
        }
        if(tempcows>0) high = mid -1;
        else {
          ans=mid;
          low = mid +1;
          }
      }
      return ans;
    }
};