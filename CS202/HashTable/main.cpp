/**
* Author : Ali Eren Günaltýlý
* ID: 21801897
* Section : 01
* Assignment : 4
*/
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    ifstream infile("input.txt");
    string line;
    int num;
    int searchNum;
    char option;
    HashTable linear(25, HashTable::LINEAR);
    HashTable quad(25, HashTable::QUADRATIC);
    HashTable doub(25, HashTable::DOUBLE);
    while (getline(infile, line)) {  //reads the file line by line
        string temp;
        for (int i = 2; i < line.length(); i++) {
            if (line[i] != ' ')
                option = line[0];
                temp += line[i];
        }
        stringstream ss;
        ss << temp;
        ss >> num;

        if (option == 'I') {
            linear.insert(num);
            quad.insert(num);
            doub.insert(num);
        }
        else if (option == 'R') {
            linear.remove(num);
            quad.remove(num);
            doub.remove(num);
        }
        else if (option == 'S') {
            int tmp;
            int tmp1;
            int tmp2;
            bool flag =  linear.search(num, tmp);
            bool flag1 = quad.search(num, tmp1);
            bool flag2 = doub.search(num, tmp2);
            if (flag) {
                cout << "In linear, " << num <<" is founded at " << tmp << " probes." << endl;
                cout << "In quadratic, " << num <<" is founded at " << tmp1 << " probes." << endl;
                cout << "In double, " << num <<" is founded at " << tmp2 << " probes." << endl;
            }
            else {
                cout << "In linear, " << num << " is not founded at " << tmp << " probes." << endl;
                cout << "In quadratic, " << num << " is  not founded at " << tmp1 << " probes." << endl;
                cout << "In double, " << num << " is not founded at " << tmp2 << " probes." << endl;
            }
        }
        else {
            cout << "Invalid char operation choose " << endl;
        }
    }
    cout << "Table size for all tables is : " << linear.getSize() << endl;
    int s, u = 0;
    cout << "---------- Linear Table ------------" << endl;
    linear.display();
    linear.analyze(s, u);
    cout << "For linear suc : " << s << ", unsucc : " << u << endl;
    s = 0;
    u = 0;
    cout << "----------- Quadratic Table -----------" << endl;
    quad.display();
    cout << "---------------" << endl;
    quad.analyze(s, u);
    cout << "For quadratic suc : " << s << ", unsucc : " << u << endl;
    s = 0;
    u = 0;
    cout << "--------------Double Table----------------" << endl;
    doub.display();
    doub.analyze(s, u);
    cout << "For double suc : " << s << ", unsucc : " << u << endl;
        /*if (line[0] == 'I') { // this part reads the instruction
            table1.insert(num);
            table2.insert(num);
            table3.insert(num);
            cout << "------------" << endl;
        }

        if (line[0] == 'R') {
            table1.remove(num);
            table2.remove(num);
            table3.remove(num);
            cout << "------------" << endl;
        }

        if (line[0] == 'S') {
            table1.search(num, searchNum);
            table2.search(num, searchNum);
            table3.search(num, searchNum);
            cout << "------------" << endl;
        }
    }
    cout << "Linear Hash Table: " << endl;		//displays the results
    table1.display();
    cout << "Quadratic Hash Table: " << endl;
    table2.display();
    cout << "Double Hash Table: " << endl;
    table3.display();

    int succ, unSucc;
    table1.analyze(succ, unSucc);
    cout << "Linear successful searches: " << succ << " unsuccessful searches: " << unSucc << endl;
    table2.analyze(succ, unSucc);
    cout << "Quadratic successful searches: " << succ << " unsuccessful searches: " << unSucc << endl;
    table3.analyze(succ, unSucc);
    cout << "Double successful searches: " << succ << endl;

    */
    return 0;
}