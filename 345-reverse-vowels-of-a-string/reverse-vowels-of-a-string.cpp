class Solution {
public:
bool isVowel(char c){
    return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ||
            c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

    
    string reverseVowels(string s) {
        
        int start= 0;
        int end= s.size()-1;

        while(start < end){
            if(!isVowel(s[end])){
                end--;
            }
            if(!isVowel(s[start])){
                start++;
            }while(start < end && !isVowel(s[start])){
                start++;
            }

            // move end until vowel
            while(start < end && !isVowel(s[end])){
                end--;
            }
             if(start < end){
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};