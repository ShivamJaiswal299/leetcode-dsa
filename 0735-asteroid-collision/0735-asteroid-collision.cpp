class Solution {
public:
// A collision happens only when the stack top moves right (+) and the current asteroid moves left (-).While they collide: smaller one explodes (pop top / drop x), equal sizes both explode, x keeps fighting after each pop.If x survives all fights, push it. The stack holds the final asteroids. Time: O(n).
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> stk;//Using a vector<int> as the stack removes the pop-and-reverse step at the end.
      for(int x:asteroids){
        bool alive = true;
        while(alive && !stk.empty() && x<0 && stk.top()>0){
          if(stk.top()<-x) stk.pop();
          else if(stk.top()==-x){
            stk.pop();
            alive=false;
          }
          else{
            alive=false;
          }
        }
        if(alive) stk.push(x);
      }
      vector <int> ans;
      while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};