#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string convertToNumericMonth(string month);
string convertToNumericMonthNoSwitch(string month);

int main() {
    string input;
    cout << "Please type in the date you want to convert" << endl;
    getline(cin,input);
    string date;
    string month;
    string year;
    int i =0;
    //get month
    while(input[i] != ',' && input[i] != ' ' && input[i] != '/'){
        month.push_back(input[i]);
        i++;
    }
    //get Date
    i++;
    while(input[i] != ',' && input[i] != ' ' && input[i] != '/'){
        date.push_back(input[i]);
        i++;
    }
    //get year
    i++;
    while(input[i] != '\0' && input[i] != '.'){
        year.push_back(input[i]);
        i++;
    }
    if(month.length()>2) {
        cout << "You have used an input containing a non numeric month. Select your conversion method [1]Switch Case [2]If using string array." << endl <<"For no conversion just press enter" << endl;
        int selected;
        cin >> selected;
        switch (selected) {
            case 1:
                month = convertToNumericMonth(month);
                break;
            case 2:
                month = convertToNumericMonthNoSwitch(month);
                break;

        }
    }

    if(year[0] == ' '){
        year.erase(0,1);
    }
    cout << date + "/" + month + "/" + year;
    return 0;
}

string convertToNumericMonthNoSwitch(string month){
    string converted;
    string months [12] = {"January","February","March","April","May","June","July","August","September", "October", "November", "December"};
    for(int i ; i<12; i++){
        if(month == months[i]){
            int conv = i+1;
            stringstream convString;
            convString << conv;
            converted = convString.str();
        }
    }
    return converted;
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