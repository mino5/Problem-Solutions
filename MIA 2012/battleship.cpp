#include <iostream>
#include <memory.h>
#include <bitset>

using namespace std;
bool playerOneField[31][31];
bool playerTwoField[31][31];

int main()
{
    
    short numberOfCases, n, w, h, orderX, orderY, p1shipPoints, p2shipPoints, p1turns, p2turns;
    char c;
    
    cin >> numberOfCases;
    
    while (numberOfCases--)
    {
          cin >> w; cin >> h; cin >> n;
          
          memset(playerOneField, false, sizeof(playerOneField));
          memset(playerTwoField, false, sizeof(playerTwoField));
          p1shipPoints = 0;
          p2shipPoints = 0;
          
          for (int i = h - 1; i >= 0; i--)
              for (int j = 0; j < w; j++)
              {
                  cin >> c;
                  if (c == '#') { playerOneField[j][i] = true; p1shipPoints++; }
              }
            
          for (int i = h - 1; i >= 0; i--)
              for (int j = 0; j < w; j++)
              {
                  cin >> c;
                  if (c == '#') { playerTwoField[j][i] = true; p2shipPoints++; }
              }         

          bool firstPlayerTurn = true;
          bool bonusRound = false;
          bool gameOver = false;
          
          p1turns = 0;
          p2turns = 0;
          
          while (n--)
          {
                cin >> orderX; cin >> orderY;
//                if (firstPlayerTurn) cout << "P1 turn (" << orderX << "," << orderY << ")" << ", turns: " << p1turns << endl;
  //                 else  cout << "P2 turn (" << orderX << "," << orderY << ")" << ", turns: " << p2turns << endl;
                   
                
                
                if (!gameOver)
                {
                
                if (!bonusRound && (p1turns == p2turns && (p1shipPoints == 0  || p2shipPoints == 0))) { gameOver = true; } //cout << "Game is over" << endl; }
                else
                {
                    if (firstPlayerTurn)
                    {
                      if (!bonusRound)
                          p1turns++;
                      
                      bonusRound = false;
                      
                      // SHOT
                      if (playerTwoField[orderX][orderY])
                      {
    //                         cout << "P2 got shot on " << orderX << " " << orderY << endl;
                             playerTwoField[orderX][orderY] = false;
                             p2shipPoints--;
                             
                             if (p2shipPoints == 0) firstPlayerTurn = false;
                                else bonusRound = true;                               
                                 
                      }                    
                      else firstPlayerTurn = false;
                                    
                }
                else
                {
                    if (!bonusRound) 
                       p2turns++;
                    
                    bonusRound = false;
                    
                    // SHOT
                    if (playerOneField[orderX][orderY])
                    {
      //                     cout << "P1 got shot on " << orderX << " " << orderY << endl;
                           playerOneField[orderX][orderY] = false;
                           p1shipPoints--;
                           if (p1shipPoints == 0) firstPlayerTurn = true; 
                              else bonusRound = true;
                    }
                    else firstPlayerTurn = true;
                }
             }
                  
           }
        }
                
        //  cout << "P1ShipPoints " << p1shipPoints << endl;
          //cout << "P2ShipPoints " << p2shipPoints << endl;
          //cout << "p1turns " << p1turns << endl;
          //cout << "p2turns " << p2turns << endl;
          
          if (p1shipPoints == p2shipPoints || (p1shipPoints > 0 && p2shipPoints > 0)) cout << "draw" << endl;
             else if (p1shipPoints == 0) cout << "player two wins" << endl;
             else if (p2shipPoints == 0) cout << "player one wins" << endl;
    }
     
    return 0;
       
}
