class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m= s.length();
        int n = t.length();
        int i = m-1;
        int j = n-1;
        int skips=0;
        int skipt=0;

        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skips++;
                    i--;
                }
                else if(skips>0){
                    skips--;
                    i--;
                }
                else{
                    break;
                }
            }

            while(j>=0){
                if(t[j]=='#'){
                    skipt++;
                    j--;
                }
                else if(skipt>0){
                    skipt--;
                    j--;
                }
                else{
                    break;
                }
            }
            char first = i<0 ? '$': s[i];
            char second = j<0 ? '$': t[j];
            if(first != second){
                return false;

            }
            i--;
            j--;
        }
        return true;
        
    }
};