#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CREW_COUNT 10

// Enums for races, ranks, and posts
typedef enum
{
    TERRAN,
    MARTIAN,
    VENUSIAN,
    SATURIAN
} Race;

typedef enum
{
    SPACER,
    ENSIGN,
    LIEUTENANT,
    COMMANDER
} Rank;

typedef enum
{
    CREWMAN,
    COMMUNICATIONS_OFFICER,
    NAVIGATION_OFFICER,
    ENGINEERING_OFFICER,
    SECURITY_OFFICER,
    CAPTAIN
} Post;

// Struct for skills
typedef struct
{
    int navigation;
    int engineering;
    int tactics;
    int leadership;
    int diplomacy;
} Skills;

// Struct for abilities
typedef struct
{
    int charisma;
    int intelligence;
    int strength;
    int psionics;
    int agility;
} Abilities;

// Struct for CrewMember
typedef struct CrewMember
{
    int service_number;
    char *name;
    Race race;
    Rank rank;
    Post post;
    Abilities abilities;
    Skills skills;
    struct CrewMember *captain; // Make sure this member exists
} CrewMember;

void save_crew_list(CrewMember **crew, int count);

// Function to generate a new CrewMember
CrewMember *generate_crew_member(int service_number)
{
    CrewMember *crew = malloc(sizeof(CrewMember));
    if (!crew)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Assign service number
    crew->service_number = service_number;

    // Default name
    char default_name[50];
    snprintf(default_name, sizeof(default_name), "Crewman%d", service_number);
    crew->name = strdup(default_name);

    // Initialize skills with default values
    crew->skills.navigation = 0;
    crew->skills.engineering = 0;
    crew->skills.tactics = 0;
    crew->skills.leadership = 0;
    crew->skills.diplomacy = 0;

    // Default post and rank
    crew->post = CREWMAN;
    crew->rank = SPACER;

    // Initialize abilities
    crew->abilities.charisma = 13;
    crew->abilities.intelligence = 3;
    crew->abilities.strength = 18;
    crew->abilities.psionics = 5;
    crew->abilities.agility = 10;

    return crew;
}

// Function to display the crew list
void display_crew(CrewMember **crew, int count)
{
    printf("Captain : %s\n", crew[0]->name); // Assuming first crew member is captain
    printf("                        Skills           Abilities    \n");
    printf("Ser#   Post  Rank  | N  E  T  L  D  |  C  I  S  P  A  |  Race  Name\n");

    for (int i = 0; i < count; i++)
    {
        CrewMember *c = crew[i]; // Ensure `c` is declared

        // Print service number
        printf("%06d  ", c->service_number);

        // Print post and rank
        const char *post_str = (c->post == CAPTAIN) ? "Cap " : (c->post == COMMUNICATIONS_OFFICER) ? "Comm"
                                                           : (c->post == NAVIGATION_OFFICER)       ? "Nav "
                                                           : (c->post == ENGINEERING_OFFICER)      ? "Eng "
                                                           : (c->post == SECURITY_OFFICER)         ? "Sec "
                                                                                                   : "Crew";

        const char *rank_str = (c->rank == SPACER) ? "Spcr" : (c->rank == ENSIGN)   ? "Ens "
                                                          : (c->rank == LIEUTENANT) ? "Lt  "
                                                          : (c->rank == COMMANDER)  ? "Cmd "
                                                                                    : "Cmd";

        printf("%-4s %-4s  | %d  %d  %d  %d  %d  | %2d %2d %2d %2d %2d  | %c  %-8s\n",
               post_str, rank_str,
               c->skills.navigation,
               c->skills.engineering,
               c->skills.tactics,
               c->skills.leadership,
               c->skills.diplomacy,
               c->abilities.charisma,
               c->abilities.intelligence,
               c->abilities.strength,
               c->abilities.psionics,
               c->abilities.agility,
               (c->race == TERRAN) ? 'T' : (c->race == MARTIAN) ? 'M'
                                       : (c->race == VENUSIAN)  ? 'V'
                                                                : 'S',
               c->name);
    }
}
void save_crew_list(CrewMember **crew, int count)
{
    FILE *file = fopen("crewmember_list.txt", "w");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "Ser#   Post  Rank  | N  E  T  L  D  |  C  I  S  P  A  |  Race  Name\n");
    for (int i = 0; i < count; i++)
    {
        CrewMember *c = crew[i];
        fprintf(file, "%06d  ", c->service_number);

        const char *post_str;
        switch (c->post)
        {
        case CAPTAIN:
            post_str = "Cap";
            break;
        case COMMUNICATIONS_OFFICER:
            post_str = "Comm";
            break;
        case NAVIGATION_OFFICER:
            post_str = "Nav";
            break;
        case ENGINEERING_OFFICER:
            post_str = "Eng";
            break;
        case SECURITY_OFFICER:
            post_str = "Sec";
            break;
        default:
            post_str = "Crew";
        }

        fprintf(file, "%-4s  ", post_str);

        const char *rank_str;
        switch (c->rank)
        {
        case SPACER:
            rank_str = "Spcr";
            break;
        case ENSIGN:
            rank_str = "Ens";
            break;
        case LIEUTENANT:
            rank_str = "Lt";
            break;
        case COMMANDER:
            rank_str = "Comm";
            break;
        }

        fprintf(file, "%-4s  | ", rank_str);

        fprintf(file, "%d  %d  %d  %d  %d  | %2d %2d %2d %2d %2d  | %c  %-8s\n",
                c->skills.navigation,
                c->skills.engineering,
                c->skills.tactics,
                c->skills.leadership,
                c->skills.diplomacy,
                c->abilities.charisma,
                c->abilities.intelligence,
                c->abilities.strength,
                c->abilities.psionics,
                c->abilities.agility,
                (c->race == TERRAN) ? 'T' : (c->race == MARTIAN) ? 'M'
                                        : (c->race == VENUSIAN)  ? 'V'
                                                                 : 'S',
                c->name);

        fclose(file);
    }
}
// Function to assign a bridge post
void assign_bridge_post(CrewMember *crew_member, char post)
{
    switch (post)
    {
    case 'C':
        crew_member->post = COMMUNICATIONS_OFFICER;
        break;
    case 'N':
        crew_member->post = NAVIGATION_OFFICER;
        break;
    case 'E':
        crew_member->post = ENGINEERING_OFFICER;
        break;
    case 'S':
        crew_member->post = SECURITY_OFFICER;
        break;
    default:
        fprintf(stderr, "Invalid bridge post.\n");
        break;
    }
}

void set_captain(CrewMember **crew, int index)
{
    CrewMember *captain = crew[index];
    captain->post = CAPTAIN;
    captain->name = "Kerlin";  // Set the captain's name
    captain->rank = COMMANDER; // Assign proper rank

    // Set the captain pointer for all crew members
    for (int i = 0; i < CREW_COUNT; i++)
    {
        crew[i]->captain = captain;
    }
}

// User menu function
void user_menu(CrewMember **crew, int count)
{
    printf("Menu:\n");
    printf("(D) Display the crew list.\n");
    printf("(C #) Set the specified crew member as captain.\n");
    printf("(B # [post]) Assign the specified crew member to a bridge post.\n");
    printf("(N # [name]) Change the specified crew member's name.\n");
    printf("(S) Save the crew list to a file.\n");
    printf("(P) Play (exit).\n");

    while (1)
    {
        printf("Enter command: ");
        char command[10];
        int index;
        scanf("%s", command);

        if (command[0] == 'D')
        {
            display_crew(crew, count);
        }
        else if (command[0] == 'C' && sscanf(command + 1, "%d", &index) == 1 && index >= 1 && index <= count)
        {
            set_captain(crew, index - 1);
        }
        else if (command[0] == 'B' && sscanf(command + 1, "%d", &index) == 1 && index >= 1 && index <= count)
        {
            printf("Enter post (C, N, E, S): ");
            char post;
            scanf(" %c", &post);
            assign_bridge_post(crew[index - 1], post);
        }
        else if (command[0] == 'N' && sscanf(command + 1, "%d", &index) == 1 && index >= 1 && index <= count)
        {
            printf("Enter new name: ");
            char new_name[50];
            scanf("%49s", new_name);
            free(crew[index - 1]->name);
            crew[index - 1]->name = strdup(new_name);
        }
        else if (command[0] == 'S')
        {
            save_crew_list(crew, count);
        }
        else if (command[0] == 'P')
        {
            break; // Exit
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}

// Main function
int main()
{
    srand((unsigned int)time(NULL));

    CrewMember *crew[CREW_COUNT];
    for (int i = 0; i < CREW_COUNT; i++)
    {
        crew[i] = generate_crew_member(i + 1);
    }

    user_menu(crew, CREW_COUNT);

    // Free the memory allocated
    for (int i = 0; i < CREW_COUNT; i++)
    {
        free(crew[i]->name);
        free(crew[i]);
    }

    return 0;
}

