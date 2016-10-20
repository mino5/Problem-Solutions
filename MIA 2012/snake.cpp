#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <bitset>

using namespace std;
typedef pair<int,int> pii;

struct SnakeState
{
    int count;   	
    vector<pii> snake;
};
 
int n,m;
pii moves[16];

queue<SnakeState> q;
	
void GenerateMoves (SnakeState state, char** board)
{
	int allowedMoves = 15; // 1111 UP/DOWN/LEFT/RIGHT
		
	pii head = *state.snake.begin();
	pii next;
	
	
	// krańce planszy
	if (head.first <= 0)
	{
		allowedMoves &= 13; // 1101
		}
	
	if (head.second <= 0)
	{
	        allowedMoves &= 7;  // 0111
	        }
	
	if (head.first >= m - 1)
	{
		allowedMoves &= 14; // 1110
		}
	
	if (head.second >= n - 1)
	{
		allowedMoves &= 11;  // 1011
		}
		
								
	// wall
	
	if (head.second < n && head.first < m - 1 && board[head.first + 1][head.second] == '#')
	{
		allowedMoves &= 14;
		}

	if (head.first > 0 && head.second < n && board[head.first - 1][head.second] == '#')
	{
		allowedMoves &= 13;
		}
		
	if (head.second > 0 && head.first < m && board[head.first][head.second - 1] == '#')
	{

		allowedMoves &= 7;
		}
	
	if (head.first < m && head.second < n - 1 && board[head.first][head.second + 1] == '#')
	{
		allowedMoves &= 11;
		}
	

	vector<pii>::iterator i;
        i = state.snake.begin();
        ++i;
        
        
        int count = (state.snake.size()) - 2;
        
        int it = 0;	
	for(;i != state.snake.end(); ++i)	
	{

		if (it == count) break;
				it++;
		pii next = (*i);
		
		
		if (next.first == head.first - 1 && next.second == head.second)
			allowedMoves &= 13;
	
		if (next.first == head.first + 1 && next.second == head.second)
			allowedMoves &= 14;
		
		if (next.second == head.second - 1 && next.first == head.first)
			allowedMoves &= 7;
		
		if (next.second == head.second + 1 && next.first == head.first)
			allowedMoves &= 11;
		
	}	
	int move = 8; // 1000

	while (allowedMoves != 0)
	{	
	
		if ((allowedMoves & move) > 0)	
		{
			SnakeState newSnakeState;
			newSnakeState.snake = vector<pii>();
			newSnakeState.count = state.count + 1;
			
			pii whereToMove = moves[move]; 
			pii newStart = *state.snake.begin();
			newStart.first += whereToMove.first;
			newStart.second += whereToMove.second;
			newSnakeState.snake.push_back(newStart);
			
			
			vector<pii>::iterator i = state.snake.begin();
			pii prev = (*i);
						
	        	for(; i != state.snake.end(); ++i)
	        	{
				  newSnakeState.snake.push_back((*i));
		        }
		        
		        newSnakeState.snake.pop_back();
		        q.push(newSnakeState);
	        }
	        
	       if ((allowedMoves & move) > 0)
		        allowedMoves -= move;
	       
	      	move = move >> 1;
	       
	       
        }   
}

int enc(pii a, pii b)
{
	if (a.first == b.first && a.second == b.second - 1) return 0;
	if (a.first == b.first && a.second == b.second + 1) return 1;
	if (a.second == b.second && a.first == b.first + 1) return 2;
	if (a.second == b.second && a.first == b.first - 1) return 3;
	
	return 0;
}

inline int enc2(pii a, pii b) { 	

	if (a.first==b.first && a.second==b.second+1) return 0; 
	if (a.first==b.first && a.second+1==b.second) return 1;
	if (a.first==b.first+1 && a.second==b.second) return 2;
	if (a.first+1==b.first && a.second==b.second) return 3;
}


int codeSnake(vector<pii> snake)
{
	int code = 0;
	
	vector<pii>::iterator i;
	i = snake.begin();
	
	pii head = (*i);
	
//	code = head.first * 16 + head.second;
	code |= head.first;
	code |= head.second << 4;
	
	int b = 8;
	
	++i;
	pii prev = head;
	
	
	for(; i != snake.end(); ++i)
        {
		//code = code << 2;
		pii current = (*i);
		//code += enc(prev, current);
		
		code |= enc2(prev, current) << b;
		b+=2;
		prev = (*i); 
	} 
	
	return code;
}


bitset<1<<24> codedSnake;
int main(int argc, char** argv)
{
	
 
	char c;
	cin >> n; // Y
	cin >> m; // X
	
	moves[8] = make_pair(0,-1);
	moves[4] = make_pair(0,1);
	moves[2] = make_pair(-1,0);
	moves[1] = make_pair(1,0);
	
	pii apple;
	SnakeState ss;
	ss.snake = vector<pii>();
	ss.count = 0;
	
        char** board = new char*[m + 1];
        
        for (int i = 0; i <= m; ++i)
        {
        	board[i] = new char[n + 1];
        }
        

	pii* l = new pii[n*m];
	int max = 1;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			cin >> c;
			
			board[j][i] = c;
			
			if (isdigit(c))
			{
				l[c - 48] = make_pair(j,i);
				if (c - 48 > max) max = c - 48;
			}
			else if (c == '@')
			{
				apple = make_pair(j,i);
			}
		}
	
	}
	
	for (int j = 1; j <= max; j++)
	{
		ss.snake.push_back(l[j]);
	}
	
	q.push(ss);
	
	int result = -1;
	
	while (!q.empty())
	{
		SnakeState current = q.front();
		q.pop();
		
		int code = codeSnake(current.snake);

		if (codedSnake[code] == 0)
        {
                               
              codedSnake[code] = 1;
              if (*(current.snake.begin()) == apple)
              {
	     	     	result = current.count;
		          	break;
              }

              GenerateMoves(current, board);
         }
	}
	
	cout << result << endl;
		
	return 0;
}
