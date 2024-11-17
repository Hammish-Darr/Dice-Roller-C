#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int rollDice(char * string){
    int finalValue;
    int d = 0;
    char timesRolledStr[64];
    int timesRolled;
    char diceStr[4];
    int dice;
    for(int i=0; i<=strlen(string);i++){
        if(string[i] == 'd'){
            d = 1;
            for(int x=0, count=0;x!=i;x++){
            if(string[x] != ' ') {timesRolledStr[count] = string[x]; count++;}
            }
            int timesRolled = atoi(timesRolledStr);
            int count = 0;
            for(int x=i+1;x!=strlen(string);x++){
                if (string[x] != '\n' && string[x] != '\0'){ //Does this if statement even do anything?
                    diceStr[count] = string[x];
                    count ++;
                }
                else break;
            }
            dice = atoi(diceStr);
            finalValue = 0;
            if (dice > 0){
                for(int j=0;j!=timesRolled;j++){
                    finalValue += ((rand()%dice)+1);
                }
            }
            else return dice;
            return finalValue;      
        }
    }
    return -1;
}

//RollDice returns an int of the total rolled value. (takes an input of "XdX").

int main() {
    srand(time(NULL));
    int maxLength = 128;
    char * string = malloc(sizeof(char) * maxLength);
    int finalValue;

    printf("============ Roll The Die. ============\n\n\n");


    while(1){
        printf("Input the die to roll, or exit.\n\n");
        fgets(string, maxLength - 1, stdin);
        if(string[strlen(string) - 1] == '\n')string[strlen(string) - 1] = '\0';
        if (strcmp(string, "exit") == 0){
            break; //Just gonna ignore all this
        }
        else{
            //Sort input into seperate strings of "XdX", and pass to rollDice.
            char tempString[32];
            int count = 0;
            for(int x=0;x<=strlen(string);++x){
                if((string[x] == ',') || (string[x] == '\0')){
                    tempString[count] = '\0';
                    printf("%d\n", rollDice(tempString));
                    count = 0;
                    
                }
                else{
                    tempString[count] = string[x];
                    count ++;
                }
                

            }

        }
    }


    free(string);

    return 0;
}