//Dr. Tyson McMillan soccer scoring program
#include <iostream>
using namespace std;

class Team
{
  private:
    int score; //data member
    int shotsOnGoal;
    string name;

  public:
    Team() //default constructor
    {score = 0; shotsOnGoal = 0; name = "DefaultName";}
    void setScore(int s) {score = s;}
    void setShotsOnGoal(int sog) {shotsOnGoal = sog;}
    void setName(string n) {name = n;}
    int getScore() const {return score;}
    int getShotsOnGoal() const {return shotsOnGoal;}
    string getName() const {return name;}

};

class Scoreboard
{
  private:
    int min;
    int sec;
    int half;
    Team home;//object home is of data type Team
    Team guest; //object guest is of data type Team
  public:
    Scoreboard()
{min = 0; sec = 0; half = 1; home = Team(); guest = Team();}
    void setMin(int m) {min = m;}
    void setSec(int s) {sec = s;}
    void setHalf(int h) {half = h;}
    void setHome(Team hSet) {home = hSet;}
    void setGuest(Team gSet) {guest = gSet;}
    int getMin() const {return min;}
    int getSec() const {return sec;}
    int getHalf() const {return half;}
    Team getHome() const {return home;}
    Team getGuest() const {return guest;}
    void showScoreboard()
    {
      cout << home.getName() << "\t\t" << guest.getName() << endl;
      cout << "\t\t\t" << min << ":"<< sec << endl;
      cout << home.getScore() << "\t\t\t\t\t\t" << guest.getScore() <<           endl;
      cout << "\t\tHalf: " << half << endl;
      cout << home.getShotsOnGoal() << " SOG\t\t\t\t\t" << guest.getShotsOnGoal() << " SOG"<< endl;
    }

};

int main() {

  Scoreboard s;
  Team tOne;
  Team tTwo;
  char choice = '\0';
  string newName = "";
  int newScore = 0;

  s.setHome(tOne);
  s.setGuest(tTwo);

  do {
    s.showScoreboard();
    cout << "\nMenu: " << endl;
    cout << "A. Update Home Team Name" << endl;
    cout << "B. Update Home Team Score" << endl;
    cout << "X. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A') {
      cout << "Enter a NAME for the home team: ";
      cin >> newName;
      tOne.setName(newName);
      cout << "\n";
    }
    else if (choice == 'b' || choice == 'B') {
      cout << "Enter a SCORE for the home team: ";
      cin >> newScore;
      tOne.setScore(newScore);
      
    }
    else if (choice == 'x' || choice == 'X') {
      cout << "\nExiting program" << endl;
    }
    
    

    s.setHome(tOne); // refresh the data in s to the new updates...
    s.setGuest(tTwo); // refresh the data in s to the new updates...
    cout << "\033[2J\033[1;1H"; // clear screen
    
  } while (choice != 'x' && choice != 'X'); 
  
  

  return 0; 
}