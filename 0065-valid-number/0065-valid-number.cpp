class Solution {
public:
    bool isNumber(string s) {
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                numSeen = true;
                numAfterE = true;
            }
            else if (s[i] == '+' || s[i] == '-') {
                // sign only at start or just after e/E
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            }
            else if (s[i] == '.') {
                // only one dot and not after exponent
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                // only one e and must have number before it
                if (eSeen || !numSeen)
                    return false;
                eSeen = true;
                numAfterE = false; // must see number after e
            }
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};