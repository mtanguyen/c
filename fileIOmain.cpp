//
//  File Name: fileIOmain.cpp
//  Course: COP3331 F 8-11am
//  Purpose: This program will read from or write to file asked by uer.
//  Created by My Nguyen on 03/29/17.
//  Copyright © 2017 My Nguyen. All rights reserved.
//

#include<iostream>
#include<fstream>
#include <string>
#include<iomanip>
using namespace std;

int main()
{
    // ifstream object
    ifstream inputFile;

    string fname; // String to hold filename.
    int count = 0;
    double number = 0;
    double sum = 0;
    double average = 0;

    // Ask user to input filename.
    cout << "Enter the filename: ";
    getline(cin, fname);
    inputFile.open(fname);

    //Test a file stream object to detect if an open operation failed using the fail member function.
    if (inputFile.fail())
    {
         cerr << "Error opening file. \n";
         return 0;
    }
    else
    {
        // Read the numbers from the file, count the numbers and add them.
        while (inputFile >> number)
        {
            sum += number;      //Add the numbers in file together.
            count++;            //Count number of numbers.
        }
    }

    //Find average of all numbers in file.
    average = sum / count;

    //Display results
    cout << "Number of numbers: " << count << endl;
    cout << "Sum of the numbers: " << sum << endl;
    cout << "Average of the numbers: " << setprecision(5) << average << endl;

    //Close file.
    inputFile.close();
    return 0;
}
