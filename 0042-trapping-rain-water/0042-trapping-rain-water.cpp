class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int watertrapped = 0;
        int maxleft=0,maxright=0;
        vector<int> maxlefthash(n), maxrighthash(n); 
        for(int i = 0;i<n;i++){
            maxleft = max(maxleft,a[i]);
            maxlefthash[i]=maxleft;
        }
        for(int i = n-1;i>=0;i--){
            maxright = max(maxright,a[i]);
            maxrighthash[i]=maxright;
        }
        for(int i = 0;i<n;i++){
            watertrapped+=min(maxlefthash[i],maxrighthash[i])-a[i];
        }
        return watertrapped;
    }
};