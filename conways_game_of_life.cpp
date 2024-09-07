#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <random>

using namespace std;

vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                                 {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

void display(vector<vector<char>> &map) {
    for(auto row : map) {
        for(auto it : row)
            cout << it << " ";
        cout << endl;
    }
}

int getNeighborCount(vector<vector<char>>& map, int row, int col) {
    int n = map.size();
    int count = 0;
    for(int i = 0; i < 8; i++) {
        int nrow = (row + direction[i][0] + n) % n;
        int ncol = (col + direction[i][1] + n) % n;
        if(map[nrow][ncol] == '0')
            count++;
    }
    return count;
}

vector<vector<char>> generateSeed(int n, int startPos, int seedSize) {
    vector<vector<char>> map(n, vector<char>(n, ' '));
    vector<vector<char>> seed(seedSize, vector<char>(seedSize));

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < seedSize; ++i) {
        for (int j = 0; j < seedSize; ++j) {
            seed[i][j] = (dis(gen) == 1) ? '0' : ' ';
        }
    }

    for(int i = startPos; i < startPos + seedSize; i++) {
        for(int j = startPos; j < startPos + seedSize; j++) {
            map[i][j] = seed[i - startPos][j - startPos];
        }
    }

    return map;
}

void clear() {
    system("cls");
}

int main() {
    clear();
    int n, startPos, seedSize, duration;

    do {
        cout << "Enter the size of 2D array: ";
        cin >> n;
        if (n < 10 or n > 30)
            cout << "Error: The size of the 2D array must be between 10 and 30." << endl;
    } while (n < 10 or n > 30);

    do {
        cout << "Enter the size of seed (should be between 5 and 10): ";
        cin >> seedSize;
        if (seedSize < 5 || seedSize > 10)
            cout << "Error: The seed size must be between 5 and 10." << endl;
    } while (seedSize < 5 || seedSize > 10);

    do {
        cout << "Enter the starting position of the seed: ";
        cin >> startPos;
        if (startPos < 0 || startPos + seedSize > n)
            cout << "Error: Starting position must allow the seed to fit inside the array." << endl;
    } while (startPos < 0 || startPos + seedSize > n);

    do {
        cout << "Enter the duration for which the simulation should run: ";
        cin >> duration;
        if (duration <= 0)
            cout << "Error: The duration must be a positive integer." << endl;
    } while (duration <= 0);

    vector<vector<char>> map = generateSeed(n, startPos, seedSize);

    clear();
    cout << "First Generation" << endl;
    display(map);
    Sleep(2000);

    int timeElapsed = 1;

    while(duration--) {
        clear();
        vector<vector<char>> nextMap = map;
        int population = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int neighbors = getNeighborCount(map, i, j);

                if(map[i][j] == '0') {
                    if(neighbors < 2 || neighbors > 3)
                        nextMap[i][j] = ' ';
                    else
                        population++;
                } else {
                    if(neighbors == 3)
                        nextMap[i][j] = '0';
                    if(nextMap[i][j] == '0')
                        population++;
                }
            }
        }

        map = nextMap;
        cout << "Time Elapsed: " << timeElapsed << endl;
        cout << "Population: " << population << endl;
        if(population == 0)
            break;
        display(map);
        timeElapsed++;
        Sleep(200);
    }

    cout << "Last Generation" << endl;
    return 0;
}
