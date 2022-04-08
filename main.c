#include<stdio.h>
#include<stdlib.h>
void Highest_mark(int , char[]);
void view_Highestscore();
void Reset_Score();
void Game_R1();
void Game_R2();
int main()
{

    char choice,player_name[20];



    printf("\n=============================================================================================\n");
    printf("\n\t\t>>>>>>>>>>>BASIC GENARAL KNOWLADGE TEST QUIZZ<<<<<<<<<<<<<<\n");
    printf("\n\t\t\t\t  PLAY AND WIN MONEY!!!!!!!!!!!");
    printf("\n=============================================================================================\n\n");
    printf("Press S to start the game\n");
    printf("Press V to view the highest mark\n");
    printf("Press R to reset score\n");
    printf("Press Q to Quit\n\n");
    printf("Enter your choice: ");
    scanf("%c",&choice);

    switch (choice)
    {
        case 'S':
        {
          printf("\nEnter your name: ");
          scanf(" %s",&player_name);
          Game_R1(player_name);
        }
        break;
        case 'V':
        view_Highestscore();
        break;
        case 'R':
        Reset_Score();
        break;
        case 'Q':
          printf("Exit");
        break;
        default:
          printf("Invalid");

    }

}
void Game_R1(char name[20])

{

    printf("\t\t\tWELCOME TO YOUR FIRST ROUND\n");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.\n");
    printf("\nGive the answer for each questions and earn money!\n");
    printf("You will get 5 question in this Round\n");
    printf("You earn Rs:1000 for each correct answers\n");
    printf("If you answered all questions correctly you can jump next round\n");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");


    char questions[][100] = {"1.Which animal never drinks water it's entirelife ?",
                             "2.Which is the largest human cell ?",
                             "3.Hormones are produced by?",
                             "4.Which is the largest gland in humanbody ?",
                             "5.Which gas is used in fire extinguisher ?"};
    char options[][100] = {"1.Kangaroo","2.Hippopotamus","3.Rat","4.Kangaroo rat",
                            "1.Liver","2.Skin","3.Spleen","4.Ovum",
                            "1.Endocrine gland","2.Pitutary gland","3.Hypothalamus gland","4.None of these",
                            "1.Heart","2.Liver","3.Brain","4.Kidney",
                            "1.Hydrogen","2.Oxygen","3.Nitrogen","4.Carbon dioxide"};

     int Answers[5] = {4, 1,1,2,4};

     int numberofQuestions = sizeof(questions)/sizeof(questions[0]);
     int guess , cash_price = 0;
     int score = 0,i;
     char ch;

     for (i = 0; i < numberofQuestions;i++)
     {
         printf("\n%s\n\n",questions[i]);

        for (int j = (i * 4); j < (i * 4) + 4;j++)
        {
            printf("%s\n",options[j]);
        }
        printf("\nguess: ");
        scanf("%d",&guess);

        if (guess == Answers[i])
        {
            printf("CORRECT! YOU WIN RS.1000\n");
            cash_price = cash_price + 1000;
            score++;
        }
        else
        {
            printf("Wrong !\n");
            printf("Correct Answer is: %d\n",Answers[i]);
        }

     }
     printf("\n\n=========================================================================================\n\n");
     printf("\t\t\tFINAL SCORE: %d/%d\n",score,numberofQuestions);
     printf("\t\t\tTOTAL CASH PRICE = %d\n",cash_price);
     printf("\n===========================================================================================\n\n");

     if (score==5){
         Highest_mark(score,name);
         printf("CONGRATULATIONS! %s YOU HAVE SELECTED NEXT ROUND\n",name);
         printf("Enter N to go to the second round ");
         scanf(" %c",&ch);
         if (ch == 'N')
          Game_R2(cash_price);
     }

     else
     {
        printf("\t\t\nSO SAD! YOUR SCORE IS NOT ENOUGH TO JUMP NEXT ROUND\n");
     }


}
void Game_R2(int c_price)
{
    int cash_price = 0;
    printf("\t\t\t\t\nWELCOME TO YOUR SECOND ROUND\n\n");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("Give the answers each questions and win money !\n");
    printf("You will get 5 questions this round\n");
    printf("This round you get Rs. 5000 for each questions\n");
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");


    char questions[][100] = {"1.What is the largest continent on Earth ?",
                             "2.What is the capital of brazil ?",
                             "3.What is the capital of Australia?",
                             "4.Which country is said to be shaped like boot?",
                             "5.Who is known as the father of zoology ?"};
    char options[][100] = {"1.Amwrica","2.Asia","3.Europe","4.Africa",
                            "1.Brasilia","2.Sao paulo","3.Rio de Janeiro","4.Salvador",
                            "1.Melbourne","2.Canberla","3.Brisbane","4.Sydney",
                            "1.Australia","2.Portugal","3.Iceland","4.Italy",
                            "1.Albert Einstein","2.Issac Newton","3.Aristotle","4.Thomas Henry Huxley"};

     int Answers[5] = {2,1,2,4,3};

     int numberofQuestions = sizeof(questions)/sizeof(questions[0]);
     int guess;
     int score = 0,i;
     char ch;


     for (i = 0; i < numberofQuestions;i++)
     {
         printf("\n%s\n\n",questions[i]);

        for (int j = (i * 4); j < (i * 4) + 4;j++)
        {
            printf("%s\n",options[j]);
        }
        printf("\nguess: ");
        scanf("%d",&guess);

        if (guess == Answers[i])
        {
            printf("CORRECT! YOU WIN RS.5000\n");
            cash_price = cash_price + 5000;
            score++;
        }
        else
        {
            printf("Wrong !\n");
            printf("Correct Answer is: %d",Answers[i]);
        }

     }
     printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
     printf("\t\t\tFINAL SCORE: %d/%d\n",score,numberofQuestions);
     printf("\t\t\tTOTAL CASH PRICE YOU WIN FROM TWO ROUNDS = %d\n",cash_price + c_price);
     printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");


}

void Highest_mark(int score , char username[])
{
FILE *file;
  file = fopen("highestmark.txt", "a");
  int count = 0;
  count+=1;

  if(file == NULL)
  {
      printf("File create fail\n");
      exit(0);
  }else {
      printf("File create Succesfully !\n");
  }
    fprintf(file,"%s\t\t%d \n",username,score);

    fclose(file);

}
void view_Highestscore()
{
 FILE *file;
 file = fopen("highestmark.txt","r");
  char read[200];
  if(file == NULL)
  {
      printf("File not exicute\n");
      exit(0);
  }
  else
     printf("---------------------HIGHESTMARK------------------\n\n");
     printf("USERNAME        SCORE\n");
     while(fscanf(file, " %s",read)!=EOF){
     printf("%s",fgets(read,200,file));
    }
     fclose(file);
}

void Reset_Score()
{

    char nm = '0';
    FILE *f;
    f = fopen("highestmark.txt","w");
    fprintf(f,"%c,%.2f",nm,0);
    fclose(f);

}



