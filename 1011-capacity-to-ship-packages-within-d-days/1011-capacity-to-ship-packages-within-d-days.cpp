class Solution {
public:
    int shipWithinDays(vector<int>& a, int days) { //a=weights
        int n=a.size(),sumofa=0,maxofa=a[0];
        //finding sumofa and maxofa
        for(int i=0;i<n;i++){
          sumofa+=a[i];
          maxofa=max(maxofa,a[i]);
        }

        //implementing binary search
        int low=maxofa,high=sumofa,mid;
        int minCapacity=high;
        while(low<=high){
          mid = low + (high-low)/2;
          int capacity=mid;
          int daysLeft = days;
          int tempWeight=0;
          for(int i=0;i<n;i++){
            tempWeight+=a[i];
            if(tempWeight>=capacity){
              if(tempWeight>capacity) i--;//cuz the extra weight will not go in the ship that day
              daysLeft--;//day decreased
              tempWeight=0;//as next day so weighting machine resets
            }
          }
          if(tempWeight) daysLeft--;//IMP CASE- note if the last ship goes little empty i.e. below capacity then that day will also count 
          //now will analyse days
          if(daysLeft>=0) { //+ve means work done before time
            minCapacity=min(minCapacity,mid);
            high=mid-1;
            }
          else if(daysLeft<0) low=mid+1;//-ve means work done after time (extra time)
        }
        return minCapacity;
    }
};