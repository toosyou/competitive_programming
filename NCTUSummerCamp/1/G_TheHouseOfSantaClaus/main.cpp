#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*
    //make the connectivity list
    int possibility[9]={1,1,2,2,3,3,4,5,5};
    vector< vector<bool> > connectivity(6);
    for(int i=0;i<6;++i){
        connectivity[i].resize(6,false);
    }
    connectivity[1][2] = connectivity[1][3] = connectivity[1][5] = true;
    connectivity[2][1] = connectivity[2][3] = connectivity[2][5] = true;
    connectivity[3][1] = connectivity[3][2] = connectivity[3][4] = connectivity[3][5] = true;
    connectivity[4][3] = connectivity[4][5] = true;
    connectivity[5][1] = connectivity[5][2] = connectivity[5][3] = connectivity[5][4] = true;

    //check all permutation
    do{
        bool this_possibility_good = true;

        if(possibility[0] != 1)
            break;

        bool select[6][6];
        for(int i=0;i<6;++i){
            for(int j=0;j<6;++j){
                select[i][j] = false;
            }
        }

        for(int i=0;i<8;++i){

            int first_node = possibility[i];
            int second_node = possibility[i+1];

            if(first_node > second_node)//make first < second
                swap(first_node,second_node);

            if(connectivity[first_node][second_node] == false || select[first_node][second_node] == true){
                this_possibility_good = false;
                break;
            }

            select[first_node][second_node] = true;
        }
        if(this_possibility_good){
            for(int i=0;i<9;++i){
                printf("%d",possibility[i]);
            }
            printf("\n");
        }
    }while(next_permutation(possibility,possibility+9));*/

    printf("123153452\n123154352\n123451352\n123453152\n123513452\n123543152\n125134532\n125135432\n125315432\n125345132\n125431532\n125435132\n132153452\n132154352\n132534512\n132543512\n134512352\n134512532\n134521532\n134523512\n134532152\n134532512\n135123452\n135125432\n135215432\n135234512\n135432152\n135432512\n152134532\n152135432\n152345312\n152354312\n153123452\n153125432\n153213452\n153254312\n153452132\n153452312\n154312352\n154312532\n154321352\n154325312\n154352132\n154352312\n");

    return 0;
}

