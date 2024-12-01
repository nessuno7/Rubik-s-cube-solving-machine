#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifndef  CUBIE
#define CUBIE

class Cubie{
    public:

    char colors[dim3]; 
    int position; //indicates the position that the cubie has in the solved state

    Cubie& operator=(const Cubie& copy);

    void insert_colors(char c1, char c2, char c3);

    void insert_position(int pos);

    void intialize_cubie(char c1, char c2, char c3, int pos);
};
#endif