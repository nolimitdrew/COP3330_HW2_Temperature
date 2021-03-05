/////////////////////////////////////////////////////////
// Bob Myers & Andrew Stade
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
   Temperature t1;		// should default to 0 Celsius
   Temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit 
   Temperature t3(12.6, 'Z');  // invalid scale, initializes to 0 Celsius
   Temperature t4(-300, 'c');  // this is below 0 Kelvin, inits to 0 Celsius
   Temperature t5(15, 'k');    // initializes to 15 Kelvin

   // display dates to the screen
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   cout << "\nTemperature t2 is: ";
   t2.Show();
   cout << "\nTemperature t3 is: ";
   t3.Show();
   cout << "\nTemperature t4 is: ";
   t4.Show();
   cout << "\nTemperature t5 is: ";
   t5.Show();
   cout << "\n";
   

   t1.Input();			// Allow user to enter a temperature for t1
   cout << "\nTemperature t1 is: ";
   t1.Show();

   t2.Input();			// Allow user to enter a temperature for t1
   cout << "\nTemperature t2 is: ";
   t2.Show();   
   
   t1.SetFormat('L');		// change format of t1 to "Long" format
   cout << "\nTemperature t1 is: ";
   t1.Show();
   
   t2.SetFormat('P');		// change format of t2 to "Precision" format
   cout << "\nTemperature t2 is: ";
   t2.Show();
   
   t1.Convert('C');
   cout << "Converting temperature 1: ";
   t1.Show();
   
   cout << "Comparing the functions t1 and t2:";
   cout << "\n" <<  t1.Compare(t2);
   cout << "\n" << t2.Compare(t1);
   
   cout << "\nChanging the increment of t1: ";
   t1.Increment(6, 'F');
   t1.Show();
   
   
   cout << endl;

   // and so on.  Add your own tests to fully test the class' 
   //   functionality.
}