class Solution {
public:
    string build(string str) {
        string ans = "";

        for (int i = 0; i < str.length(); i++) {

            if (str[i] == '#') {

                if (ans.length() > 0) {
                    ans.pop_back();
                }

            } 
            else {
                ans.push_back(str[i]);
            }
        }

        return ans;
    }

    bool backspaceCompare(string s, string t) {

        string a = build(s);
        string b = build(t);

        return a == b;
    }
};