
#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;


class ABNode { // uses the class BinaryNode
	public:
		int board_value=0;
		int depth = 0;
		char board[5][5]=
			{ 
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
            };
		vector<ABNode> children;
	
		ABNode(){}
	
};

void PrintBoard(char board[5][5]){
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

int boardspace(char board[5][5]){
	int size=0;
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(board[i][j]=='_')
					{size++;}	
			}
		}
		return size;
}

int row_score(char board[5][5]){
	int ocount = 0;
	int xcount = 0;
	int row[5];
	int score = 0;
	for(int i=0; i<5; i++){
		xcount =0;
		ocount =0;
		for(int k = 0; k<5 ; k++)
		{
			if(board[i][k]=='X')
				++xcount;	
			else if(board[i][k]=='O')
				++ocount;
		}
		if(xcount>0 && ocount>0)
			row[i] = 0;
		else
			row[i]=(int)(pow(10,(xcount-1)))-(int)(pow(10,(ocount-1)));
				//cout<<row[i]<<endl;		
	}
	for(int j = 0; j < 5; ++j)
	{
		score += row[j];
	} 
	return score;
}

int column_score(char board[5][5]){
	int ocount = 0;
	int xcount = 0;
	int score = 0;
	int column[5];
	for(int i=0; i<5; i++){
	    xcount =0;
		ocount =0;
		for(int k = 0; k<5 ; k++){	
				if(board[k][i]=='X')
						++xcount;	
				else if(board[k][i]=='O')
						++ocount;
					}	
				if(xcount>0 && ocount>0)
					column[i] = 0;
				else
					column[i] = (int)(pow(10,(xcount-1)))-(int)(pow(10,(ocount-1)));
		}
	for(int j = 0; j < 5; ++j){
			score += column[j];
			} 
	return score;
}

int diagonal_score(char board[5][5]){
	int ocount = 0;
	int xcount = 0;
	int score = 0;
	for(int i=0; i<5; i++){
		if(board[i][i]=='X')
			++xcount;	
		else if(board[i][i]=='O')
			++ocount;}
	if(xcount>0 && ocount>0)
		score += 0;
	else
		score += (int)(pow(10,(xcount-1)))-(int)(pow(10,(ocount-1)));
	ocount =0;
	xcount =0;
	for(int i=0; i<5; i++){
		if(board[i][4-i]=='X')
			++xcount;	
		if(board[i][4-i]=='O')
			++ocount;}
	if(xcount>0 && ocount>0)
		score += 0;
	else
		score += (int)(pow(10,(xcount-1)))-(int)(pow(10,(ocount-1)));
	//cout<<score<<endl;		
	return score;
}

int calculate_board(char board[5][5]){
	int score = 0;
		score = diagonal_score(board)+row_score(board)+column_score(board);
		return score;
		}
	


int win_condition(char array[5][5]){
	char winner = 'k';
	for (int i = 0; i < 5; i++){
    if (array[i][0] == array[i][1] and array[i][1] == array[i][2] 
		and array[i][2] == array[i][3] and array[i][3] == array[i][4])
			{winner = array[i][0];}
			if(winner == 'X'){return 100;}
			if(winner == 'O'){return -100;}
	}

	for (int i = 0; i < 5; i++){
	if (array[0][i] == array[1][i] and array[1][i] == array[2][i]
		and array[2][i] == array[3][i]	and array[3][i] == array[4][i])
			 {winner = array[0][i];}
				if(winner == 'X'){return 100;}
				if(winner == 'O'){return -100;}
	}

	if ((array[0][0] == array[1][1] and array[1][1] == array[2][2] and array[2][2] == array[3][3] and array[3][3] == array[4][4] ) or 
		(array[0][4] == array[1][3] and array[1][3] == array[2][2] and array[2][2] == array[3][1] and array[3][1] == array[4][0]))
			{winner = array[2][2];}
		
	if(winner == 'X'){return 100;}
	if(winner == 'O'){return -100;}
	return 0;

}



int recursiveTreeWalk(ABNode &root, char XO, int size, int alpha, int beta)
{
   if(win_condition(root.board)>0){
		root.board_value = 1000000;
		//cout<<"winner"<<endl;
		return root.board_value;
	}
	else if(win_condition(root.board)<0){
		root.board_value = -1000000;
		//cout<<"loser"<<endl;
		return root.board_value;
	}
   else if(size==0 || root.depth == 5){		
		root.board_value = calculate_board(root.board);
		return root.board_value;
		
	}
	else{
		if(XO == 'O'){
			XO = 'X';
			//root.board_value = alpha;
		}else{
			//root.board_value = beta;
			XO = 'O';
			}
	root.children.resize(size);
	char board[5][5];
	memcpy(board, root.board,sizeof(root.board));
	for(int k=0;k<root.children.size();k++){
		memcpy(root.children[k].board, root.board, sizeof(root.board));
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(board[i][j]=='_')
					{
					board[i][j] = XO;
					root.children[k].board[i][j] = XO;
					root.children[k].depth = root.depth + 1;
					
					i=5;
					j=5;
					}	
			}
		}
		int score;
		
		if(XO == 'X'){
			score = recursiveTreeWalk(root.children[k], XO, size-1, alpha, beta);
			//root.board_value = max(root.board_value, root.children[k].board_value);
			//root.children[k].board_value = score;
			
			if(score > alpha ){
				alpha = score;
				root.children[k].board_value = score;
				//memcpy(root.board,root.children[k].board, sizeof(root.children[k].board));
			}
			else{
			root.children[k].board_value = -99999999;
			}
			if(beta <= alpha)
				break;	
		}
		else{
			score = recursiveTreeWalk(root.children[k], XO, size-1, alpha, beta);
			//root.board_value = min(root.board_value, root.children[k].board_value);
			//root.children[k].board_value = score;
			
			if(score < beta){
				beta = score;
				root.children[k].board_value = score;
				//memcpy(root.board,root.children[k].board, sizeof(root.children[k].board));
				}
			else{
			root.children[k].board_value = 99999999;
			}
			if(beta <= alpha)
				break;
				
			
				}
			
	}
	
	if(XO == 'X'){
		//root.board_value = alpha;
		return alpha;}
	else{
		//root.board_value = beta;
		return beta;
	}
	 
}
return root.board_value;
}


int minimax(char board[5][5]){
	int x, y;
	ABNode root;
	for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(board[i][j]!=root.board[i][j])
					{
						root.board[i][j]=board[i][j];
					}
						
			}
		}
	int size = boardspace(root.board);
	int ALPHA = -99999999;
	int BETA = 99999999;
	PrintBoard(root.board);
	int best = recursiveTreeWalk(root, 'O', size, ALPHA, BETA);
	for(unsigned int k = 0; k<root.children.size(); ++k){
		if(best == root.children[k].board_value){
		cout<<root.children[k].board_value<<endl;	
		PrintBoard(root.children[k].board);
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(board[i][j]!=root.children[k].board[i][j]){
					x =i;
					y =j;}
			}
		}
	}
	}
	return x*10+y;
}

int main(){
	char board[5][5] =
			{ 
				{'O','_','_','_','_'},
				{'_','_','_','_','_'},
				{'_','_','X','_','_'},
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
    };
	cout<<minimax(board)<<endl;
	

return 0;
}