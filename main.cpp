#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date::Date(){
   month = 1;
   monthName = "January";
   year = 2000;
   day = 1;
}

Date::Date(unsigned m, unsigned d, unsigned y){
   month = m;
   day = d;
   year = y;

    if(month <= 12 && month >= 1){
    if (month == 2) { 
        if (isLeap(y) && d >= 30) {
            day = 29;
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        } else if(d >= 29 && !isLeap(y)) {
            day = 28;
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
        if(day >= 31){
         day = 30;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
    } else if(day >= 32){ 
        day = 31;
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

    if (day <= 1){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }
    
   } else {
      if(month >= 13){
      month = 12;
   } else if (month <= 0){
      month = 1;
   }
   if (month == 2) { 
        if (isLeap(y) && d >= 30) {
            day = 29;
        } else if(d >= 29 && !isLeap(y)) {
            day = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
        if(day >= 31){
         day = 30;
        }
    } else if(day >= 32){ 
        day = 31;
    }

    if (day <= 1){
      day = 1;
    }
    cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;

   }

   if(month == 1){
      monthName = "January";
   } else if (month == 2){
      monthName = "February";
   }else if (month == 3){
      monthName = "March";
   }else if (month == 4){
      monthName = "April";
   }else if (month == 5){
      monthName = "May";
   }else if (month == 6){
      monthName = "June";
   }else if (month == 7){
      monthName = "July";
   }else if (month == 8){
      monthName = "August";
   }else if (month == 9){
      monthName = "September";
   }else if (month == 10){
      monthName = "October";
   }else if (month == 11){
      monthName = "November";
   }else if (month == 12){
      monthName = "December";
   }
}

Date::Date(const string &mn, unsigned d, unsigned y){
   monthName = mn;
   day = d;
   year = y;

  
   monthName.at(0) = toupper(monthName.at(0));
   
   
   if(monthName == "January" || monthName == "january"){
      month= 1;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   } else if (monthName == "February" || monthName == "february"){
      month = 2;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if (isLeap(y) && d >= 30) {
            day = 29;
             cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        } else if(d >= 29 && !isLeap(y)) {
            day = 28;
             cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
   }else if (monthName == "March" || monthName == "march"){
      month= 3;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   }else if (monthName == "April" || monthName == "april"){
      month= 4;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 31){
         day = 30;
          cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
   }else if (monthName == "May" || monthName == "may"){
      month= 5;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   }else if (monthName == "June" || monthName == "june"){
      month= 6;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      } else if(day >= 31){
         day = 30;
          cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
   }else if (monthName == "July" || monthName == "july"){
      month= 7;
       if(day < 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   }else if (monthName == "August" || monthName == "august"){
      month= 8;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   }else if (monthName == "September" || monthName == "september"){
      month= 9;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 31){
         day = 30;
          cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
   }else if (monthName == "October" || monthName == "october"){
      month= 10;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    } else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   }else if (monthName == "November" || monthName == "november"){
      month= 11;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      }else if(day >= 31){
         day = 30;
          cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
   }else if (monthName == "December" || monthName == "december"){
      month= 12;
       if(day <= 0){
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      } else if(day >= 32){ 
        day = 31;
         cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

   } else {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      monthName = "January";
      day = 1;
      month = 1;
      year = 2000;
   }

}

void Date::printNumeric() const{
   cout << month << '/' << day << '/' << year;
}

void Date::printAlpha() const{
    cout << monthName << ' ' << day << ", " << year;
}

bool Date::isLeap(unsigned y) const{
   if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)){
      return true;
   }else {
      return false;
   }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    if (m == 2) { 
        if (isLeap(y)) {
            return 29;
        } else {
            return 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) { // April, June, September, November
        return 30;
    } else { 
        return 31;
    }
}

string Date::name(unsigned m) const{
   if(m == 1){
      return "January";
   } else if (m == 2){
      return "February";
   }else if (m == 3){
      return  "March";
   }else if (m == 4){
      return "April";
   }else if (m == 5){
      return "May";
   }else if (m == 6){
      return "June";
   }else if (m == 7){
      return "July";
   }else if (m == 8){
      return "August";
   }else if (m == 9){
      return "September";
   }else if (m == 10){
      return "October";
   }else if (m == 11){
      return "November";
   }else if (m == 12){
      return "December";
   }

   return "Unknown";
}

unsigned Date::number(const string &mn) const{
   if(mn == "January" || mn == "january"){
     return 1;
   } else if (mn == "February" || mn == "February"){
      return 2;
   }else if (mn == "March" || mn == "march"){
      return 3;
   }else if (mn == "April" || mn == "april"){
      return 4;
   }else if (mn == "May" || mn == "may"){
      return 5;
   }else if (mn == "June" || mn == "june"){
      return 6;
   }else if (mn == "July" || mn == "july"){
      return 7;
   }else if (mn == "August" || mn == "august"){
      return 8;
   }else if (mn == "September" || mn == "september"){
      return 9;
   }else if (mn == "October" || mn == "october"){
      return 10;
   }else if (mn == "November" || mn == "november"){
      return 11;
   }else if (mn == "December" || mn == "december"){
      return 12;
   }

   return 0;
}




// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
