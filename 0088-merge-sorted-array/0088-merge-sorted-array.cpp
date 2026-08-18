class Solution {
public:
    void merge(vector<int>& a1, int n1, vector<int>& a2, int n2) {
      //here we will traverse all the 3 idxs from rear to front 
      int idx1=n1-1,idx2=n2-1; //1 for a1 2nd for a2
      int i=i=n1+n2-1; //this one for correcting the position 
      while(i>=0 && idx1>=0 && idx2>=0){ //as if one of them finishes first then no need of comparing, simple copy the remaining array onto the main one 
        if(a1[idx1]>=a2[idx2]) a1[i--]=a1[idx1--];
        else if(a1[idx1]<a2[idx2]) a1[i--]=a2[idx2--];
      }
      while(idx2>=0) a1[i--]=a2[idx2--]; //this is for copying the remaining a2 (if reamins) into a1
      //also no need of coping a1 to a1 as that is already in the correct form.
    }
};