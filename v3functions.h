#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>
#include <sstream>
using namespace std;

vector <string> lineread;
vector <string> temp;

int linecount = 0;
int errorcount = 0;
const int columncount = 8; /// file column count
int filesize = 12345; /// file entry count
float vectortotaltime = 0;
string path = "";

void outputPath() {
    cout << "input file destination" << endl;
    cout << "example: C:/Users/.../" << endl;
    cin >> path;
}

void fileGenerator()
{
    ofstream file0(path + std::to_string(filesize) + ".txt");
    for (int x = 1; x < filesize + 1; x++) {
        file0 << ("vardas" + std::to_string(x)) << " " << ("pavarde" + std::to_string(x)) << " ";
        for (int y = 0; y < columncount - 2; y++)
        {
            file0 << to_string(rand() % 10 + 1) << " ";
        }
        file0 << "\n";
    }
    file0.close();
}


void readLine()
{
    string qwer;
    ifstream file;
    try {
        file.open(path + std::to_string(filesize) + ".txt");
        if (!file.is_open()) {
            throw 403;
        }
    }

    catch (int asd) {
        cout << "ERROR: missing file" << endl;
        std::terminate();
    }

    while (getline(file, qwer)) {
        if (qwer == "") {                 /// check for empty lines, skip to next line if empty found
            continue;
        }
        ::lineread.push_back(qwer);
        linecount++;
    }
    file.close();
}

void readStr(string a)
{
    string word;
    stringstream str(a);
    while (str >> word) {
        temp.push_back(word);
    }
}

class timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    timer() : start{ std::chrono::high_resolution_clock::now() } {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
    }
};
void idk(timer a, string type) {
    cout << std::to_string(filesize) + ".txt " << type << ":" << a.elapsed() << "s" << endl;
    vectortotaltime += a.elapsed();
}
