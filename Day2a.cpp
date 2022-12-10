#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main() {
    ifstream rps;
    //A or X for rock (1 pt), B or Y for paper (2 pt), C or Z for scissors (3 pt)
    //+6 for winning
    map<string, int> point_map;
    //Draw and 1 pt for shape
    point_map.insert(pair<string, int>("A X", 4));
    //I win and 2 pt for shape
    point_map.insert(pair<string, int>("A Y", 8));
    //I lose and 3 pt for shape
    point_map.insert(pair<string, int>("A Z", 3));
    //I lose and 1 pt for shape
    point_map.insert(pair<string, int>("B X", 1));
    //Draw and 2 pt for shape
    point_map.insert(pair<string, int>("B Y", 5));
    //I win and 3 pt for shape
    point_map.insert(pair<string, int>("B Z", 9));
    //I win and 1 pt for shape
    point_map.insert(pair<string, int>("C X", 7));
    //I lose and 2 pt for shape
    point_map.insert(pair<string, int>("C Y", 2));
    //Draw and 3 pt for shape
    point_map.insert(pair<string, int>("C Z", 6));
    rps.open("Day2RPS.txt");
    if (rps.is_open()) {
        string current;
        int total_my_points = 0;
        while (getline(rps, current)) {
            //cout << "1: " << current[0] << " 2: " << current[1] << " 3: " << current[2] << endl;
            total_my_points += point_map[current];
            if (total_my_points < 30) {
                cout << "ORIGINAL: " << current << " My total points: " << total_my_points << endl;
            } 
        }
        cout << "My total points: " << total_my_points << endl;
    } else {
        cout << "Failed to open file." << endl;
    }
    rps.close();    
    return 0;
}