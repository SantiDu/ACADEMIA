#include <iostream>
#include <iomanip>

using namespace std;

template <class T>    // This parameter type T allows us to instantiate a Stack containing elements of any type.
class Stack {
    private:
        int size;                    // Stack has fixed size.
        int top_index;           // which element is at the top of the Stack.
        int element_count;  // keep track of elements to avoid overflow.
        T * list;                 // a dynamic array of T objects.
    public:
        static const int DEFAULT_STACK_SIZE;
        static const int DEFAULT_TOP_INDEX;
        static const int DEFAULT_ELEMENT_COUNT;
    public:
        Stack();
        Stack(int size);
        ~Stack();
        void ShowContent() const;
        bool Push (T m_object);    // insert a T object to the Stack data structure
        T Pop();                          // remove an object from the list and return it
        int GetCount() const;
};

class Car {
};

int main() {
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.ShowContent();
    stack.Pop();
    stack.ShowContent();

    Stack <Car *> * p_stack = nullptr;
    p_stack = new Stack<Car *>();
    p_stack->Push(nullptr);
    p_stack->Pop();
    Car * p_car = nullptr;
    while ( p_stack->GetCount() > 0) {
        p_car = p_stack->Pop();    // remove the top Car * element on the Stack. 
        delete p_car;
    }
    delete p_stack;
    return 0;
}

template <class T>
const int Stack<T>::DEFAULT_STACK_SIZE = 1024;
template <class T>
const int Stack<T>::DEFAULT_TOP_INDEX = -1;
template <class T>
const int Stack<T>::DEFAULT_ELEMENT_COUNT = 0;

template <class T>
Stack<T>::Stack ( ) : size  (Stack<T>::DEFAULT_STACK_SIZE ), 
                                    top_index (Stack<T>::DEFAULT_TOP_INDEX),
                                    element_count (Stack<T>::DEFAULT_ELEMENT_COUNT),
                                    list (new T [ Stack<T>::DEFAULT_STACK_SIZE ])  {  }

template <class T>
Stack<T>::Stack ( int size ) : size  (size), 
                                                top_index (Stack<T>::DEFAULT_TOP_INDEX),
                                                element_count (Stack<T>::DEFAULT_ELEMENT_COUNT),
                                                list ( new T [ size] ) {  }

template <class T>
Stack<T>::~Stack() {
    delete[] list;
}

template <class T>
void Stack<T>::ShowContent() const {
    for (int i = 0; i < element_count; ++i) {
        cout << list[i] << endl;
    }
}

template <class T>
bool Stack<T>::Push ( T object ) {
         if (element_count < size) {
                 top_index++; 
                 list [top_index] = object;     // always add to the top of the Stack.
                 element_count++;
                  return true; 
          }
          else {
                return false;
          }
}

template <class T>
T   Stack<T>::Pop  ( ) {
   if  ( top_index != -1 ) {  // if stack is not empty
        T  val = list[ top_index];    // save the top element to return.
             top_index--;
             element_count--;
              return val;
     }
     else {
           T default_object;
           return default_object; // stack is empty- return a default object.
      }
}

template <class T>
int Stack<T>::GetCount() const {
     return element_count;
}