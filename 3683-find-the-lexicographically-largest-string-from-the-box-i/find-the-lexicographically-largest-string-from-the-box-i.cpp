class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int maxLen = n - (numFriends - 1);
        if (numFriends == 1) return word;
        string ans= "";
        for(int i =0; i<n; i++){
            int len = min (maxLen, n-i);
            string temp = word.substr(i, len);
            if(temp > ans){
                ans = temp;
            }
        }
        return ans;
    }
};