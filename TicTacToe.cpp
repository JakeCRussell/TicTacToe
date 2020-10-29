// TicTacToe.cpp
// Computing Project
// TicTacToe game with human vs A.I
// with 3 different A.I. difficulty levels
// and human vs human functionality
// Candidate number: 146797
// 2015 - 2016

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char checkWin(char* board, int p); // declaration of functions
void initialise(char* board);
void playerMove(char ch, char* board);
void easyMove(char player, char* board);
void normalMove(char player, char* board);
void hardMove(char player, char* board, int p);
void displayBoard(char* board);
int aiWinCheck(char* board);
int aiLossCheck(char* board);
int minimax(char player, char* board, int p);

int main(void)
{
	char board[9];  //intitial board array declaration
	char done, select;
	bool easy = true;
	int count;

	do{
		system("CLS");
		done =  ' ';
		initialise(board); 
		count = 0;	  
		cout<<"     Tic Tac Toe."<<endl<<endl;
		cout<<" Please select the way you'd like to play: " <<endl;
		cout<<" [1]. Human vs easy A.I."<<endl;
		cout<<" [2]. Human vs normal A.I."<<endl;
		cout<<" [3]. Human vs hard A.I."<<endl;
		cout<<" [4]. Human vs Human."<<endl;
		cout<<endl<<"Please enter the number of your selection, or enter [Q] to quit:";
		cin>>select;
		system("CLS");
		switch(select){
		
		case '1': 
			cout<<"  Human vs. easy difficulty A.I. selected"<<endl;
			cout<<"  You will be playing as [X], would you like to go first? [Y/N]:";
			cin>>select;
			while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
				cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
				cin>>select;
			}
			if((select == 'n')||(select == 'N')){
				easyMove('O', board);
			    done = checkWin(board, count); /* check for winner again */
				system("CLS");
				cout<<endl;
				count++;
			}
			do {
				cout<<"    You are playing against the easy A.I. as [X]"<<endl<<endl;
			    displayBoard(board);
			    playerMove('X', board);
			    done = checkWin(board, count); /* check winner */
				count++;
				if(count == 9){
					break;
				}
			    if(done!= ' '){
					break; /* if winner found...*/
				}
			    easyMove('O', board);
			    done = checkWin(board, count); /* check for winner again */
				system("CLS");
				cout<<endl;
				count++;
			} while(done== ' ');
			
			system("CLS");
			
			if(done=='X'){
				cout<<endl<<"    Human player won!"<<endl;
			}
			else if(done=='O'){
				cout<<endl<<"    A.I. player won!"<<endl;
			}
			else if(done=='D'){
				cout<<endl<<"    The game ends in a draw!"<<endl;
			}
			else{
				cout<<endl<<"    There was an error deciding the winner."<<endl;
			}
			cout<<endl;
			displayBoard(board); /* show final positions */
			
			cout<<endl<<"Enter any character to return to the menu:"<<endl;
			system("pause");   	   	 
			break;
		
		case '2':
			cout<<"  Human vs. normal difficulty A.I. selected"<<endl;
			cout<<"  You will be playing as [X], would you like to go first? [Y/N]:";
			cin>>select;
			while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
				cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
				cin>>select;
			}
			if((select == 'n')||(select == 'N')){
				normalMove('O', board);
			    done = checkWin(board, count); /* check for winner again */
				system("CLS");
				cout<<endl;
				count++;
			}
			do {
				cout<<"    You are playing against the normal A.I. as [X]"<<endl<<endl;
			    displayBoard(board);
			    playerMove('X', board);
			    done = checkWin(board, count); /* check winner */
				count++;
			    if(done!= ' '){
					break; /* if winner found...*/
				}
			    normalMove('O', board);
			    done = checkWin(board, count); /* check for winner again */
				count++;
				system("CLS");
				cout<<endl;
			} while(done== ' ');
			
			system("CLS");
			
			if(done=='X'){
				cout<<endl<<"    Human player won!"<<endl;
			}
			else if(done=='O'){
				cout<<endl<<"    A.I. player won!"<<endl;
			}
			else if(done=='D'){
				cout<<endl<<"    The game ends in a draw!"<<endl;
			}
			else{
				cout<<endl<<"    There was an error deciding the winner."<<endl;
			}
			cout<<endl;
			displayBoard(board); /* show final positions */
			
			cout<<endl<<"Enter any character to return to the menu:"<<endl;
			system("pause");   	   	 
			break;
			
		case '3':
			cout<<"  Human vs. hard difficulty A.I. selected"<<endl;
			cout<<"  You will be playing as [X], would you like to go first? [Y/N]:";
			cin>>select;
			while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
				cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
				cin>>select;
			}
			if((select == 'n')||(select == 'N')){
				hardMove('O', board, -1);
			    done = checkWin(board, count); /* check for winner again */
				system("CLS");
				cout<<endl;
				count++;
			}
			do {
				cout<<"    You are playing against the hard A.I. as [X]"<<endl<<endl;
			    displayBoard(board);
			    playerMove('X', board);
			    done = checkWin(board, count); /* check winner */
				count++;
			    if(done!= ' '){
					break; /* if winner found...*/
				}
			    hardMove('O', board, -1);
			    done = checkWin(board, count); /* check for winner again */
				count++;
				system("CLS");
				cout<<endl;
			} while(done== ' ');
			
			system("CLS");
			
			if(done=='X'){
				cout<<endl<<"    Human player won!"<<endl;
			}
			else if(done=='O'){
				cout<<endl<<"    A.I. player won!"<<endl;
			}
			else if(done=='D'){
				cout<<endl<<"    The game ends in a draw!"<<endl;
			}
			else{
				cout<<endl<<"    There was an error deciding the winner."<<endl;
			}
			cout<<endl;
			displayBoard(board); /* show final positions */
			
			cout<<endl<<"Enter any character to return to the menu:"<<endl;
			system("pause");   	   	 
			break;
			
		case '4':
			cout<<"  Human vs. Human selected"<<endl;
			cout<<"    Player 1 is [X] and has the first turn, Player 2 is [O]."<<endl;
			do {
				cout<<"    Player 1's turn [X]."<<endl<<endl;
			    displayBoard(board);
			    playerMove('X', board);
			    done = checkWin(board, count); /* check winner */
				system("CLS");
				cout<<endl;
				count++;
			    if(done!= ' '){
					break; /* if winner found...*/
				}
				cout<<"    Player 2's turn [O]. "<<endl<<endl;
				displayBoard(board);
			    playerMove('O', board);
			    done = checkWin(board, count); /* check for winner again */
				system("CLS");
				cout<<endl;
				count++;
			} while(done== ' ');
			
			if(done=='X'){
				cout<<endl<<"    Player 1 [X] has won!"<<endl;
			}
			else if(done=='O'){
				cout<<endl<<"    Player 2 [O] has won!"<<endl;
			}
			else if(done=='D'){
				cout<<endl<<"    The game ends in a draw!"<<endl;
			}
			else{
				cout<<endl<<"    There was an error deciding the winner."<<endl;
			}
			cout<<endl;
			displayBoard(board); /* show final positions */
			
			cout<<endl<<"Enter any character to return to the menu:"<<endl;
			system("pause");   	   	   
			break;
			
		case 'q':
		case 'Q':
			break;
			
		default:
			cout<<"    Invalid entry, please try again."<<endl;
		}
	
	}while((select!='q')&&(select!='Q'));
	
	
	return 0;
}

/*Functions and function prototypes below
==============================================================================*/

void initialise(char* board) // board intitialisation, ensure all values are ' '
{
	int i;

	for(i=0; i<9; i++){ 
		board[i] =  ' ';
	}
}


void playerMove(char ch, char* board) // function for human player input
{
	int x, y, move;

	cout<<"  Enter X,Y coordinates for your move: " << endl;
	cout<<"    X: ";
	cin >> x;
	cout<<"    Y: ";
	cin >> y;
	cout<<endl;

	move = ((x-1)*3)+(y-1);

	if(board[move]!= ' '){
    	cout<<"    Invalid move, try again."<<endl;
    	playerMove(ch, board);
  	}
 	else {
		board[move] = ch;
	}
}

void easyMove(char player, char* board) // easy difficulty A.I. move input
{
	int i;
	bool found = false;
	int move;
	move = aiWinCheck(board);
	if(move!= -1)
	{
		board[move] = player;
		return;
	}
	else{	 
	    while (found == false)
		{
			i = rand() % 9;
	        if(board[i] == ' ')
	        {
	            board[i] = '0';
	            found = true;
	        }
		}
	}
}

void normalMove(char player, char* board) // normal difficulty A.I. function
{
	int i;
	bool found = false;
	int move;
	move = aiWinCheck(board);
	if(move!= -1)
	{
		board[move] = player;
		return;
	}
	move = aiLossCheck(board);
	if(move!= -1)
	{
		board[move] = player;
		return;
	}
	else{	 
	    while (found == false)
		{
			i = rand() % 9;
	        if(board[i] == ' ')
	        {
	            board[i] = '0';
	            found = true;
	        }
		}
	}	   	   
}

void hardMove(char player, char* board, int p) // hard difficulty A.I. function
{
	int move;
	move = aiWinCheck(board);
	if(move!= -1)
	{
		board[move] = player;
		return;
	}
	move = aiLossCheck(board);
	if(move!= -1)
	{
		board[move] = player;
		return;
	}
	move = minimax(player, board, p);
	board[move] = player;
	return;
}

int aiWinCheck(char* board)
{
	//check for possible win in top row
	if((board[0]==' ')&&(board[1]=='O')&&(board[2]=='O')){
		return 0;
	}
	else if((board[0]=='O')&&(board[1]==' ')&&(board[2]=='O')){
		return 1;
	}
	else if((board[0]=='O')&&(board[1]=='O')&&(board[2]==' ')){
		return 2;
	}
	//check for possible win in middle row
	else if((board[3]==' ')&&(board[4]=='O')&&(board[5]=='O')){
		return 3;
	}
	else if((board[3]=='O')&&(board[4]==' ')&&(board[5]=='O')){
		return 4;
	}
	else if((board[3]=='O')&&(board[4]=='O')&&(board[5]==' ')){
		return 5;
	}
	//check for possible win in bottom row
	else if((board[6]==' ')&&(board[7]=='O')&&(board[8]=='O')){
		return 6;
	}
	else if((board[6]=='O')&&(board[7]==' ')&&(board[8]=='O')){
		return 7;
	}
	else if((board[6]=='O')&&(board[7]=='O')&&(board[8]==' ')){
		return 8;
	}
	//check for possible win in left column
	else if((board[0]==' ')&&(board[3]=='O')&&(board[6]=='O')){
		return 0;
	}
	else if((board[0]=='O')&&(board[3]==' ')&&(board[6]=='O')){
		return 3;
	}
	else if((board[0]=='O')&&(board[3]=='O')&&(board[6]==' ')){
		return 6;
	}
	//check for possible win in middle column
	else if((board[1]==' ')&&(board[4]=='O')&&(board[7]=='O')){
		return 1;
	}
	else if((board[1]=='O')&&(board[4]==' ')&&(board[7]=='O')){
		return 4;
	}
	else if((board[1]=='O')&&(board[4]=='O')&&(board[7]==' ')){
		return 7;
	}
	//check for possible win in right column
	else if((board[2]==' ')&&(board[5]=='O')&&(board[8]=='O')){
		return 2;
	}
	else if((board[2]=='O')&&(board[5]==' ')&&(board[8]=='O')){
		return 5;
	}
	else if((board[2]=='O')&&(board[5]=='O')&&(board[8]==' ')){
		return 8;
	}
	//check for possible win in \ diagonal
	else if((board[0]==' ')&&(board[4]=='O')&&(board[8]=='O')){
		return 0;
	}
	else if((board[0]=='O')&&(board[4]==' ')&&(board[8]=='O')){
		return 4;
	}
	else if((board[0]=='O')&&(board[4]=='O')&&(board[8]==' ')){
		return 8;
	}
	//check for possible win in / diagonal
	else if((board[2]==' ')&&(board[4]=='O')&&(board[6]=='O')){
		return 2;
	}
	else if((board[2]=='O')&&(board[4]==' ')&&(board[6]=='O')){
		return 4;
	}
	else if((board[2]=='O')&&(board[4]=='O')&&(board[6]==' ')){
		return 6;
	}
	else{
		return -1;
	}
}

int aiLossCheck(char* board)
{
	//check for imminent loss in top row
	if((board[0]==' ')&&(board[1]=='X')&&(board[2]=='X')){
		return 0;
	}
	else if((board[0]=='X')&&(board[1]==' ')&&(board[2]=='X')){
		return 1;
	}
	else if((board[0]=='X')&&(board[1]=='X')&&(board[2]==' ')){
		return 2;
	}
	//check for imminent loss in middle row
	else if((board[3]==' ')&&(board[4]=='X')&&(board[5]=='X')){
		return 3;
	}
	else if((board[3]=='X')&&(board[4]==' ')&&(board[5]=='X')){
		return 4;
	}
	else if((board[3]=='X')&&(board[4]=='X')&&(board[5]==' ')){
		return 5;
	}
	//check for imminent loss in bottom row
	else if((board[6]==' ')&&(board[7]=='X')&&(board[8]=='X')){
		return 6;
	}
	else if((board[6]=='X')&&(board[7]==' ')&&(board[8]=='X')){
		return 7;
	}
	else if((board[6]=='X')&&(board[7]=='X')&&(board[8]==' ')){
		return 8;
	}
	//check for imminent loss in left column
	else if((board[0]==' ')&&(board[3]=='X')&&(board[6]=='X')){
		return 0;
	}
	else if((board[0]=='X')&&(board[3]==' ')&&(board[6]=='X')){
		return 3;
	}
	else if((board[0]=='X')&&(board[3]=='X')&&(board[6]==' ')){
		return 6;
	}
	//check for imminent loss in middle column
	else if((board[1]==' ')&&(board[4]=='X')&&(board[7]=='X')){
		return 1;
	}
	else if((board[1]=='X')&&(board[4]==' ')&&(board[7]=='X')){
		return 4;
	}
	else if((board[1]=='X')&&(board[4]=='X')&&(board[7]==' ')){
		return 7;
	}
	//check for imminent loss in right column
	else if((board[2]==' ')&&(board[5]=='X')&&(board[8]=='X')){
		return 2;
	}
	else if((board[2]=='X')&&(board[5]==' ')&&(board[8]=='X')){
		return 5;
	}
	else if((board[2]=='X')&&(board[5]=='X')&&(board[8]==' ')){
		return 8;
	}
	//check for imminent loss in \ diagonal
	else if((board[0]==' ')&&(board[4]=='X')&&(board[8]=='X')){
		return 0;
	}
	else if((board[0]=='X')&&(board[4]==' ')&&(board[8]=='X')){
		return 4;
	}
	else if((board[0]=='X')&&(board[4]=='X')&&(board[8]==' ')){
		return 8;
	}
	//check for imminent loss in / diagonal
	else if((board[2]==' ')&&(board[4]=='X')&&(board[6]=='X')){
		return 2;
	}
	else if((board[2]=='X')&&(board[4]==' ')&&(board[6]=='X')){
		return 4;
	}
	else if((board[2]=='X')&&(board[4]=='X')&&(board[6]==' ')){
		return 6;
	}
	else{
		return -1;
	}
}

int minimax(char player, char* board, int p) // minimax algorithm for hard difficulty A.I. function
{
    int i, index;
 
    // Base case
	char state = checkWin(board, p);
	if (state == 'O'){
		return 1;
	}
	else if(state == 'X'){
		return -1;
	}
	else if(state == 'D'){
		return 0;
	}
 
    // Main Part
    if(player=='X') {
        int mx=-100;    // Max. possible score of 'X'
 
        // Check all possible moves for player X
        for(i=0;i<9;i++) {
            if(board[i]==' ') {
                // Fill this part of the board
                board[i]='X';
                int score;
                score=minimax('O', board , i);
                if(mx < score) {
                    mx=score;
                    index=i;
                }
                // Empty the box when done
                board[i]=' ';
            }
        }
        return index;
    }
    else {
        int mn=+100;   // Min. possible score of 'O'
        for(i=0;i<9;i++) { 
			if(board[i]==' ') { 
				board[i]='O'; 
				int score; 
				score=minimax('X', board, i); 
				if(mn > score) {
                    mn=score;
                    index=i;
                }
                board[i]=' ';
            }
        }
        return index;
    }
}
void displayBoard(char* board) // board display
{
	int i;
	cout<<"        | 1 | 2 | 3 |"<<endl;
	cout<<"     ---|---|---|---|"<<endl; 
    cout<<"      1 | " << board[0] << " | " << board[1] << " | " << board[2] << " |";
	cout<<endl<<"     ---|---|---|---|"<<endl;
	cout<<"      2 | " << board[3] << " | " << board[4] << " | " << board[5] << " |";
   	cout<<endl<<"     ---|---|---|---|"<<endl;
	cout<<"      3 | " << board[6] << " | " << board[7] << " | " << board[8] << " |";
   	cout<<endl<<"     ---|---|---|---|"<<endl;
	cout<< endl;
}


char checkWin(char* board, int p) //used for identifying winner or tie game
{
	if(p < 0){
		return ' ';
	}
		// Check if the game is drawn
	else if(p == 9){
		return 'D';
	}
	// check rows
	if(board[0]==board[1] && board[0]==board[2]) {
		return board[0];
	}
	if(board[3]==board[4] && board[3]==board[5]) {
		return board[3];
	}
	if(board[6]==board[7] && board[6]==board[8]) {
		return board[6];
	}
	// check columns 
    if(board[0]==board[3] && board[0]==board[6]) {
		return board[0];
	}
	if(board[1]==board[4] && board[1]==board[7]) {
		return board[1];
	}
	if(board[2]==board[5] && board[2]==board[8]) {
		return board[2];
	}
  /* test diagonals */
	if(board[0]==board[4] && board[0]==board[8]) {
			return board[0];
		}

	if(board[2]==board[4] && board[2]==board[6]) {
			return board[2];
		}
	return ' ';
}

