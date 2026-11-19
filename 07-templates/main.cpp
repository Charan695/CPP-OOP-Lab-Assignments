#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

// Generic stack: T can be int, float, string, or another suitable type.
template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(const T& value) { elements.push_back(value); }
    bool empty() const { return elements.empty(); }

    void pop() {
        if (empty()) {
            cout << "Stack is empty; cannot pop.\n";
            return;
        }
        elements.pop_back();
    }

    const T& top() const {
        if (empty()) throw out_of_range("Stack is empty");
        return elements.back();
    }

    void display() const {
        cout << "Stack (bottom to top): ";
        for (const T& value : elements) cout << value << ' ';
        cout << '\n';
    }
};

int main() {
    Stack<int> integers;
    integers.push(10);
    integers.push(20);
    integers.display();
    cout << "Integer top: " << integers.top() << '\n';

    Stack<float> decimals;
    decimals.push(1.5f);
    decimals.push(2.5f);
    decimals.display();
    cout << "Float top: " << decimals.top() << '\n';

    Stack<string> words;
    words.push("C++");
    words.push("Templates");
    words.display();
    cout << "String top: " << words.top() << '\n';

    integers.pop();
    integers.display();
    return 0;
}
