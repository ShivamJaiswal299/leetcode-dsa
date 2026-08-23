class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int maxBloomday=1,n=a.size();
        for(int i=0;i<n;i++) maxBloomday=max(maxBloomday,a[i]);
        int low = 1,mid,high = maxBloomday,minDay=maxBloomday+1;
        while(low<=high){
          mid=low + (high-low)/2;
          int currDay=mid;
          int tempReqBouquet=m;
          int tempReqFlower=k;
          for(int i=0;i<n;i++){
            if(currDay>=a[i]) tempReqFlower--;
            else tempReqFlower=k;
            if(tempReqFlower==0){
              tempReqBouquet--;
              tempReqFlower=k;
            }
          }
            if(tempReqBouquet<=0){
              minDay=min(minDay,currDay);
              high=mid-1;
            }
            else{
              low=mid+1;
            }

        }
        return minDay==maxBloomday+1?-1:minDay;
    }
};