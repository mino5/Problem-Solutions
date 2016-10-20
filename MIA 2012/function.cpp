#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;
queue <int> intstack;
stack <char> charstack;
//stack <int> currentStack;
bitset<400010> inProgram;
bitset<900000> outProgram;
//bitset<40> inProgram;
//bitset<40> outProgram;
string prog;

int main(int argc, char** argv)
{
    
    int numberOfCases, numberOfInstructions, temp;
    cin >> numberOfCases;
    
    while (--numberOfCases >=0)
    {
        int part = 0 , result = 0, i = 0, j = 0;
        inProgram.reset();
        outProgram.reset();
    
        cin >> numberOfInstructions;     
        cin >> prog;

        int progSize = prog.size();
        
        int pow16 = progSize - 1;
        int start = (progSize - 1) * 4;
        
        for(int j = 0; j < progSize; j++) 
        {
            int currentNumber = (prog[j] >= 'A') ? (prog[j] - 'A' + 10) : (prog[j] - '0');
            
            if (currentNumber - 8 >= 0) { if (j == 0) start += 3; inProgram[pow16 * 4 + 3] = 1; currentNumber -= 8; }
            if (currentNumber - 4 >= 0) { if (j == 0) start += 2; inProgram[pow16 * 4 + 2] = 1; currentNumber -= 4; }
            if (currentNumber - 2 >= 0) { if (j == 0) start += 1; inProgram[pow16 * 4 + 1] = 1; currentNumber -= 2; }
            if (currentNumber - 1 >= 0)   inProgram[pow16 * 4] = 1;
               
            pow16--;
        }
        
        int k = numberOfInstructions;
    
        while (--k >= 0)
        {
             cin >> temp;
             intstack.push(temp);
        }
      
        int instructionDiff = intstack.front();
        intstack.pop();
        
        i = 0;
        int outProgramCursor = 0;
        short current;
        int firstNumber = 0;

        
        while (numberOfInstructions > 0)
        {                     
            short current = inProgram[i];
                    
            if (current == 1)
            {
                if (numberOfInstructions > 1)
                    outProgram[outProgramCursor++] = 1;
                    
                part += (1 << j) ;
                j++;

            }
            else if (! (numberOfInstructions == 1 && i < start))
            {   

                 if (numberOfInstructions == 1)
                 {
                          part += instructionDiff;
                          
                          while (part > 0)
                          {
                                short rest = part % 2; 
                                part /= 2;
                                
                                outProgram[outProgramCursor++] = rest;
                          }
                                        
                 }
                 else
                 {
                     
                     while (instructionDiff--) 
                           outProgram[outProgramCursor++] = 1; 
                 }
                 
                 outProgram[outProgramCursor++] = 0;
                 if (!intstack.empty()) instructionDiff = intstack.front();
                 if (!intstack.empty()) intstack.pop();
                 numberOfInstructions--;
                 part = 0;
                 j = 0;
                     
            }
            else j++;
            
           i++;   
           
      }

       int currentHex = 0;
       char currentHexChar;

       for (int k = 0; k < outProgramCursor; k++)
       {
           // cout << "k: " << k << ", currentHex: " << currentHex << endl;
           if (k != 0 && (k % 4 == 0 || k == outProgramCursor - 1))
           {
                       currentHexChar = currentHex <= 9 ? currentHex + '0' : currentHex + 'A' - 10;
                       charstack.push(currentHexChar);
                       currentHex = outProgram[k];
           }
           else
           {           if (outProgram[k] == 1)
                          currentHex += (1 << ( k % 4)) ;
                           
           }
       }
       
       bool wasSth = false;
       while (!charstack.empty() && charstack.top() == '0') charstack.pop();
       
                   
   //    cout << outProgram << endl;
       while (!charstack.empty())
       {
             char currentHexChar = charstack.top();
             cout << currentHexChar;
             charstack.pop();
             wasSth = true;
       }    
       
       if (!wasSth) cout << "0";
       
       cout << endl;
    }
     
     return 0;   
}
