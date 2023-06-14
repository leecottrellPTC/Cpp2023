#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

#define NODES 7
string nodeNames[NODES] = {"ERI", "MDT", "LBE","PHL", 
    "PIT", "UNV", "AVP"};
void initilizeArray(int matrix[NODES][NODES]){
    for(int row = 0; row < NODES; row++){
        for(int col = 0; col < NODES; col++){
            matrix[row][col] = 0;
        }   //end col
    }   //end row
}//end init

void initilizeRandomArray(int matrix[NODES][NODES]){
    for(int row = 0; row < NODES; row++){
        for(int col = 0; col < NODES; col++){
            if(row == col){
                matrix[row][col] = 0;   
                //no self links
            }
            else{
                //undirected graph
                matrix[row][col] = int(rand() %2);  //get 0 or 1
                matrix[col][row] = matrix[row][col];  //get 0 or 1
                //setKnownConnection(matrix, row, col,int(rand() %2);
            }

        }   //end col
    }   //end row
}//end init


void displayMatrix(int matrix[NODES][NODES]){
    cout << "-----";
    for(int row = 0; row < NODES; row ++){
        cout <<setw(5) << nodeNames[row];
    }
    cout << endl;
    for(int row = 0; row < NODES; row++){
        cout << setw(5) << nodeNames[row];
        for(int col = 0; col < NODES; col++){
           cout << setw(5) << matrix[row][col];
        }   //end col
        cout << endl;
    }   //end row
}

void setKnownConnection(int matrix[NODES][NODES],int row, int col, 
    bool directed = false){
    matrix[row][col] = 1;
    if(directed == false){
        matrix[col][row] = 1;
    }
}

void showAllConnectionsFromNode(int matrix[NODES][NODES], int node){
    int startNode = node;       //hold onto original node
    queue<int> links;           //places to visit
    set<string> connections;    //names of connected airports
    set<string>::iterator conItr;
    bool visited[NODES] = {false, false, false, false, false, false, false};//7 false
    links.push(node);       //put the starting location in teh queue
    visited[node] = true;   //set first node as visited
    while(!links.empty()){
        node = links.front();
        links.pop();
        for(int col =0; col < NODES; col++){
            if(matrix[node][col] == 1 && visited[col] == false){
                //cout << nodeNames[col];
                links.push(col);
                visited[col] = true;
                connections.insert(nodeNames[col]);
            }//end if
        }//end for
    }//end while
    cout << nodeNames[startNode] << " is connected to ";
    for(conItr = connections.begin(); conItr != connections.end(); conItr++){
        cout << *conItr << " ";
    }
}
int main(){
    srand(time(NULL));
    int matrix[NODES][NODES];
    initilizeArray(matrix);
    //initilizeRandomArray(matrix);
    // setKnownConnection(matrix, 0, 1);
    // setKnownConnection(matrix, 2, 3);
    // setKnownConnection(matrix, 3, 4, true);
    setKnownConnection(matrix, 1, 2);
    setKnownConnection(matrix, 4, 3);
    setKnownConnection(matrix, 4, 1);
    setKnownConnection(matrix, 5, 6);
    setKnownConnection(matrix, 0, 1);

    displayMatrix(matrix);
    showAllConnectionsFromNode(matrix, 0);

}


