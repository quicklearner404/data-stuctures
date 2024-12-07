//#include <iostream>
//#include <stack>
//using namespace std;
//
//class MinStack {
//private:
//    stack<int> mainStack;  // Stores all the elements of the stack
//    stack<int> minStack;   // Tracks the minimum value in the stack
//
//public:
//    // Push an element onto the stack
//    void push(int value) {
//        mainStack.push(value);
//
//        // If minStack is empty or the value is smaller or equal to the current minimum, push it
//        if (minStack.empty() || value <= minStack.top()) {
//            minStack.push(value);
//        }
//    }
//
//    // Remove the top element from the stack
//    void pop() {
//        if (mainStack.empty()) {
//            cout << "Stack is empty. Cannot pop.\n";
//            return;
//        }
//
//        // If the top element of mainStack is the same as minStack's top, pop from minStack too
//        if (mainStack.top() == minStack.top()) {
//            minStack.pop();
//        }
//        mainStack.pop();
//    }
//
//    // Get the top element of the stack
//    int top() const {
//        if (mainStack.empty()) {
//            cout << "Error! Stack is empty. Returning -1.\n";
//            return -1;
//        }
//        return mainStack.top();
//    }
//
//    // Get the minimum element in the stack
//    int get_min() const {
//        if (minStack.empty()) {
//            cout << "Error! Stack is empty. Returning -1 as minimum.\n";
//            return -1;
//        }
//        return minStack.top();
//    }
//
//    // Print the current stack structure
//    void printStack() const {
//        if (mainStack.empty()) {
//            cout << "Stack is empty.\n";
//            return;
//        }
//
//        cout << "Main Stack (top -> bottom): ";
//        for (auto temp = mainStack; !temp.empty(); temp.pop()) {
//            cout << temp.top() << " ";
//        }
//        cout << "\n";
//
//        cout << "Min Stack (top -> bottom): ";
//        for (auto temp = minStack; !temp.empty(); temp.pop()) {
//            cout << temp.top() << " ";
//        }
//        cout << "\n";
//    }
//};
//
//int main() {
//    MinStack minStack;
//
//    cout << "Pushing 3 onto the stack.\n";
//    minStack.push(3);
//    minStack.printStack();
//
//    cout << "Pushing 5 onto the stack.\n";
//    minStack.push(5);
//    minStack.printStack();
//
//    cout << "Pushing 2 onto the stack.\n";
//    minStack.push(2);
//    minStack.printStack();
//
//    cout << "Pushing 1 onto the stack.\n";
//    minStack.push(1);
//    minStack.printStack();
//
//    cout << "Current minimum: " << minStack.get_min() << "\n";
//
//    cout << "Popping from the stack.\n";
//    minStack.pop();
//    minStack.printStack();
//
//    cout << "Current minimum: " << minStack.get_min() << "\n";
//
//    cout << "Popping from the stack.\n";
//    minStack.pop();
//    minStack.printStack();
//
//    cout << "Current top: " << minStack.top() << "\n";
//
//    cout << "Current minimum: " << minStack.get_min() << "\n";
//
//    cout << "Popping from the stack.\n";
//    minStack.pop();
//    minStack.printStack();
//
//    cout << "Popping from the stack.\n";
//    minStack.pop();
//    minStack.printStack();
//
//    cout << "Attempting to pop from an empty stack.\n";
//    minStack.pop();
//
//    cout << "Current minimum: " << minStack.get_min() << "\n";
//    cout << "Current top: " << minStack.top() << "\n";
//
//    return 0;
//}
