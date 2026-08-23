class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n=a.size(),maxPiles=-1;
        for(int i=0;i<n;i++) maxPiles=max(maxPiles,a[i]);
        int low=1,mid,high=maxPiles;
        int ans=maxPiles;
        while(low<=high){
          mid = low + (high-low)/2;
          int k = mid;
          //checking wheather this k(i.e.mid) can possibly be answer or not 
          int i,tempH;
          for(i=0,tempH=h;(tempH>-1) && i<n;i++) tempH=tempH-(a[i]%k==0?a[i]/k:a[i]/k+1);
          //IMP NOTE - if k=6 , h=14 12 12 12 12 12 12 6 -> h=13 this means he gets free 1 hr before so u will think lets decrease k but if u do k=5 , then h req. will be higher , so its not neccessay that remaining h should become completely zero for finding k ,  it can be 1, 2, 3, etc 
          if(tempH<0) low=mid+1; 
          else if(tempH>=0){
            ans=min(ans,mid);
            high=mid-1;
          }
        }
        return ans;
    }
};