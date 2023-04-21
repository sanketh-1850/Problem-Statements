#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

//number of seats
#define seats 10

int main(){

    char seating[seats],c[2],count=0;

    //accepting the initial seating of students
    printf("Enter the inital seating of students:\n(use \'g\' for girl and \'b\' for boy)\n");
    for (int i=0; i<seats ; i++) {
        printf("Enter gender of student %d:", i+1);
        scanf("%s", c);
        
        //to tackle wrong input
        if ( (c[0] != 'g') && (c[0] != 'b') ){
            printf("Wrong input!\n");
            i--;
            continue;
        }

        seating[i] = toupper(c[0]);       //this is done to exclude the '\n' stored in c[1]
    }
    
    //display initial seating
    printf("\nInitial seating:\n");
    for(int k=0; k<seats ; k++){
        printf("%c\t",seating[k]);
    }
    printf("\n");

    //when principal arrives
    //bubble sort is used to sort in decending order
    for(int i=0; i<seats-1 ; i++){
        count=0;
        for(int j=0; j<=seats-i-1 ; j++){

            if(seating[j] < seating[j+1]){
                char temp=seating[j];
                seating[j]=seating[j+1];
                seating[j+1]=temp;
                count++;
            }
        
        }
        
        if(count == 0)      // if count=0 then it means that array is fully sorted
            break;

        //display seating after each boy changes seat
        printf("\nAfter boy %d changes seat:\n", i+1);
        for(int j=0; j<seats ; j++){
            printf("%c\t",seating[j]);
        }
        printf("\n");
        getch();
    
    }

    // display final seating
    printf("\nFinal seating:\n");
    for(int k=0; k<seats ; k++){
        printf("%c\t",seating[k]);
    }
    printf("\n");

    return 0;
}