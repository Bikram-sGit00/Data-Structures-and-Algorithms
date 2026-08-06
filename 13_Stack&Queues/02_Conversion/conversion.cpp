➡️ problemLinks --> 

✅ infix to postfix --> // Function to return precedence of operators
int prec(char c) {
    if (c == '^')  // Exponent operator has highest precedence
        return 3;
    else if (c == '/' || c == '*')  // Multiplication and division have higher precedence than addition
        return 2;
    else if (c == '+' || c == '-')  // Addition and subtraction have lowest precedence
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> st; // Stack to hold operators and parentheses
    string result;  // String to hold the resulting postfix expression

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the result string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack
        else if (c == '(')
            st.push('(');

        // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // Pop the ‘(‘ from the stack
        }

        // If an operator is scanned
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);  // Push the current operator to the stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;  // Output the result
}

Time Complexity :  

Space Complexity :  

✅ infix to prefix --> 
// Function to check if a character is an operator
bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));  // If the character is neither alphabetic nor numeric, it's an operator
}

// Function to return the precedence of operators
int getPriority(char C) {
    if (C == '-' || C == '+')  // Addition and subtraction have lowest precedence
        return 1;
    else if (C == '*' || C == '/')  // Multiplication and division have higher precedence
        return 2;
    else if (C == '^')  // Exponent operator has highest precedence
        return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    infix = '(' + infix + ')';  // Add parentheses to handle edge cases
    int l = infix.size();
    stack<char> char_stack;  // Stack to store operators
    string output;  // String to store the resulting postfix expression

    for (int i = 0; i < l; i++) {

        // If the scanned character is an operand, add it to output
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If the scanned character is ‘(’, push it to the stack
        else if (infix[i] == '(')
            char_stack.push('(');

        // If the scanned character is ‘)’, pop and output from the stack until an ‘(‘ is encountered
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            char_stack.pop();  // Remove '(' from the stack
        }

        // If an operator is found
        else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                } else {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                // Push current operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    
    // Pop all remaining elements from the stack
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;  // Return the postfix expression
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string infix) {
    int l = infix.size();

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);  // Convert the modified infix to postfix

    // Reverse the postfix expression to get the prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;  // Return the prefix expression
}

Time Complexity :  

Space Complexity :  

✅ Company Tags -->  