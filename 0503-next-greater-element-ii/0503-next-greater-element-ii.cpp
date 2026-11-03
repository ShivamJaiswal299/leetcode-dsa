class Solution {
public:
//this is just a modification of 503. Next Greater Element I
//keypoint- when there is an circular array always think about double/twice the array.
    vector<int> nextGreaterElements(vector<int>& nums) {
      vector <int> a = nums;
      a.insert(a.end(),nums.begin(),nums.end());

      stack<int>stk;
      vector<int> ans(a.size(),-1);
      for(int i = a.size()-1;i>=0;i--){
        int x = a[i];
        while(!stk.empty() && x>=stk.top()){
          stk.pop();
        }
        if(stk.empty()){
          ans[i]=-1;
        }else{
          ans[i]=stk.top();
        }
        stk.push(x);
      }
      return vector<int> (ans.begin(),ans.begin()+nums.size());
    }
};