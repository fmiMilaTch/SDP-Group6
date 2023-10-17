#include <iostream>
#include "stack.hpp"

template<typename T>
class StackQueue {
    Stack<T> pushStack;
    Stack<T> popStack;
    T topElem;
    unsigned queueLen=0;

    void reversal(Stack<T>&, Stack<T>&);
public:

    void push(const T&);
    bool isEmpty();
    T pop();
    T peek();
};

template<typename T>
void StackQueue<T>::reversal(Stack<T>& source, Stack<T>& destination){
    for(unsigned i=0;i<queueLen;i++){
       destination.Push(source.Pop());
    }
}

template<typename T>
void StackQueue<T>::push(const T& newElem){
    if(!queueLen){
        topElem=newElem;
    }
    pushStack.Push(newElem);
    queueLen++;
}

template<typename T>
T StackQueue<T>::pop(){
    if(queueLen){
        reversal(pushStack,popStack);
        T popElem=popStack.Pop();
        topElem=popStack.Peek();
        queueLen--;
        reversal(popStack,pushStack);

        return popElem;
    }
    ///exception;
}

template<typename T>
T StackQueue<T>::peek(){
    if(queueLen){
        return topElem;
    }
    ///exception;
}

template<typename T>
bool StackQueue<T>::isEmpty(){
    return !queueLen;
}
