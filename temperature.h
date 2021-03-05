
/* Name: Andrew Stade
Date: 9/26/2019
Section: 2 */

class Temperature
{
public:
    Temperature();                  // default constructor 
    Temperature(double t, char u);  // constructor with parameters
    
    // accessors
    void Input();
    void Show();
    bool Set(double deg, char s);
    double GetDegrees() const;
    char GetScale() const;
    
    // mutators
    bool SetFormat(char f);
    bool Convert(char sc);
    int Compare(const Temperature& d);
    
    void Increment(int deg, char sc);
    
private:
    double temp;
    char scale;
    char format;
};
    
    