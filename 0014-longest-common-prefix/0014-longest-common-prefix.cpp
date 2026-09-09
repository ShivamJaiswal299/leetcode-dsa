class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
      string result = "";
        for(int i=0;i<strs[0].length();i++){//take each char of 1st string and compare to all other.
          char x = strs[0][i];
          result+=x;
          for(int j=1;j<strs.size();j++){
            if((strs[j].length()<i+1) ||(strs[j][i] != x)){//first condition is for bound check , eg . Trace {"ab", "a"}
              result.pop_back();
              return result;
            }
          }
        }
      return result;
    }
};