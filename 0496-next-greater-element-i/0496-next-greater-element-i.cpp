class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int> stk;
      unordered_map<int,int> mp;
      for(int i=nums2.size()-1;i>=0;i--){
        int x =nums2[i];
        while(!stk.empty() && x>=stk.top()){
            stk.pop();
        }
        if(stk.empty()){
            mp[x]=-1;
        }else{
            mp[x]=stk.top();
        }
        stk.push(x);
      }
      vector<int>ans;
      for(int x:nums1){
        ans.push_back(mp[x]);
      }
      return ans;
    }
};