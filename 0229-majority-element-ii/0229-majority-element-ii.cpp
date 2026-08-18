class Solution {
public:
// moore voting algorithm-IF MEMBER OF 3RD HOUSE DIDNT GET A SEAT THEN HE WILL ALSO NOT ALLOW 1 MEMBER OF BOTH OTHER GROUP TO BE SEATED so thatswhy there will be cnt-- for both other house
    vector<int> majorityElement(vector<int>& a) {
      int cnt1=0,cnt2=0,ele1=INT_MIN,ele2=INT_MIN;
      // CHECKING VOTING'S POSSIBLE WINNER 
      for (int i=0;i<a.size();i++){
        if(cnt1==0 && a[i]!=ele2){
          cnt1=1;
          ele1=a[i];
        }
        else if(cnt2==0 && a[i]!=ele1){
          cnt2=1;
          ele2=a[i];
        }
        else if(a[i]==ele1) cnt1++;
        else if(a[i]==ele2) cnt2++;
        else{
          cnt1--;
          cnt2--;
        }
      }
      //VERIFYING THE WINNER THAT IS IT TRUELY A MAJOTIRY ELEMENT
      cnt1=0,cnt2=0;
      for(auto x: a ){
        if(x==ele1) cnt1++;
        else if(x==ele2) cnt2++;
      }
      // PUTTING IT IN VECTOR FOR RETURNING
      vector<int> result;
      if(cnt1>(a.size()/3)) result.push_back(ele1);
      if(cnt2>(a.size()/3)) result.push_back(ele2);
      return result;
    }
};