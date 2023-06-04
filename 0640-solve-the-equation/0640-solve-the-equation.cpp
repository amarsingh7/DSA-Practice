class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size();
        int sign = 1, coeff = 0, tot = 0, i = 0;

        for (int j = 0; j < n; j++) 
        {
            if (equation[j] == '+' || equation[j] == '-') {
                if (j > i)
                    tot += sign * std::stoi(equation.substr(i, j - i));
                i = j;
            } 
            else if (equation[j] == 'x') {
                if ((i == j) || equation[j - 1] == '+')
                    coeff += sign;
                else if (equation[j - 1] == '-')
                    coeff -= sign;
                else
                    coeff += sign * std::stoi(equation.substr(i, j - i));
                i = j + 1;
            } 
            else if (equation[j] == '=') {
                if (j > i)
                    tot += sign * std::stoi(equation.substr(i, j - i));
                sign = -1;
                i = j + 1;
            }
        }

        if (i < n)
            tot += sign * std::stoi(equation.substr(i));

        if (coeff == 0 && tot == 0)
            return "Infinite solutions";
        if (coeff == 0 && tot)
            return "No solution";

        int ans = -tot / coeff;
        return "x=" + std::to_string(ans);
    }
};