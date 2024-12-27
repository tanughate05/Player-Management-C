#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Players
{
    int jerseyNumber;
    char name[50];
    int runs;
    int wickets;
    int matches;
} Players;

void addPlayer(Players *, int *);
void displayPlayers(Players *, int* );
void RemovePlayer(Players * , int* );
int SearchPlayerByJersey(Players *, int , int );
int SerachPlayerByName(Players *, int , char *);

    void main()
{
    int choice;
    int i;
    int size = 5;
    int *n=&size;
    Players *newPlayers = (Players *)malloc(size * sizeof(Players));
    if (newPlayers == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    
    {
        printf("\nPlayer Management System:\n");
        printf("1. Add Player\n");
        printf("2. Display All Players\n");
        printf("3.Remove Players\n");
        printf("4. SerachById Players\n");
        printf("5.SearchByName Player\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPlayer(newPlayers, &size);
            break;
        case 2:
            displayPlayers(newPlayers, &n);
            break;
        case 3:
                 
                 RemovePlayer(newPlayers,&n);
                 break;
        case 4:
               SearchPlayer( newPlayers, size);
                break;
               
        case 5: UpdatePlayer(newPlayers,size);
                break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }while(size<5);
}

void addPlayer(Players *newPlayers, int *size)
{
    int i;
    for (i = 0; i < *size; i++)
    {
        printf("Enter Jersey Number: ");
        scanf("%d", &newPlayers[i].jerseyNumber);
        printf("Enter Player Name: ");
        scanf("%s", newPlayers[i].name);
        printf("Enter Runs: ");
        scanf("%d", &newPlayers[i].runs);
        printf("Enter Wickets: ");
        scanf("%d", &newPlayers[i].wickets);
        printf("Enter Matches Played: ");
        scanf("%d", &newPlayers[i].matches);
    }
}

void displayPlayers(Players *newPlayers, int* size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("The jersey number is: %d\n", newPlayers[i].jerseyNumber);
        printf("The player name is: %s\n", newPlayers[i].name);
        printf("The Runs are: %d\n", newPlayers[i].runs);
        printf("The Wickets are: %d\n", newPlayers[i].wickets);
        printf("The matches played are: %d\n", newPlayers[i].matches);
    }
}
void RemovePlayers(Players *newPlayers, int *size)
{
    int i, playerJersey;
    printf("Enter Jersey Number: ");
    scanf("%d", &playerJersey);

    int index = SearchPlayerByJersey(newPlayers, *size, playerJersey);
    if (index == -1)
    {
        printf("Player not found.\n");
        return;
    }

    for (i = index; i < *size - 1; i++)
    {
        newPlayers[i] = newPlayers[i + 1];
    }

    (*size)--;
    printf("Player removed.\n");
}
void SearchPlayer(Players *newPlayers,int size)
{
    printf("Enter the choice for Search by id=1 or Search by Name=2");
    int ch;
    scanf("%d",&ch);
    if(ch==1 )
    {
    printf("Enter id of Player");
    int JerseyNum;
    scanf("%d",&JerseyNum);
       int index = SearchPlayerByJersey(newPlayers,size,JerseyNum);
       if(index!= -1)
       {
           Players p = newPlayers[index];
           printf("Player Details----");
           printf("Jersey Number :%d", p.jerseyNumber);
           printf("Names:%d", p.name);
           printf("Runs:%d", p.runs);
           printf("Wickets:%d", p.wickets);
           printf("Matches:%d", p.matches);
       }
    }
    else if(ch==2)
    {
    printf("Enter Name of Player");
    char JName[20];
    scanf("%s",&JName);
         
         int index = SearchPlayerByName(newPlayers,size,JName);

         if(index != -1)
         {
            printf("Player not found");
            return;
         }

         Players p = newPlayers[index];
         printf("Player Details----");
         printf("Jersey Number :%d",p.jerseyNumber);
         printf("Names:%d",p.name);
         printf("Runs:%d",p.runs);
         printf("Wickets:%d",p.wickets);
         printf("Matches:%d",p.matches);
    }
    else
    {
        printf("Invalid Choice");
    }
}
void UpdatePlayer(Players *newPlayers, int size)
{
      printf("Enter the choice:");
      int choice;
      scanf("%d",&choice);
     if(choice == 1)
     {
        printf("Enter the jersey number");
        int jersyNum ;
        scanf("%d",&jersyNum);
        printf("Enter new runs to be updated");
        int r ;
        scanf("%d",&r);
        for(int i =0;i<size;i++)
        {
            int index = SearchPlayerByJersey(newPlayers,size,jersyNum);
             newPlayers[index].runs = r;
        }
     }
     else if(choice == 2)
     {
        printf("Enter the jersey number");
        int jersyNumber;
        scanf("%d",&jersyNumber);
        printf("Enter new wickets to be updated");
        int w;
        scanf("%d",&w);
        for (int i = 0; i < size; i++)
        {
            int index = SearchPlayerByJersey(newPlayers, size, jersyNumber);
            newPlayers[index].wickets = w;
        }
     }
}
int  SearchPlayerByJersey(Players *newPlayers,int size, int JerseyNumber )
{
   

    for(int i=0;i<size;i++)
    {
        if(newPlayers[i].jerseyNumber== JerseyNumber )
        {
               return i; 
        }
    }
    return -1;
}
int SearchPlayerByName(Players *newPlayers,int size, char * PlayerName)
{
    for(int i=0;i<size;i++)
    {
            if(strcmp(newPlayers[i].name,PlayerName)==0)
            {
                return i;
            }
    }
    return -1;
}