#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main() {
    ifstream rucksacks_in;
    rucksacks_in.open("Day3Rucksacks.txt");
    string current;
    string total;
    int priorities = 0;
    bool part1 = false;
    if (rucksacks_in.is_open() && part1) {
        while (getline(rucksacks_in, current)) {
            string first_half = current.substr(0, current.length()/2);
            string second_half = current.substr(current.length()/2);
            //cout << first_half << " " << second_half << endl;
            bool found = false;
            //cout << "First len: " << first_half.length() << " Second len: " << second_half.length() << endl;
            //N**2 time (Brute force), N space complexity
            for (int i = 0; i < first_half.length(); i++) {
                if (found) {
                    break;
                }
                for (int j = 0; j < second_half.length(); j++) {
                    if (first_half[i] == second_half[j]) {
                        total += first_half[i];
                        found = true;
                        break;
                    }
                }
            }
        }
    } else {
        cout << "Failed to open file for part 1." << endl;
    }
    int lineCount = 0;
    string lineOne;
    string lineTwo;
    string lineThree;
    map<char, int> sameChar_map;
    if (rucksacks_in.is_open() && !part1) {
        while (getline(rucksacks_in, current)) {
            lineCount++;
            switch (lineCount) {
            case 1:
                lineOne = current;
                break;
            case 2:
                lineTwo = current;
                break;
            case 3:
                lineThree = current;
                lineCount = 0;
                //Nlog(n) time complexity, N space complexity
                for (int i = 0; i < lineOne.length(); i++) {
                    char letter = lineOne[i];
                    sameChar_map.insert(pair<char, int>(letter, 0));
                    //cout << "Line one check " << sameChar_map[letter] << endl;
                }
                //cout << sameChar_map.size() << endl;
                for (int j = 0; j < lineTwo.length(); j++) {
                    char letter = lineTwo[j];
                    if (sameChar_map.count(letter)) {
                        sameChar_map[letter]++;
                        //cout << "Match from lineTwo found " << sameChar_map[letter] << endl;
                    }
                }
                //cout << sameChar_map.size() << endl;
                for (int k = 0; k < lineThree.length(); k++) {
                    char letter = lineThree[k];
                    if (sameChar_map.count(letter) && sameChar_map[letter] >= 1) {
                        total += letter;
                        //cout << "MATCH FOUND: " << letter << endl;
                        break;
                    }
                }
                //cout << sameChar_map.size() << endl;
                lineOne = "";
                lineTwo = "";
                lineThree = "";
                sameChar_map.clear();
                break;
            default:
                cout << "No case found" << endl;
                break;
            }
        }
    } else {
        cout << "Failed to open file for part 2." << endl;
    }
    //cout << total << " " << total.length() << endl;
    for (int k = 0; k < total.length(); k++) {
        //get ASCII value, convert
        int ascii = int(total[k]);
        if (isupper(ascii)) {
            priorities += ascii-38;
            //cout << ascii-38 << " UPPER" << endl;
        } else {
            priorities += ascii-96;
            //cout << ascii-96 << endl;
        }
    }
    cout << "Total priorities: " << priorities << endl; 
    rucksacks_in.close();    
    return 0;
}