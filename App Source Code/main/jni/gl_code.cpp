
#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <string>



#define  LOG_TAG    "libgl2jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
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
    std::vector<ABNode> children;

    ABNode(){}

};

void PrintBoard(char board[5][5]){
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            //cout << board[i][j] << " ";
        }
        //cout << endl;
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
    int ocount{0}, xcount{0}, score{0};
    int row[5];
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
    int ocount{0}, xcount{0}, score{0};
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
        if(winner == 'O'){return -100;}}
    for (int i = 0; i < 5; i++){
        if (array[0][i] == array[1][i] and array[1][i] == array[2][i]
            and array[2][i] == array[3][i]	and array[3][i] == array[4][i])
        {winner = array[0][i];}
        if(winner == 'X'){return 100;}
        if(winner == 'O'){return -100;}}
    if ((array[0][0] == array[1][1] and array[1][1] == array[2][2]
         and array[2][2] == array[3][3] and array[3][3] == array[4][4] ) or
        (array[0][4] == array[1][3] and array[1][3] == array[2][2]
         and array[2][2] == array[3][1] and array[3][1] == array[4][0]))
    {winner = array[2][2];}
    if(winner == 'X'){return 100;}
    if(winner == 'O'){return -100;}
    return 0;
}



int recursiveTreeWalk(ABNode &root, char XO, int size, int alpha, int beta)
{
    if(win_condition(root.board)>0){
        root.board_value = 1000000;
        return root.board_value;
    }
    else if(win_condition(root.board)<0){
        root.board_value = -1000000;
        return root.board_value;
    }
    else if(size==0 || root.depth == 5){
        root.board_value = calculate_board(root.board);
        return root.board_value;
    }
    else{
        if(XO == 'O'){
            XO = 'X';
        }else{
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
                if(score > alpha ){
                    alpha = score;
                    root.children[k].board_value = score;

                }
                else{
                    root.children[k].board_value = -99999999;
                }
                if(beta <= alpha)
                    break;
            }
            else{
                score = recursiveTreeWalk(root.children[k], XO, size-1, alpha, beta);
                if(score < beta){
                    beta = score;
                    root.children[k].board_value = score;
                }
                else{
                    root.children[k].board_value = 99999999;
                }
                if(beta <= alpha)
                    break;
            }

        }

        if(XO == 'X'){
            return alpha;}
        else{

            return beta;
        }

    }

}


std::string itos(int x,int y){
       std::string x_cord = "";
        std::string y_cord = "";
        if(x==0){
            x_cord = "0";
        }
        if(x==1){
            x_cord = "1";
        }
        if(x==2){
            x_cord = "2";
        }
        if(x==3){
            x_cord = "3";
        }
        if(x==4){
            x_cord = "4";
        }
        if(y==0){
            y_cord = "0";
        }
        if(y==1){
            y_cord = "1";
        }
        if(y==2){
            y_cord = "2";
        }
        if(y==3){
            y_cord = "3";
        }
        if(y==4){
            y_cord = "4";
        }
    return (x_cord+y_cord);
}

int tie_condition(char board[5][5]){
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(board[i][j] == '_')
            {
                return 0;
            }

        }
    }
    return 6969;

}

std::string minimax(char board[5][5]){
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
            PrintBoard(root.children[k].board);
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    if(board[i][j]!=root.children[k].board[i][j]){
                        x =i;
                        y =j;}
                    board[i][j]=root.children[k].board[i][j];
                }
            }
        }
    }
    int win = win_condition(board);
    string info="3";
    if(win == 100){info = "0";}
    if(win == -100){info = "1";}
    if(tie_condition(board)==6969){info = "2";}
    return itos(x,y)+info;
}

std::string get_best_move(std::string s){

    char board[5][5] =
            {
                    {s[0],s[1],s[2],s[3],s[4]},
                    {s[5],s[6],s[7],s[8],s[9]},
                    {s[10],s[11],s[12],s[13],s[14]},
                    {s[15],s[16],s[17],s[18],s[19]},
                    {s[20],s[21],s[22],s[23],s[24]},
            };

    std::string move_cord = minimax(board);

    return move_cord;
}

//Function to print current board


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
                    board[i][b_m_p.at(1) - 5] = 'X';
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

string astar(string s){
    char board[5][5] =
            {
                    {s[0],s[1],s[2],s[3],s[4]},
                    {s[5],s[6],s[7],s[8],s[9]},
                    {s[10],s[11],s[12],s[13],s[14]},
                    {s[15],s[16],s[17],s[18],s[19]},
                    {s[20],s[21],s[22],s[23],s[24]},
            };
    char old[5][5];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {

                old[i][j]=board[i][j];


        }
    }
           h_function(board);

    int x{900},y;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(board[i][j]!=old[i][j]){
                x =i;
                y =j;}
        }
    }

    int win = win_condition(board);
    if(x == 900){return "bugg";}
    string info = "3";
    if(win == 100){info = "0";}
    if(win == -100){info = "1";}
    if(tie_condition(board)==6969){info = "2";}
    return itos(x,y)+info;
}


extern "C" {
    JNIEXPORT jstring JNICALL Java_com_android_gl2jni_AIfunctions_aiminimax(JNIEnv * env, jobject obj , jstring board_string);
    JNIEXPORT jstring JNICALL Java_com_android_gl2jni_AIfunctions_astar(JNIEnv *env, jobject thisObj, jstring inJNIStr);
};

JNIEXPORT jstring JNICALL Java_com_android_gl2jni_AIfunctions_aiminimax(JNIEnv * env, jobject obj, jstring board_string)
{
    const char *s = env->GetStringUTFChars(board_string,NULL);
    std::string get_it = s;
    get_it = get_best_move(get_it);
    const char *buf = get_it.c_str();

    jstring big = env->NewStringUTF(buf);
    env->ReleaseStringUTFChars(board_string,s);
    return(big);
    env->ReleaseStringUTFChars(board_string,s);

}

JNIEXPORT jstring JNICALL Java_com_android_gl2jni_AIfunctions_astar(JNIEnv * env, jobject obj, jstring board_string)
{
    const char *s = env->GetStringUTFChars(board_string,NULL);
    std::string get_it = s;
    get_it = astar(get_it);
    const char *buf = get_it.c_str();

    jstring big = env->NewStringUTF(buf);
    env->ReleaseStringUTFChars(board_string,s);
    return(big);
    env->ReleaseStringUTFChars(board_string,s);

}
