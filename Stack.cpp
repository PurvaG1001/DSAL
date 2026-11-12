#include <iostream>
#include <cctype> // For isalnum() to check if character is letter or digit
using namespace std;

// ------------------------
// Node for the linked list stack
// ------------------------
struct Node {
    char data;   // To store the character (operand or operator)
    Node* next;  // Pointer to next node
};

// ------------------------
// Stack class using singly linked list
// ------------------------
class Stack {
    Node* top;   // Points to top node

public:
    Stack() {
        top = NULL; // Initially stack is empty
    }

    // Push a character onto the stack
    void push(char x) {
        Node* t = new Node;  // Create new node
        t->data = x;         // Store data
        t->next = top;       // New node points to old top
        top = t;             // Update top
    }

    // Pop a character from the stack
    char pop() {
        if (top == NULL)
            return '\0';  // If empty, return null char

        char x = top->data;   // Save data to return
        Node* t = top;        // Temp pointer to delete node

        // Move top to next node
        top = top->next;

        delete t;             // Delete old top node
        return x;             // Return popped data
    }

    // Peek at the top of the stack
    char peek() {
        if (top != NULL)
            return top->data;
        else
            return '\0';  // Return null char if empty
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

// ------------------------
// Function to check precedence of operators
// Higher value means higher precedence
// ------------------------
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;  // Lowest

    if (op == '*' || op == '/')
        return 2;  // Higher

    return 0;  // For other chars (like '(' or operands)
}

// ------------------------
// Function to convert infix expression to postfix
// Example: A+B*C -> ABC*+
// ------------------------
string infixToPostfix(string infix) {
    Stack s;              // Our stack
    string postfix = "";  // Result string

    // Loop through each character
    for (char ch : infix) {

        if (isalnum(ch)) {
            // If it is an operand (letter/number), add to output
            postfix += ch;
        }

        else if (ch == '(') {
            // If '(', push to stack
            s.push(ch);
        }

        else if (ch == ')') {
            // If ')', pop until '(' is found
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();

            s.pop(); // Pop '('
        }

        else {
            // If operator (+, -, *, /)

            // Pop operators with higher or same precedence
            while (!s.isEmpty() && precedence(ch) <= precedence(s.peek()))
                postfix += s.pop();

            // Push current operator
            s.push(ch);
        }
    }

    // Pop remaining operators from stack
    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

// ------------------------
// Function to convert infix to prefix
// Steps:
// 1. Reverse infix expression
// 2. Swap '(' and ')'
// 3. Get postfix of modified expression
// 4. Reverse the postfix to get prefix
// Example: A+B*C -> +A*BC
// ------------------------
string infixToPrefix(string infix) {
    string rev = "";  // To hold reversed expression

    // Step 1 & 2: Reverse and swap brackets
    for (int i = infix.length() - 1; i >= 0; i--) {
        if (infix[i] == '(')
            rev += ')';
        else if (infix[i] == ')')
            rev += '(';
        else
            rev += infix[i];
    }

    // Step 3: Get postfix of modified expression
    string postfix = infixToPostfix(rev);

    // Step 4: Reverse postfix to get prefix
    string prefix = "";

    for (int i = postfix.length() - 1; i >= 0; i--) {
        prefix += postfix[i];
    }

    return prefix;
}

// ------------------------
// Main function
// ------------------------
int main() {
    string infix;

    // Get infix input from user
    cout << "Enter infix: ";
    cin >> infix;

    // Call functions and show output
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;

    return 0;
}
