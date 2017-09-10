#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
int readScore(void);
void saveScore(int score);

int main(){
    //Declare variables
    int menu=0;
    char name[16];
    int counter=0;
    int rand_num, score;
    int guess=0;

    FILE* fscore; //Include file pointer

    while(menu != 4){

        printf("\n\n**************** NUMBER GUESSING GAME MENU v1.0 **************\n");
        printf("\t1.Create Player Name.\n\t2.Play.\n\t3.View Score.\n\t4.Quit.\n");
        printf("**************************************************************\n");
        printf("Your Choice: ");
        scanf("%d", &menu);

        if(menu == 1){
            printf("\nEnter a player name: ");
            scanf("%15s", name);
        }
        else if(menu == 2){
            srand(time(NULL)); //Initialize a seed for rand() function
            rand_num = 1 + rand()%100; //Generate a random integer
            while(guess != rand_num){
                printf("\nGuess the number picked: ");
                scanf("%d", &guess);
                if(guess > rand_num){
                    printf("\nNumber is smaller than your guess.");
                }
                else if(guess < rand_num){
                    printf("\nNumber is greater than your guess.");
                }
                counter++;
            }
            printf("\nYour guess is correct!!\n");
            printf("Number of guesses: %d\n", counter);
            if(counter < score){
                //Call function to overwrite the highest score
                saveScore(counter);
            }
            counter = 0;
        }
        else if(menu == 3){
            //Call function to retrieve the highest score from file
            score = readScore();
            printf("\nThe best score is: %d\n", score);
        }
    }
    return 0;
}
int readScore(void){
    // Read the score from file
    FILE *fscore = fopen("score.txt", "r");
	int score;
	fscanf(fscore, "%d", &score);
    fclose(fscore);
    return score;
}

void saveScore(int score){
    // Save the score to file
    FILE *fscore = fopen("score.txt", "w+");
    fprintf(fscore, "%d", score);
    fclose(fscore);
}
