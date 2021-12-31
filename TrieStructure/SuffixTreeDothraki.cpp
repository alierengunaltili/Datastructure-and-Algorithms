// SuffixTreeDothraki.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include "Trie.h"

void readInput(string fileName, Trie* trie);

int main(int argc, char* argv[])
{
    char* outputPath = argv[2];
    freopen(outputPath, "w", stdout);
    Trie trie;
    readInput(argv[1], &trie);
    freopen("CON", "w", stdout);
}

void readInput(string fileName, Trie* trie) {
    string line = "\n";
    fstream inputFile;
    inputFile.open(fileName.c_str());
    while (getline(inputFile, line)) {
        if (line.find("insert") != std::string::npos) {
            string key;
            string value;
            size_t firstBrackets = line.find('(');
            size_t comma = line.find(',');
            size_t lastBrackets = line.find(')');
            for (int i = firstBrackets + 1; i < comma; i++)
                key += line[i];
            for (int i = comma + 1; i < lastBrackets; i++)
                value += line[i];
            trie->insert(key, value);
        }
        if (line.find("search") != std::string::npos) {
            size_t firstBrackets = line.find('(');
            size_t lastBrackets = line.find(')');
            string key;
            for (int i = firstBrackets + 1; i < lastBrackets; i++)
                key += line[i];
            trie->search(key);
        }
        if (line.find("delete") != std::string::npos) {
            size_t firstBrackets = line.find('(');
            size_t lastBrackets = line.find(')');
            string key;
            for (int i = firstBrackets + 1; i < lastBrackets; i++)
                key += line[i];
            trie->deleteWord(key);
        }
        if (line.find("list") != std::string::npos) {
            trie->travel();
        }
    }
}
