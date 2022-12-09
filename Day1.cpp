#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream p1;
    int elves = 1;
    int greatestElf;
    vector<int> totalCalories;
    p1.open("Day1.txt");
    if (p1.is_open()) {
        int tempCalories = 0;
        string current;
        int cint;
        while (getline(p1, current)) {
            //cout << current << endl;
            if (!current.empty()) {
                cint = stoi(current);
                tempCalories += cint;
                //if gathered calories are greater than last in list, place at end of list
                if (!totalCalories.empty() && tempCalories > totalCalories[totalCalories.size() - 1]) {
                    greatestElf = elves;
                } 
            } else {
                //cout << tempCalories << endl;
                //cout << "Empty line" << endl;
                elves++;
                totalCalories.push_back(tempCalories);
                tempCalories = 0;
            }
        }   
    }
    p1.close();
    sort(totalCalories.begin(), totalCalories.end());
    //cout << "First: " << totalCalories[totalCalories.size()-1] << ", Second: " << totalCalories[totalCalories.size()-2] << ", Third: " << totalCalories[totalCalories.size()-3] << endl;
    //cout << "Largest calories: " << totalCalories[totalCalories.size()-1] << ", Most burdened elf: " << greatestElf << endl;
    cout << "Sum of 3 most burdened elves: " << totalCalories[totalCalories.size()-1] + totalCalories[totalCalories.size()-2] + totalCalories[totalCalories.size()-3] << endl;
}