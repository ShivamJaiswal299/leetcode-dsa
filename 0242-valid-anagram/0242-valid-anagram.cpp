class Solution {
public:
  bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    //make a array to store freq for all char
    int freq[26]={0};
    for(char c: s) freq[c-'a']++;//++ for 1st array elements
    for(char c: t) freq[c-'a']--;//-- for 2nd array elements
    for(int i=0;i<26;i++) if (freq[i]) return false; // if not zero then its not anagram
    return true;
  }
};