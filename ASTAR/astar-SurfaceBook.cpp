#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

//Function to print current board
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

vector<int> row_to_win_comp(char board[5][5]){
	//find number of moves by the computer needed to win (if possible) in each row
	int xcount = 0;
	bool is_o;
	vector<int> to_win_values;
	for(int i = 0; i < 5; i++){
		xcount = 0;
		is_o = false;
		//First we figure out if there is an O in the row to see if winning is possible
		for (int r = 0; r < 5; r++){
			if (board[i][r] == 'O')
				is_o = true;
		}
		//Then we add the current amount of X's to a counter
		for(int k = 0; k < 5 ; k++){
			if(board[i][k] == 'X')
				++xcount;
		}
		//Now add the weight (moves needed to win) for each row to a vector, if winning is not possible set 
		//the weight to an arbitrarily large value (25)
		if (is_o == false)
			to_win_values.push_back(5 - xcount);
		else if (is_o == true)
			to_win_values.push_back(25);
	}
	return to_win_values;
}

vector<int> column_to_win_comp(char board[5][5]){
	//find number of moves by the computer needed to win (if possible) in each column
	int xcount = 0;
	bool is_o;
	vector<int> to_win_values;
	for(int i = 0; i < 5; i++){
		xcount = 0;
		is_o = false;
		//First we figure out if there is an O in the column to see if winning is possible
		for (int r = 0; r < 5; r++){
			if (board[r][i] == 'O')
				is_o = true;
		}
		//Then we add the current amount of X's to a counter
		for(int k = 0; k < 5 ; k++){
			if(board[k][i] == 'X')
				++xcount;
		}
		//Now add the weight (moves needed to win) for each row to a vector, if winning is not possible set 
		//the weight to an arbitrarily large value (25)
		if (is_o == false)
			to_win_values.push_back(5 - xcount);
		else if (is_o == true)
			to_win_values.push_back(25);
	}
	return to_win_values;
}


vector<int> diagonal_to_win_comp(char board[5][5]){
	//find number of moves needed to win (if possible) in each diagonal
	int xcount = 0;
	vector<int> to_win_values;
	bool is_o_lr = false;
	bool is_o_rl = false;
	//First we figure out if there is an O in the left-to-right diagonal 
	//and right-to-left diagonal to see if winning is possible
	for (int r = 0; r < 5; r++){
		if (board[r][r]=='O'){
			is_o_lr = true;
		}
	}
	for (int r = 0; r < 5; r++){
		if (board[r][4-r]=='O'){
			is_o_rl = true;
		}
	}
	
	//Then we add the current amount of X's in the left-to-right diagonal to a counter
	for(int i=0; i<5; i++){
		if(board[i][i]=='X'){
			++xcount;
		}
	}
	//Now add the weight (moves needed to win) for each diagonal to a vector, if winning is not possible set 
	//the weight to an arbitrarily large value (25)
	if (is_o_lr == false){
		to_win_values.push_back(5 - xcount);
	}
	else if (is_o_lr == true){
		to_win_values.push_back(25);
	}
	
	//Repeat for the right-to-left diagonal
	xcount = 0;
	for(int i=0; i<5; i++){
		if(board[i][4-i]=='X'){
			++xcount;
		}
	}
	if (is_o_rl == false){
		to_win_values.push_back(5 - xcount);
	}
	else if (is_o_rl == true){
		to_win_values.push_back(25);
	}
	
	return to_win_values;
}

vector<int> row_to_win_player(char board[5][5]){
	//find number of moves needed by the player to win (if possible) in each row
	//Same formula as with row_to_win_comp
	int ocount = 0;
	bool is_x;
	vector<int> to_win_values;
	for(int i = 0; i < 5; i++){
		ocount = 0;
		is_x = false;
		for (int r = 0; r < 5; r++){
			if (board[i][r] == 'X')
				is_x = true;
		}
		for(int k = 0; k < 5 ; k++){
			if(board[i][k] == 'O')
				++ocount;
		}
		if (is_x == false)
			to_win_values.push_back(5 - ocount);
		else if (is_x == true)
			to_win_values.push_back(25);
	}
	return to_win_values;
}

vector<int> column_to_win_player(char board[5][5]){
	//find number of moves needed by the player to win (if possible) in each column
	//same formula as with column_to_win_comp
	int ocount = 0;
	bool is_x;
	vector<int> to_win_values;
	for(int i = 0; i < 5; i++){
		ocount = 0;
		is_x = false;
		for (int r = 0; r < 5; r++){
			if (board[r][i] == 'X')
				is_x = true;
		}
		for(int k = 0; k < 5 ; k++){
			if(board[k][i] == 'O')
				++ocount;
		}
		if (is_x == false)
			to_win_values.push_back(5 - ocount);
		else if (is_x == true)
			to_win_values.push_back(25);
	}
	return to_win_values;
}

vector<int> diagonal_to_win_player(char board[5][5]){
	//find number of moves needed by the player to win (if possible) in each diagonal
	//Same formula as diagonal_to_win_computer
	int ocount = 0;
	vector<int> to_win_values;
	bool is_x_lr = false;
	bool is_x_rl = false;
	for (int r = 0; r < 5; r++){
		if (board[r][r]=='X'){
			is_x_lr = true;
		}
	}
	for (int r = 0; r < 5; r++){
		if (board[r][4-r]=='X'){
			is_x_rl = true;
		}
	}
	
	for(int i=0; i<5; i++){
		if(board[i][i]=='O'){
			++ocount;
		}
	}
	if (is_x_lr == false){
		to_win_values.push_back(5 - ocount);
	}
	else if (is_x_lr == true){
		to_win_values.push_back(25);
	}
	
	ocount = 0;
	for(int i=0; i<5; i++){
		if(board[i][4-i]=='O'){
			++ocount;
		}
	}
	if (is_x_rl == false){
		to_win_values.push_back(5 - ocount);
	}
	else if (is_x_rl == true){
		to_win_values.push_back(25);
	}
	return to_win_values;
}

vector<int> to_win_sum_comp(char board[5][5]){
	//calculate moves needed to win and sum all of the moves needed to win into one vector
	vector<int> rtw, ctw, dtw, tw;
	rtw = row_to_win_comp(board);
	ctw = column_to_win_comp(board);
	dtw = diagonal_to_win_comp(board);
	for (int i =0; i < 5; i++){
		tw.push_back(rtw.at(i));
	}
	for (int i =0; i < 5; i++){
		tw.push_back(ctw.at(i));
	}
	for (int i =0; i < 2; i++){
		tw.push_back(dtw.at(i));
	}
	return tw;
}

vector<int> to_win_sum_player(char board[5][5]){
	//calculate moves needed to win and sum all of the moves needed to win into one vector
	vector<int> rtw, ctw, dtw, tw;
	rtw = row_to_win_player(board);
	ctw = column_to_win_player(board);
	dtw = diagonal_to_win_player(board);
	for (int i =0; i < 5; i++){
		tw.push_back(rtw.at(i));
	}
	for (int i =0; i < 5; i++){
		tw.push_back(ctw.at(i));
	}
	for (int i =0; i < 2; i++){
		tw.push_back(dtw.at(i));
	}
	return tw;
}

vector<int> best_move_comp(char board[5][5]){
	//find computers best move that will bring it closest to a win
	vector<int> tw_c = to_win_sum_comp(board);
	int best_tw = 25;
	int best_tw_position = 0;
	//Loop through the vector and find the lowest value needed to win, add this
	//item and its position to a vector and return it
	for (int i = 0; i < 12; i++){
		if (tw_c.at(i) != 25 && tw_c.at(i) < best_tw){
			best_tw = tw_c.at(i);
			best_tw_position = i;
		}
	}
	vector<int> best_move;
	best_move.push_back(best_tw);
	best_move.push_back(best_tw_position);
	return best_move;
}

vector<int> best_move_player(char board[5][5]){
	//find players best move that will bring it closest to a win
	vector<int> tw_c = to_win_sum_player(board);
	int best_tw = 25;
	int best_tw_position = 0;
	//Loop through the vector and find the lowest value needed to win, add this
	//item and its position to a vector and return it
	for (int i = 0; i < 12; i++){
		if (tw_c.at(i) != 25 && tw_c.at(i) < best_tw){
			best_tw = tw_c.at(i);
			best_tw_position = i;
		}
	}
	vector<int> best_move;
	best_move.push_back(best_tw);
	best_move.push_back(best_tw_position);
	return best_move;
}


void h_function(char board[5][5]){
	//function to determine the best possible move for the comp, be it to block or to place its own
	vector<int> b_m_p = best_move_player(board);
	vector<int> b_m_c = best_move_comp(board);
	if (b_m_p.at(0) < b_m_c.at(0)){
		//if the player is closer to winning than the computer, block it by taking his best move
		//handle equal weight positions where either option would bring you the same distance
		//to victory just by prioritizing top left as most important to bottom right least important placement
		if (b_m_p.at(1) < 5){ //If the best player move is on a row, block it
			for (int i = 0; i < 5; i++){
				if (board[b_m_p.at(1)][i] == '_'){
					board[b_m_p.at(1)][i] = 'X';
					break;
				}
			}	
		}
		if (b_m_p.at(1) > 4 && b_m_p.at(1) < 10){//If the best player move is on a column, block it
			for (int i = 0; i < 5; i++){
				if (board[i][b_m_p.at(1) - 5] == '_'){
					board[i][b_m_c.at(1) - 5] = 'X';
					break;
				}
			}	
		}
		if (b_m_p.at(1) == 10){//If the best player move is on a left-to-right diagonal, block it
			for (int i = 0; i < 5; i++){
				if (board[i][i] == '_'){
					board[i][i] = 'X';
					break;
				}
			}	
		}
		if (b_m_p.at(1) == 11){//If the best player move is on a right-to-left diagonal, block it
			for (int i = 0; i < 5; i++){
				if (board[i][4-i] == '_'){
					board[i][4-i] = 'X';
					break;
				}
			}	
		}
	}
	else{
		//otherwise, take the best computer move
		//handle equal weight positions where either option would bring you the same distance
		//to victory just by prioritizing top left as most important to bottom right least important placement
		if (b_m_c.at(1) < 5){
			for (int i = 0; i < 5; i++){
				if (board[b_m_c.at(1)][i] == '_'){
					board[b_m_c.at(1)][i] = 'X';
					break;
				}
			}	
		}
		if (b_m_c.at(1) > 4 && b_m_c.at(1) < 10){
			for (int i = 0; i < 5; i++){
				if (board[i][b_m_c.at(1) - 5] == '_'){
					board[i][b_m_c.at(1) - 5] = 'X';
					break;
				}
			}	
		}
		if (b_m_c.at(1) == 10){
			for (int i = 0; i < 5; i++){
				if (board[i][i] == '_'){
					board[i][i] = 'X';
					break;
				}
			}	
		}
		if (b_m_c.at(1) == 11){
			for (int i = 0; i < 5; i++){
				if (board[i][4-i] == '_'){
					board[i][4-i] = 'X';
					break;
				}
			}	
		}
	}
}

int main(){
	char board[5][5] =
			{ 
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
				{'_','_','X','_','_'},
				{'_','_','_','_','_'},
				{'_','_','_','_','_'},
    };
	cout << "Starting board:" << endl;
	PrintBoard(board);
	int input1 = 0;
	int input2 = 0;
	ofstream outfile;
	outfile.open("log.txt");
	outfile << "Game begins\n Difficulty: Hard\n AI Algorithm: A*\n\n";
	while (input1 != -1){
		cout << "Enter the row of your choice." << endl;
		cin >> input1;
		cout << "Enter the column of your choice." << endl;
		cin >> input2;
		board[input1 - 1][input2 - 1] = 'O';
		h_function(board);
		cout << "Current board:" << endl;
		PrintBoard(board);
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				outfile << board[i][j] << " ";
			}
			outfile << endl;
		}
		outfile << endl;
	}
	
	return 0;
}