class Solution {
public:
    int removeDuplicates(vector<int>& a) {
      int n=a.size();
      int uniele=0;
      for(int i=1;i<n;i++) if(a[i]!=a[i-1]) a[++uniele]=a[i];
      return uniele+1;  
    }
      // ---------------------------------
      // int n=a.size();
      // int uniele=1;
      // for(int i=1;i<n;i++){
      //   int temp=a[i-1];
      //   bool flag =false;
      //   for(int j=i;j<n;j++){
      //     if(a[j]>temp) {
      //       a[i]=a[j];
      //       uniele++;
      //       flag=true;
      //       break;
      //     }
      //   }
      //     if(!flag) break;
      // }
      // return uniele;
      // ---------------------------------
};