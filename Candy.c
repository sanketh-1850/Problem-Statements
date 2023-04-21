#include <stdio.h>
#include <stdlib.h>

//checks from front
int ankit(int *candyrack, int n){
    int max=candyrack[0]+candyrack[1]+candyrack[2], temp;
    for(int i=1; i+2<n ;i++){
        temp=candyrack[i]+candyrack[i+1]+candyrack[i+2];
        if(max<temp){
            max=temp;
        }
    }
    return max;
}

//checks from back
int riya(int *candyrack, int n){
    int max=candyrack[n-1]+candyrack[n-2]+candyrack[n-3], temp;
    for(int i=n-2; i-2>=0 ;i--){
        temp=candyrack[i]+candyrack[i-1]+candyrack[i-2];
        if(max<temp){
            max=temp;
        }
    }
    return max;
}

//checks from both front and back at the same time
int priya(int *candyrack, int n){
    int max=-1,temp1,temp2;
    for(int i=0; i<n/2 ;i++){
        temp1=candyrack[i]+candyrack[i+1]+candyrack[i+2];
        temp2=candyrack[n-i-1]+candyrack[n-i-2]+candyrack[n-i-3];
        if((temp1>max) && (temp1>temp2)){
            max=temp1;
        }
        else if((temp2>max) && (temp2>=temp1)){
            max=temp2;
        }
    }
    return max;
}

int main(){
    int *candyRack, n, ankit_max, riya_max, priya_max;

    printf("Enter number of candy jars(must be greater than 3):");
    scanf("%d",&n);
    candyRack=(int*)malloc(n*sizeof(int));
    
    //accepting number of candies in each jar
    printf("Enter the candies in each candy jar:\n");
    for(int i=0;i<n;i++){
        printf("Candies in jar %d:", i+1);
        scanf("%d", &candyRack[i]);
    }

    //calculating using three algorithms
    ankit_max=ankit(candyRack, n);
    riya_max=riya(candyRack, n);
    priya_max=priya(candyRack, n);

    printf("\nankit max=%d\nriyamax=%d\npriyamax=%d\n", ankit_max, riya_max, priya_max);

    return 0;
}