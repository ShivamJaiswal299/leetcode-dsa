class Solution {
public:
    bool rotateString(string s, string goal) {
      //concatananating then finding goal in the concatenated string. 
      if(s.length()!=goal.length()) return false;
      string temp = s+s;
      if(temp.find(goal)<s.length()) return true;//.find gives a unsigned int. it gives index of the starting at the first occurence , if it doesnt find the substring it gives a faily large number
      else return false;
    }
};