#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum class State {kEmpty, kObsacle};

vector <State> ParseLine(string line){
    istringstream sline(line);
    int n;
    char c;
    vector <State> row;
    while (sline >> n >> c && c == ','){
        if (n == 0){
            row.push_back(State::kEmpty);
        }else {
            row.push_back(State::kObsacle);
        }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path){
    ifstream myfile(path); // for streaming file : ifstream input file stream;
    vector <vector <State>> board {}; // vector of vectors to be returned ----> we need values returned from file as strings to be stored, in the form of vector
    if (myfile){
        string line;
        while (getline(myfile, line)){
            vector <State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(State cell){
    switch(cell){
        case State :: kObsacle : return "⛰️ ";
        default : return "0  "; 
    }
}

void PrintBoard(const vector<vector<State>> board){
    for (int i=0; i< board.size(); ++i){
        for(int j=0; j< board[i].size(); ++j ){
            cout << CellString(board[i][j]);
        }
    cout << endl;
    }
}


int main(){
    auto board = ReadBoardFile("test.txt");
    PrintBoard(board);
}