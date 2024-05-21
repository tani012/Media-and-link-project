#include <stdio.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char username[64];
    int mediaCount;
    int linkCount;
} User;

int main() {
    FILE *fp;
    char line[1024];
    User users[1024];
    int numUsers = 0;

    
    fp = fopen("yogesh.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

   
    const char linkPattern = "((https?|ftp)://[^\\s/$.?#].[^\\s])";

    regex_t regex;
    int ret = regcomp(&regex, linkPattern, REG_EXTENDED);
    if (ret != 0) {
        printf("Error compiling regular expression.\n");
        fclose(fp);
        return 1;
    }

    
    while (fgets(line, sizeof(line), fp) != NULL) {
      
        char *timestampEnd = strchr(line, '-');
        if (timestampEnd != NULL) {
           
            char *usernameStart = timestampEnd + 2;
           
            char *usernameEnd = strchr(usernameStart, ':');
            if (usernameEnd != NULL) {
                
                int usernameLength = usernameEnd - usernameStart;
                if (usernameLength > 0 && usernameLength < 64 - 1) {
                    char username[64];
                    strncpy(username, usernameStart, usernameLength);
                    username[usernameLength] = '\0';

                    
                    int isDuplicate = 0;
                    for (int i = 0; i < numUsers; i++) {
                        if (strcmp(users[i].username, username) == 0) {
                            isDuplicate = 1;
                            break;
                        }
                    }

                   
                    if (!isDuplicate) {
                        strcpy(users[numUsers].username, username);
                        users[numUsers].mediaCount = 0;
                        users[numUsers].linkCount = 0;
                        numUsers++;
                    }
                }
            }
            if (strstr(line, "<Media omitted>") != NULL) {
                users[numUsers - 1].mediaCount++;
            } else {
                ret = regexec(&regex, line, 0, NULL, 0);
                if (ret == 0) {
                    users[numUsers - 1].linkCount++;
                }
            }
        }
    }

    printf("\nUnique Usernames:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s\t INDEX %d\n", users[i].username, i);
    }
    printf("\t\t\t\t~~\n");
    printf("\t\t\t  To get the count of media and link enter the INDEX [ENTER -1 TO EXIT]");
    printf("\n\t\t\t\t~~");
    printf("\nOR Enter 1025 to get count of media and links that users shared separately\n");
    printf("OR Enter 1026 to get count of total media and links in chat\n");
    
    printf("\nEnter the value: ");
    int ind;
 
    scanf("%d",&ind);
    if(ind<=numUsers&& ind>=0){
        printf("\n");
        printf("Number of media %s sent: %d\n", users[ind].username,users[ind].mediaCount);
        printf("Number of links %s sent: %d\n", users[ind].username,users[ind].linkCount);
        printf("~");
        main();
    }
    else if(ind==1025){
    for(int i=0;i< numUsers;i++){
        printf("\n");
        printf("Number of media %s sent: %d\n", users[i].username,users[i].mediaCount);
        printf("Number of links %s sent: %d\n", users[i].username,users[i].linkCount);
        printf("\n");
    }
    printf("~");
    main();
    }
    else if(ind==1026){
     int sum_media=0,sum_link=0;
    for(int i=0;i< numUsers;i++){
       
        sum_media+=users[i].mediaCount;
        sum_link+=users[i].linkCount;
    }

    printf("\n");
    printf("Total Number of media in chat: %d\n",sum_media);
    printf("Total Number of links in chat: %d\n",sum_link);
    printf("\n");
    printf("~");

    main();
    }
else if(ind == -1){
        printf("EXITED THE PROGRAM\n");
        fclose(fp);
        return 0;
    }
else {
    printf("PLEASE ENTER A VALID INDEX\n");
    main();
    }

    fclose(fp);

    return 0;
}