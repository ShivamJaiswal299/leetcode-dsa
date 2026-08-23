class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int maxBloomday=1,n=a.size();
        if(n<(long long)m*k) return -1;//if total flowers are less then that are req, then its not possible.
        for(int i=0;i<n;i++) maxBloomday=max(maxBloomday,a[i]);
        //binary search tech
        int low = 1,mid,high = maxBloomday,minDay=maxBloomday+1;
        while(low<=high){
          mid=low + (high-low)/2;
          int currDay=mid;
          int tempReqBouquet=m;
          int tempReqFlower=k;
          for(int i=0;i<n;i++){
            if(currDay>=a[i]) tempReqFlower--;
            else tempReqFlower=k;
            //now 1 bouquet is made
            if(tempReqFlower==0){
              tempReqBouquet--;
              tempReqFlower=k;
            }
          }
          // checking that all bouquet are made or not
            if(tempReqBouquet<=0){
              minDay=min(minDay,currDay);
              high=mid-1;
            }
            else{
              low=mid+1;
            }
        }
        //-1 if not possible
        return minDay==maxBloomday+1?-1:minDay;
    }
};