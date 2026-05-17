class Solution {
public:

    bool isBalanced(vector<int> &freq){
        int t=0;
        for(int f: freq){
            if(f > 0){
                if(t == 0){
                    t = f;
                }
                else if(f != t){
                    return false;
                }
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                if(isBalanced(freq)){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};