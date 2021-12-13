#include <stdio.h>
#include <string.h>

void masterMind(char *param_1){

    //var initialize
    char testInteger[4];
    int round = 0;
    int correct = 0;
    int incorrect = 4;
    int wrong = 0;
    int j =0;

    //Initialize the game
    printf("Will you find the secret code?\n");
    printf("----\n");
   
   //The game can't go longer than 10rounds
    while(round < 11){ 
        //section that get printed everytime
        printf("Round %d \n", round);
        printf(">");
        scanf("%s", testInteger);

        //removing the wrong condidition if it go triggered throughout the game
        wrong =0;

        /*initializing loop to check if 
            a) the user input contain only number from 0 - 9 on each position
                it trigger the wrong condition that restart another round 
            b) check on each position if the user number is equal to the secret code
                if it is, it check the next position (j+=1), and increase the "correct" counter by 1
        */
        while(j <strlen(testInteger)){
            for(int i = 0; i<strlen(testInteger); i+=1){
                if(testInteger[i] < 47 || testInteger[i] > 57){
                    wrong = 1;
                }
                if(testInteger[i] == param_1[j]){
                    wrong =0;
                    correct += 1;
                    j+=1;    
                }
                else{
                    j+=1; 
                }
            }
        }

        //trigger only if 4 correct position and number are meet
        if(correct == 4){
                printf("Congratz! You did it!\n");
                break;
                }   
        //finish the round when wrong input
        if(wrong != 0){
            printf("Wrong input!\n");
            correct = 0;
            incorrect = 4;
        }

        //when any of the 2 others conditions aren't True, the game keep playing until 10 rounds
        else{
            incorrect -= correct;
            printf("Well placed pieces: %d\n", correct);
            printf("Misplaced pieces: %d\n", incorrect);
            printf("----\n");
            correct = 0;
            incorrect = 4;

        }
        //reset the j counter value to 0
        j=0;
        //increase the round by 1
        round += 1;
        if(round > 10){
            printf("You lost! \nThe secret code was %s \n", param_1);
        }
    }
    
    
}