#include <iostream> 
using namespace std;

template <typename T>
class Stack
{
private:

    struct Node
    {
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* top;
    int size;

public:

    Stack() : top(nullptr), size(0) {}
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(const T& value)
    {
        Node* newNode = new Node(value, top);
        top = newNode;
        ++size;
    }
 
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        --size;
    }
 
    T peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return T();
        }

        return top->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
    cout << "Stack size after pop: " << stack.getSize() << endl;

    return 0;
}