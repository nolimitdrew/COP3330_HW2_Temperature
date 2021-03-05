
/* Name: Andrew Stade
Date: 9/26/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "temperature.h"

using namespace std; 

Temperature::Temperature()
// Passes in those with empty parementers
{
    temp = 0;
    scale = 'C';
    format = 'D';
}

Temperature::Temperature(double t, char u)
// Long error checking for passed in values
{
    if (u == 'F' && t >= -459.67)
    {
        temp = t;
        scale = u;
        format = 'D';
    }
    else if (u == 'f' && t >= -459.67)
    {
        temp = t;
        scale = 'F';
        format = 'D';
    }
    else if (u == 'C' && t >= -273.15)
    {
        temp = t;
        scale = u;
        format = 'D';
    }
    else if (u == 'c' && t >= -273.15)
    {
        temp = t;
        scale = 'C';
        format = 'D';
    }
    else if (u == 'K' && t >= 0)
    {
        temp = t;
        scale = u;
        format = 'D';
    }
    else if (u == 'k' && t >= 0)
    {
        temp = t;
        scale = 'K';
        format = 'D';
    }
    else 
    {
        temp = 0;
        scale = 'C';
        format = 'D';
    }
}

void Temperature::Input()
// Prompts the user to enter inputs for temperature and scale
{
    double inp1;
    char inp2;
 
    cout << "\nInput a temperature and scale: ";
    cin >> inp1;
    cin >> inp2;
    while (inp2 != 'c' && inp2 != 'C' && inp2 != 'f' && inp2 != 'F' && inp2 != 'k' && inp2 != 'K')
    {
        cout << "Invalid temperature. Try again: ";
        cin >> inp1;
        cin >> inp2;
    }
    
    if (inp2 == 'f')
    {
        inp2 = 'F';
        Temperature(inp1, inp2);
        Set(inp1, inp2);
    }
    else if (inp2 == 'c')
    {
        inp2 = 'C';
        Temperature(inp1, inp2);
        Set(inp1, inp2);
    }
    else if (inp2 == 'k')
    {
        inp2 = 'K';
        Temperature(inp1, inp2);
        Set(inp1, inp2);
    }
    else
    {
        Temperature(inp1, inp2);
        Set(inp1, inp2);
    }
}
    
void Temperature::Show() 
// This function will print out the temperature in the proper format
{
    int precision = cout.precision();
    char fill = cout.fill();
    ios_base::fmtflags oldflags = cout.flags();
    // Code pertaining to the "Precision" format
    
    string S; 
    
    if (format == 'D')
    {  
        cout << temp << ' ' << scale;
    }
    else if (format == 'P')
    {
        cout << setprecision(1) << showpoint << fixed << temp << ' ' << scale << endl;
    }
    else if (format == 'L')
    {
        if (scale == 'F')
        {
            S = " Fahrenheit";
            cout << temp << fixed<< showpoint<< S <<endl;
        }
        else if (scale == 'C')
        {
            S = " Celcius";
            cout << temp << fixed<< showpoint<< S <<endl;
        }
        else if (scale == 'K')
        {
            S = " Kelvin";
            cout << temp << fixed<< showpoint<< S <<endl;
        }
        
    }
    
    cout.precision(precision);
    cout.fill(fill);
    cout.flags(oldflags);



}

bool Temperature::Set(double deg, char s)
// Set function for the temperature and scale
{

        if (s == 'F' && deg >= -459.67)
        {
            temp = deg;
            scale = s;
            return true;
        }
        else if (s == 'C' && deg >= -273.15)
        {
            temp = deg;
            scale = s;
            return true;
        }
        else if (s == 'K' && deg >= 0)
        {
            temp = deg;
            scale = s;
            return true;
        }
        else
        {
            return false;
        } 
}

double Temperature::GetDegrees() const
{   
    return (temp);
}

char Temperature::GetScale() const
{
    return (scale);
}

bool Temperature::SetFormat(char f)
// Runs the char entered, and will change the format accordingly
{
   
    if (f == 'D')
    {
        format = 'D';
        return true;
    }
    else if (f == 'P')
    {
        format = 'P';
        return true;
    }
    else if (f == 'L')
    {
        format = 'L';
        return true;
    }
    else 
    {
        return false;
    }
    
    
}

bool Temperature::Convert(char sc)
// Used for changing between units for temperature (F,C,K)
{
    if (sc == 'f' || sc == 'F')
    {
        if (scale == 'C')
        {
            temp = (temp * 9 / 5) + 32;
            scale = sc;
            return true;
        }
        else if (scale == 'K')
        {
            temp = (temp - 273.15) * 9 / 5 + 32;
            scale = sc;
            return true;
        }
        else if (scale == 'F')
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    else if (sc == 'c' || sc == 'C')
    {
        if (scale == 'F')
        {
            temp = (temp - 32) * 5/9;
            scale = sc;
            return true;
        }
        else if (scale == 'K')
        {
            temp = temp - 273.15;
            scale = sc;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if (sc == 'k' || sc == 'K')
    {
        if (scale == 'F')
        {
            temp = (temp - 32) * 5 / 9 + 273.15;
            scale = sc;
            return true;
        }
        else if (scale == 'C')
        {
            temp = temp + 273.15;
            scale = sc;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
    
    
}

int Temperature::Compare(const Temperature& d)
// Allows to compare two temperatures called
{
   Temperature answer = d;
   answer.Convert(scale);
   
   if (temp < answer.temp)
   {
       return -1;
   }
   if (temp == answer.temp)
   {
       return 0;
   }
   if (temp > answer.temp)
   {
       return 1;
   }
}

void Temperature::Increment(int deg, char sc)
// Extra Credit. Allows an increase to the temperature accordingly
{
    if (sc == 'F')
    {
        if (scale == 'C')
        {
            Convert('F');
            temp = temp + deg;
            Convert('C');
        }
        else if (scale == 'K')
        {
            Convert('F');
            temp = temp + deg;
            Convert('K');
        }
        else if (scale == 'F')
        {
            temp = temp + deg;
        }
    }
    else if (sc == 'C')
    {
        if (scale == 'F')
        {
            Convert('C');
            temp = temp + deg;
            Convert('F');
        }
        else if (scale == 'K')
        {
            Convert('C');
            temp = temp + deg;
            Convert('K');
        }
        else if (scale == 'C')
        {
            temp = temp + deg;
        }
    }
    else if (sc == 'K')
    {
        if (scale == 'F')
        {
            Convert('K');
            temp = temp + deg;
            Convert('F');
        }
        else if (scale == 'C')
        {
            Convert('K');
            temp = temp + deg;
            Convert('C');
        }
        else if (scale == 'K')
        {
            temp = temp + deg;
        }
    }
           
}