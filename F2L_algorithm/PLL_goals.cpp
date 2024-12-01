//moves are found here https://jperm.net/algs/2look/pll

/*
input: Cube object current state
output: Cube with move applied
executes the 2-look PLL algorithm and return the modified cube
*/
Cube diag(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"F", "R", "u", "r", "u", "R", "U", "r", "f", "R", "U", "r", "u", "r", "F", "R", "f"};
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}
Cube headl(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"R", "U", "r", "u", "r", "F", "2R", "u", "r", "u", "R", "U", "r", "f"};
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}
Cube H(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"2L", "2R", "D", "2L", "2R", "2U", "2L", "2R", "D", "2L", "2R"} ;
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}
Cube Ua(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"R", "u", "R", "U", "R", "U", "R", "u", "r", "u", "2R"};
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}
Cube Ub(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"2R", "U", "R", "U", "r", "u", "r", "u", "r", "U", "r"};
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}
Cube Z(Cube cube){
    Cube appoggio_cube(cube);

    vector<string> move_;
    move_ = {"R", "l", "B", "2L", "2R", "F", "2L", "2R", "B", "R", "l", "2D", "2L", "2R"};
    appoggio_cube = appoggio_cube.scramble_cube(move_);
    appoggio_cube.moves.insert(appoggio_cube.moves.end(), move_.begin(), move_.end());

    return appoggio_cube;
}

/*
input: Cube object current state 
output: bool
returns true if the last layer is permuted correctly
*/
bool check_corners_PLL(Cube cube){
    if(cube.colors[10] != 'r'){
        return false;
    }
    if(cube.colors[8] != 'r'){
        return false;
    }
    if(cube.colors[24] != 'b'){
        return false;
    }
    if(cube.colors[26] != 'b'){
        return false;
    }
    if(cube.colors[32] != 'o'){
        return false;
    }
    if(cube.colors[34] != 'o'){
        return false;
    }
    if(cube.colors[16] != 'g'){
        return false;
    }
    if(cube.colors[18] != 'g'){
        return false;
    }

    return true;
}

/*
input: Cube object current state
output: bool
function checks all the colors of the Cube, if Cube matches the solved state returns true
*/
bool check_goal_PLL(Cube cube){
    for(int i=0; i<8; i++){
        if(cube.colors[i] != 'y'){
            return false;
        }
    }

    for(int i=8; i<16; i++){
        if(cube.colors[i] != 'r'){
            return false;
        }
    }

    for(int i=16; i<24; i++){
        if(cube.colors[i] != 'g'){
            return false;
        }
    }

    for(int i=24; i<32; i++){
        if(cube.colors[i] != 'b'){
            return false;
        }
    }

    for(int i=32; i<40; i++){
        if(cube.colors[i] != 'o'){
            return false;
        }
    }

    for(int i=40; i<48; i++){
        if(cube.colors[i] != 'w'){
            return false;
        }
    }

    return true;
}

/*
input: Cube object current state, Cube object goal state
output: string vector of moves
finds the vector of moves for the 2-look PLL and returns it
*/
vector<string> PLL_search(Cube current_state, Cube goal_state){
    if(current_state == goal_state){
        return current_state.moves;
    }
    else{
        vector<Cube> frontier;
        Cube goal_PLL_1(current_state);

        frontier.push_back(execute_move("U", current_state));
        frontier.back().add_move_end("U");
        frontier.push_back(execute_move("u", current_state));
        frontier.back().add_move_end("u");
        frontier.push_back(execute_move("2U", current_state));
        frontier.back().add_move_end("2U");
        frontier.push_back(current_state);

        int size = frontier.size();
        
        for(int i=0; i<size; i++){
            frontier.push_back(diag(frontier[i]));
            frontier.push_back(headl(frontier[i]));
        }

        int size2 = frontier.size();

        for(int i=size; i<size2; i++){
            frontier.push_back(execute_move("U", frontier[i]));
            frontier.back().add_move_end("U");
            frontier.push_back(execute_move("u", frontier[i]));
            frontier.back().add_move_end("u");
            frontier.push_back(execute_move("2U", frontier[i]));
            frontier.back().add_move_end("2U");
            frontier.push_back(frontier[i]);
        }

        for(int i = 0; i<frontier.size(); i++){
            if(check_corners_PLL(frontier[i]) == true){
                goal_PLL_1 = frontier[i];
                goal_PLL_1.moves = frontier[i].moves;
                break;
            }
        }

        if(goal_PLL_1 == goal_state){
            return goal_PLL_1.moves;
        }
        else{
            frontier = {};

            frontier.push_back(execute_move("U", goal_PLL_1));
            frontier.back().add_move_end("U");
            frontier.push_back(execute_move("u", goal_PLL_1));
            frontier.back().add_move_end("u");
            frontier.push_back(execute_move("2U", goal_PLL_1));
            frontier.back().add_move_end("2U");
            frontier.push_back(goal_PLL_1);
            
            size = frontier.size();

            for(int i=0; i<size; i++){
                frontier.push_back(H(frontier[i]));
                frontier.push_back(Ua(frontier[i]));
                frontier.push_back(Ub(frontier[i]));
                frontier.push_back(Z(frontier[i]));
            }

            size2 = frontier.size();

            for(int i = size; i < size2; i++){
                frontier.push_back(execute_move("U", frontier[i]));
                frontier.back().add_move_end("U");
                frontier.push_back(execute_move("u", frontier[i]));
                frontier.back().add_move_end("u");
                frontier.push_back(execute_move("2U", frontier[i]));
                frontier.back().add_move_end("2U");
                frontier.push_back(frontier[i]);
            }

            for(int i = 0; i<frontier.size(); i++){
                if(check_goal_PLL(frontier[i]) == true){
                    return frontier[i].moves;
                }
            }

            cout<<"Error: PLL failed"<<endl;
            throw 300;
        }
    }

    return {"0"};
}
