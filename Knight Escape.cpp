#include <iostream>		
#include <cctype>		   
using namespace std;

const string WhiteKnight = "\u2658";		
const string BlackKnight = "\u265E";		
const string BlankPosition = " ";			
//global varibale declared
string p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25;

char menuOption;
int moveNumber = 1;
int x = 0;
int originalPosition;
int nextPosition;
int score = 500;

//Checks if the Move is in an L shape or not 
void validMov (int begPos, int endPos, bool &moveVal){
  moveVal = false;

  int i,j,k,l,m,n,o,p;

  i = begPos - 9;//top right
  j = begPos - 11;//top left
  k = begPos - 3;//right up
  l = begPos + 7;//right down
  m = begPos + 11;// down right
  n = begPos + 9;// down left
  o = begPos - 7;// left up
  p = begPos + 3;// left down


  if (begPos == 1 ||begPos == 2 ||begPos == 3 ||begPos == 4 ||begPos ==5 ||begPos == 6||begPos == 7 ||begPos == 8 ||begPos == 9 ||begPos == 10 ||begPos == 15 ||begPos == 20 ||begPos == 25){// 1 2 3 4 5 6 7 8 9 10 15 20 25
    i = false;
  }
  if (begPos == 1 ||begPos == 2 ||begPos == 3 ||begPos == 4 ||begPos ==5 ||begPos == 6||begPos == 7 ||begPos == 8 ||begPos == 9 ||begPos == 10 ||begPos == 11||begPos == 16 ||begPos == 21 ){//1 2 3 4 5 6 7 8 9 10 11 16 21
    j = false;
  }
  if (begPos == 1 ||begPos == 2 ||begPos == 3 ||begPos == 4 ||begPos ==5 ||begPos == 9||begPos == 10 ||begPos == 14 ||begPos == 15 ||begPos == 19 ||begPos == 20 ||begPos == 24||begPos == 25){// 1 2 3 4 5 9 10 14 15 19 20 24 25
    k = false;
  }
  if (begPos == 4 ||begPos == 5 ||begPos == 9 ||begPos == 10 ||begPos ==14 ||begPos == 15 ||begPos == 19 ||begPos == 20 ||begPos == 21 ||begPos == 22 ||begPos == 23||begPos == 24||begPos == 25){//4 5 9 10 14 15 19 20 21 22 23 24 25
    l = false;
  }
  if (begPos == 5 ||begPos ==10||begPos ==15 ||begPos == 16||begPos == 17 ||begPos == 18||begPos == 19 ||begPos == 20 ||begPos == 21 ||begPos == 22 ||begPos == 23||begPos == 24||begPos == 25){//5 10 15 16 18 17 19 20 21 22 23 24 25
    m = false;
  }
  if (begPos==1||begPos == 6||begPos==11  ||begPos == 16||begPos == 17 ||begPos==18||begPos == 19 ||begPos == 20 ||begPos == 21 ||begPos == 22 ||begPos == 23||begPos == 24||begPos == 25){//1 6 11 16 17 18 19 20 21 22 23 24 25
    n = false;
  }
  if (begPos == 1 ||begPos == 2 ||begPos == 3 ||begPos == 4 ||begPos ==5 ||begPos == 6||begPos == 7 ||begPos == 11 ||begPos == 12 ||begPos == 16 ||begPos == 17 ||begPos == 21||begPos == 22){// 1 2 3 4 5 6 7 11 12 16 17 21 22
    o = false;
  }
  if (begPos == 1 ||begPos == 2 ||begPos == 6 ||begPos == 7 ||begPos ==11 ||begPos == 12||begPos == 16 ||begPos == 17 ||begPos == 21 ||begPos == 22 ||begPos == 23 ||begPos == 24||begPos == 25){// 1 2 6 7 11 12 16 17 21 22 23 24 25
    p = false;
  }

  
  if (endPos == i || endPos == p || endPos == o || endPos == n || endPos == m || endPos == l || endPos == k || endPos == j){
    moveVal = true; //returns true if the move is valid
  }
}
 

//Check if the position has a blank position where the user is about to move his horse 
bool validPosBlack (int h){
    bool statement;
    switch (h){
    case 1: { p1 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 2: { p2 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 3: { p3 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 4: { p4 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 5: { p5 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 6: { p6 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 7: { p7 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 8: { p8 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 9: { p9 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 10: { p10 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 11: { p11 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 12: { p12 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 13: { p13 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 14: { p14 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 15: { p15 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 16: { p16 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 17: { p17 == BlankPosition ? statement =1 : statement = 0; return statement; break;}
    case 18: { p18 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 19: { p19 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 20: { p20 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 21: { p21 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 22: { p22 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 23: { p23 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 24: { p24 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
    case 25: { p25 == BlankPosition ? statement = 1 : statement = 0; return statement; break;}
  }
}

//Check if theres a black knight or a white knight in a specific position return with a 1 or 0 which corelate to a True or False
bool validPos (int c){
  bool b;
  switch (c){
      case 1: { p1 == BlackKnight || p1 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 2: { p2 == BlackKnight || p2 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 3: {p3 == BlackKnight || p3 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 4: {p4 == BlackKnight || p4 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 5: {p5 == BlackKnight || p5 == WhiteKnight? b = 1 : b = 0; return b; break;} 
      case 6: {p6 == BlackKnight||  p6 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 7: {p7 == BlackKnight || p7 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 8: {p8 == BlackKnight||  p8 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 9: {p9 == BlackKnight || p9 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 10:{p10 == BlackKnight||  p10 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 11:{p11 == BlackKnight || p11 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 12:{ p12 == BlackKnight||  p12 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 13:{p13 == BlackKnight || p13 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 14:{p14 == BlackKnight||  p14 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 15:{p15 == BlackKnight||  p15 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 16:{p16 == BlackKnight || p16 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 17:{p17 == BlackKnight||  p17 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 18:{ p18 == BlackKnight || p18 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 19:{p19 == BlackKnight||  p19 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 20:{p20 == BlackKnight || p20 == WhiteKnight? b = 1 : b = 0; return b; break;} 
      case 21:{ p21 == BlackKnight||  p21 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 22:{p22 == BlackKnight||  p22 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 23:{p23 == BlackKnight || p23 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 24:{ p24 == BlackKnight || p24 == WhiteKnight? b = 1 : b = 0; return b; break;}
      case 25:{ p25 == BlackKnight || p25 == WhiteKnight? b = 1 : b = 0; return b; break;}
  }
}
//returns if the statement is true or false


//Swaps the position of the white knight to a specific position
void swappingWhite (int z){
   switch (z){
      case 1: { p1 = WhiteKnight ;break;}
      case 2: { p2 = WhiteKnight; break;}
      case 3: { p3 = WhiteKnight;  break;}
      case 4: { p4 = WhiteKnight;  break;}
      case 5: { p5 = WhiteKnight;  break;}
      case 6: { p6 = WhiteKnight;  break;}
      case 7: { p7 = WhiteKnight; break;}
      case 8: { p8 = WhiteKnight; break;}
      case 9: { p9 = WhiteKnight; break;}
      case 10: { p10 = WhiteKnight;  break;}
      case 11: { p11 = WhiteKnight; break;}
      case 12: { p12 = WhiteKnight; break;}
      case 13: { p13 = WhiteKnight;  break;}
      case 14: { p14 = WhiteKnight;  break;}
      case 15: { p15 = WhiteKnight;  break;}
      case 16: { p16 = WhiteKnight;  break;}
      case 17: { p17 = WhiteKnight;  break;}
      case 18: { p18 = WhiteKnight;  break;}
      case 19: { p19 = WhiteKnight; break;}
      case 20: { p20 = WhiteKnight; break;}
      case 21: { p21 = WhiteKnight; break;}
      case 22: { p22 = WhiteKnight; break;}
      case 23: { p23 = WhiteKnight; break;}
      case 24: { p24 = WhiteKnight; break;}
      case 25: { p25 = WhiteKnight; break;}
  }
}


//Swaps the position of the black knight to a specific position
void swappingBlack (int r){
    switch (r){
      case 1: { p1 = BlackKnight; break;}
      case 2: { p2 = BlackKnight; break;}
      case 3: { p3 = BlackKnight;  break;}
      case 4: { p4 = BlackKnight;  break;}
      case 5: { p5 = BlackKnight;  break;}
      case 6: { p6 = BlackKnight;  break;}
      case 7: { p7 = BlackKnight; break;}
      case 8: { p8 = BlackKnight; break;}
      case 9: { p9 = BlackKnight; break;}
      case 10: { p10 = BlackKnight;  break;}
      case 11: { p11 = BlackKnight; break;}
      case 12: { p12 = BlackKnight; break;}
      case 13: { p13 = BlackKnight;  break;}
      case 14: { p14 = BlackKnight;  break;}
      case 15: { p15 = BlackKnight;  break;}
      case 16: { p16 = BlackKnight;  break;}
      case 17: { p17 = BlackKnight;  break;}
      case 18: { p18 = BlackKnight;  break;}
      case 19: { p19 = BlackKnight; break;}
      case 20: { p20 = BlackKnight; break;}
      case 21: { p21 = BlackKnight; break;}
      case 22: { p22 = BlackKnight; break;}
      case 23: { p23 = BlackKnight; break;}
      case 24: { p24 = BlackKnight; break;}
      case 25: { p25 = BlackKnight; break;}
  }
}

//Swaps the position of the black knight to a blank postition or white knight to a blank position
void swappingPos (int w){
  switch (w){
    case 1: {p1 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p1 = BlankPosition; break;}
    case 2: {p2 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p2 = BlankPosition; break;}
    case 3: {p3 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p3 = BlankPosition; break;}
    case 4: {p4 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p4 = BlankPosition; break;}
    case 5:{p5 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p5 = BlankPosition; break;}
    case 6: {p6 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p6 = BlankPosition; break;}
    case 7: {p7 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p7 = BlankPosition; break;}
    case 8: {p8 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p8 = BlankPosition; break;}
    case 9: {p9 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p9 = BlankPosition; break;}
    case 10: {p10 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p10 = BlankPosition; break;}
    case 11: {p11 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p11 = BlankPosition; break;}
    case 12: {p12 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p12 = BlankPosition; break;}
    case 13: {p13 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p13 = BlankPosition; break;}
    case 14: {p14 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p14 = BlankPosition; break;}
    case 15: {p15 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p15 = BlankPosition; break;}
    case 16: {p16 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p16 = BlankPosition; break;}
    case 17: {p17 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p17 = BlankPosition; break;}
    case 18: {p18 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p18 = BlankPosition; break;}
    case 19: {p19 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p19 = BlankPosition; break;}
    case 20: {p20 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p20 = BlankPosition; break;}
    case 21: {p21 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p21 = BlankPosition; break;}
    case 22: {p22 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p22 = BlankPosition; break;}
    case 23: {p23 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p23 = BlankPosition; break;}
    case 24: {p24 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p24 = BlankPosition; break;}
    case 25: {p25 == WhiteKnight ? swappingWhite(nextPosition): swappingBlack(nextPosition); p25= BlankPosition; break;}
  }
}

//Displays the  opening message
void displayWelcomeMessage()
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}

//Displays the knights board with the numbers(positions)
void displayBoard()
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} 


// Main() function of the program, containing the loop that controls
// game play
int main() {

  p1 = BlackKnight, p2 = p1,p3 = p1,p4 = p1,p6 = p1,p7 = p1,p8 = p1,p9 = p1,p10 = p1,p11 = p1,p12 = p1,p13 = p1,p14 = p1,p15 = p1,p16 = p1,p17 = p1,p18 = p1,p19 = p1,p20 = p1,p22 = p1,p23 = p1,p24 = p1,p25 = p1;
  p21= WhiteKnight;
  p5 = BlankPosition;

   
  displayWelcomeMessage();
	
	// Set board values to the default starting position
   // ...
	
  displayBoard();
  cout << "Current score: " << score << endl;
   // Loop that controls game play
  while(x != 1) {
    

    cout << endl << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
		cin >> menuOption;
		menuOption = toupper(menuOption); // convert user input to uppercase
		if(menuOption != 'M'&&menuOption !='R'&&menuOption !='X'){
       displayBoard();
       cout<<"Current score:"<<score<<endl;
       continue;
    //If the user inputs an x the program exits out of the while loop 
    }
    if (menuOption == 'X'){
      cout << "Exiting..." << endl;
      break;
    }
		
		// If the user entered 'R' to reset,
    // reset the board back to the beginning
    if (menuOption == 'R'){
      //reassigning the posiitons of the board
      p1 = BlackKnight, p2 = p1,p3 = p1,p4 = p1,p6 = p1,p7 = p1,p8 = p1,p9 = p1,p10 = p1,p11 = p1,p12 = p1,p13 = p1,p14 = p1,p15 = p1,p16 = p1,p17 = p1,p18 = p1,p19 = p1,p20 = p1,p22 = p1,p23 = p1,p24 = p1,p25 = p1;
      p21 = WhiteKnight;
      p5 = BlankPosition;
      cout <<  "   *** Restarting" ;
      score = 500;//resets the score
      moveNumber = 1;
      displayBoard();
      cout << "Current score: " << score << endl;
    }
		
		//if the user inputs M then the user has to inputs of starting position and end position
    if (menuOption == 'M'){
      cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): ";
      cin >> originalPosition >> nextPosition;

      cout << "You have chosen to move a knight from position " << originalPosition << " to position " << nextPosition<<"." << endl;
      
      //checks if the input in the specified range
      if ((originalPosition >= 1 && originalPosition <= 25) && (nextPosition >= 1 && nextPosition <= 25)){


        bool checker;
        //checks if the move is valid
        bool z = validPos(originalPosition);
        if (z) {
          //checks if the next position is valid
          bool y = validPosBlack (nextPosition);
          if (y) {
            //check if the move is in an L shape
            validMov (originalPosition, nextPosition, checker);
            if (checker) {
              //swaps the position
              swappingPos (originalPosition);
              displayBoard();
              //if you reach the end point then a congratulations message is displayed
              if (p5 == WhiteKnight){
               cout <<"Congratulations, you did it!" << endl;
               break;
              }
              //invalid then the score decreases
              moveNumber += 1;
              score-=5;
              cout<<"Current score: "<<score<<endl;
            } else {
              //if the move is not in a L shape then the score decreases
              cout << "Invalid move. Knights can only move in an L-shape. Try again.";
              score-=10;
              cout<<endl <<"Current score: "<<score<<endl;
              if (score <=0){
               x += 1;
               break;
              }
            }
          } else {
            //if the next position is not empty then score also decreases and a message is displayed
            cout << "The destination position should be empty. Try again.";
            score-=10;
            cout<<endl <<"Current score: "<<score<<endl;
            if (score <=0){
              x += 1;
              break;
            }
          }
        } else {
          //starting position should have a knight if not then the score also decreases by 10
          cout << "The source position should have a knight. Try again.";
          score-=10;
          cout<<endl <<"Current score: "<<score<<endl;
          if (score <=0){
           x += 1;
           break;
          }
        }

      } 

      if (originalPosition < 1 || originalPosition > 25) {
        //score decreses if the input is not in the specific range
        cout << "The source position should be a valid position on the board (1-25). Try again.";
        score-=10;
        cout<<endl <<"Current score: "<<score<<endl;
        if (score <=0){
           x += 1;
           break;
          }
      } else if (nextPosition < 1 || nextPosition > 25){
        //score decreses if the input is not in the specific range
        cout << "The destination position should be a valid position on the board (1-25). Try again.";
        score-=10;
        cout<<endl <<"Current score: "<<score<<endl;
        if (score <=0){
          x += 1;
          break;
          }
      }
      
      if (score <=0){
       x += 1;
       break;
    }
    }
  }
  
 // end loop for game play
  //if the score decreses to 0 the game automatically stops and displays a message for the reason
  if (score <= 0){
    cout<<endl<<endl<<"You have run out of moves. Try to do better next time!"<<endl;

    }
  //thank you message displayed
  cout << "Thank you for playing!" << endl;
  //stops the while loop
  x+= 1;
	return 0;
}
