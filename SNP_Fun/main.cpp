#include <iostream>
#include "SNP_Fun.h"
#include <fstream>
using namespace std;

int main()
{
    SNP_Fun *Initial = new SNP_Fun(); //Create an instance for a "default" database

    Initial->initial_data(); //Creates the "default" database

    string userinput; //For user input

    SNP_Fun *User= new SNP_Fun(); //Create an instance for a "user" database

    while (userinput != "6")// main menu loop
    {
        cout	<<	"======Main Menu====="	<<	endl;
        cout	<<	"1. Enter your SNP file name"	<<	endl;
        cout	<<	"2. find an rsid"	<<	endl;
        cout	<<  "3. print rsid with matching genotype"	<<	endl;
        cout    <<  "4. find an rsid in User" << endl;
        cout    <<  "5. print all rsids for a chromosome" << endl;
        cout    <<  "6. Quit" << endl;


        getline(cin, userinput);

        if (userinput == "1")
        {
            string infile;
            cout	<<	"Enter your SNP file name"	<<	endl;
            getline(cin, infile);
            User->createMatrix(infile);
        }

        else if(userinput == "2")
        {
            string RSID_str;
            string chromo;
            string geno;

            cout << "Enter your SNP: ";
            getline(cin, RSID_str);

            cout << "Enter your chromosome: ";
            getline(cin, chromo);

            cout << "Enter your genotype: ";
            getline(cin, geno);
            cout << '\n';

            if(RSID_str == "" || chromo == "" || geno == "")
            {
                cout << "Please enter a valid SNP, chromosome, and genotype combination" << '\n';
            }
            else
            {
                Initial->retrieveRSID(RSID_str, stoi(chromo), geno);
            }
        }
        else if (userinput == "3")
        {
            string geno;

            cout << "Enter your genotype: ";
            getline(cin, geno);
            cout << '\n';

            User->printMatchingGeno(geno);
        }
        else if (userinput=="4")
        {
            string RSID_str;
            string chromo;
            string geno;

            cout << "Enter your SNP: ";
            getline(cin, RSID_str);

            cout << "Enter your chromosome: ";
            getline(cin, chromo);

            cout << "Enter your genotype: ";
            getline(cin, geno);
            cout << '\n';
            User->retrieveRSID(RSID_str, stoi(chromo), geno);
        }
        else if(userinput == "5")
        {
            string chromo1;
            cout << "Enter your chromosome: ";
            getline(cin, chromo1);
            int chromo = stoi(chromo1);

            User->printAllForChromosome(chromo);

        }

    }
    cout << "Goodbye!"<<endl;
    return 0;
}
