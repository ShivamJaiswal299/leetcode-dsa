class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
      //to remember it- think of the brute force but then instead of trying all the k use binary search, how to know?? cuz when things are monotonic binary can help.
        int n=a.size(),maxPiles=-1;
        for(int i=0;i<n;i++) maxPiles=max(maxPiles,a[i]);//finding max piles
        int low=1,mid,high=maxPiles;
        int ans=maxPiles;
        while(low<=high){
          mid = low + (high-low)/2;
          int k = mid;//just for convinient
          //checking wheather this k(i.e.mid) can possibly be answer or not 
          int i,tempH;
          for(i=0,tempH=h;(tempH>-1) && i<n;i++) tempH=tempH-(a[i]%k==0?a[i]/k:a[i]/k+1);
          //IMP NOTE - if k=6 , h=14 12 12 12 12 12 12 6 -> h=13 this means he gets free 1 hr before so u will think lets decrease k but if u do k=5 , then h req. will be higher , so its not neccessay that remaining h should become completely zero for finding k ,  it can be 1, 2, 3, etc 
          //also keep in mind if some k is giving temph==0 then its not neccesary that it is the minimun k that can do so eg- 26 26 26 26 26 26 26 here h=26 gives tempH=0 but h=25 too give that.
          if(tempH<0) low=mid+1; 
          else if(tempH>=0){
            ans=min(ans,mid);
            high=mid-1;
          }
        }
        return ans;
    }
};