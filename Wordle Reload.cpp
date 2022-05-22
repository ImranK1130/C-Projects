/* main.cpp
    Wordle Reload is a game that allows you to guess either a 3 letter word or 5 letter word.
    You have a set amount of time to guess a word.  At the conlusion of game play
    you will be provided stats on your overall game play.

    Author: Zuhaira Tayab, Imran Khan 
    Date: 2/27/2022
    Class: CS 141, Spring 2022, UIC
    System: Visual Studio Communzity Windows 
*/

#include <iostream>  
#include <cctype> 
#include <vector>      
#include <ctime>  
#include <fstream> 
#include <algorithm>
#include <cassert> 
using namespace std;



void fiveLetterWordInstructions()// the function displays the instructions of the code
{
  cout<< "To get started, enter your first 5 letter word."<<endl;
  cout<< "You have 6 attempts to guess the random word."<<endl;
  cout<< "The timer will start after your first word entry."<<endl;
  cout<<"Try to guess the word within 40 seconds."<<endl;
}



void threeLetterWordInstructions()// this function displays the instruction of the game 
{
  cout<<"To get started, enter your first 3 letter word."<<endl;
  cout<<"You have 4 attempts to guess the random word."<<endl;
  cout<<"The timer will start after your first word entry."<<endl;
  cout<<"Try to guess the word within 20 seconds."<<endl;
}



void randomWord(int randMax, int &ranNumber) //the function chooses a random word 
{
  ranNumber = rand() % randMax;
}



int binarySearch(string searchWord, vector< string> dictionary)//the function does the binary search of the string 
{
  
  int mid;
  int low;
  int high;

  high = dictionary.size();
  low = 0;

  while (high >= low) 
  {
    
    mid =(high+low)/2;

    int searchResult = searchWord.compare(dictionary.at(mid));

      if (searchResult == 0) 
      {
        return mid;
      }
      else if (searchResult < 0)
      {
        high = mid - 1;
      }
      else 
      {
        low = mid + 1;
      }
   }
   return -1; 
  
}



void VectorForDictionary(vector <string> &fiveWorddictionary,vector <string> &threeWorddictionary)//makes a vector which contains 3 and 5 letter word
{
  ifstream inStream;
  inStream.open("wordlewords.txt");
  assert( inStream.fail() == false ); 
  string word;

  
  while (inStream >> word)
  {
    if (word.size() == 3)
    {
      threeWorddictionary.push_back(word);
    } 
    else 
    {
      fiveWorddictionary.push_back(word);
      
    }
  }
  
  inStream.close();
}




void displaymenuOption1Board (string stringGuess,int &amountOFRows, char menu1Board[4][3])// displays the board for menu option 1
{

  for (int row = 0; row < amountOFRows; row++)
  {
    for (int col = 0; col < stringGuess.size(); col++)
    {
      cout << "[" << menu1Board[row][col] << "]" << " ";
    }
    cout << endl;
  }
  
  amountOFRows++;
  cout << endl;
  
}



void displaymenuOption2Board (string stringGuess,int &amountOFRows, char menu2Board[6][5])//displays the board for menu option 2
{

  for (int row = 0; row < amountOFRows; row++)
  {
    for (int col = 0; col < stringGuess.size(); col++) 
    {
      cout << "[" << menu2Board[row][col] << "]" << " ";
    }
    cout << endl;
  }
  amountOFRows ++;
  cout << endl;
  
}



void compareMenuOption1 ( char menu1Board[4][3],string wordFromUser, int &amountOFRows,string guess) // compares the board for menu option 1
{
  
  for (int i = 0; i < wordFromUser.size(); i++)//for loop 1
    {
    for (int j = 0; j < guess.size(); j++)//for loop 2
    {
      if ( (i != j) &&  (wordFromUser.at(i) == guess.at(j))  && menu1Board[amountOFRows][i] != toupper(guess.at(j)) ) 
      {
        menu1Board[amountOFRows][i] = wordFromUser.at(i); //to check if it matches
      } 
      else if ((i == j) && (wordFromUser.at(i) == guess.at(j))) 
      {
        menu1Board[amountOFRows][i] = toupper(guess.at(i));//to check if it matches
        
      } 
    }
  }
  
  amountOFRows ++;
  
}


void compareMenuOption2 (char menu2Board[6][5],string wordFromUser, int &amountOFRows,string guess) //compares the board for menu option 2
{
  
  for (int i = 0; i < wordFromUser.size(); i++) //for loop
  {
    for (int j = 0; j < guess.size(); j++)//for loop
    {
      if ( (wordFromUser.at(i) == guess.at(j)) && (i == j) ) //if loop to check the string 
      {
        menu2Board[amountOFRows][i] = toupper(guess.at(j));//string comparison
      } 
      else if ( (wordFromUser.at(i) == guess.at(j)) && (i != j) && menu2Board[amountOFRows][i] != toupper(guess.at(j))) 
      {
        menu2Board[amountOFRows][i] = wordFromUser.at(i);//string comparison
      } 
    }
  }
  amountOFRows ++;//rows increase
  
}


//runs the game of menu option 1
void menuOption1(int &streak,string ranString, char arrayBoard[4][3],int &wordsGuessed, vector <string> dictionary,   vector<int> &dictionaryForStreak,vector<int> &dictionaryForTime)
{
  
  string guessOfUser;
  int numGuesses = 1;
  int elapsedTime = 0;
  int numOfAttempts = 4;
  int checkString;
  int countNoOfRows = 0;
  time_t startTime;
  
  threeLetterWordInstructions();


  
  while (numOfAttempts > 0) //while loop if the number of attempts are not 0
  { 
    cout << endl << "Please enter word -->  ";
    cin >> guessOfUser;
    cout<< endl;

    std:: transform(guessOfUser.begin(), guessOfUser.end(), guessOfUser.begin(), ::tolower);

    checkString =  binarySearch( guessOfUser, dictionary);//binary search for the string 

    if ((checkString != -1) && numOfAttempts == 4 )
    {
      startTime = time( NULL);
    }

    if (guessOfUser.size() == 3)
    {
      
      if (checkString != -1) 
      {
        compareMenuOption1 (arrayBoard,guessOfUser, countNoOfRows ,ranString);
        displaymenuOption1Board (ranString, numGuesses,  arrayBoard);
        numOfAttempts -= 1;


        
        if (guessOfUser == ranString)
        {
          elapsedTime = difftime( time( NULL), startTime);
          dictionaryForTime.push_back(elapsedTime);
          
          cout << "Nice Work!  You guessed the correct word\n"
               << "  - You completed the board in: " << elapsedTime << " seconds.\n"
               << "  - It took you " << numGuesses - 1 << "/" << "4 " << "attempts.\n";
          
          wordsGuessed ++ ;
          streak ++;
          break;
        } 


          
        else if (numOfAttempts == 0) //if the number of attempts are equal to 0 then the maximum number of attempts
        {
          dictionaryForStreak.push_back(streak);
          streak = 0;
          cout << "Maximum amount of attempts have been reached. Try again." << endl;
        }
        
      }
      else //if the loop doesnt work
      {
        cout << "Not a playable word, please select another word." << endl;
      }
    }
    else //if the loop doesnt work
    {
      cout << "Invalid word entry - please enter a word that is 3 characters long." << endl;
    }
  }
  
}



//runs the game of menu option 2
void menuOption2(int &streak,string ranString, char arrayBoard[6][5],int &wordsGuessed, vector <string> dictionary,   vector<int> &dictionaryForStreak,vector<int> &dictionaryForTime) {

  int stringExist;
  string guessOfUser;
  int numAttempts = 6;
  int numGuesses = 1;
  int elapsedTime = 0;
  int countNoOfRows = 0;
  time_t startTime;

  fiveLetterWordInstructions();// instructions that are displayed on the screen for the 5 letter word game play

  while (numAttempts > 0) //number of attempts are not equal to 0
  {

    cout << "Please enter word -->  ";
    cin >> guessOfUser;
    cout << endl;

    

    std:: transform(guessOfUser.begin(), guessOfUser.end(), guessOfUser.begin(), ::tolower);//to lower the user input to lower cases
    
    stringExist =  binarySearch(guessOfUser, dictionary);

    if ((stringExist != -1) && numAttempts == 6 )
    {
      startTime = time( NULL);//time the user for the amount of attempts
    }

    if (guessOfUser.size() == 5) 
    {
      if (stringExist != -1) 
      {
        
        compareMenuOption2 (arrayBoard,guessOfUser, countNoOfRows ,ranString);
    
        displaymenuOption2Board (ranString,numGuesses,  arrayBoard);
  
        numAttempts -= 1;
          
        if (guessOfUser == ranString){ //if the user gets the correct answer in the amount of attempts
          elapsedTime = difftime( time( NULL), startTime);
          dictionaryForTime.push_back(elapsedTime);
          cout << "Nice Work!  You guessed the correct word\n"
               << "  - You completed the board in: " << elapsedTime << " seconds.\n"
               << "  - It took you " << numGuesses - 1 << "/" << "6 " << "attempts.\n";
          wordsGuessed ++;
          streak ++;
          break;
        }
        else if (numAttempts == 0) 
        {
          dictionaryForStreak.push_back(streak);
          streak = 0;
          cout << "Maximum amount of attempts have been reached. Try again." << endl;
        }
        
      } 
      else 
      {
        cout <<  "Not a playable word, please select another word." << endl;
      }
    } 
    else 
    {
      cout << "Invalid word entry - please enter a word that is 5 characters long." << endl;
    }
  }
  
}


//Gives the statistics of the game
void statsOfTheGame( vector <int> dictionaryForStreak, vector <int> timeDictionary,int numberOfGuesses)
{

  
  int avgTime = 0;
  int maxWins = 0;
  

  if (numberOfGuesses > 1) {
    for (int i = 0; i < timeDictionary.size(); i++){
      avgTime += timeDictionary.at(i);
    }
  
    avgTime = avgTime / timeDictionary.size();
  }

  for (int i = 0; i < dictionaryForStreak.size(); i++){
    
    if (maxWins < dictionaryForStreak.at(i)){
      maxWins = dictionaryForStreak.at(i);
    }
  }
    
  
  cout << "Overall Stats:\n"
       << "  - You guessed: " << numberOfGuesses << endl
       << "  - Your longest streak is: " << maxWins << endl;
  if (numberOfGuesses < 1)
  {
    cout << "  - Average word completion time: N/A" << endl;
  }
  else 
  {
    cout << "  - Average word completion time: " << avgTime << endl;
    
  }
    cout <<  "Exiting program";
}




void instructions()// the game intructions that are displayed on the screen 
{
    cout << "Program 3: Wordle Reload \n"
        << "CS 141, Spring 2022, UIC \n"
        << " \n"
        << "The objective of this game is to guess the randomly selected \n"
        << "word within a given number of attempts. You can select either \n"
        << "a three or five word board. \n"
        << "At the conlusion of the game, stats will be displayed.  \n"
        << "Indicators will be given if characters of the user entered \n"
        << "word are reflected in the guessed word. \n"
        << "  - If the character is in the correct position, the character \n"
        << "    will display as an uppercase value.\n"
        << "  - If the character is within the random word, the character \n"
        << "    will display as a lowercase value.\n"
        << "  - If you enter a character that is not in the word, an asterisk '*' \n"
        << "    will display."
        << " \n"
        << endl;
}

void menu(int &userInput){// the menu instructions that are displayed on the screen and you can choose a menu option and play either 3 letter play or 6
  cout  << endl 
        << "Select a menu option:\n"
        << "   1. To play Wordle Reload 3 letter play\n"
        << "   2. To play Wordle Reload 5 letter play\n"
        << "   3. Exit the program\n"
        << "Your choice --> ";
  cin >> userInput;
  cout << endl;
}


int main() {


  vector<string> menuOption1Dictionary;
  vector<string> menuOption2Dictionary;
  vector<int> dictionaryForStreak;
  vector<int> dictionaryForTime;

  int menuOption;
  srand (1);
  string randomString;
  int totalGuesses = 0;
  int randNumberGenerator = 0;
  int streak = 0;
  int gameState = 0;
  
  
  VectorForDictionary(menuOption2Dictionary,menuOption1Dictionary);
  
  instructions();
  

  while (gameState == 0) 
  {
    
    menu(menuOption);
    
    if (menuOption == 1)//runs the game if the user input is 1
    {
      
      char menuOption1Board[4][3]= 
    {
      {'*', '*', '*'},
      {'*', '*', '*'},
      {'*', '*', '*'},
      {'*', '*', '*'}
      };
    
      randomWord(menuOption1Dictionary.size(),randNumberGenerator);
      randomString = menuOption1Dictionary.at(randNumberGenerator);
      menuOption1(streak,randomString,menuOption1Board,totalGuesses,menuOption1Dictionary,dictionaryForStreak,dictionaryForTime);
      
    } 
    else if (menuOption == 2) //runs the game if the user input is 2
    {

      char menuOption2Board[6][5]= 
    {
      {'*', '*', '*', '*', '*'},
      {'*', '*', '*', '*', '*'},
      {'*', '*', '*', '*', '*'},
      {'*', '*', '*', '*', '*'},
      {'*', '*', '*', '*', '*'},
      {'*', '*', '*', '*', '*'},
      };
      
      randomWord( menuOption2Dictionary.size(),randNumberGenerator);
      randomString = menuOption2Dictionary.at(randNumberGenerator);
      menuOption2(streak,randomString,menuOption2Board,totalGuesses,menuOption2Dictionary,dictionaryForStreak,dictionaryForTime);
      
    } 
    else // if the menu option is 3 displays the streaks and the stats of the game
    {
      dictionaryForStreak.push_back(streak);
      statsOfTheGame(dictionaryForStreak,dictionaryForTime,totalGuesses);
      gameState ++;
    }
  }
	return 0;
}




