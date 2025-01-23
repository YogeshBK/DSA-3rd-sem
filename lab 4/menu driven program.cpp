

/*Write a menu driven program to convert following 
1. Infix to postfix
2. Infix to prefix
3. Evaluation of Expression*/



#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to determine the precedence of operators
int precedence(char ch) {
    if (ch == '^' || ch == '$') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// Function to check if a character is an operator
bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '^';
}

class Postfix {
public:
    string exp;
    stack<char> op_stack;

    void input() {
        cout << "Enter an infix expression: ";
        cin >> exp;
    }

    string postfixcalc() {
        string postfix = "";

        // Iterate through the expression using a for loop with an index
        for (size_t i = 0; i < exp.length(); ++i) {
            char ch = exp[i]; // Access the current character

            if (isalpha(ch) || isdigit(ch)) {
                postfix += ch; // Append operands directly to postfix
            } else if (ch == '(') {
                op_stack.push(ch);
            } else if (ch == ')') {
                while (!op_stack.empty() && op_stack.top() != ')'){
                    postfix += op_stack.top();
                    op_stack.pop();
                }
                if (!op_stack.empty() && op_stack.top() == '(') {
                    op_stack.pop(); // Pop the '('
                }
            } else if (isoperator(ch)) {
                while (!op_stack.empty() && precedence(op_stack.top()) >= precedence(ch)) {
                    postfix += op_stack.top();
                    op_stack.pop();
                }
                op_stack.push(ch);
            }
        }

        // Pop remaining operators
        while (!op_stack.empty()) {
            postfix += op_stack.top();
            op_stack.pop();
        }

        
        cout << "Postfix expression: " << postfix << endl;

        return postfix;
    }
};

class Prefix {
public:
    string prefix_exp;
    stack<char> prefixop_stack;

    void prefixinput() {
        cout << "Enter an infix expression: ";
        cin >> prefix_exp;
    }

    string reverse(string str) {
        string rev = "";
        for (int i = str.length() - 1; i >= 0; --i) {
            rev += str[i];
        }
        return rev;
    }

    void prefixcalc() {
        // Step 1: Reverse the infix string
        string reversed = reverse(prefix_exp);
        cout << "Reversed expression: " << reversed << endl;

        // Step 2: Modify parentheses
        for (size_t i = 0; i < reversed.length(); ++i) {
            if (reversed[i] == '(') {
                reversed[i] = ')';
            } else if (reversed[i] == ')') {
                reversed[i] = '(';
            }
        }

        // Step 3: Convert the modified reversed string to postfix
        Postfix obj;
        obj.exp = reversed;
        string postfix_result = obj.postfixcalc();  // This will compute the postfix of the reversed string

        // Step 4: Reverse the resulting postfix string
        string prefix_str = reverse(postfix_result);

        
        cout << "Prefix expression: " << prefix_str << endl;
    }
};

class Evaluation {
public:
    string exp;
    stack<int> exp_stack;

    void input() {
        cout << "Enter the expression for evaluation: ";
        cin >> exp;
    }

    void evaluate() {
        for (size_t i = 0; i < exp.length(); ++i) {
            char ch = exp[i];

            if (isdigit(ch)) {
                exp_stack.push(ch - '0'); // Convert char digit to integer
            } else if (isoperator(ch)) {
                int b = exp_stack.top(); exp_stack.pop();
                int a = exp_stack.top(); exp_stack.pop();

                int result = 0;
                if (ch == '+') result = a + b;
                else if (ch == '-') result = a - b;
                else if (ch == '*') result = a * b;
                else if (ch == '/') result = a / b;

                exp_stack.push(result);
            }
        }

        cout << "Result of the expression: " << exp_stack.top() << endl;
    }
};

int main() {
    char ch;
    do {
        cout << "Menu" << endl;
        cout << "1. Infix to Postfix" << endl;
        cout << "2. Infix to Prefix" << endl;
        cout << "3. Evaluation of Expression" << endl;
        cout << "Enter your choice (1-3) or 'n' to exit: ";
        cin >> ch;

        switch (ch) {
            case '1': {
                cout << "Infix to Postfix:" << endl;
                Postfix obj;
                obj.input();
                obj.postfixcalc();
                break;
            }
            case '2': {
                Prefix obj2;
                obj2.prefixinput();
                obj2.prefixcalc();
                break;
            }
            case '3': {
                Evaluation obj3;
                obj3.input();
                obj3.evaluate();
                break;
            }
            default:{
            	cout << "Invalid option." << endl;
				break;
			}
                
        }
    } while (ch != 'n');

    return 0;
}

