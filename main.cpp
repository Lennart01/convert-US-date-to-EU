#include <iostream>
#include <string>
using namespace std;

string convertToNumericMonth(string month);

int main() {
    string input;
    cin >> input;
    string date;
    string month;
    string year;
    int i =0;
    //get month
    while(input[i] != ','){
        month.push_back(input[i]);
        i++;
    }
    //get Date
    i++;
    while(input[i] != ','){
        date.push_back(input[i]);
        i++;
    }
    //get year
    i++;
    while(input[i] != '\0'){
        year.push_back(input[i]);
        i++;
    }
    if(month.length()>2){
        month = convertToNumericMonth(month);
    }
    cout << date + "/" + month + "/" + year;
    return 0;
}
/* function to convert typed out months into their corresponding numeric values */
string convertToNumericMonth(string month){
    string converted;
    switch (month[0])  {
        case 'J':
            if(month == "January"){
                converted="1";
            }else if(month == "June"){
                converted="6";
            }else {
                converted = "7";
            }
            break;

        case 'F':
            converted="2";
            break;
        case 'M':
            if(month == "March"){
                converted="3";
            } else{
                converted="5";
            }
            break;
        case 'A':
            if(month == "April"){
                converted="4";
            } else{
                converted="8";
            }
            break;
        case 'S':
            converted="9";
            break;
        case 'O':
            converted=10;
            break;
        case 'N':
            converted="11";
            break;
        case 'D':
            converted="12";
            break;
        default:
            converted = "ERROR INVALID MONTH";
    }
    return converted;
}