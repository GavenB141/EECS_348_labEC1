#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Take in a string and parse it to a number
double extractNumeric(const string& str) {
    int i = 0;
    char sign = '+';

    double output = 0;

    // check for a sign character
    if (str[0] == '-') {
        sign = '-';
        i++;
    } else if (str[0] == '+') {
        i++;
    }

    bool in_mantissa = false;
    int divisor = 1;

    // Iterate through the rest
    for(; i < str.length(); i++) {
        // Check for digit using ascii values and append
        if (str[i] >= 48 && str[i] <= 57) {
            output *= 10;
            output += str[i] - 48;

            // Multiply divisor if after decimal point
            if (in_mantissa) {
                divisor *= 10;
            }
        } else if (str[i] == '.') {
            // recognize decimal point
            in_mantissa = true;
        } else {
            // invalid character found
            return -999999.99;
        }
    }

    // Apply all characteristics
    output /= divisor;
    if (sign == '-') {
        output *= -1;
    }
    return output;
}

int main () {
    string input;

    while(true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
