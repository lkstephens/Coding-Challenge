#include <iostream>
#include <vector>
#include <string>
using namespace std;


int ConvertRomanToDecimal (string romNumeral) {
    int number = 0;
    if (romNumeral.find("CM") != string::npos) {
        number -= 200;
    }
    if (romNumeral.find("CD") != string::npos) {
        number -= 200;
    }
    if (romNumeral.find("XC") != string::npos) {
        number -= 20;
    }
    if (romNumeral.find("XL") != string::npos) {
        number -= 20;
    }
    if (romNumeral.find("IX") != string::npos) {
        number -= 2;
    }
    if (romNumeral.find("IV") != string::npos) {
        number -= 2;
    }
    while (romNumeral.find('M') != string::npos) {
        number += 1000;
        romNumeral.erase(romNumeral.find('M'), 1);
    }
    while (romNumeral.find('D') != string::npos) {
        number += 500;
        romNumeral.erase(romNumeral.find('D'), 1);
    }
    while (romNumeral.find('C') != string::npos) {
        number += 100;
        romNumeral.erase(romNumeral.find('C'), 1);
    }
    while (romNumeral.find('L') != string::npos) {
        number += 50;
        romNumeral.erase(romNumeral.find('L'), 1);
    }
    while (romNumeral.find('X') != string::npos) {
        number += 10;
        romNumeral.erase(romNumeral.find('X'), 1);
    }
    while (romNumeral.find('V') != string::npos) {
        number += 5;
        romNumeral.erase(romNumeral.find('V'), 1);
    }
    while (romNumeral.find('I') != string::npos) {
        number += 1;
        romNumeral.erase(romNumeral.find('I'), 1);
    }

    return number;
}

void ConvertThousandths (int nThousandths, vector<char> & nRomanNumerals) {
    if (nThousandths > 0 && nThousandths < 4) {
        for (int i = 0; i < nThousandths; i++) {
            nRomanNumerals.push_back('M');
        }
    }
}

void ConvertHundredths (int nHundredths, vector<char> & nRomanNumerals) {
    int i;
    if (nHundredths > 0 && nHundredths < 4) {
        for (i = 0; i < nHundredths; i++) {
            nRomanNumerals.push_back('C');
        }
    } else if (nHundredths == 4) {
        nRomanNumerals.push_back('C');
        nRomanNumerals.push_back('D');
    } else if (nHundredths > 4 && nHundredths < 9) {
        nRomanNumerals.push_back('D');
        for (i = 5; i < nHundredths; i++) {
            nRomanNumerals.push_back('C');
        }
    } else if (nHundredths == 9) {
        nRomanNumerals.push_back('C');
        nRomanNumerals.push_back('M');
    }
}

void ConvertTenths (int nTenths, vector<char> & nRomanNumerals) {
    int i;
    if (nTenths > 0 && nTenths < 4) {
        for (i = 0; i < nTenths; i++) {
            nRomanNumerals.push_back('X');
        }
    } else if (nTenths == 4) {
        nRomanNumerals.push_back('X');
        nRomanNumerals.push_back('L');
    } else if (nTenths > 4 && nTenths < 9) {
        nRomanNumerals.push_back('L');
        for (i = 5; i < nTenths; i++) {
            nRomanNumerals.push_back('X');
        }
    } else if (nTenths == 9) {
        nRomanNumerals.push_back('X');
        nRomanNumerals.push_back('C');
    }
}

void ConvertOnes (int nOnes, vector<char> & nRomanNumerals) {
    int i;
    if (nOnes > 0 && nOnes < 4) {
        for (i = 0; i < nOnes; i++) {
            nRomanNumerals.push_back('I');
        }
    } else if (nOnes == 4) {
        nRomanNumerals.push_back('I');
        nRomanNumerals.push_back('V');
    } else if (nOnes > 4 && nOnes < 9) {
        nRomanNumerals.push_back('V');
        for (i = 5; i < nOnes; i++) {
            nRomanNumerals.push_back('I');
        }
    } else if (nOnes == 9) {
        nRomanNumerals.push_back('I');
        nRomanNumerals.push_back('X');
    }
}

int main() {
    string romanNumeral;
    vector<char> newRomanNumerals;
    int numThousandths = 0;
    int numHundredths = 0;
    int numTenths = 0;
    int numOnes = 0;
    unsigned int i;

    //Convert Roman to Decimal

    cout << "Roman Numeral Converter" << endl << endl;
    cout << "Enter Roman Numeral: ";
    cin >> romanNumeral;
    cout << endl << "Number: " << ConvertRomanToDecimal(romanNumeral) << endl << endl;


    //Convert Decimal to Roman with Input

    cout << "Enter number in the thousandths place (0-3): ";              //ConvertThousandths
    cin >> numThousandths;
    cout << endl;
    if (numThousandths > 3) {
        cout << "Number not in range. Run program again.";
        return 1;
    } else {
        ConvertThousandths(numThousandths, newRomanNumerals);
    }


    cout << "Enter number in the hundredths place (0-9): ";               //ConvertHundredths
    cin >> numHundredths;
    cout << endl;
    if (numHundredths < 0 || numHundredths > 9) {
        cout << "Number not in range. Run program again." << endl;
        return 1;
    } else {
        ConvertHundredths(numHundredths, newRomanNumerals);
    }


    cout << "Enter number in the tenths place: ";                        //ConvertTenths
    cin >> numTenths;
    cout << endl;
    if (numTenths < 0 || numTenths > 9) {
        cout << "Number not in range. Run program again." << endl;
        return 1;
    } else {
        ConvertTenths(numTenths, newRomanNumerals);
    }


    cout << "Enter number in the ones place: ";                          //ConvertOnes
    cin >> numOnes;
    cout << endl;
    if (numOnes < 0 || numOnes > 9) {
        cout << "Number not in range. Run program again." << endl;
        return 1;
    } else {
        ConvertOnes(numOnes, newRomanNumerals);
    }


    cout << "Roman Numeral is: ";                                        //Print Roman Numerals
    for (i = 0; i < newRomanNumerals.size(); i++) {
        cout << newRomanNumerals.at(i);
    } cout << endl;


    return 0;
}
