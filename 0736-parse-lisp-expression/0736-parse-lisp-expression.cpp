class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> scope;
        return eval(expression, scope);
    }

    // Split expression into top-level tokens
    vector<string> parse(string s) {
        vector<string> res;
        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } 
            else if (s[i] == '(') {
                int j = i, count = 0;
                while (i < n) {
                    if (s[i] == '(') count++;
                    if (s[i] == ')') count--;
                    i++;
                    if (count == 0) break;
                }
                res.push_back(s.substr(j, i - j));
            } 
            else {
                int j = i;
                while (i < n && s[i] != ' ') i++;
                res.push_back(s.substr(j, i - j));
            }
        }
        return res;
    }

    int eval(string expr, unordered_map<string, int> scope) {
        // number
        if (isdigit(expr[0]) || expr[0] == '-') {
            return stoi(expr);
        }

        // variable
        if (expr[0] != '(') {
            return scope[expr];
        }

        // remove outer ()
        expr = expr.substr(1, expr.size() - 2);

        vector<string> tokens = parse(expr);

        string op = tokens[0];

        if (op == "add") {
            return eval(tokens[1], scope) + eval(tokens[2], scope);
        }

        if (op == "mult") {
            return eval(tokens[1], scope) * eval(tokens[2], scope);
        }

        // let
        for (int i = 1; i < tokens.size() - 1; i += 2) {
            scope[tokens[i]] = eval(tokens[i + 1], scope);
        }

        return eval(tokens.back(), scope);
    }
};