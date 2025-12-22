class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int write=0;
        while(i < chars.size()){
            char curr = chars[i];
            int count = 0;

            while(i < chars.size() && curr == chars[i]){
                count++;
                i++;
            }

            chars[write] = curr;
            write++;

            if(count > 1){
                string cnt = to_string(count);
                for(char c: cnt){
                    chars[write] = c;
                    write++;
                }
            }
        }
        return write;
    }
};