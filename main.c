//Includes necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

//Prototypes
void mainmenu(int i);
void showLogo();
void drawhangman(int i);
void getword();
void generatecurrentword();
void singlegame();
void multigame();
void battlegame();
void maingame();
void anothergame();
void resetgame();
void printstage(char mode);
void howtoplay();
void credit();
int randomNumber(int max_number);

//Declare global variables
int cursor = 1, i, j, len, error = 0;

char guessword[200], currentword[200], ans;

//Sets a directory for the word database
char dbdir[5000] = "wordlist.txt";

int main()
{
    resetgame();
    //prints the Main Menu
    mainmenu(cursor);

    char key;

    //Detect key UP and DOWN until ENTER is pressed
    do
    {
        key = getch();  //Get the input
        switch(key)
        {
            case 72 :
                mainmenu(--cursor); //Select upper menu
                break;
            case 80 :
                mainmenu(++cursor); //Select lower menu
                break;
        }
    } while(key!=13);

    //Launch a game or screen depending on the menu selected
    switch(cursor)
    {
        case 1 :
            singlegame();
            break;
        case 2 :
            multigame();
            break;
        case 3 :
            battlegame();
            break;
        case 4 :
            howtoplay();
            break;
        case 5 :
            credit();
            break;
        case 6 :
            exit(1);    //Exit game
    }
}

//Prints the main menu and change the selection when selection key is pressed
void mainmenu(int i)
{
    //Clears the screen
    system("cls");

    //prints the Logo
    showLogo();

    //draws a hangman
    drawhangman(99);

    //Prints the main menu depending on the cursor's position
    switch(i)
    {
        case 1 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[*] Singleplayer");
            printf("\n\t\t\t[] Multiplayer");
            printf("\n\t\t\t[] Battle Mode");
            printf("\n\t\t\t[] How to Play");
            printf("\n\t\t\t[] Credit");
            printf("\n\t\t\t[] Exit");
            break;
        case 2 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[] Singleplayer");
            printf("\n\t\t\t[*] Multiplayer");
            printf("\n\t\t\t[] Battle Mode");
            printf("\n\t\t\t[] How to Play");
            printf("\n\t\t\t[] Credit");
            printf("\n\t\t\t[] Exit");
            break;
        case 3 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[] Singleplayer");
            printf("\n\t\t\t[] Multiplayer");
            printf("\n\t\t\t[*] Battle Mode");
            printf("\n\t\t\t[] How to Play");
            printf("\n\t\t\t[] Credit");
            printf("\n\t\t\t[] Exit");
            break;
        case 4 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[] Singleplayer");
            printf("\n\t\t\t[] Multiplayer");
            printf("\n\t\t\t[] Battle Mode");
            printf("\n\t\t\t[*] How to Play");
            printf("\n\t\t\t[] Credit");
            printf("\n\t\t\t[] Exit");
            break;
        case 5 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[] Singleplayer");
            printf("\n\t\t\t[] Multiplayer");
            printf("\n\t\t\t[] Battle Mode");
            printf("\n\t\t\t[] How to Play");
            printf("\n\t\t\t[*] Credit");
            printf("\n\t\t\t[] Exit");
            break;
        case 6 :
            printf("\n\t\t\tWelcome to Hangman\n");
            printf("\n\t\t\t[] Singleplayer");
            printf("\n\t\t\t[] Multiplayer");
            printf("\n\t\t\t[] Battle Mode");
            printf("\n\t\t\t[] How to Play");
            printf("\n\t\t\t[] Credit");
            printf("\n\t\t\t[*] Exit");

        //If the selection is at the lowest or highest then put it to am appropriate position
        default :
            if(i > 6)
            {
                cursor = i = 1;
                mainmenu(cursor);
            }
            else if(i < 1)
            {
                cursor = i = 6;
                mainmenu(cursor);
            }
    }

    printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
}

//Prints out the Logo
void showLogo()
{
      printf("\t\t--------------------------------------------\n");
      printf("\t\t| #  #   #   #   #  #### #   #   #   #   # |\n");
      printf("\t\t| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
      printf("\t\t| #### ##### # # # #  ## # # # ##### # # # |\n");
      printf("\t\t| #  # #   # #  ## #   # #   # #   # #  ## |\n");
      printf("\t\t| #  # #   # #   #  ###  #   # #   # #   # |\n");
      printf("\t\t--------------------------------------------\n");
}

//Draws a Hangman depending on input value (player's mistake)
void drawhangman(int i)
{
 switch (i) {
     case 0 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t\n");
      printf("\t\t\t\n");
      printf("\t\t\t\n");
      printf("\t\t\t\n");
      printf("\t\t\t\n");
      printf("\t\t\t\n");
      printf("\t\t\t____________\n\n");
     break;

     case 1 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 2 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 3 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 4 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 5 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |    |\n");
      printf("\t\t\t  |    |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 6 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 7 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 8 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   /\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 9 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   / \\\n");
      printf("\t\t\t__|_________\n\n");
     break;

     case 10 :
      printf("\t\t\tAmount of wrong letters: %d\n\n", i);
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    X \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   / \\\n");
      printf("\t\t\t__|_________\n\n");
     break;

    //This one is for the menu
     default :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   / \\\n");
      printf("\t\t\t__|_________\n\n");
     break;

 }
}

//Randomly select a word from the database and put it into guessword
void getword()
{
    //String to store read data
    char rawtext[100000];

    //Set up a pointer for the file
    FILE *fpt;

    //Open the file in Read-Only mode
    fpt = fopen(dbdir, "r");

    //Check for error
    if(fpt == NULL){
        system("cls");
        printf("Error opening database, please enter the file's directory (use forward slash(/) not back slash(\\)) and press ENTER.\n");
        gets(dbdir);
        singlegame();
    }

    int n;

    //Read the file and write it into the array
    n = fread(rawtext, 1, 100000, fpt);

    //Ends the array with NULL to make it a string
    rawtext[n] = '\0';

    //Seperate the words with "|"
    char *token = strtok(rawtext, "|");

    //Pointer variable to keep the pointer of words
    char *words[1000] = {0};
    int f = 0;
    while(token != NULL)
    {
      //Allocating memory for the pointer
      words[f] = malloc(strlen(token)+1);

      // Copying entire string to pointer
      strcpy(words[f],token);

      // Resetting pointer
      token = strtok(NULL, "|");
      f++;
    }

    //Closing the file
    fclose(fpt);

    //Retrieve a random number
    int wordN = randomNumber(f);

    //Free all memory allocated for the strings
    int q;
    for(q = 0; q < 200; q++)
    {
        //If it's not the selected word, clear the memory
        if(q != wordN){
            free(words[q]);
        }
    }

    //printf("Check words : %s\n", words[wordN]);

    //Copy the selected word to guessword
    strcpy(guessword, words[wordN]);

    //printf("Check guessword : %s\n", guessword);

    generatecurrentword();
}

//Generate the currentword to display on the stage
void generatecurrentword ()
{
    //Get the string length of the word
    len = strlen(guessword);

    //Generate the current word guessed
    for(i = 0; i < len; i++)
    {
        if(guessword[i] != ' '){
            currentword[i] = '-';
        } else {
            currentword[i] = ' ';
        }
    }
}

//Starts Singleplayer mode game
void singlegame()
{
    getword();

    //Clear the screen
    system("cls");

    printstage('s');

    maingame();
}

//Starts Multiplayer mode game
void multigame()
{
    //Clear the screen
    system("cls");

    printf("Enter the word (Don't let your friend see it) : ");

    //Get the input
    gets(guessword);

    //Change to lowercase
    strlwr(guessword);

    //Clear the screen
    system("cls");

    printf("Check guess word : %s\n", guessword);

    generatecurrentword();

    printstage('m');

    maingame();
}


//Starts Battle mode game
void battlegame()
{
    //Strings for players's names
    char p1name[20], p2name[20];

    getword();

    //Clear the screen
    system("cls");

    //Ask for players's names
    printf("\n\t\tEnter Player 1's name : ");
    scanf("%s", p1name);
    printf("\n\t\tEnter Player 2's name : ");
    scanf("%s", p2name);

    //Prints the stage in battle mode and let player 1 plays first
    printstage('b');
    printf("\n\n\t\t%s's turn", p1name);
    printf("\n\t\tAnswer : ");

    int check = 0, player = 0;

    //Loop until the word has been guessed
    while(strcmp(guessword, currentword) != 0)
    {
        //Retrieving the user entry
        scanf("%c", &ans);


        if(ans != '\n'){

            check = 0;

            player++;

            for(i = 0; i < len; i++)
            {
                //Check if the input is correct
                if(guessword[i] == ans){
                    //Add the correct letter
                    check++;
                    currentword[i] = ans;
                }
                //printf("Check check : %d", check);
            }

            //If the answer alphabet doesn't match any alphabet in guessword, increase error.
            if(check == 0){
                error++;
            }
        }

        system("cls");
        printstage('b');

        //Determine which player's turn is it
        if(player % 2 == 0){
            printf("\n\n\t\t%s's turn", p1name);
            printf("\n\t\tAnswer : ");
        } else {
            printf("\n\n\t\t%s's turn", p2name);
            printf("\n\t\tAnswer : ");
        }

        //printf("Check check : %d\n", check);
    }

    system("cls");
    printstage('b');

    //Determine who is the winner and prints out a message
    if(player %2 ==0){
        printf("\n\n\t\t%s WINS!!", p1name);
        anothergame();
    } else {
        printf("\n\n\t\t%s WINS!!", p2name);
        anothergame();
    }
}

//The main game engine
void maingame()
{
    int check = 0;

    //Loop until the word has been guessed
    while((strcmp(guessword, currentword) != 0) && error < 10)
    {
        //Retrieving the user entry
        printf("\t\tAnswer : ");
        scanf("%c", &ans);

        if(ans != '\n'){

            check = 0;

            for(i = 0; i < len; i++)
            {
                //Check if the input is correct
                if(guessword[i] == ans){
                    //Add the correct letter
                    check++;
                    currentword[i] = ans;
                }
                //printf("Check check : %d", check);
            }

            //If the answer alphabet doesn't match any alphabet in guessword, increase error.
            if(check == 0){
                error++;
            }
        }

        //Clear the screen
        system("cls");
        printstage('s');

        //printf("Check check : %d\n", check);
    }

    //Determine whether the player wins or lose and display a message and ask if they want another game
    if(error == 10){
        printf("\n\n\t\tYou LOSE!!, try again next time. :3\n");
        anothergame();
    } else {
        printf("\n\n\t\tCongratulations, You WIN!!.\n");
        anothergame();
    }
}

//Asks whether the player wants to play again or not
void anothergame()
{
    printf("\n\t\tAnother game? [y/n]");
        char c;
        c = getche();
        if(c == 'y'){
            main();
        } else {
            exit(1);
        }
}

//Resets all variables to default
void resetgame()
{
    *guessword = "\0";
    *currentword = "\0";
    error = 0;
}

//Prints out the stage in different modes
void printstage(char mode)
{
    printf("\t%s\n\n\t%s\n\t%s\n\t%s\n\t%s\n\n\t%s%s\n\n",
           "Welcome to the Hangman!",
           "The objective in this game is to guess the word.",
           "You can enter both upper or lowercase letters.",
           "If you think you know the word, you can type it in all at once.",
           "You will loose if you make 10 mistakes.",
           "This is the word you need to guess: ",
           currentword);

    //Draws a hangman if it's not Battle mode
    if(mode != 'b'){
        drawhangman(error);
    }
}

//Prints How to Play texts
void howtoplay()
{
    system("cls");

    printf("\n\t\t%s\n\n%s\n\n%s\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n%s\n\n%s\n\n%s",
           "::HOW TO PLAY::",
           "The objective in this game is to guess the word.",
           "In Singleplayer mode, the game will randomly pick you a word.",
           "You will have to guess enter a letter.",
           "If you think you know the word, you can type it in all at once.",
           "In Multiplayer mode, the rule is the same as single player",
           "but one will be entering a word for another to guess.",
           "In Battle mode, the game will randomly pick you a word.",
           "Each player will then take turn to guess.",
           "The first player that figure the word out is the winner",
           "You will lose if you make 10 mistakes in every mode expect battle mode.",
           "Press any key to return to the main menu.");

    getch();
    main();
}

//Prints Credit
void credit()
{
    system("cls");

    printf("\n\t%s\n\n\t%s\n\n\t%s\n\n\t%s",
           "Created by Krishna Ojha, Gautam Gupta, Aakash Rana, Jyokpa Chamling Rai",
           "For 1st Semester C Programming project.",
           "Student ID# = KAN078BCT-040,033,04,37",
           "Press anykey to go back to the main menu.");

    getch();
    main();
}

//Randoms a number from 0 to max_number
int randomNumber(int max_number)
{
srand(time(NULL));
int g = (rand() % (max_number + 1));
return g;
}
