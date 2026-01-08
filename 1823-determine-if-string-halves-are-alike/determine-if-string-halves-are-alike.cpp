class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }
        else{
            return false;
        }
    }
    bool halvesAreAlike(string s) {
        int countR = 0;
        int countL = 0;
        int i = 0;
        int j = (s.size())/2;
        while(i < (s.size()/2) && j < s.size()){
            if(isVowel(s[i])){
                countL++; 
            }
            if(isVowel(s[j])){
                countR++;
            }
            i++;
            j++;
        }
        if(countR == countL){
                return true;
        }
        else{
            return false;
        }
    
    }
};