#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#ifndef  F2l
#define F2l

class F2L{
    public:

    Cubie corners[dim8];
    Cubie edges[dim12];

    vector<string> moves;

    F2L();
    F2L(const F2L& copy);

    void add_move(string move);
    void erase_moves();

    void initialize_F2L();

    void conversion_cube_F2L(Cube cube);
    void conversion_array_F2L(char colors[]);

    void move_edges(int i1, int i2, int i3, int i4);
    void move_corners(int i1, int i2, int i3, int i4);
    void move_edges_2(int i1, int i2, int i3, int i4);
    void move_corners_2(int i1, int i2, int i3, int i4);

    F2L r();
	F2L R();
	F2L l();
	F2L L();
	F2L u();
	F2L U();
	F2L d();
	F2L D();
	F2L f();
	F2L F();
	F2L b();
	F2L B();
    F2L R2();
	F2L L2();
	F2L U2();
	F2L D2();
	F2L F2();
	F2L B2();

    F2L execute_move(string move);

    void scramble_f2l(vector<string> moves);

    void change_some_position_corner(int final_position, int position_to_move_to);
    void change_some_position_edge(int final_position, int position_to_move_to);

    bool is_goal_found(F2L goal);
    bool check_some_positions(vector<int> positions_to_check_corners, vector<int> positions_to_check_edges, F2L f2l);
    void return_states(queue<F2L>* frontier);
};
#endif