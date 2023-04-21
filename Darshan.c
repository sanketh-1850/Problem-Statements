#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//defining value constraints
#define vipMax 5
#define freeMax 20

//defining time constraints
#define laddu 5
#define cave 100
#define prasad 25

int timeCounter = 0;

int main(){
    int freeQ[freeMax], vipQ[vipMax], vipFront=0, freeFront=0, prasadStack[25], prasadTop=-1;

    //laddus are prepared first
    for(int i=0; i<25; i++){
        prasadStack[++prasadTop] = i+1;
        timeCounter += laddu;
    }
    
    //initializing the time of arrival of free devotees
    printf("Enter the arrival time of first free devotee(must be greater than 125):");
    scanf("%d", &freeQ[0]);
    for(int i=1; i<freeMax; i++){
        freeQ[i] = freeQ[i-1]+50;       //devotees arrive at every 50 seconds after first devotee
    }

    //accepting the arrival time of vip devotees
    for(int i=0; i<vipMax; i++){
        printf("Enter the time of arrival of vip %d:", i+1);
        scanf("%d", &vipQ[i]);
    }

    //display initial values
    printf("\nTime elapsed:%d\nNo. of laddus left:%d\nNumber of Vip darshan done:%d\nNumber of Free darshan done:%d\n\n", timeCounter, prasadStack[prasadTop], vipFront, freeFront);
    getch();


    //looping till all devotees are done
    while( (freeFront < freeMax) || (vipFront < vipMax) ){

        //if free queue is done and vip is yet to arrive
        if ( (timeCounter < vipQ[vipFront]) && (freeFront == freeMax) && (vipFront!=vipMax) ){
            timeCounter = vipQ[vipFront];
            timeCounter += cave;
            vipFront++;
            prasadTop--;
        }

        //if vip arrives when free queue is not done
        else if ( timeCounter >= vipQ[vipFront] && (vipFront!=vipMax) ){
            timeCounter += cave;
            vipFront++;
            prasadTop--;
        }

        //no vips have arrived yet
        else{
            timeCounter += cave;
            freeFront++;
            prasadTop--;
        }

        //display values after each devotee has finished darshan
        printf("\nTime elapsed:%d\nNo. of laddus left:%d\nNumber of Vip darshan done:%d\nNumber of Free darshan done:%d\n\n", timeCounter, prasadStack[prasadTop], vipFront, freeFront);
        getch();
    }
    
    //add time taken to collect prasad to total time
    timeCounter += prasad;
    printf("\nData at the end of the day(after prasad distribution to the last devotee):\nTime elapsed:%d\nNo. of laddus left:%d\nNumber of Vip darshan done:%d\nNumber of Free darshan done:%d\n\n", timeCounter, prasadStack[prasadTop], vipFront, freeFront);
    getch();
    
    return 0;
}