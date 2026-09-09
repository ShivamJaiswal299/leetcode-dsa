// class Solution {
// public:
//     string reverseWords(string s) {
//       string word = " " ,result = ""; 
//         for(int i = s.length()-1;i>=0;i--){
//           char c = s[i];
//           if(c==' ' && word!=" "){
//             result+=word;
//             word=" ";
//           }
//           else if (c!=' '){
//             word.insert(word.begin(),c);

//           }
//         }
//       if(word!=" ") result+=word;
//       result.pop_back();
//       return result;
//     }
// };
//better time complexity (as not inserting at front everytime which takes O(n))
class Solution {
public:
    string reverseWords(string s) {
        string word, result;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ' ' && !word.empty()) {
                reverse(word.begin(), word.end());//reversing once instead of inserting everytime at front. eg - "yks"
                result += word + " "; //"sky" becomes "sky "
                word="";
            } else if (c != ' ') {
                word.push_back(c); 
            }
        }
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            result += word;
        } else if (!result.empty()) {
            result.pop_back();  // remove trailing space
        }
        return result;
    }
};