#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000
#define NUM_PLAYERS 20500

int num_players =0;

struct nfl_player
{
    char player_id[50];//end with tab
    char player_name[50];// end with tab
    char position[50]; //commnet
    char birthdate[50];//end with tab
    char college[50];//end with comma
    char teams[500];//tab seperated, end of line
};

int create_structs(struct nfl_player *players);

int find_teammates(struct nfl_player *players,char * name, int this_degree);


int player(char *name,struct nfl_player *p_players);

int format_teams(char * teams);

int search(char* college, struct nfl_player *p_players);

int main(int argc, char *argv[]) {
    struct nfl_player *p_players = malloc(NUM_PLAYERS * sizeof(struct nfl_player));



    create_structs(p_players);

    if(argc >= 2 && strcmp(argv[1],"--search") == 0)
    {
        printf("search\n");
        search(argv[2],p_players);
    }
    else if(argc >= 2 && strcmp(argv[1],"--player") == 0)
    {
        printf("player\n");
        player(argv[2],p_players);
    }
    else if(argc >= 2 && strcmp(argv[1],"--stats") == 0)
    {
        find_teammates(p_players,argv[2],1);
    }
    else if(argc >= 2 && strcmp(argv[1],"--distance") == 0)
    {
        printf("distance, not yet understood\n");
    }
    else if(argc >= 2 && strcmp(argv[1],"--oracle") == 0)
    {
        printf("oracle, not yet understood\n");
    }
    else{
        printf("invalid command or command not entered\n");
        find_teammates(p_players,"DixoRa20",1);
    }









   free(p_players);
    return 0;
}





int create_structs(struct nfl_player * players)
{
    FILE* file = fopen("nfl.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    char line[BUFFER];
    int current_player = 0;
    enum Field {
        player_id,
        player_name,
        position,
        birthdate,
        college,
        teams
    };

    char * token;

    enum Field currentfield = player_id;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        strcpy(players[i].player_id, "");
        strcpy(players[i].player_name, "");
        strcpy(players[i].position, "");
        strcpy(players[i].birthdate, "");
        strcpy(players[i].college, "");
        strcpy(players[i].teams, "");
    }

   while(fgets(line,sizeof(line),file))
   {

    currentfield = player_id;
    token = strtok(line,"\t");


    while(token != NULL)
    {

        switch(currentfield)
        {
            case player_id:
                strcpy(players[current_player].player_id, token);
                break;
            case player_name:
                strcpy(players[current_player].player_name, token);
                break;
            case position:
                strcpy(players[current_player].position, token);
                break;
            case birthdate:
                strcpy(players[current_player].birthdate, token);
                break;
            case college:
                strcpy(players[current_player].college, token);
                break;
            case teams:
                strcat(players[current_player].teams, "\t");
                strcat(players[current_player].teams, token);
                break;

        }
        token = strtok(NULL, "\t");
        if (currentfield !=5){
            currentfield++;
        }
    }
    current_player ++;
    num_players++;
   }
    fclose(file)

    return 0;

}


int player(char *name, struct nfl_player * p_players)
{

    for(int i = 0; i<num_players -1; i++)
    {
        if(strcmp(p_players[i].player_name,name) == 0)
        {
            printf("%s\t%s\t%s\t%s\n",p_players[i].player_id,p_players[i].player_name,p_players[i].position,p_players[i].college);
            format_teams(p_players[i].teams);
            printf("\n");

        }
    }

}


int format_teams(char * teams)
{
    char * token;

    token = strtok(teams,"\t");
    printf("\n");

    while(token != NULL)
    {
        printf("\t%s\n",token);

        token = strtok(NULL, "\t");
    }

}

int search(char* college, struct nfl_player *p_players)
{
    for(int i = 0; i<num_players -1; i++)
    {
        char * player_college = p_players[i].college;
        char * name = p_players[i].player_name;

        char * result = strstr(player_college,college);
        char * result2 = strstr(name,college);

        if(result != NULL || result2 !=NULL)
        {
            printf("%s\t%s\t%s\t%s",p_players[i].player_id,p_players[i].player_name,p_players[i].position,p_players[i].college);
            format_teams(p_players[i].teams);
            printf("\n");
        }
    }
}


int find_teammates(struct nfl_player *players,char * name,int this_degree)

{
    int capacity = num_players;
    int size = 0;



    char * listed_names[num_players];
    for (int i = 0; i < num_players; i++) {
    listed_names[i] = "";
}




    int contacts = 0;
    int player_index = -1;
    for(int i = 0; i<num_players -1; i++)
    {
        if(strcmp(players[i].player_id,name) == 0)
        {
            player_index = i;

        }
    }

    if (player_index == -1)
    {
        printf("player not found");
        return -1;
    }tely, Bob is labeled with a support phone number. Not to be deterred, you call and ask for help.


                {
                    char * check = strstr(listed_names[size],players[i].player_id);
                    if (check != NULL)
                    {
                    }
                    else{
                        listed_names[size] = players[i].player_id;
                        printf("1: %s 2: %s - %d\n",listed_names[size],players[i].player_id,k);
                        size ++;
                        break;
                    }
                }
            }
        }
        token = strtok(NULL, "\t"); // rotate through teams of POI
    }
    printf("%d",size);
}
