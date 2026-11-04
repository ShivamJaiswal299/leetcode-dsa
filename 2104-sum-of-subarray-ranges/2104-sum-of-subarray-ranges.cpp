class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
      // we have to find sum of ranges i.e. (sum of subarray's max) - (sum of subarray's min) cuz range = largest - smallest element 
      //so we have to find sum of maxes sum of mins then substract them.
      int n = a.size();
      // rather than 2 different fn we can also use single function as only the > and >= becomes < and <= (nothing else is different).
      return sumofmax(a,n) - sumofmin(a,n);
    }

    long long sumofmin(vector <int> &a, int n){
      vector<int> left(n,-1), right(n,-1);
      stack<int>stk;
      //left part length.
      for(int i=0;i<n;i++){
        while(!stk.empty() && a[i]<=a[stk.top()]) stk.pop();
        if(!stk.empty()) left[i] = i - stk.top();
        else left[i] = i+1;
        stk.push(i);
      }
      //reset the stack.
      while(!stk.empty()) stk.pop(); 
      //right part length.
      for(int i=n-1;i>=0;i--){
        while(!stk.empty() && a[stk.top()]>a[i]) stk.pop();
        if(!stk.empty()) right[i] = stk.top() - i;
        else right[i] = n-i;
        stk.push(i);
      }

      long long ans = 0;
      for(int i = 0;i<n;i++){
        ans += (long long)a[i]*left[i]*right[i];
      }
      return ans;
    }

    long long sumofmax(vector <int> &a, int n){
      vector<int> left(n,-1), right(n,-1);
      stack<int>stk;
      //left part length.
      for(int i=0;i<n;i++){
        while(!stk.empty() && a[i]>=a[stk.top()]) stk.pop();
        if(!stk.empty()) left[i] = i - stk.top();
        else left[i] = i+1;
        stk.push(i);
      }
      //reset the stack.
      while(!stk.empty()) stk.pop(); 
      //right part length.
      for(int i=n-1;i>=0;i--){
        while(!stk.empty() && a[stk.top()]<a[i]) stk.pop();
        if(!stk.empty()) right[i] = stk.top() - i;
        else right[i] = n-i;
        stk.push(i);
      }

      long long ans = 0;
      for(int i = 0;i<n;i++){
        ans += (long long)a[i] * left[i]*right[i];
      }
      return ans;
    }
};