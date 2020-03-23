/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */


// ==================================
// WingTangWong's UDT(s) From Project3
// ==================================
#include <iostream>
using namespace std;

// ==============================
// Microwave
struct Microwave
{
   // Constructor and destructor declarations 
   Microwave()
   {
      cout << "Microwave constructor!" << endl;
   }
   ~Microwave()
   {
      cout << "Microwave destructor!" << endl;
   }

   // 5 properties:
   // 1) wattage
   float wattage;

   // 2) plugged in or not
   bool powerAvailable;
   // 3) active or not
   bool active;

   // 4) current settings
   int powerLevel;

   // 5) time remaining
   float remainingTime;

   // 3 things it can do:
   // 1) open/close door
   void doorChangeState( bool openDoor );

   // 2) set time/power levels
   void setPowerLevel( int newPowerLevel );
   void setTimer( int newTimeRemaining );

   // 3) start/stop
   void startMicrowave();


};

// ==============================
// Smart Power Strip
struct SmartPowerStrip
{
   // Constructor and destructor declarations 
   SmartPowerStrip()
   {
      cout << "SmartPowerStrip constructor!" << endl;
   }
   ~SmartPowerStrip()
   {
      cout << "SmartPowerStrip destructor!" << endl;
   }
   // 5 properties:
   // 1) network address(ip address/netmask/gateway/dns)
   struct NetworkConfig
   {
      int ipAddress[4];
      int netmask[4];
      int gateway[4];
      bool configured;
      bool online;
   };

   // 2) list of individual socket states (on/off)

   struct SocketState
   {
      bool enabled;
      bool toggling;
      int countDownForToggle;
      bool somethingPullingPower;
      double powerConsumed;
   };

   SocketState sockets[8]; // 8 socket power strip


   // 3) stored history of power consumption per socket

   struct PowerDataPoint
   {
      double uptime;
      double powerConsumed=0.0;
      bool   socketState; // true = on, false = off
   };

   // 4) stored history of socket state changes

   PowerDataPoint socketHistory[MAX_LOG_LENGTH];

   // 5) stored 'uptime' value

   double uptime;

   // 3 things it can do:
   // 1) change individual socket state: on-to-off,off-to-on,toggle/bounce

   void socketOff( int socket );
   void socketOn(  int socket );
   void socketToggle( int socket, float waitBeforeOn );
   bool getSocketState( int socket );

   // 2) perform global socket change: all on, all off, all toggle/bounce

   void allSocketOn();
   void allSocketOff();
   void allSocketToggle( float waitBeforeOn );

   // 3) reconfigure network settings
   void setIP( NetworkConfig newConfig );

};

// ==============================
// Wild Squirrel
struct WildSquirrel
{
   // Constructor and destructor declarations 
   WildSquirrel()
   {
      cout << "WildSquirrel constructor!" << endl;
   }
   ~WildSquirrel()
   {
      cout << "WildSquirrel destructor!" << endl;
   }

   // 5 properties:
   // 1) Number of nuts in mouth
   int nutsInMouth;
   // 2) Number of trees visited per hour
   int treesVisitedPerHour;
   // 3) Has Jumped In Baby Carriage in Lifetime (bool)
   bool visitedBabyCarriage;
   // 4) Is Sprinting(bool)
   bool isSprinting;
   // 5) Is Chittering(bool)
   bool isChittering;

   // 3 things it can do:
   // 1) Place Nut In Mouth
   bool placeNutInMouth(); // might fail...
   // 2) Sprint to random location (inclusive of baby carriages)
   bool sprintToRandomLocation(); // might fail
   // 3) Chitter for random length of time.
   float performChittering(); // returns random value indicating how long chittering will go on for

};


// ==========================
// Two new UDT(s)




int main()
{
   WildSquirrel ws;
   Microwave mw;
   SmartPowerStrip sps;

   std::cout << "good to go!" << std::endl;
}
