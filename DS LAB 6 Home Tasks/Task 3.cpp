#include <iostream>
using namespace std;

class Stack {
public:
    int top;
    int size;
    char* arr;

    Stack(int n) {
        top = -1;
        size = n;
        arr = new char[n];
    }

    void push(char element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack overflow." << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            char val = arr[top];
            top--;
            return val;
        } else {
            cout << "Stack underflow." << endl;
            return '\0';
        }
    }

    char topElement() {
        if (top >= 0)
            return arr[top];
        else
            return '\0';
    }

    bool isEmpty() {
        return (top == -1);
    }

    int precedence(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

    void infixToPostfix(string infix) {
        Stack s(infix.length());
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                postfix += c;
            } else if (c == '(') {
                s.push(c);
            } else if (c == ')') {
                while (!s.isEmpty() && s.topElement() != '(') {
                    postfix += s.pop();
                }
                s.pop();
            } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (!s.isEmpty() && s.precedence(s.topElement()) >= s.precedence(c)) {
                    postfix += s.pop();
                }
                s.push(c);
            }
        }
        while (!s.isEmpty()) {
            postfix += s.pop();
        }
        cout << "Postfix Expression: " << postfix << endl;
    }
};

int main() {
    string str;
    cout << "Enter an infix expression: ";
    cin >> str;
    Stack st(str.length());
    st.infixToPostfix(str);
    return 0;
}

