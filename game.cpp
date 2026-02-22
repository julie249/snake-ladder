#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;
int rollDice(){
    return rand()%6+1;
}
int main(){
    srand(time(0)); 

    int currentPlayer=1;
    int position[3]={0,1,1}; 

    // Snakes and Ladders mapping
    map<int,int> snakesAndLadders={
        // Ladders
        {4,14},{9,31},{20,38},{28,84},
        {40,59},{51,67},{63,81},{71,91},
        // Snakes
        {17, 7}, {54, 34}, {62, 19}, {64, 60},
        {87, 24}, {93, 73}, {95, 75}, {99, 78}
    };
    cout<<"Snake and Ladder Game Started!\n";
    while(true){
        cout<<"\nPlayer "<<currentPlayer<<"'s turn\n";
        cout<<"Press ENTER to roll dice...";
        cin.ignore();

        int dice=rollDice();
        cout<<"Dice rolled: "<<dice<<endl;

        int newPos=position[currentPlayer]+dice;

        if(newPos>100){
            cout<<"Move exceeds 100. Stay at "<<position[currentPlayer]<<endl;
        }else{
            position[currentPlayer]=newPos;
            cout<<"Moved to: "<<newPos<<endl;

            // Check for snake or ladder
            if(snakesAndLadders.count(newPos)){
                int finalPos=snakesAndLadders[newPos];
                if(finalPos>newPos)
                    cout<<"Ladder! Climb up to "<<finalPos<<endl;
                else
                    cout<<"Snake! Slide down to "<<finalPos<<endl;

                position[currentPlayer]=finalPos;
            }
        }

        cout<<"Player 1 position: "<<position[1]<<",Player 2 position: "<<position[2]<<endl;

        // win condition
        if(position[currentPlayer]==100){
            cout<<"\nPlayer "<<currentPlayer<<"Wins the Game!\n";
            break;
        }

        // Switch turn if dice is not 6
        if(dice!=6){
            currentPlayer=(currentPlayer==1)?2:1;
        }else{
            cout<<"Rolled a 6! Extra turn!\n";
        }
    }
    return 0;
}
