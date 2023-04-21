#include <stdio.h>
#include <conio.h>

struct dress{
    int dress;
    char color[20];
}dress[7];

int main(){
    printf("Enter 7 colours for each day of the week:\n");
    //initialising colours
    for(int i=0;i<7;i++){
        printf("Enter colour %d:",i+1);
        scanf("%s",dress[i].color);
        dress[i].dress=0;
    }

    //printing the order of dresses
    printf("\n\n");
    for(int i=0;i<28;i++){
        printf("Day %d:\n", i+1);
        printf("Color:%s\nDay:%s dress%d\n", dress[i%7].color, dress[i%7].color, ++(dress[i%7].dress));
        printf("Evening:%s dress%d\n\n", dress[i%7].color, ++(dress[i%7].dress));
        getch();
    }

    return 0;
}