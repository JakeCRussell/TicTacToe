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
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <string>
using std::string;

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
	string score;
	string name;
	stringstream ss;
	vector<string> scores;
	
	ifstream infile("scoreboard.txt");
		//loop until end of file is reached
	while(true){
		getline(infile, score);
		if(infile.eof()){
			break;
		}	 	 
		scores.push_back(score);
	}
	ofstream outfile("scoreboard.txt");
	
	do{
		system("CLS");
		done =  ' ';
		initialise(board); 
		count = 0;	  
		cout<<"     Tic Tac Toe."<<endl<<endl;
		cout<<" Please select the way you'd like to play: " <<endl;
		cout<<" [1]. Human vs A.I."<<endl;
		cout<<" [2]. Human vs Human"<<endl;
		cout<<" [3]. A.I. vs. A.I."<<endl;
		cout<<" [4]. View scoreboard."<<endl;
		cout<<endl<<"Please enter the number of your selection, or enter [Q] to quit:";
		cin>>select;
		switch(select){
		case '1':
			do{
				system("CLS");
				done =  ' ';
				initialise(board); 
				count = 0;	  
				cout<<"  Human vs. A.I. selected"<<endl;
				cout<<endl;
				cout<<"    [1]. Easy difficulty."<<endl;
				cout<<"    [2]. Normal difficulty."<<endl;
				cout<<"    [3]. Hard difficulty."<<endl<<endl;
				cout<<"  Enter the number of your selection, or enter [R] to return to the main menu:";
				cin>>select;
				
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
						cout<<endl<<"    You are playing against the easy A.I. as [X]"<<endl<<endl;	  	  	  	  	  	  
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    You are playing against the easy A.I. as [X]"<<endl<<endl;
					    displayBoard(board);
					    playerMove('X', board);
					    done = checkWin(board, count); /* check winner */
						count++;
						system("CLS");
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
					    easyMove('O', board);
						cout<<endl<<"    You are playing against the easy A.I. as [X]"<<endl<<endl;	  	  	  	  	  	  
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
					    done = checkWin(board, count); /* check for winner again */
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					cout<<endl;
					displayBoard(board); /* show final positions */
					if(done=='X'){
						cout<<endl<<"    Human player won!"<<endl;
						cin.clear();		
						cin.ignore(80, '\n');
						cout<<"    Please enter 3 characters for your score on the scoreboard: "<<endl;
						getline(cin, name);
						ss<<count<<"  "<<name<<"  "<<"Easy A.I."<<endl;
						getline(ss, score);
						scores.push_back(score);
					}
					else if(done=='O'){
						cout<<endl<<"    A.I. player won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					
					
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
						cout<<endl<<"    You are playing against the normal A.I. as [X]"<<endl<<endl;						
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    You are playing against the normal A.I. as [X]"<<endl<<endl;
					    displayBoard(board);
					    playerMove('X', board);
					    done = checkWin(board, count); /* check winner */
						count++;
						system("CLS");
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
					    normalMove('O', board);
						cout<<endl<<"    You are playing against the normal A.I. as [X]"<<endl<<endl;						
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
					    done = checkWin(board, count); /* check for winner again */
						count++;
						system("CLS");
						cout<<endl;
					} while(done== ' ');
					
					system("CLS");
					cout<<endl;
					displayBoard(board); /* show final positions */
					if(done=='X'){
						cout<<endl<<"    Human player won!"<<endl;
						cin.clear();		
						cin.ignore(80, '\n');
						cout<<"    Please enter 3 characters for your score on the scoreboard: "<<endl;
						getline(cin, name);
						ss<<count<<"  "<<name<<"  "<<"Normal A.I."<<endl;
						getline(ss, score);
						scores.push_back(score);
					}
					else if(done=='O'){
						cout<<endl<<"    A.I. player won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					
					
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
						cout<<endl<<"    You are playing against the hard A.I. as [X]"<<endl<<endl;	  	  	  	  	  	  
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    You are playing against the hard A.I. as [X]"<<endl<<endl;
					    displayBoard(board);
					    playerMove('X', board);
					    done = checkWin(board, count); /* check winner */
						count++;
					    system("CLS");
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
					    hardMove('O', board, -1);
						cout<<endl<<"    You are playing against the hard A.I. as [X]"<<endl<<endl;	  	  	  	  	  	  
						displayBoard(board);
						cout<<endl<< "Opponent's move."<<endl;
						system("pause");
					    done = checkWin(board, count); /* check for winner again */
						count++;
						system("CLS");
						cout<<endl;
					} while(done== ' ');
					
					system("CLS");
					cout<<endl;
					displayBoard(board); /* show final positions */
					if(done=='X'){
						cout<<endl<<"    Human player won!"<<endl;
						cin.clear();		
						cin.ignore(80, '\n');
						cout<<"    Please enter 3 characters for your score on the scoreboard: "<<endl;
						getline(cin, name);
						ss<<count<<"  "<<name<<"  "<<"Hard A.I.";
						getline(ss, score);
						scores.push_back(score);
					}
					else if(done=='O'){
						cout<<endl<<"    A.I. player won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					
				
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
				
				default:
					cout<<"Invalid entry, please try again."<<endl;
				}
			}while((select!='r')&&(select!='R'));
			break;

		case '2':
			system("CLS");
			done =  ' ';
			initialise(board); 
			count = 0;	  
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
				if(count == 9){
					break;
				}
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
			
			cout<<endl;
			displayBoard(board); /* show final positions */	
			   	   	   
			if(done=='X'){
				cout<<endl<<"    Player 1 [X] has won!"<<endl;
				cin.clear();		
				cin.ignore(80, '\n');
				cout<<"    Please enter 3 characters for your score on the scoreboard: "<<endl;
				getline(cin, name);
				ss<<count<<"  "<<name<<"  "<<"Human player"<<endl;
				getline(ss, score);
				scores.push_back(score);
			}
			else if(done=='O'){
				cout<<endl<<"    Player 2 [O] has won!"<<endl;
			}
			else{
				cout<<endl<<"    The game ends in a draw!"<<endl;
			}
			cout<<endl<<"Enter any character to return to the menu:"<<endl;
			system("pause");   	   	   
			break;
			
		case '3':
			do{
				system("CLS");
				done =  ' ';
				initialise(board); 
				count = 0;	  
				cout<<"  A.I. vs. A.I. selected"<<endl<<endl;
				cout<<"    [1]. Easy vs. Easy."<<endl;
				cout<<"    [2]. Easy vs. Normal."<<endl;
				cout<<"    [3]. Easy vs. Hard."<<endl;
				cout<<"    [4]. Normal vs. Normal."<<endl;
				cout<<"    [5]. Normal vs. Hard."<<endl;
				cout<<"    [6]. Hard vs. Hard."<<endl<<endl;
				cout<<"  Enter the number of your selection, or enter [R] to return to the main menu:";
				cin>>select;
								
				switch(select){
				case '1':
					system("CLS");	
					cout<<"  Easy A.I. vs. Easy A.I. selected"<<endl;
					cout<<"  Player [X] will have the first turn.";
					do {
						cout<<"    Easy A.I. vs. Easy A.I."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    easyMove('X', board);
					    done = checkWin(board, count); /* check winner */
						displayBoard(board);
						system("pause"); // pause to show last move of both player
						system("CLS");
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Easy A.I. vs. Easy A.I."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
					    easyMove('O', board);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Easy A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Easy A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
					
				case '2':
					cout<<"  Easy A.I.[X] vs. Normal A.I.[O] selected"<<endl;
					cout<<"  Will the Easy A.I.[X] go first? [Y/N]:";
					cin>>select;
					while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
						cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
						cin>>select;
					}
					system("CLS");
					if((select == 'n')||(select == 'N')){
						cout<<"    Easy A.I.[X] vs. Normal A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
						normalMove('O', board);
						displayBoard(board);
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    Easy A.I.[X] vs. Normal A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    easyMove('X', board);
					    done = checkWin(board, count); /* check winner */
						displayBoard(board);
						system("pause"); // pause to show last move of player
						system("CLS");
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Easy A.I.[X] vs. Normal A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
					    normalMove('O', board);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Easy A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Normal A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
						 	 	 	 
				case '3':
					cout<<"  Easy A.I.[X] vs. Hard A.I.[O] selected"<<endl;
					cout<<"  Will the Easy A.I.[X] go first? [Y/N]:";
					cin>>select;
					while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
						cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
						cin>>select;
					}
					system("CLS");
					if((select == 'n')||(select == 'N')){
						cout<<"    Easy A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
						hardMove('O', board, -1);
						displayBoard(board);
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    Easy A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    easyMove('X', board);
					    done = checkWin(board, count); /* check winner */
						displayBoard(board);
						system("pause");
						system("CLS");
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Easy A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
					    hardMove('O', board, -1);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause"); // pause to show last moves of both players
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Easy A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Hard A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
					
				case '4':
					system("CLS");
					cout<<"  Normal A.I.[X] vs. Normal A.I.[O] selected"<<endl;
					cout<<"  Player [X] gets the first turn."<<endl;
					do {
						cout<<"    Normal A.I.[X] vs. Normal A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    normalMove('X', board);
					    done = checkWin(board, count); /* check winner */
						displayBoard(board);
						system("pause");
						system("CLS");
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Normal A.I.[X] vs. Normal A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    normalMove('O', board);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause"); // pause to show last moves of both players
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Normal A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Normal A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
					
				case '5':
					cout<<"  Normal A.I.[X] vs. Hard A.I.[O] selected"<<endl;
					cout<<"  Will the Normal A.I.[X] go first? [Y/N]:";
					cin>>select;
					while((select!='y')&&(select!='Y')&&(select!='n')&&(select!='N')){
						cout<<"Invalid entry, enter [Y] for yes or [N] for no: "<<endl;
						cin>>select;
					}
					system("CLS");
					if((select == 'n')||(select == 'N')){
						cout<<"    Normal A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
						hardMove('O', board, -1);
						displayBoard(board);
						system("pause");
						system("CLS");
						cout<<endl;
						count++;
					}
					system("CLS");
					do {
						cout<<"    Normal A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    normalMove('X', board);
					    done = checkWin(board, count); /* check winner */
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Normal A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
					    hardMove('O', board, -1);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause"); // pause to show last moves of both players
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Normal A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Hard A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
					
				case '6':
					system("CLS");
					cout<<"  Hard A.I.[X] vs. Hard A.I.[O] selected"<<endl;
					cout<<"  Player [X] gets the first turn."<<endl;
					do {
						cout<<"    Hard A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [X]'s move: "<<endl;
					    hardMove('X', board, -1);
					    done = checkWin(board, count); /* check winner */
						displayBoard(board);
						system("pause");
						system("CLS");
						count++;
						if(count == 9){
							break;
						}
					    if(done!= ' '){
							break; /* if winner found...*/
						}
						cout<<"    Hard A.I.[X] vs. Hard A.I.[O]."<<endl<<endl;
						cout<<"  [O]'s move: "<<endl;
					    hardMove('O', board, -1);
					    done = checkWin(board, count); /* check for winner again */
						displayBoard(board);
						system("pause"); // pause to show last moves of both players
						system("CLS");
						cout<<endl;
						count++;
					} while(done== ' ');
					
					system("CLS");
					
					if(done=='X'){
						cout<<endl<<"    Hard A.I. player [X] won!"<<endl;
					}
					else if(done=='O'){
						cout<<endl<<"    Hard A.I. player [O] won!"<<endl;
					}
					else{
						cout<<endl<<"    The game ends in a draw!"<<endl;
					}
					cout<<endl;
					displayBoard(board); /* show final positions */
					
					cout<<endl<<"Enter any character to return to the menu:"<<endl;
					system("pause");   	   	 
					break;
					
				case 'b':
				case 'B':
					break;
				default:
					cout<<"    Invalid entry, please try again."<<endl;
				}
			}while((select!='r')&&(select!='R'));
			break;
		
		case '4':
			system("CLS");
			cout<<"    Scoreboards."<<endl;
			sort(scores.begin(), scores.end());
			for(int r = 0; r < scores.size(); r++){
				cout<<"  "<<r+1<<". "<<scores[r]<<endl;
				outfile << scores[r] << endl;
			}
			cout<<endl;
			system("pause");
			break;
			
		case 'r': //cases to prevent error message being shown when quit or return command entered
		case 'R':	 
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

	{	 
	    while (found == false)
		{
			i = rand() % 9;
	        if(board[i] == ' ')
	        {
	            board[i] = player;
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
	else{	 
	    while (found == false)
		{
			i = rand() % 9;
	        if(board[i] == ' ')
	        {
	            board[i] = player;
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
	move = minimax('O', board, p);
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
	char state;
	
	if(p > -1){
	    // Base case
		state = checkWin(board, p);
		if (state == 'O'){
			return 1;
		}
		else if(state == 'X'){
			return -1;
		}
		else if(state == 'D'){
			return 0;
		}
	}
 
    // Main Part
    if(player=='O') {
        int mx=-100;    // Max. possible score of current player
 
        // Check all possible moves for current player
        for(i=0;i<9;i++) {
            if(board[i]==' ') {
                // Fill this part of the board
                board[i]='O';
                int score;
                score=minimax('X', board , i);
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
        int mn=+100;   // Min. possible score of opposing player
        for(i=0;i<9;i++) { 
			if(board[i]==' ') { 
				board[i]='X'; 
				int score; 
				score=minimax('O', board, i); 
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
		// Check if the game is drawn
	if(p == 9){
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

