
///Task 1
#include <iostream>
#include "stack.hpp"
#include <string>

void inputParr(Stack<char> &, const std::string&);
bool areParrCorrect(const Stack<char> &);
int main (){

    Stack<char> Parr;
    std::string input;
    std::cin>>input;
    inputParr(Parr,input);

    std::cout<<areParrCorrect(Parr);

}

void inputParr(Stack<char> & parrStack, const std::string& input){
    int inputLenght=input.length();
    for(int i=0;i<inputLenght;i++){
        parrStack.Push(input[i]);
    }
}

bool areParrCorrect(const Stack<char> & parrStack){
    Stack<char> stackCpy(parrStack);

    char lastParr, currParr;
    int openParr=0;
    while(!stackCpy.Empty()){
        lastParr=stackCpy.Peek();
        if((lastParr==')')||(lastParr=='}')||(lastParr==']')){
            openParr++;
        }
        else{
            openParr--;
        }
        stackCpy.Pop();
        currParr=stackCpy.Peek();
        if((lastParr==')'&&((currParr=='{')||(currParr=='[')))||(lastParr=='}'&&((currParr=='(')||(currParr=='[')))||(lastParr==']'&&((currParr=='{')||(currParr=='(')))){
            return false;
        }
    }
    return openParr==0;
}
