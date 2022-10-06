/*        Approach to the problem
 

 For this question, I made use of 2 stacks. 
 One to keep track of the previous number (numbers) and one for the closing bracket (brackets). 
 So when the stacks are empty, I insert the first number and corresponding closing brackets into the respective stacks. 
 Now when I encounter next number in the list, so based on the number inside of the top of numbers stack, I take the difference between the top number in the stack and the new number from list and insert or pop closing brackets based on that.

Basically taking two stacks, a paper, pen and walk through the string, will give you the idea around how to solve this problem. 
Time complexity of the whole program is O(N*9).

below is the code .
*/

#include <bits/stdc++.h>
#include <string> 

using namespace std;

int main()
{
  int T;
  cin>>T;
  int W = 1;
  while(T--) {
    string s;
    cin>>s;
    vector<int> A;
    for(int i=0; i<s.length(); i++) {
      A.push_back(s[i]-48);
    }
    stack<char> endBrackets;
    stack<int> numbers;
    string ans = "";
    for(int i=0; i<A.size(); i++) {
      int value = A[i];
      if(numbers.size() == 0) {
        for(int j=0; j<value; j++) {
        ans += '(';
        endBrackets.push(')');
      }
      }
      // here we will solve for either positive difference or negative difference
      if(numbers.size() > 0) {
        int top = numbers.top();
        numbers.pop();
        int diff = top - value;
        if(diff == 0) {
          ans += std::to_string(top);
          numbers.push(value);
        } else if(diff > 0) {
          ans += std::to_string(top);
          int k = 0;
          while(k<diff) {
            int ch = endBrackets.top();
            endBrackets.pop();
            ans += ch;
            k++;
          }
          numbers.push(value);
        } else {
          ans += std::to_string(top);
          diff = -1*diff;
          for(int k=0; k<diff; k++) {
            ans += '(';
          }
          for(int k=0; k<diff; k++) {
            endBrackets.push(')');
          }
          numbers.push(value);
        }
      } else {
        numbers.push(value);
      }
    }
    while(!numbers.empty()) {
      int top = numbers.top();
      numbers.pop();
      ans += std::to_string(top);
      while(!endBrackets.empty()) {
        ans += endBrackets.top();
        endBrackets.pop();
      }
    }
    cout<<"Case #"<<W<<": "<<ans<<endl;
    W++;
  }
  return 0;
}

/*
4
021
312
4
221
*/