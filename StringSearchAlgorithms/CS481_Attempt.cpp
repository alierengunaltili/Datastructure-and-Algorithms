// MWE for argh.h by Adi Shavit (github.com/adishavit)
// compile with: g++ example.cpp
// run with: ./a.out -i III -o OOO -f FFF -v
#pragma warning(disable : 4996)


#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include "argh.h"
#include <fstream>
using namespace std;

#define IS_LINEBREAK(ch) (ch == '\n' || ch == '\r')

void fill_buffer(char** buffer, string filename);
int BM(string p, string t, int& comp);
int bruteForce(string p, string t, int& comp);
void createPiTable(string p, int p_len, int* pi);
int KMPSearch(string p, string t, int& comp);



int main(int argc, char* argv[])
{
	argh::parser cmdl;
	cmdl.parse(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

	if (cmdl["-v"]) // check for flags with []
		cout << "verbose enabled." << endl;
	string i, o, a;
	cmdl("-i") >> i; // i = text
	cmdl("-a") >> a; // o = a value
	cmdl("-o") >> o; // f = pattern
    char* dna = NULL;
    fill_buffer((char**)&dna, i);
    string t = dna;
    char* pattern;
    fill_buffer((char**)&pattern, o);
    string p = pattern;
    char* value;
    clock_t tStart = clock();
    /* Do your stuff here */
    string a1 = a;
    int index = 0;
    int comp = 0;

    if (a1 == ("BM")) {
        auto start = chrono::high_resolution_clock::now();
        index = BM(p, t, comp);
        cout << "Boyern Moore: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        time_taken *= 1e-9;
        time_taken = time_taken * 1000;
        cout << "Runtime was " << fixed
            << time_taken << "ms. " << endl;
    }
    else if (a1 == ("KMP")) {
        auto start1 = chrono::high_resolution_clock::now();
        index = KMPSearch(p, t, comp);
        cout << "Knuth-Morris-Pratt: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end1 = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

        time_taken *= 1e-9;
        time_taken = time_taken * 1000;
        cout << "Runtime was " << fixed
            << time_taken << "ms. " << endl;
    }
    else if (a1 ==("BF")) {
        auto start2 = chrono::high_resolution_clock::now();
        index = bruteForce(p, t, comp);
        cout << "Brute Force: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end2 = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
        time_taken *= 1e-9;
        time_taken = time_taken * 1000;
        cout << "Runtime was " << fixed
            << time_taken << "ms. " << endl;
    }
    else if (a1 == ("A")) {
        comp = 0;
        auto start3 = chrono::high_resolution_clock::now();
        index = bruteForce(p, t, comp);
        cout << "Brute Force: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end3 = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken1 =
            chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
        time_taken1 *= 1e-9;
        time_taken1 = time_taken1 * 1000;
        cout << "Runtime was " << fixed
            << time_taken1 << "ms. " << endl;
        cout << "-----------------" << endl;
        comp = 0;
        auto start4 = chrono::high_resolution_clock::now();
        index = KMPSearch(p, t, comp);
        cout << "Knuth-Morris-Pratt: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end4 = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken2 =
            chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();

        time_taken2 *= 1e-9;
        time_taken2 = time_taken2 * 1000;
        cout << "Runtime was " << fixed
            << time_taken2 << "ms. " << endl;
        cout << "----------------------" << endl;

        comp = 0;
        auto start5 = chrono::high_resolution_clock::now();
        index = BM(p, t, comp);
        cout << "Boyern Moore: " << endl;
        cout << "pattern was found in query file at position " << index << endl;
        cout << comp << " character comparisons performed. " << endl;
        auto end5 = chrono::high_resolution_clock::now();
        // Calculating total time taken by the program.
        double time_taken3 =
            chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();

        time_taken3 *= 1e-9;
        time_taken3 = time_taken3 * 1000;
        cout << "Runtime was " << fixed
            << time_taken3 << "ms. " << endl;
        cout << "--------------------" << endl;

        if (time_taken1 < time_taken2) {
            if (time_taken1 < time_taken3) {
                cout << "Best algorithm was Brute Force. " << endl;
            }
            else {
                cout << "Best algorithm was Boyern Moore." << endl;
            }
        }
        else {
            if (time_taken2 < time_taken3) {
                cout << "Best algorithm was Knuth-Morris-Pratt. " << endl;
            }
            else {
                cout << "Best algorithm was Boyern Moore. " << endl;
            }
        }
    }
	return 0;
}



void fill_buffer(char** buffer, string filename)
{
    FILE* fp = NULL;
    const char* c = filename.c_str();
    fp = fopen(c, "r");

    if (fp == NULL)
    {
        printf("file cannot be opened...\n");
        exit(1);
    }

    while (fgetc(fp) != '\n') {}

    // get number of characters
    unsigned int num_of_chs = 0;
    char ch;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (!(IS_LINEBREAK(ch) || ch == EOF))
        {
            num_of_chs++;
        }
    }
    *buffer = (char*)malloc(sizeof(char) * (num_of_chs + 1));

    rewind(fp);

    while (fgetc(fp) != '\n') {}

    // fill buffer
    unsigned int i = 0;
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (!(IS_LINEBREAK(ch) || ch == EOF))
        {
            *(*buffer + i) = ch;
        }
        ++i;
    }
    *(*buffer + i - 1) = '\0'; // i - 1 to undo last increment

    fclose(fp);
}


int BM(string p, string t, int& comp) {
    int* badChar = new int[4];

    for (int i = 0; i < 4; i++) {
        badChar[i] = t.length();
    }
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'A') {
            badChar[0] = i;
        }
        else if (p[i] == 'C') {
            badChar[1] = i;
        }
        else if (p[i] == 'T') {
            badChar[2] = i;
        }
        else {
            //case p[i] == G
            badChar[3] = i;
        }
    }
    int shift = 0;
    while (shift <= (t.length() - p.length())) {
        int j = p.length() - 1; //start to try from the rightside of the pattern.

        while (j >= 0 && (p[j] == t[shift + j])) {
            comp++;
            j--;
        }

        if (j >= 0) {
            comp++;
            if (t[shift + j] == 'A') {
                if (j > badChar[0]) {
                    shift = shift + (j - badChar[0]);
                }
                else {
                    shift++;
                }
            }
            else if (t[shift + j] == 'C') {
                if (j > badChar[1]) {
                    shift = shift + (j - badChar[1]);
                }
                else {
                    shift++;
                }
            }
            else if (t[shift + j] == 'T') {
                if (j > badChar[2]) {
                    shift = shift + (j - badChar[2]);
                }
                else {
                    shift++;
                }
            }
            else {
                if (j > badChar[3]) {
                    shift = shift + (j - badChar[3]);
                }
                else {
                    shift++;
                }
            }
        }
        else {
            return shift + 1;
        }
    }
    return -1;
}

int bruteForce(string p, string t, int& comp) {
    int p_length = p.length();
    int t_length = t.length();
    int flag = 0;
    for (int i = 0; i < t_length; i++) {
        flag = 0;
        for (int j = 0; j < p_length; j++) {
            comp++;
            if (p[j] == t[i + j]) {
                flag++;
                if (flag == p_length) {
                    comp++;
                    return i + 1;
                }
            }
            else {
                break;
            }
        }
    }
}


void createPiTable(string p, int p_len, int* pi) {
    int tmp = 0;
    pi[0] = 0;
    int i = 1;
    while (i < p_len) {
        if (p[i] != p[tmp]) {
            if (tmp == 0) {
                pi[i] = 0;
                i++;
            }
            else {
                tmp = pi[tmp - 1];
            }
        }
        else {
            pi[i] = ++tmp;
            i++;
        }
    }
}
// Prints occurrences of txt[] in pat[]
int KMPSearch(string p, string t, int& comp)
{
    int M = p.length();
    int N = t.length();


    int* lps = new int[M];
    createPiTable(p, M, lps);

    int i = 0; // index for t
    int j = 0; // index for p

    while (i < N) {
        comp++;
        if (p[j] == t[i]) {
            j++;
            i++;
        }

        if (j == M) {
            int index = i - j;
            return i - j + 1;

        }

        else if (i < N && p[j] != t[i]) {
            if (j == 0) {
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
    }
}
