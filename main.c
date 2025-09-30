#include <corecrt_search.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vcruntime.h>

#define winnerCount 5
#define plusPoint 1

char losetext[] = "you lose, the computer wins a point";
char wintext[] = "you win, the human race wins a point";
char tietext[] = "its a tie, try again";
enum {
  win1 = -4,
  win2 = -2,
  win3 = 1,
  win4 = 3,
  lose1 = -3,
  lose2 = -1,
  lose3 = 2,
  lose4 = 4,
  tie = 0
} modes;
const char *weaponNames[] = {"spock", "scissor", "paper", "rock", "lizard"};
int humanPoint = 0;
int computerPoint = 0;
int firstRound = 1;

void loseAction() {
  puts(losetext);
  computerPoint += plusPoint;
}

void winAction() {
  puts(wintext);
  humanPoint += plusPoint;
}

int main() {
  printf("Hello! are you ready for RPSSL!\n");
  srand(time(NULL));
  while (humanPoint < winnerCount && computerPoint < winnerCount) {
    printf("Choose your weapon: ");
    int userChoice = getchar() - '0';
    getchar();
    if (userChoice < 0 || userChoice > 4) {
      puts("Write a number between 0-4");
      continue;
    }

    int computerChoice = rand() % 5;
    int number = userChoice - computerChoice;

    switch (number) {
    case win1:
      winAction();
      break;

    case win2:
      winAction();
      break;

    case win3:
      winAction();
      break;

    case win4:
      winAction();
      break;

    case lose1:
      loseAction();
      break;

    case lose2:
      loseAction();
      break;

    case lose3:
      loseAction();
      break;

    case lose4:
      loseAction();
      break;

    case tie:
      puts(tietext);
      break;
    }

    if (!firstRound) {
      printf("You choose %s, while the computer chose %s\n",
             weaponNames[userChoice], weaponNames[computerChoice]);
    }
    firstRound = 0;

    printf("The score is now human: %d, computer: %d\n", humanPoint,
           computerPoint);

    if (humanPoint == winnerCount) {
      puts("\ncongrats for winning over a computer!");
    }

    else if (computerPoint == winnerCount) {
      puts("\nUnfortunatly the computer won");
    }
  }
}