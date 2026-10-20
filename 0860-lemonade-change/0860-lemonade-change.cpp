class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> billcnt(2,0); //storing change of 5 and 10 dollars in these 2 index.
        for(int x: bills){
          if(x==5) billcnt[0]++;
          else if(x==10){
            if(billcnt[0]==0) return false;
            else {
              billcnt[1]++;
              billcnt[0]--;
            }
          }
          else if(x==20){
            
            if(billcnt[0]>0 && billcnt[1]>0){   // give $10 + $5 (preferred)
              billcnt[1]--; 
              billcnt[0]--;
            }
            else if(billcnt[0]>=3){             // otherwise give three $5
              billcnt[0]-=3;
            }
            //here 20 $ is not added in billcnt as we never give 20$ as a change to someone 
            else return false;
          }
        }
      return true;
    }
};