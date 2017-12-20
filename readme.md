//The beginning of each .cpp has an explanation for each the good and bad examples.

//All ten principles are included in each but are also explained here:

/*
Domain Separation GOOD
  the production variable cannot be modified by the development environment functions because it is a private variable.
*/

class Prod {
  const int password = 12345;
  int prodVariable = 3;
  public:
    void setPVar(int,int);
    void getPVar() { cout << "\nproduction variable is " << prodVariable;}
    void addP(int,int);
};

/*
Domain Separation BAD
  the production variable CAN be modified by anyone because it is a global variable.
*/

int prodVariable;

/*
Process Isolation GOOD
  variables are declared with values so they do not access old data from memory.
*/

/*
Process Isolation BAD
  
*/

/*
Resource Encapsulation GOOD
  we have classes that contain variables and functions to change them. 
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

/*
Resource Encapsulation BAD
*/

/*
Least Privilege GOOD 
  the user can change the development variable he has access too, but not the production variable that he doesn't have access to.
*/

/*
Least Privilege BAD
*/

/*
Modularity GOOD
  classes have functions to work on the variables so we can call the same function when variables may change.
*/

/*
Modularity BAD
*/

/*
Layering GOOD
  production variables must have a password to be updated.
*/

/*
Layering BAD
*/

/*
Abstraction GOOD
  user gets choices to manipulate data, but doesn't know how it is done
*/

/*
Abstraction BAD 
*/

/*
Data Hiding GOOD
  the password is contained in the class, but is not visible to dev because it is private.
*/

/*
Data Hiding BAD 
*/

/*
Simplicity GOOD 
  this isn't the simplest user interface, but each option is explained as simply as possible and it doesn't do crazy things.
*/

/*
Simplicity BAD 
*/

/*
Minimization GOOD 
  cases where the user may enter unaccepted information are simply rejected, and the program terminates.
*/

/*
Minimization BAD 
*/