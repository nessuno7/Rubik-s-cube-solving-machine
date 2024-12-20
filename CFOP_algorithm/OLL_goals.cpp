//moves are found at https://jperm.net/algs/2look/oll

/*
input: Cube object for current state, reference count of yellow edge faces, reference count of yellow corner faces 
output: void
counts how many corners and edges on the last layers have the yellow color orientated upwards 
*/
void count_yellow(Cube cube, int& count_e, int& count_c){
    count_c = 0;
    count_e = 0;

    if(cube.colors[0] == 'y'){
        count_c ++;
    }
    if(cube.colors[2] == 'y'){
        count_c ++;
    }
    if(cube.colors[5] == 'y'){
        count_c ++;
    }
    if(cube.colors[7] == 'y'){
        count_c ++;
    }
    if(cube.colors[1] == 'y'){
        count_e ++;
    }
    if(cube.colors[4] == 'y'){
        count_e ++;
    }
    if(cube.colors[6] == 'y'){
        count_e ++;
    }
    if(cube.colors[3] == 'y'){
        count_e ++;
    }
}

/*
input: Cube object current state
output: string vector of moves to reach the OLL (orient last layer) goal
finds the first and second algorithm for 2-look OLL and returns them as a string move vector
*/
vector<string> OLL_solve(Cube cube){

    int count_edges;
    int count_corners;
    count_yellow(cube, count_edges, count_corners);
    vector<string> moves;
    vector<string> moves_OLL;

    if(count_edges == 0){
        moves_OLL = {"F", "R", "U", "r", "u", "f", "B", "U", "L", "u", "l", "b"}; // dot shape
    }
    else if(count_edges == 2){
        if(cube.colors[1] == 'y' && cube.colors[6] == 'y'){
            moves_OLL = {"u", "F", "R", "U", "r", "u", "f"};//I shape to correct with u
        }
        else if(cube.colors[3] == 'y' && cube.colors[4] == 'y'){
            moves_OLL = {"F", "R", "U", "r", "u", "f"};//I shape
        }
        else if(cube.colors[4] == 'y' && cube.colors[6] == 'y'){
            moves_OLL = {"B", "U", "L", "u", "l", "b"};//L shape
        }
        else if(cube.colors[3] == 'y' && cube.colors[6] == 'y'){
            moves_OLL = {"u", "B", "U", "L", "u", "l", "b"};//L shape to correct with u
        }
        else if(cube.colors[3] == 'y' && cube.colors[1] == 'y'){
            moves_OLL = {"2U", "B", "U", "L", "u", "l", "b"};//L shape to corret with U2
        }
        else if(cube.colors[1] == 'y' && cube.colors[4] == 'y'){
            moves_OLL = {"U", "B", "U", "L", "u", "l", "b"};//L shape to correct with U
        }
        else{
            cout<<"Error: OLL I/L"<<endl;
            throw 201;
        }
    }
    else if(count_edges == 4){
        moves_OLL = {};
    }
    else{
        cout<<"Error: OLL first algorithm"<<endl;
        throw 69;
    }

    cube = cube.scramble_cube(moves_OLL);
    moves = moves_OLL;
    moves_OLL = {};
    count_yellow(cube, count_edges, count_corners);


    if(count_edges == 4){
        if(count_corners == 4){
            moves_OLL = {};
        }
        else if(count_corners == 0){
            if(cube.colors[8] == 'y' && cube.colors[10] == 'y' && cube.colors[32] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"U", "R", "U", "r", "U", "R", "u", "r", "U", "R", "2U", "r"};//H to correct with U
            }
            else if(cube.colors[18] == 'y' && cube.colors[16] == 'y' && cube.colors[24] == 'y' && cube.colors[26] == 'y'){
                moves_OLL = {"R", "U", "r", "U", "R", "u", "r", "U", "R", "2U", "r"};//H
            }
            else if(cube.colors[24] == 'y' && cube.colors[10] == 'y' && cube.colors[32] == 'y' && cube.colors[26] == 'y'){
                moves_OLL = {"R", "2U", "2R", "u", "2R", "u", "2R", "2U", "R"}; //Pi
            }
            else if(cube.colors[32] == 'y' && cube.colors[34] == 'y' && cube.colors[26] == 'y' && cube.colors[16] == 'y'){
                moves_OLL = {"u", "R", "2U", "2R", "u", "2R", "u", "2R", "2U", "R"};//Pi to correct with u
            }
            else if(cube.colors[18] == 'y' && cube.colors[16] == 'y' && cube.colors[8] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"2U", "R", "2U", "2R", "u", "2R", "u", "2R", "2U", "R"};//Pi to correct with U2
            }
            else if(cube.colors[8] == 'y' && cube.colors[10] == 'y' && cube.colors[18] == 'y' && cube.colors[24] == 'y'){
                moves_OLL = {"U", "R", "2U", "2R", "u", "2R", "u", "2R", "2U", "R"};//Pi to correct with U
            }
            else{
                cout<<"Error: OLL H/Pi"<<endl;
                throw 202;
            }
        }
        else if(count_corners == 1){
            if(cube.colors[8] == 'y' && cube.colors[16] == 'y' && cube.colors[24] == 'y'){
                moves_OLL = {"R", "2U", "r", "u", "R", "u", "r"};//Antisune
            }
            else if(cube.colors[8] == 'y' && cube.colors[24] == 'y' && cube.colors[32] == 'y'){
                moves_OLL = {"u", "R", "2U", "r", "u", "R", "u", "r"};//Antisune to correct with u
            }
            else if(cube.colors[24] == 'y' && cube.colors[16] == 'y' && cube.colors[32] == 'y'){
                moves_OLL = {"2U", "R", "2U", "r", "u", "R", "u", "r"};//Antisune to correct wit U2
            }
            else if(cube.colors[16] == 'y' && cube.colors[32] == 'y' && cube.colors[8] == 'y'){
                moves_OLL = {"U", "R", "2U", "r", "u", "R", "u", "r"};//Antisune to correct with U
            }
            else if(cube.colors[10] == 'y' && cube.colors[18] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"R", "U", "r", "U", "R", "2U", "r"};//Sune
            }
            else if(cube.colors[26] == 'y' && cube.colors[34] == 'y' && cube.colors[18] == 'y'){
                moves_OLL = {"U", "R", "U", "r", "U", "R", "2U", "r"};//Sune to correct with U
            }
            else if(cube.colors[26] == 'y' && cube.colors[10] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"2U", "R", "U", "r", "U", "R", "2U", "r"};//Sune to correct with U2
            }
            else if(cube.colors[26] == 'y' && cube.colors[10] == 'y' && cube.colors[18] == 'y'){
                moves_OLL = {"u", "R", "U", "r", "U", "R", "2U", "r"};//Sune to correct with u
            }
            else{
                cout<<"Error: OLL Antisune/Sune"<<endl;
                throw 203;
            }
        }
        else if(count_corners == 2){
            if(cube.colors[0] == 'y' && cube.colors[7] == 'y' && cube.colors[18] == 'y' && cube.colors[8] == 'y'){
                moves_OLL = {"F", "r", "f", "L", "F", "R", "f", "l"};//L
            }
            else if(cube.colors[0] == 'y' && cube.colors[7] == 'y' && cube.colors[32] == 'y' && cube.colors[26] == 'y'){ 
                moves_OLL = {"2U", "F", "r", "f", "L", "F", "R", "f", "l"};//L to correct with U2
            }
            else if(cube.colors[2] == 'y' && cube.colors[5] == 'y' && cube.colors[34] == 'y' && cube.colors[16] == 'y'){ 
                moves_OLL = {"U", "F", "r", "f", "L", "F", "R", "f", "l"};//L to correct with U
            }
            else if(cube.colors[2] == 'y' && cube.colors[5] == 'y' && cube.colors[24] == 'y' && cube.colors[10] == 'y'){ 
                moves_OLL = {"u", "F", "r", "f", "L", "F", "R", "f", "l"};//L to correct with u
            }
            else if(cube.colors[2] == 'y' && cube.colors[7] == 'y' && cube.colors[8] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"L", "F", "r", "f", "l", "F", "R", "f"};//T
            }
            else if(cube.colors[5] == 'y' && cube.colors[7] == 'y' && cube.colors[18] == 'y' && cube.colors[24] == 'y'){
                moves_OLL = {"u", "L", "F", "r", "f", "l", "F", "R", "f"};//T to correct with u
            }
            else if(cube.colors[0] == 'y' && cube.colors[5] == 'y' && cube.colors[10] == 'y' && cube.colors[32] == 'y'){
                moves_OLL = {"2U", "L", "F", "r", "f", "l", "F", "R", "f"};//T to correct with U2
            }
            else if(cube.colors[0] == 'y' && cube.colors[2] == 'y' && cube.colors[16] == 'y' && cube.colors[26] == 'y'){ 
                moves_OLL = {"U", "L", "F", "r", "f", "l", "F", "R", "f"};//T to correct with U
            }
            else if(cube.colors[7] == 'y' && cube.colors[2] == 'y' && cube.colors[24] == 'y' && cube.colors[26] == 'y'){
                moves_OLL = {"u", "2R", "D", "r", "2U", "R", "d", "r", "2U", "r"};//U to correct with u
            }
            else if(cube.colors[5] == 'y' && cube.colors[7] == 'y' && cube.colors[32] == 'y' && cube.colors[34] == 'y'){
                moves_OLL = {"2U", "2R", "D", "r", "2U", "R", "d", "r", "2U", "r"};//U to correct with U2
            }
            else if(cube.colors[0] == 'y' && cube.colors[5] == 'y' && cube.colors[16] == 'y' && cube.colors[18] == 'y'){
                moves_OLL = {"U", "2R", "D", "r", "2U", "R", "d", "r", "2U", "r"};//U to correct with U
            }
            else if(cube.colors[0] == 'y' && cube.colors[2] == 'y' && cube.colors[10] == 'y' && cube.colors[8] == 'y'){ 
                moves_OLL = {"2R", "D", "r", "2U", "R", "d", "r", "2U", "r"};//U
            }
            else{
                cout<<"Error: OLL L/T/U"<<endl;
                throw 204;
            }
        }
    }
    else{
        cout<<"Error: OLL second algorithm"<<endl;
        throw 205;
    }

    cube = cube.scramble_cube(moves_OLL);

    bool control = true;
    for(int i = 0; i<8; i++){
        if(cube.colors[i] != 'y'){
            control = false;
        }
    }

    if(control == false){
        cout<<"Error: OLL failed"<<endl;
        throw 206;
    }

    moves.insert(moves.end(), moves_OLL.begin(), moves_OLL.end());

    return moves;
}