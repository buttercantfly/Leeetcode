



class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0){
            return true;
        }

        int s_index = 0;
        for(int i =0; i < t.length(); i++){
            if (s[s_index] == t[i]){
                s_index++;
            }

            if(s_index == s.length()){
                return true;
            }
        }

        return false;
    }
};