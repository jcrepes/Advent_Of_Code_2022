#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    ifstream rangesfin;
    string current;
    int totalContaining = 0;
    int totalOverlapping = 0;
    rangesfin.open("Day4Ranges.txt");
    if (rangesfin.is_open()) {
        while (getline(rangesfin, current)) {
            int firstNum = 0;
            int secondNum = 0;
            int thirdNum = 0;
            int fourthNum = 0;
            string sfirstNum;
            string ssecondNum;
            string sthirdNum;
            string sfourthNum;
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '-' && current[i] != ',') {
                    if (firstNum == 0) {
                        sfirstNum += current[i];
                    } else if (secondNum == 0) {
                        ssecondNum += current[i];
                    } else if (thirdNum == 0) {
                        sthirdNum += current[i];
                    } else {
                        sfourthNum += current[i];
                        fourthNum = stoi(sfourthNum);
                    } 
                } else {
                    if (firstNum == 0) {
                        //cout << "FirstNum test: " << sfirstNum << endl;
                        firstNum = stoi(sfirstNum);
                        //cout << firstNum << endl;
                    } else if (secondNum == 0) {
                        //cout << "SecondNum test: " << ssecondNum << endl;
                        secondNum = stoi(ssecondNum);
                    } else {
                        //cout << "ThirdNum test: " << sthirdNum << endl;
                        thirdNum = stoi(sthirdNum);
                    }
                }
                
            }
            if ((firstNum <= thirdNum && secondNum >= fourthNum) || (thirdNum <= firstNum && fourthNum >= secondNum)) {
                //cout << "Range Overlap " << endl;
                totalContaining++;
            }
            //PART 2
            if ((firstNum <= thirdNum && thirdNum <= secondNum) || (firstNum <= fourthNum && fourthNum <= secondNum) || (thirdNum <= firstNum && firstNum <= fourthNum) || (thirdNum <= secondNum && secondNum <= fourthNum)) {
                totalOverlapping++;
            }
            //cout << "First: " << firstNum << " Second: " << secondNum << " Third: " << thirdNum << " Fourth: " << fourthNum << endl;
        }
    } else {
        cout << "Failed to open file." << endl;
    }
    cout << "Total Containing: " << totalContaining << endl;
    cout << "Total Overlapping: " << totalOverlapping << endl;
    return 0;
}