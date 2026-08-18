class Solution {
public:
//METHOD 1 - 2 POINTERS APPROACH, here sorting is required and indices are not maintained but give space o(1), so we take left and right pointer on both the corners of the vector, if sum of both pointers is greater than key we decrement right else if its smaller then we increment left until key is found #IT IS THE SAME AS FOR 2SUM BUT WE APPLY IT FOR EVERY TRAVERSAL
    vector<vector<int>> threeSum(vector<int>& a) {
      if(a.size()<3) return {}; //SIZE SMALLER THAN 3
      sort(a.begin(),a.end());
      vector<vector<int>> result;
      int n =a.size();
      for(int i=0;i<n-2;i++){ //N-2 CUZ WE NEED A TOTAL OF 3 MEMBERS
        if(i>0 && a[i]==a[i-1] ) continue; //IF i IS DUPLICATE
        int comp=0-a[i];
        int left=i+1, right=n-1;
        while(left<right){
          int sum = a[left] + a[right];
          if(sum<comp){
            left++;
          }
          else if(sum>comp){
            right--;
          }
          else{
            while(left<right && a[left]==a[left+1]) left++;//SKIPPING ALL DUPLICATE
            while(left<right && a[right]==a[right-1]) right--;//SKIPPING ALL DUPLICATE
            result.push_back({a[i],a[left++],a[right--]});
          }
        }

      }
      return result;
    }
//METHOD 2 - HASHMAP APPROACH,here we will traverse over the vector and apply 2sum on every element, here space is o(n) but no need of sorting and hence indices are maintained , as here no need of indices in this question so this is not the best approach
};