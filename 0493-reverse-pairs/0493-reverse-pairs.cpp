class Solution {
public:
    void merge(vector<int>& a,int low, int mid, int high){
      vector <int> temp(high+1-low);
      int j=mid+1;
      for(int i=low;i<=mid;i++){
        while(j<=high && a[i]>(long long)2*a[j]) j++;
        count+=j-(mid+1);
      }
      int i=low,h=0;
      j=mid+1;
      while(i<=mid && j<=high){
        if(a[i]<=a[j]) temp[h++]=a[i++];
        else if(a[i]>a[j]) temp[h++]=a[j++];
      }
      while(i<=mid) temp[h++]=a[i++];
      while(j<=high) temp[h++]=a[j++];
      for(int k=low;k<=high;k++) a[k]=temp[k-low];
    }
    void mergeSort(vector<int>& a,int low, int high){
      if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
      }
    }
    int count=0;
    int reversePairs(vector<int>& a) { //main fn
        mergeSort(a,0,a.size()-1);
        return count;
    }
};