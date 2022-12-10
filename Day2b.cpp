#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main() {
    ifstream rps;
    //A for rock (1 pt), B for paper (2 pt), C (3 pt)
    //X for lose, Y for draw, Z for win
    //+6 for winning, +3 for draw
    map<string, int> point_map;
    //lose and 3 pt for shape
    point_map.insert(pair<string, int>("A X", 3));
    //draw and 1 pt for shape
    point_map.insert(pair<string, int>("A Y", 4));
    //win and 2 pt for shape
    point_map.insert(pair<string, int>("A Z", 8));
    //lose and 1 pt for shape
    point_map.insert(pair<string, int>("B X", 1));
    //draw and 2 pt for shape
    point_map.insert(pair<string, int>("B Y", 5));
    //win and 3 pt for shape
    point_map.insert(pair<string, int>("B Z", 9));
    //lose and 2 pt for shape
    point_map.insert(pair<string, int>("C X", 2));
    //draw and 3 pt for shape
    point_map.insert(pair<string, int>("C Y", 6));
    //win and 1 pt for shape
    point_map.insert(pair<string, int>("C Z", 7));
    rps.open("Day2RPS.txt");
    if (rps.is_open()) {
        string current;
        int total_my_points = 0;
        while (getline(rps, current)) {
            total_my_points += point_map[current];
            if (total_my_points < 30) {
                //cout << "ORIGINAL: " << current << " My total points: " << total_my_points << endl;
            } 
        }
        cout << "My total points: " << total_my_points << endl;
    } else {
        cout << "Failed to open file." << endl;
    }
    rps.close();    
    return 0;
}