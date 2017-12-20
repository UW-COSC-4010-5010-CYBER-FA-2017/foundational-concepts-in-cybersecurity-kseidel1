#include<iostream>
#include<string>
using namespace std;

  /*domain separation: the production variable CAN be modified by anyone because it is a global variable.

    process isolation: variables aren't declared with values so they may be initialized with old data from memory.

    resource encapsulation: variables are public or global and so can be changed by whatever or whoever.

    least priviledge: no password is necessary to change the production variable

    modularity: if you want to add, you have to do it yourself. no function to help.
    
    layering: while there is a password, it isn't necessary to change production variables. 

    abstraction: I don't really know how to implement this.

    data hiding: all data is visible to the user, even if it shouldn't be (like the password)

    simplicity: This can do some weird things, since we use strings instead of characters for input.

    minimization: we do no verification on user input, so anything can happen.
  */

int prodVariable;

class Prod {
  public:
    const int password = 12345;
    void setPVar(int,int);
    void getPVar() { cout << "\nproduction variable is " << prodVariable;}
    //void addP(int,int);
};

class Dev {
  Prod prod;
  public:
    int devVar;
    void setVar(int,int,int);
    void getVar() { 
      cout << "\ndev variable is " << devVar;
      prod.getPVar();
    }
    //void addDP(int,int,int);
    void seePword() {cout << "\nthe password is: " << prod.password;};
};

void Dev::setVar(int pword, int d, int p) {
  devVar = d;
  prod.setPVar(pword, p);  
}

/*void Dev::addDP(int pword, int d, int p) {
  prod.addP(pword, p);
  devVar += d;
}*/

void Prod::setPVar(int pword, int p) {
  prodVariable = p;
}

/*void Prod::addP(int pword, int p) {
  prodVariable += p;
}*/

int main() {  
  Dev dev;
  string input, input1;
  int pword;
  int d;
  int p; 

  cout << "Welcome! You may edit DEV but must have a password to edit PROD.\n"
    << "Would you like to see the password? y or n: ";
  cin >> input;
  if (input == "y")
    dev.seePword();

  cout << "\nWould you like to enter a password? y or n (or q to quit)";
  cin >> input;


  while (input == "n") {
    cout << "\nWhat would you like to do? \nChange variables, enter C\nAdd together, enter A\nQuit enter Q: ";
    cin >> input1;
    if (input1 == "C" || input1 == "c") {
      dev.getVar();
      cout << "\nEnter the new dev/prod variables d p (ie 5 5): ";
      cin >> d >> p;
      dev.setVar(pword,d,p);
      dev.getVar();
    }

    else if (input1 == "A" || input1 == "a") {
      dev.getVar();
      cout << "\nEnter the values to add to current values d p (ie 5 5): ";
      cin >> d >> p;
      //dev.addDP(pword,d,p);
      dev.devVar =+ d;
      prodVariable =+ p;
      dev.getVar();
    }

    else {
      cout << "\nWould you like to enter a password for Prod yet? y or n (q to quit)";  
      cin >> input;
    }

  }

  while (input == "y") {
    cout << "\nPlease enter the password. ";
    cin >> pword;
    cout << "\nWhat would you like to do? \nChange variables, enter C\nAdd together, enter A\nQuit enter Q : ";
    cin >> input1;
    if (input1 == "C" || input1 == "c") {
      dev.getVar();
      cout << "\nEnter the new dev/prod variables d p (ie 5 5): ";
      cin >> d >> p;
      dev.setVar(pword,d,p);
      dev.getVar();
    }

    else if (input1 == "A" || input1 == "a") {
      dev.getVar();
      cout << "\nEnter the values to add to current values d p (ie 5 5): ";
      cin >> d >> p;
      //dev.addDP(pword,d,p);
      dev.devVar =+ d;
      prodVariable =+ p;
      dev.getVar();
    }

    else if (input1 == "Q" || input1 == "q"){
      cout <<"\nThank you! We will now exit.\n";
      break;
  }
    cout << "\nWould you like to go again? y or n ";
    cin >> input;

    if (input == "n") {
      cout <<"\nThank you! We will now exit.\n";
      break;
    }
  }
  
  while (input == "q") {
    cout <<"\nThank you! We will now exit.\n";
    break;
  }

  if (input != "y" || input != "n" || input != "q") {
    cin >> input;
}