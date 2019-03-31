#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "def.h"

/*This is just a game test about picking plants or 
something, I guess... Maybe I'll actually comment
this code but thats highly unlikely.*/

//dimensions of the grid of the printed field
//0 is generation level, 1 is 'map', 2 is player and structures(?)
char matrix[GRIDX][GRIDY][3]; 
int comp_matrix[GRIDX][GRIDY];

//inventory buffer string
char *BUF =" || ";

//inventory of collected items
char *invent[20];

//sets up field and inventory
void setup();

//'*M*att' *rand*om, just a rand function to serve my needs for this
int mrand();

//converts an int value to a char to represent a flower
char itoflr(int in);

void printout();

int main(int argc, char *argv[]){

    if(argc==1){
        srand(rand());
    }else if(argc==2){
        srand(atoi(argv[1]));
    }else{
        printf("args broke homie...");
        return 1;
    }

    setup();
    printout();

    return 0;
}

int mrand(){
    return rand() / (RAND_MAX / (QUANT - 0 + 1) + 1);
}

char itoflr(int in){
    switch (in){

        case 0:
            return ',';

        case 1:
            return '\"';

        case 2:
            return '*';

        case 3:
            return '#';

        case 4:
            return '0';

        case 5:
            return '+';

        case 6:
            return '%';
        
        case 7:
            return '~';

        case 8:
            return '@';

        case 9:
            return '^';

        case 10:
            return '=';
    
        default:
            return' ';
    }
}

/*generates starting states of inventory and grid*/
void setup(){
    invent[0]="[ INVENTORY: ]";

    for(int i=0;i<GRIDX;i++){
        for(int j=0;j<GRIDY;j++){
            int temp=mrand();
            matrix[i][j][0]=itoflr(temp);
            matrix[i][j][1]='0';
            comp_matrix[i][j]=temp;
        }
    }
    matrix[GRIDX/2][GRIDY/2][1]='X';
}

void printout(){
    putchar('\n');
    for(int i=0;i<GRIDX;i++){
        for(int j=0;j<GRIDY;j++){
            if(matrix[i][j][1]=='0'){
                putchar(matrix[i][j][0]);
            }else{
                putchar('X');
            }
            putchar(' ');
        }
        char *temp=strcat(BUF,*invent[i]);
        printf(temp);
        putchar('\n');
    }
}