class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0;
        int maxF =0;
        int maxLen =0;
        vector<int> freq(26, 0);

        for(int i=0; i< s.size(); i++){
            freq[s[i]-'A']++;
            maxF = max(maxF, freq[s[i]-'A']);

            if((i-l+1)-maxF > k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLen =max(maxLen, i-l+1);
        }
        return maxLen;
    }
};