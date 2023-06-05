#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;
queue<string> directions;
void fillQueue(){
    //you would build a loop to ask for directions
    //quit when done, do not add quit to queue
    directions.push("Step 1 - heat oven to 350");
    directions.push("Step 2 - mix ingredients");
    directions.push("Step 3 - pour into pan");
    directions.push("Step 4 - put in oven");
    directions.push("Step 5 - cook for 1 hour");
}
void showQueue(){
    string aStep;
    while(!directions.empty()){
        aStep = directions.front();//get the first object
        directions.pop();
        cout << aStep << endl;
        //system.pause(1000);
    }
}
bool balancedExpression(string exp){
    //find a ( - put (push) on the stack
    //find a ) - pop from the stack
    //the pop should match (should be a close )  )
    //stack should be empty at the end of the function
    stack<char> parens;
    for(char ch : exp){
        if(ch == '(' || ch == '{' || ch == '['){
            parens.push(ch);
        }

        if(ch == ')' || ch == '}' || ch==']'){
            //if stack is empty, unbalanced
            if(parens.empty()){
                return false;
            }

            char top = parens.top();//take from the stack
            parens.pop();           //object is now gone
            if((top == '(' && ch !=')')
                || (top == '{' && ch !='}')
                || (top == '[' && ch !=']')){
                return false;
            }//end top if
        }//end  if )
    }//end for loop
    
    return parens.empty();

}

int main(){
    fillQueue();
    showQueue();
  /*  string exp = "({5 - x}*[2 + x])";   //balanced
    string exp2 = "{((5 - x)[*(]2 + x)))"; //not balanced
    if(balancedExpression(exp)){
        cout << exp << " is balanced\n";
    }
    else {
        cout << exp << "is not balanced\n";
    }
    if(balancedExpression(exp2)){
        cout << exp2 << " is balanced\n";
    }
    else {
        cout << exp2 << "is not balanced\n";
    }
*/
}
