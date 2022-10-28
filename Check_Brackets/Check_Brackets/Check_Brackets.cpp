#include <iostream>
#include <stack>
#include <string>

using namespace std;


struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Check(char c) {
        if (type == '[' && c == ']') {
            return true;
        }
        if (type == '{' && c == '}') {
            return true;
        }
        if (type == '(' && c == ')') {
            return true;
        }
        return false;
    }

    char type;
    int position;
};

void print(stack<Bracket> st) {
    char c;
    while (st.size()) {
        c = st.top().type;
        cout << c;
        st.pop();
    }
    cout << endl;
}

int main() {
    std::string text;
    getline(std::cin, text);
    int faulty_pos = -1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            
            Bracket* b = new Bracket(next, position + 1);
            opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}') {
          
            if (opening_brackets_stack.size() == 0) {
                faulty_pos = position + 1;
                break;
            }
            else if (opening_brackets_stack.top().Check(next)) {
                
                opening_brackets_stack.pop();
            }
            else {
                faulty_pos = position + 1;
                break;
            }
        }
    }

  
    if (opening_brackets_stack.size() == 0 && faulty_pos == -1) {
        cout << "Success" << endl;
    }
    else {
        if (opening_brackets_stack.size() && faulty_pos == -1) {
            faulty_pos = opening_brackets_stack.top().position;
        }
        cout << faulty_pos << endl;
    }

    return 0;
}