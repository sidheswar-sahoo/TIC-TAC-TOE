//# TIC-TAC-TOE
//A SIMPLE CONSOLE BASED TIC-TAC-TOE GAME USING C+
#include<iostream>
#include<math.h>
#include<vector>
#include <algorithm>
using namespace std;
char array[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int x;
int playerno,slot,row,coloumn;
char input;
char slottochar(int n){
    return array[(n-1)/3][(n-1)%3];
}
bool validity(int n){
    if(n<1||n>9||array[row][coloumn]=='X'||array[row][coloumn]=='O'){return 0;}
    return 1;
}
bool ifwins(){
    if(array[row][0]==array[row][1]&&array[row][1]==array[row][2]||array[0][coloumn]==array[1][coloumn]&&array[1][coloumn]==array[2][coloumn]){
        return true;
    }
    if(slot==1||slot==3||slot==9||slot==7||slot==5){
        if(slottochar(1)==slottochar(5)&&slottochar(5)==slottochar(9)||slottochar(3)==slottochar(5)&&slottochar(5)==slottochar(7)){
            return true;
        }
    }
    return false;
}
 int main(){
    cout<<"WELCOME TO TIC-TAC-TOE"<<endl;
    for(int i=1;i<=9;){
        int x=i%2;
        if(x==0){
            playerno=2;
            input='O';
        }
        if(x==1){
           playerno=1;
           input='X';
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<array[j][k];
               if(k<=1){cout<<" | ";}
            }
            cout<<endl;
            cout<<"---------";
            cout<<endl;
        }
        cout<<"player"<<playerno<<"("<<input<<");enter your slot"<<endl;
        cin>>slot;
        row=(slot-1)/3;
        coloumn=(slot-1)%3;
        if(validity(slot)==0){
            cout<<"invalid move ,please try again"<<endl;
            continue;
        }
        else{
        array[row][coloumn]=input;
        if(ifwins()==1){
            for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<array[j][k];
                if(k<=1){cout<<" | ";}
            }
            cout<<endl;
            cout<<"---------";
            cout<<endl;
        }
            cout<<"player"<<playerno<<" wins"<<endl;
            break;
        }
        i++;
    }
    }
    cout<<"game over"<<endl;

 }