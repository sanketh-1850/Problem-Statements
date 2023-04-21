#include <stdio.h>
#include <string.h>

int main(){
    char parts[20][20]={"spoke","handlebar","bottom bracket","spacer","air chamber","wheel hub", "rear sprocket","disc brake", "chain", "pedal", "saddle","seatpost"
    ,"crank", "chain ring","rim", "tyre"}, stack[20][20];
    int top=-1;
    
    //printing part names for reference
    printf("\nThese are the parts for reference:\n");
    for(int i=0;i<16;i++){
        printf("\'%s\'  ",parts[i]);
    }
    
    //accepting the order of the parts in which they were dismantled
    printf("\n\nEnter the order of parts removed(enter \'~\' when done):\n");
    while(1){
        printf("Enter part %d:", top+2);
        gets(stack[++top]);
        if(strcmp(stack[top],"~") == 0){
            top--;
            break;
        }
    }
    
    //printing the order in which they can put back the bike
    printf("\n\nThe order to put back the bike is:\n");
    int count=1;
    while(top>=0){
        printf("%d.%s\n",count++,stack[top--]);
    }
    return 0;
}