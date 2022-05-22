/**------------------------------------------
    Prog 5: March Madness Frenzy
    The dataset covers ranges of the basketball game for both men and women brackets for 2021 and 2022. The prediction file was also used. The file is broken down in different regions and championship. The program has options to analyze this data in different ways.

    Course: CS 141, Spring 2022.
    System: Windows Visual Studio Code Community
    Date: 4/11/2022
    Author: Imran Khan
*/


#include <iostream> 
#include <string.h>
#include <vector>
#include <fstream> 
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

//bulls class made which has private and public datd types and stores the rows of the file. Uses the getter and setter fumction to get the data from the given file selected by the user
class bulls{

  private:
  string Region;
  int Rank1;
  int Rank2;
  string Team1;
  string Team2;
  string WinningT;
  int Score1;
  int Score2;
  int Rnum;
  int Gnum;
  int DATA;
public:
bulls(){
  
    Region = "N/A";
    Rank1 = 0;
    Team1 = "N/A";
    Score1 = 0;
    Rank2 = 0;
    Team2 = "N/A";
    Score2 = 0;
    WinningT = "N/A";
    Rnum  = 0;
    Gnum  = 0;
  
      }
  
 bulls(string partOfRegion, int partOFRank1,string partOFTeam1,int partOFScore1,int partOFRank2,string partOFTeam2, int partOFScore2,string partOFWinningTeam,int partOFRoundNumber,int partOFGameNumber){
  
  Region = partOfRegion;
  Rank1 =  partOFRank1;
  Team1 = partOFTeam1;
  Score1 = partOFScore1;
  Rank2 = partOFRank2;
  Team2 = partOFTeam2;
  Score2 = partOFScore2;
  WinningT = partOFWinningTeam;
  Rnum  = partOFRoundNumber;
  Gnum  = partOFGameNumber;
  }
    
  

  void setRegion(string R) {Region = R;}
  void setRank1  (int r1){Rank1 = r1 ;}
  void setRank2  (int r2){Rank2 = r2 ;}
  void setTeam1  (string t1){Team1 = t1 ;}
  void setTeam2  (string t2){Team2 = t2 ;}
  void setWinningT (string w) {WinningT = w ;}
  void setScore1  (int s1){Score1 = s1 ;}
  void setScore2  (int s2){Score2 = s2 ;}
  void setRnum  (int rank){Rnum = rank ;}
  void setGnum (int gamenum){Gnum = gamenum ;}
  
  string getRegion() const {return Region;}//this sets R to Region
  int getRank1  () const {return Rank1 ;}//this sets 
  int getRank2  ()const {return Rank2 ;} 
  string getTeam1  ()const {return Team1  ;} 
  string getTeam2  ()const {return Team2  ;} 
  string getWinningT () const {return WinningT ;} 
  int getScore1  ()const {return Score1  ;} 
  int getScore2  ()const {return Score2 ;} 
  int getRnum  ()const {return Rnum;} 
  int getGnum ()const {return Gnum ;}
  
  
  
  };//end of BULLS class function

//----------------------------------------------------------------------------

//struct created for the values of the different rows in the document provided
struct DATA{
  string Region;
  int Rank1;
  int Rank2;
  string Team1;
  string Team2;
  string WinningT;
  int Score1;
  int Score2;
  int Rnum;
  int Gnum;
  int DATA;

};//end of struct DATA
//-------------------------------------------------------------------------------

//This function will run through the csv file and seperate the document where there is a ',' and add it to a vector called word.
void seperationforL(string row, vector<string>&SUMDATA){
  string terms;
  stringstream sstream(row);

  while (getline(sstream, terms, ',' )){
    SUMDATA.push_back(terms);
  }
  
  if (SUMDATA.at(3).empty()){
    SUMDATA.at(3) = "0";
  } 
  if (SUMDATA.at(4).empty()){
    SUMDATA.at(4) = "0";
  } 
  if (SUMDATA.at(5).empty()){
    SUMDATA.at(5) = "0";
  } 
  if (SUMDATA.at(1).empty()){
    SUMDATA.at(1) = "0";
  } 
  if (SUMDATA.at(2).empty()){
    SUMDATA.at(2) = "0";
  } 
    if (SUMDATA.at(6).empty()){
    SUMDATA.at(6) ="0";
  }
  if (SUMDATA.at(7).empty()){
    SUMDATA.at(7) = "0";
  } 
  if (SUMDATA.at(8).empty()){
    SUMDATA.at(8) = "0";
  } 
  if (SUMDATA.at(9).empty()){
    SUMDATA.at(9) = "0";
  } 
}//end of function seperationforL

//-------------------------------------------------------------------------------


//This fuction will read through the csv file and seperate it into rows and uses the setter function to set the value of each row to a place into an vector called words the fucntion getline is used in this function to seperate the words where there is a ',
void readFile(vector<string>&ALLDATA,vector<bulls>&ALLINFORMATION,bulls numrows,string chart){

  string line;
  
  ifstream inStream;
  inStream.open(chart);
  assert(inStream.fail() == false);

  getline(inStream,line);
  while (getline(inStream,line)){
    seperationforL(line,ALLDATA);

    
  numrows.setRegion(ALLDATA.at(0));
  numrows.setRank1(stoi(ALLDATA.at(1)));
  numrows.setRank2(stoi(ALLDATA.at(4)));
  numrows.setTeam1(ALLDATA.at(2));
  numrows.setTeam2(ALLDATA.at(5));
  numrows.setWinningT(ALLDATA.at(7));
  numrows.setScore1(stoi(ALLDATA.at(3)));
  numrows.setScore2(stoi(ALLDATA.at(6)));
  numrows.setRnum(stoi(ALLDATA.at(8)));
    
  numrows.setGnum(stoi(ALLDATA.at(9)));

  ALLINFORMATION.push_back(numrows);

  ALLDATA.clear();

  }
}//end of readfile Function

//----------------------------------------------------------------------------

//This fuction will read through the second csv file and seperate it into rows and uses the setter function to set the value of each row to a place into an vector called words the fucntion getline is used in this function to seperate the words where there is a ',
void readSecondFile(vector<string>&ALLDATA,vector<bulls>&secondInfo,bulls numrows,string chart){
  string line;
  
  ifstream inStream;
  inStream.open(chart);
  assert(inStream.fail() == false);

  getline(inStream,line);
  while (getline(inStream,line)){
    seperationforL(line,ALLDATA);

    
  numrows.setRegion(ALLDATA.at(0));
  numrows.setRank1(stoi(ALLDATA.at(1)));
  numrows.setRank2(stoi(ALLDATA.at(4)));
  numrows.setTeam1(ALLDATA.at(2));
  numrows.setTeam2(ALLDATA.at(5));
  numrows.setWinningT(ALLDATA.at(7));
  numrows.setScore1(stoi(ALLDATA.at(3)));
  numrows.setScore2(stoi(ALLDATA.at(6)));
  numrows.setRnum(stoi(ALLDATA.at(8)));
    
  numrows.setGnum(stoi(ALLDATA.at(9)));

  secondInfo.push_back(numrows);

  ALLDATA.clear();

  }
}//end of readSecondFile Function
//------------------------------------------------------------------------------

//menu introduction for he user to understand what the program will do
void menuIntroduction(string &filename) { 
  cout << "Program 5: March Madness Frenzy CS 141, Spring 2022, UIC \n"
    << "This program reads in data from NCAA Basketball Tournaments (aka March Madness). It provides overall information regarding the data, allows you to see the path taken to the championship, uses rankings of teams to determine which region is expected to win at a given round and to find the best underdog team, and calculates point differences within the games. You can also compare the actual brackets to your own predictions!\n"
    << "Enter the name of the file with the data for the NCAA tournament: ";
  cout<<endl;
  cin>>filename;
  
  }//end of menuIntroduction

//------------------------------------------------------------------------------


//Outputs the first menu option to the user and returns their input to the main which is used further in another function
void userChoice(int &menuUserOption1) { 
  cout << "\n"
       << "Select a menu option: \n" 
       << "  1. Display overall information about the data \n"
       << "  2. Display the path of the winning team to the championship\n"
      << "  3. Determine which region is expected to win the championship based on a given round\n"
      << "  4. Identify the best underdog within a given round\n"
      << "  5. Find the shoo-in and nail-biting games within a given round, or overall\n"
     << "  6. Compare the actual brackets to your predicted brackets\n"
    << "  7. Exit\n"
    << "Your choice --> " ;
    cin>> menuUserOption1;
}//end of userChoice
//------------------------------------------------------------------------------


//reads the mens basketball file and outputs the answer for the menu option 1 which is the total number of games played anf the final four contestants are.
void menuOption1Men (vector<bulls>&ALLINFORMATION){
  vector<string> vector1;
  vector<string> vector2;

  cout<< "Total number of games played in tournament: " <<ALLINFORMATION.size()<<endl;
  
  
  for(int i =0; i< ALLINFORMATION.size(); i++){
    if (ALLINFORMATION.at(i).getRegion() == "Final Four"){
      vector1.push_back(ALLINFORMATION.at(i).getTeam1());
      vector1.push_back(ALLINFORMATION.at(i).getTeam2());
      }
  }

  cout<< "The Final Four contestants are: "<<endl;

  for(int i =0; i<ALLINFORMATION.size();i++){
    for(int k = 0;k<vector1.size();k++){
      if(ALLINFORMATION.at(i).getTeam1() == vector1.at(k) || ALLINFORMATION.at(i).getTeam2() == vector1.at(k)){
        if(ALLINFORMATION.at(i).getRegion() == "South"||ALLINFORMATION.at(i).getRegion() == "West"||ALLINFORMATION.at(i).getRegion() == "East"||ALLINFORMATION.at(i).getRegion() == "Midwest"){
          if(find(vector2.begin(),vector2.end(), ALLINFORMATION.at(i).getRegion()) == vector2.end()){
            cout<<"        "<<ALLINFORMATION.at(i).getRegion()<< " region:    "<<vector1.at(k)<<endl;
            vector2.push_back(ALLINFORMATION.at(i).getRegion());
          }
          
        }
      
    }
    
  }
  }
}//end of menuOption1Men
//-------------------------------------------------------------------------------

//reads the womens basketball file and outputs the answer for the menu option 1 which is the total number of games played anf the final four contestants are.
void menuOption1Women(vector<bulls>&ALLINFORMATION){
    vector<string> vector1;
  vector<string> vector2;

  cout<< "Total number of games played in tournament: " <<ALLINFORMATION.size()<<endl;
  
  
  for(int i =0; i< ALLINFORMATION.size(); i++){
    if (ALLINFORMATION.at(i).getRegion() == "Final Four"){
      vector1.push_back(ALLINFORMATION.at(i).getTeam1());
      vector1.push_back(ALLINFORMATION.at(i).getTeam2());
      }
  }

  cout<< "The Final Four contestants are: "<<endl;

  for(int i =0; i<ALLINFORMATION.size();i++){
    for(int k = 0;k<vector1.size();k++){
      if(ALLINFORMATION.at(i).getTeam1() == vector1.at(k) || ALLINFORMATION.at(i).getTeam2() == vector1.at(k)){
        if(ALLINFORMATION.at(i).getRegion() == "Greensboro"||ALLINFORMATION.at(i).getRegion() == "Wichita"||ALLINFORMATION.at(i).getRegion() == "Spokane"||ALLINFORMATION.at(i).getRegion() == "Bridgeport"){
          if(find(vector2.begin(),vector2.end(), ALLINFORMATION.at(i).getRegion()) == vector2.end()){
            cout<<"        "<<ALLINFORMATION.at(i).getRegion()<< " region:    "<<vector1.at(k)<<endl;
            vector2.push_back(ALLINFORMATION.at(i).getRegion());
          }
          
        }
      
    }
    
  }
  }
}//end of menuOption1Women
//-------------------------------------------------------------------------------

//reads the given file and has the vector as the parameter and runs through the file and displays the answer for the menu option 2 which is the path of the championship for the winning team
void menuOption2(vector<bulls>&ALLINFORMATION){
  string winningTeam;
  vector< int > gameNumber;
  vector<string>player1;
  vector<string>player2;
  vector< int > roundNumber;

  cout<<"Path to the championship: "<<endl;
  for(int i =0; i<ALLINFORMATION.size(); i++){
    if(ALLINFORMATION.at(i).getRegion() == "Championship") {
      winningTeam = ALLINFORMATION.at(i).getWinningT();
    }
  }
  for(int i = 0; i<ALLINFORMATION.size();i++){
    if(ALLINFORMATION.at(i).getTeam1() == winningTeam ||ALLINFORMATION.at(i).getTeam2() == winningTeam){
      if(ALLINFORMATION.at(i).getRnum() == 1){
      roundNumber.push_back(1);
     player1.push_back(ALLINFORMATION.at(i).getTeam1());
     player2.push_back(ALLINFORMATION.at(i).getTeam2()); 
    gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      else if(ALLINFORMATION.at(i).getRnum() == 2){
      roundNumber.push_back(2);
      player1.push_back(ALLINFORMATION.at(i).getTeam1());
     player2.push_back(ALLINFORMATION.at(i).getTeam2());
   gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      else if(ALLINFORMATION.at(i).getRnum() == 3){
      roundNumber.push_back(3);
      player1.push_back(ALLINFORMATION.at(i).getTeam1());
     player2.push_back(ALLINFORMATION.at(i).getTeam2());       gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      else if(ALLINFORMATION.at(i).getRnum() == 4){
      roundNumber.push_back(4);
      player1.push_back(ALLINFORMATION.at(i).getTeam1());
     player2.push_back(ALLINFORMATION.at(i).getTeam2());
   gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      else if(ALLINFORMATION.at(i).getRnum() == 5){
      roundNumber.push_back(5);
      player1.push_back(ALLINFORMATION.at(i).getTeam1());
     player2.push_back(ALLINFORMATION.at(i).getTeam2());
   gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      else if(ALLINFORMATION.at(i).getRnum() == 6){
      roundNumber.push_back(6);
      player1.push_back(ALLINFORMATION.at(i).getTeam1());
      player2.push_back(ALLINFORMATION.at(i).getTeam2());
   gameNumber.push_back(ALLINFORMATION.at(i).getGnum());
      }
      
    }
  }
  for(int i = 5; i>=0;i--){
    cout<<"Round "<<roundNumber.at(i)<<", Game "<<gameNumber.at(i)<<": "<<player1.at(i)<<" vs "<<player2.at(i)<<". Winner: "<< winningTeam<<endl;
    }
}//end of menuOption2
//-----------------------------------------------------------------------------

//Displays the menuoption for the menuoption 3 to the user so that they can input the correct value they want the output of.
void subFunctionOf3(int &optionNumber3){
  cout<<"Enter a round to be evaluated: "<<endl;
   cout<<"Select 2 for round 2"<<endl;
  cout<< "Select 3 for round 3 'Sweet 16'"<<endl;
  cout<< "Select 4 for round 4 'Elite 8'"<<endl;
  cout<< "Select 5 for round 5 'Final 4'"<<endl;
  cout<< "Your choice --> ";
  cin>>optionNumber3;
}//end of subFunctionOf3
//-----------------------------------------------------------------------------


//reads the mens basketball file and outputs the answer for the menu option 3
void final4option3men(vector<string>final4teams,vector<bulls>ALLINFORMATION,int&index){
  index =0;
  int z = ALLINFORMATION.size();
  for (int i = z-1; i>=0;i--){
    if(ALLINFORMATION.at(i).getRegion()=="West"){
      for (int j = 0; j<final4teams.size();j++){
        if(final4teams.at(j)==ALLINFORMATION.at(i).getTeam1()||final4teams.at(j)==ALLINFORMATION.at(i).getTeam2()){
         index =0;
         return;
         break;
         break;
        }
       }
      }
    else if (ALLINFORMATION.at(i).getRegion()=="South"){
      for (int j = 0; j<final4teams.size();j++){
        if(final4teams.at(j)==ALLINFORMATION.at(i).getTeam1()||final4teams.at(j)==ALLINFORMATION.at(i).getTeam2()){
         index =1;
          return;
          break;
          break;
        }
       }
    }
    else if (ALLINFORMATION.at(i).getRegion()=="East"){
      for (int j = 0; j<final4teams.size();j++){
        if(final4teams.at(j)==ALLINFORMATION.at(i).getTeam1()||final4teams.at(j)==ALLINFORMATION.at(i).getTeam2()){
         index =2;
          return;
         break;
          break;
        }
       }
    }
    else if (ALLINFORMATION.at(i).getRegion()=="Midwest"){
      for (int j = 0; j<final4teams.size();j++){
        if(final4teams.at(j)==ALLINFORMATION.at(i).getTeam1()||final4teams.at(j)==ALLINFORMATION.at(i).getTeam2()){
          index =3;
         return;
         break;
         break;
        }
       }
    }
    }
  
}//end of final4option3men
//-------------------------------------------------------------------------------


//reads the mens basketball file and outputs the answer for the menu option 3
void menuOption3Men(vector<bulls>&ALLINFORMATION,int optionNumber){
  vector<int>westRanks;
  vector<int>southRanks;
  vector<int>eastRanks;
  vector<int>midwestRanks;
  vector<int>allranks;
  vector<int>final4Ranks;
  vector<string>final4teams;
  string winningRegion;
  int min =1000;
  int pop =0;
  int region =0;
  int westAddition = 0;
  int southAddition = 0;
  int eastAddition = 0;
  int midwestAddition = 0;

  cout<<"Analyzing round "<<optionNumber<<"..."<<endl;
  for (int i = 0; i<ALLINFORMATION.size();i++){
    if (ALLINFORMATION.at(i).getRnum()==optionNumber){
      if(ALLINFORMATION.at(i).getRegion()=="West"){
        if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        westRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        westRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="South"){
      if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        southRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        southRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="East"){
       if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        eastRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        eastRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Midwest"){
       if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        midwestRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        midwestRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Final Four"){
      if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        final4Ranks.push_back(ALLINFORMATION.at(i).getRank1());
        final4teams.push_back(ALLINFORMATION.at(i).getTeam1());
          }
        else {
        final4Ranks.push_back(ALLINFORMATION.at(i).getRank2());
          final4teams.push_back(ALLINFORMATION.at(i).getTeam2());
          }
      }
    }
  }

  for(int i =0; i<westRanks.size();i++){
    westAddition+=westRanks.at(i);
  }
   for(int i =0; i<southRanks.size();i++){
    southAddition+=southRanks.at(i);
  }
   for(int i =0; i<eastRanks.size();i++){
    eastAddition+=eastRanks.at(i);
  }
   for(int i =0; i<midwestRanks.size();i++){
    midwestAddition+=midwestRanks.at(i);
  }

  allranks.push_back(westAddition);
  allranks.push_back(southAddition);
  allranks.push_back(eastAddition);
  allranks.push_back(midwestAddition);


  
  for(int i =0; i<allranks.size();i++){
    
    
    if(allranks.at(i) < min){
      min = allranks.at(i);

      region =i;
      
    }
  }
  if(optionNumber ==5){
  final4option3men(final4teams,ALLINFORMATION,region);
    }

  if (region == 0){winningRegion = "West";}
  else if (region == 1){winningRegion = "South";}
  else if (region == 2){winningRegion = "East";}
  else if (region == 3){winningRegion = "Midwest";}

  cout<<endl<<"The region expected to win is: "<<winningRegion<<endl;

  

}//end of menuOption3Men
//-----------------------------------------------------------------------------


//reads the women basketball file and outputs the answer for the menu option 3
void menuOption3Women(vector<bulls>&ALLINFORMATION,int optionNumber){
    vector<int>GreensboroRanks;
  vector<int>WichitaRanks;
  vector<int>SpokaneRanks;
  vector<int>BridgeportRanks;
  vector<int>allranks;
  vector<int>final4Ranks;
  vector<string>final4team;
  string winningRegion;
  int min =1000;
  int region =0;
  int westAddition = 0;
  int southAddition = 0;
  int eastAddition = 0;
  int midwestAddition = 0;

  cout<<"Analyzing round "<<optionNumber<<"..."<<endl;
  for (int i = 0; i<ALLINFORMATION.size();i++){
    if (ALLINFORMATION.at(i).getRnum()==optionNumber){
      if(ALLINFORMATION.at(i).getRegion()=="Greensboro"){
        if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        GreensboroRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        GreensboroRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Wichita"){
      if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        WichitaRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        WichitaRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Spokane"){
       if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        SpokaneRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        SpokaneRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Bridgeport"){
       if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        BridgeportRanks.push_back(ALLINFORMATION.at(i).getRank1());
          }
        else {
        BridgeportRanks.push_back(ALLINFORMATION.at(i).getRank2());
          }
      }
      else if(ALLINFORMATION.at(i).getRegion()=="Final Four"){
      if(ALLINFORMATION.at(i).getWinningT()==ALLINFORMATION.at(i).getTeam1()){
        final4Ranks.push_back(ALLINFORMATION.at(i).getRank1());
        final4team.push_back(ALLINFORMATION.at(i).getTeam1());
          }
        else {
        final4Ranks.push_back(ALLINFORMATION.at(i).getRank2());
          final4team.push_back(ALLINFORMATION.at(i).getTeam2());
          }
          }
      }
    }
  

  for(int i =0; i<GreensboroRanks.size();i++){
    westAddition+=GreensboroRanks.at(i);
  }
   for(int i =0; i<WichitaRanks.size();i++){
    southAddition+=WichitaRanks.at(i);
  }
   for(int i =0; i<SpokaneRanks.size();i++){
    eastAddition+=SpokaneRanks.at(i);
  }
   for(int i =0; i<BridgeportRanks.size();i++){
    midwestAddition+=BridgeportRanks.at(i);
  }

  allranks.push_back(westAddition);
  allranks.push_back(southAddition);
  allranks.push_back(eastAddition);
  allranks.push_back(midwestAddition);

 
  
  for(int i =0; i<allranks.size();i++){
    
    
    if(allranks.at(i) < min){
      min = allranks.at(i);
      region =i;
      
    }
  }

  if (region == 0){winningRegion = "Greensboro";}
  else if (region == 1){winningRegion = "Wichita";}
  else if (region == 2){winningRegion = "Spokane";}
  else if (region == 3){winningRegion = "Bridgeport";}

  cout<<endl<<"The region expected to win is: "<<winningRegion<<endl;
}//end of menuOption3women
//--------------------------------------------------------------------------------

//Displays the menuoption for the menuoption 4 to the user so that they can input the correct value they want the output of.
void subFunctionOf4(int &optionNumber4){
  cout<<"Enter a round to be evaluated: "<<endl;
  cout<<"Select 2 for round 2"<<endl;
  cout<< "Select 3 for round 3 'Sweet 16'"<<endl;
  cout<< "Select 4 for round 4 'Elite 8'"<<endl;
  cout<< "Select 5 for round 5 'Final 4'"<<endl;
  cout<<"   Select 6 for round 6 'Championship' "<<endl;
  cout<< "Your choice --> ";
  cin>>optionNumber4;
}//end of subFunctionOf4
//-------------------------------------------------------------------------

//runs through the given file and outputs the answer for the menu option 4
void menuOption4(vector<bulls>&ALLINFORMATION,int optionNumber){
  vector <string> v1;  
  vector <int> v2;   

  if(optionNumber <= 5){
    for(int i = 0; i<ALLINFORMATION.size(); i++){
      if(ALLINFORMATION.at(i).getRnum()==optionNumber-1){
        if(ALLINFORMATION.at(i).getTeam1()==ALLINFORMATION.at(i).getWinningT()){
          v1.push_back(ALLINFORMATION.at(i).getTeam1());
          v2.push_back(ALLINFORMATION.at(i).getRank1());
        }
        else if(ALLINFORMATION.at(i).getTeam2()==ALLINFORMATION.at(i).getWinningT()){
          v1.push_back(ALLINFORMATION.at(i).getTeam2());
          v2.push_back(ALLINFORMATION.at(i).getRank2());
        }
      }
    }

    int max = v2.at(0);
    int count;
    for (int j = 0;j<v2.size();j++){
      if (v2.at(j)>max){
        max = v2.at(j);
        count = j;
      }
    }

  cout<<"The best underdog team is "<<v1.at(count)<<" which has rank "<<v2.at(count)<<"."<<endl;
  }

  else{
    for(int l = 0; l < ALLINFORMATION.size();l++){
      if(ALLINFORMATION.at(l).getRnum() == 6){
        if(ALLINFORMATION.at(l).getWinningT() == ALLINFORMATION.at(l).getTeam1()){
          cout<<"The best underdog team is "<<ALLINFORMATION.at(l).getTeam2()<<" which has rank "<<ALLINFORMATION.at(l).getRank2()<<"."<<endl;
        }
        else if(ALLINFORMATION.at(l).getWinningT() == ALLINFORMATION.at(l).getTeam2()){
          cout<<"The best underdog team is "<<ALLINFORMATION.at(l).getTeam1()<<" which has rank "<<ALLINFORMATION.at(l).getRank1()<<"."<<endl;

        }
      }
    }
  }
}//menuOption4
//-----------------------------------------------------------------------------


//Displays the menuoption for the menuoption 5 to the user so that they can input the correct value they want the output of.
void subFunctionOf5(int &optionNumber5){
  cout<<"Enter a round to be evaluated: "<<endl;
  cout<<"   Select 1 for round 1"<<endl;
  cout<<"   Select 2 for round 2"<<endl;
  cout<<"   Select 3 for round 3 'Sweet 16'"<<endl;
  cout<<"   Select 4 for round 4 'Elite 8'"<<endl;
  cout<<"   Select 5 for round 5 'Final 4'"<<endl;
  cout<<"   Select 6 for round 6 'Championship'"<<endl;
  cout<<"   Select 7 for the overall tournament"<<endl;
  cout<< "Your choice --> ";
  cin>>optionNumber5;
}//subFunctionOf5
//------------------------------------------------------------------------------

//runs through the given file and outputs the answer for the menu option 5
void menuOption5(vector<bulls>&ALLINFORMATION,int optionNumber){
  int score1 = 0;
  int score2 = 0;
  int maximum = 0;
  int minimum = 1000;
  int difference =0;
  string maxteam1;
  string maxteam2;
  string minteam1;
  string minteam2;
  string maxwinningTeam;
  string minwinningTeam;
  int maxgameNumber = 0;
  int mingameNumber = 0;
  int maxroundNumber = 0;
  int minroundNumber = 0;


  if(optionNumber ==7){
    cout<<"Analyzing the overall tournament..."<<endl;
    for (int i = 0; i<ALLINFORMATION.size();i++){
      score1 =ALLINFORMATION.at(i).getScore1();
        score2 = ALLINFORMATION.at(i).getScore2();
        difference = abs(score1 -score2);
        
        if(maximum < difference){
          maximum = difference;
          maxteam1 = ALLINFORMATION.at(i).getTeam1();
          maxteam2 = ALLINFORMATION.at(i).getTeam2();
          maxwinningTeam = ALLINFORMATION.at(i).getWinningT();
          maxgameNumber = ALLINFORMATION.at(i).getGnum();
          maxroundNumber =ALLINFORMATION.at(i).getRnum();
        }
        if(minimum>difference){
          minimum = difference;
          minteam1 = ALLINFORMATION.at(i).getTeam1();
          minteam2 = ALLINFORMATION.at(i).getTeam2();
          minwinningTeam = ALLINFORMATION.at(i).getWinningT();
          mingameNumber = ALLINFORMATION.at(i).getGnum();
          minroundNumber =ALLINFORMATION.at(i).getRnum();
        }
        
        
      }
    
  }
  else {
    cout<<"Analyzing round "<<optionNumber<<"..."<<endl;
    for (int i = 0; i<ALLINFORMATION.size();i++){
      if (ALLINFORMATION.at(i).getRnum()==optionNumber){
        score1 =ALLINFORMATION.at(i).getScore1();
        score2 = ALLINFORMATION.at(i).getScore2();
        difference = abs(score1 -score2);
        
        if(maximum < difference){
          maximum = difference;
          maxteam1 = ALLINFORMATION.at(i).getTeam1();
          maxteam2 = ALLINFORMATION.at(i).getTeam2();
          maxwinningTeam = ALLINFORMATION.at(i).getWinningT();
          maxgameNumber = ALLINFORMATION.at(i).getGnum();
          maxroundNumber =ALLINFORMATION.at(i).getRnum();
        }
        if(minimum>difference){
          minimum = difference;
          minteam1 = ALLINFORMATION.at(i).getTeam1();
          minteam2 = ALLINFORMATION.at(i).getTeam2();
          minwinningTeam = ALLINFORMATION.at(i).getWinningT();
          mingameNumber = ALLINFORMATION.at(i).getGnum();
          minroundNumber =ALLINFORMATION.at(i).getRnum();
        }
        
        }
      }
    }
  cout<<"The shoo-in game was: "<<endl;
  cout<<"Round "<<maxroundNumber<<", Game "<<maxgameNumber<<": "<<maxteam1<<" vs "<<maxteam2<<". Winner: "<<maxwinningTeam<<endl;
  cout<<"The difference was "<<maximum<<" points."<<endl;


  cout<<endl<<"The nail-biting game was: "<<endl;
  cout<<"Round "<<minroundNumber<<", Game "<<mingameNumber<<": "<<minteam1<<" vs "<<minteam2<<". Winner: "<<minwinningTeam<<endl;
  cout<<"The difference was "<<minimum<<" points."<<endl;

}//menuOption5
//----------------------------------------------------------------------------

//runs through the given file and outputs the answer for the menu option 5
void menuOption6(vector<string>&ALLDATA,vector<bulls>&ALLINFORMATION,bulls numrows,string chart){
  string file2;
  vector<bulls>secondInfo;
  int score =0;
  int roundNumber =0 ;
  int guessedcorrect=0;
  
  cout<<"Enter the name of the file with your predicted brackets: "<<endl;
  cin>>file2;
  readSecondFile(ALLDATA,secondInfo,numrows,file2);

  
  for(int i =0; i<ALLINFORMATION.size();i++){    if(ALLINFORMATION.at(i).getWinningT()==secondInfo.at(i).getWinningT()){
       guessedcorrect +=1;
       roundNumber = ALLINFORMATION.at(i).getRnum();
       score += roundNumber*5;
         
    }
  }
  cout<<"You correctly predicted the winner for "<<guessedcorrect<<" games."<<endl;
  cout<<"This means that you have a score of "<<score<<"."<<endl;

  if(score>= 250){
    cout<<"Great job! You could consider entering your predictions to win money!"<<endl;
  }
  else{
    cout<<"You may want to learn more about basketball to improve your predictions next year."<<endl;
  }
}//end of menuOption6
//------------------------------------------------------------------------------


int main() {
  int secondOption = 0;//for menuOption2
  string file;
  int optionNumber3 =0;//for menuOption3
  int optionNumber5 =0;//for menuOption5
  int optionNumber4 =0;//for menuOption4
  
  int runningTheProgram =1;
  vector<string>ALLDATA;//all data of the file is stored into this vector
  vector<bulls>ALLINFORMATION;//all information of the file is stored 
  
  bulls dataRow;//struct used
  
  
  menuIntroduction(file);//for the menu
  readFile(ALLDATA,ALLINFORMATION,dataRow,file);//reads the file
  

  while (runningTheProgram==1) {
    //runs the program if the value is 1
    

    userChoice (secondOption);

    if (secondOption < 8 ) {
      

      switch(secondOption) {
        
        case 1:
          if(file == "womens_bracket_2022_predictions1.csv"||file =="womens_bracket_2022.csv"){
            menuOption1Women(ALLINFORMATION);
          }
          else{
            menuOption1Men(ALLINFORMATION);
          }
          
          break;
        case 2:
          menuOption2(ALLINFORMATION);
          break;
				case 3:
          subFunctionOf3(optionNumber3);

					if(file == "womens_bracket_2022_predictions1.csv"||file =="womens_bracket_2022.csv"){
            menuOption3Women(ALLINFORMATION,optionNumber3);
          }
          else{
            menuOption3Men(ALLINFORMATION,optionNumber3);
          }
          break;
				case 4:
          subFunctionOf4(optionNumber4);
          menuOption4(ALLINFORMATION,optionNumber4);
          
          break;
        case 5:
          subFunctionOf5(optionNumber5);
          menuOption5(ALLINFORMATION,optionNumber5);
          break;
				case 6:
					menuOption6(ALLDATA,ALLINFORMATION,dataRow,file);
          
					break;
        case 7:
          cout<<"Exiting program...";
          runningTheProgram++;
					break;
          
      }
      
    } else {
      
      cout << endl << "Invalid value.  Please re-enter a value from the menu options below.\n" ;
    }
    
  }

  return 0;
}

