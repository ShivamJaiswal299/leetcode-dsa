class Solution {
public:
    int splitArray(vector<int> &a, int students)  {
        int n =a.size(),maxPg=a[0],sumPg=0;
        if(students>n) return -1;
        for(int i=0;i<n;i++){
            maxPg=max(maxPg,a[i]);
            sumPg+=a[i];
        }
        int low = maxPg,mid,high=sumPg,ans=sumPg;
        while(low<=high){
            int mid = low + (high-low)/2;
            int tempLimit = mid;
            int studentsLeft=students;
            int tempPg=a[0];
            int maxPg=a[0];
            for(int i=1;i<n;i++){
                if(tempPg+a[i]<mid) tempPg+=a[i];
                else if(tempPg+a[i]>mid) {
                    maxPg=max(maxPg,tempPg);
                    studentsLeft--;
                    tempPg=a[i];
                }//-------
                else if(tempPg+a[i]==mid){
                    maxPg=max(maxPg,mid);
                    studentsLeft--;
                    tempPg=0;
                }
            }
            maxPg=max(maxPg,tempPg);
            if(tempPg) studentsLeft--;
            if(studentsLeft>=0) {
                high = mid-1;
                ans=min(ans, maxPg);
                }
            else if(studentsLeft<0) {
                low=mid+1;
            }
        }
        return ans;
    }
};