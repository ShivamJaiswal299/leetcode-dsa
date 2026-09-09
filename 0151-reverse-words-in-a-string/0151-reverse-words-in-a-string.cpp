class Solution {
public:
    string reverseWords(string s) {
      string word = " " ,result = ""; 
        for(int i = s.length()-1;i>=0;i--){
          char c = s[i];
          if(c==' ' && word!=" "){
            result+=word;
            word=" ";
          }
          else if (c!=' '){
            word.insert(word.begin(),c);

          }
        }
      if(word!=" ") result+=word;
      result.pop_back();
      return result;
    }
};