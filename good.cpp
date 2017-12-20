#include<iostream>
using namespace std;

  /*domain separation: The production variable cannot be modified by the development environment functions.

    process isolation: variables are declared with values so they do not access old data from memory. 

    resource encapsulation: we have classes that contain variables and functions to change them. 

    least priviledge: the user can change the development variable he has access too, 
    but not the production variable that he doesn't have access to. 

    modularity: classes have functions to work on the variables so we can call the same function when
    variables may change.
    
    layering: production variables must have a password to be updated.

    abstraction: user gets choices to manipulate data, but doesn't know how it is done

    data hiding: the password is contained in the class, but is not visible to dev because it is private.

    simplicity:  this isn't the simplest user interface, but each option is explained as simply as possible
    and it doesn't do crazy things.

    minimization: cases where the user may enter unaccepted information are simply rejected, and the
    program terminates.
  */

class Prod {
  const int password = 12345;
  int prodVariable = 3;
  public:
    void setPVar(int,int);
    void getPVar() { cout << "\nproduction variable is " << prodVariable;}
    void addP(int,int);
};

class Dev {
  int devVar = 3;
  Prod prod;
  public:
    void setVar(int,int,int);
    void getVar() { 
      cout << "\ndev variable is " << devVar;
      prod.getPVar();
    }
    void addDP(int,int,int);
    void seePword() {cout << "\nSorry, you can't see a private variable.";};
};

void Dev::setVar(int pword, int d, int p) {
  devVar = d;
  prod.setPVar(pword, p);  
}

void Dev::addDP(int pword, int d, int p) {
  prod.addP(pword, p);
  devVar += d;
}

void Prod::setPVar(int pword, int p) {
  if(pword != password)
    cout << "\nDev doesn't have the rights to modify production variables.";
  else 
    prodVariable = p;
}

void Prod::addP(int pword, int p) {
  if(pword != password)
    cout << "\nDev doesn't have the rights to modify production variables.";
  else 
    prodVariable += p;
}

int main() {  
  Dev dev;
  char input, input1;
  int pword = 0;
  int d = 0;
  int p = 0; 
  cout << "Welcome! You may edit DEV but must have a password to edit PROD.\n"
    << "Would you like to see the password? y or n: ";
  cin >> input;
  if (input == 'y')
    dev.seePword();
  cout << "\nWould you like to enter a password? y or n (q to quit) ";
  cin >> input;
  while (input == 'n') {
    cout << "\nWhat would you like to do? \nChange variables, enter C\nAdd together, enter A\nQuit enter Q: ";
    cin >> input1;
    if (input1 == 'C' || input1 == 'c') {
      dev.getVar();
      cout << "\nEnter the new dev/prod variables d p (ie 5 5): ";
      cin >> d >> p;
      dev.setVar(pword,d,p);
      dev.getVar();
    }
    else if (input1 == 'A' || input1 == 'a') {
      dev.getVar();
      cout << "\nEnter the values to add to current values d p (ie 5 5): ";
      cin >> d >> p;
      dev.addDP(pword,d,p);
      dev.getVar();
    }
    else {
      cout << "\nWould you like to enter a password for Prod yet? y or n (q to quit)";  
      cin >> input;
    }
  }
  while (input == 'y') {
    cout << "\nPlease enter the password. ";
    cin >> pword;
    cout << "\nWhat would you like to do? \nChange variables, enter C\nAdd together, enter A\nQuit enter Q : ";
    cin >> input1;
    if (input1 == 'C' || input1 == 'c') {
      dev.getVar();
      cout << "\nEnter the new dev/prod variables d p (ie 5 5): ";
      cin >> d >> p;
      dev.setVar(pword,d,p);
      dev.getVar();
    }
    else if (input1 == 'A' || input1 == 'a') {
      dev.getVar();
      cout << "\nEnter the values to add to current values d p (ie 5 5): ";
      cin >> d >> p;
      dev.addDP(pword,d,p);
      dev.getVar();
    }
    else if (input1 == 'Q' || input1 == 'q'){
      cout <<"\nThank you! We will now exit.\n";
      break;
  }
    cout << "\nWould you like to go again? y or n ";
    cin >> input;
    if (input == 'n') {
      cout <<"\nThank you! We will now exit.\n";
      break;
    }
  }
  
  while (input == 'q') {
    cout <<"\nThank you! We will now exit.\n";
    break;
  }
}