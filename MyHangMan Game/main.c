#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showHangman(int);

int main(void)
{
    aga:
    system("color C");

    char word[100], TempWord[100];
    char WordOutput[100];
    int no_of_tries = 6 , match = 0;


    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;

    system("cls");
    printf("\n\n Enter a word in small case and press ENTER");
    printf("\n\n\t Enter HERE ==>  ");
    scanf("%s",word);
    printf("\n\n\tPress ENTER");
    getchar();
    length = strlen(word);

    system("cls");

    printf("\n\n\t\t\tWELCOME TO THE HANGMAN GAME\n\t\t\t===========================\n\n\n");
    printf("\n\n You will have 5 chances to guess the right word");

    printf("\n\n\tPress ENTER ");

    getchar();

    system("cls");

        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        WordOutput[i] = '_';
        WordOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",WordOutput[i]);

    }
    while(no_of_tries != 0)
    {
        match = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabetFromUser);
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z')
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        match = 2;
    }
    fflush(stdin);
    if (match != 2)
    {
        for(counter=0;counter<length;counter++)
	    {
		    if(alphabetFromUser==word[counter])
                    {
                        match = 1;
                    }
               }

	   if(match == 0)
	    {
     	      printf("\n\t :( You have %d tries left ",--no_of_tries);
	          getchar();
              showHangman(no_of_tries);
              getchar();
	    }

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         match = 0;
                 if(alphabetFromUser == word[counter])
	          {
     		     position = counter ;
     		     match = 1;
	          }
    	      if(match == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          WordOutput[i] = alphabetFromUser;
                      }
                      else if( WordOutput[i] >= 'a' && WordOutput[i] <= 'z' )
                      {
                          continue;
                  	  }

                      else
                      {
                          WordOutput[i] = '_';
                      }
                }
                TempWord[position] = alphabetFromUser;
                TempWord[length] = '\0';
                winner = strcmp(TempWord,word);

                if(winner == 0)
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",word);
                    printf("\n\n\n\n\t\tEASY HUH???\n\n");
                    int dec;
                    printf("\n\n\t Enter 1 To Play Again and 0 to Quit\n\n");
                    ent1:
                    scanf("%d",&dec);
                    if (dec == 0)
                        {
                            return 0;
                        }
                    if (dec == 1)
                        {
                            goto aga;
                        }
                    if (dec != 1 || dec != 0)
                        {
                            goto ent1;
                        }
                    return 0;
                }
	       }
	    }
      }
     }

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",WordOutput[i]);
      }

    }

      if(no_of_tries <= 0)
      {
          printf("\n\n\t The Word was %s ",word);
          printf("\n\n\t THE MAN IS DEAD NOW!!!!!");
	      printf("\n\n\t Better luck next!!!");
	      int dec;
	      printf("\n\n\t Enter 1 To Play Again and 0 to Quit\n\n");
	      ent:
	      scanf("%d",&dec);
	      if (dec == 0)
          {
              return 0;
          }
          if (dec == 1)
          {
              goto aga;
          }
          if (dec != 1 || dec != 0)
          {
              goto ent;
          }

      }
}



void showHangman(int choice)
 {

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }
      return;
 }



