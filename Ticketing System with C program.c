
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


struct visitData{
char *SrNo;
char *ticketNo;
char *Name;
char *ID;
};
struct ticket {
struct visitData visitor;
struct ticket *nextPtr;
};


struct ticket* head = NULL;


int number = 0;
int avasr = 1;
int exitkey;
char *sr;
char temper[];
char name[32];
char id[32];
char* tickno;
char* retrievesr();
int retrievetickno(char name[]);
void functionswitcher(int switcher);
void addvisitor(void);
void deletevisitor(void);
char* searchvisitor(void);
void Exit(int exitkey);

 int print_tickets(){
     struct ticket* curr =  head;
     while (curr != NULL) {
    printf("%s %s %s %s", curr->visitor.SrNo,curr->visitor.Name,curr->visitor.ticketNo,curr->visitor.ID);
    curr = curr->nextPtr;
  }
  printf("\n");
  return 0;}
void add_ticket(char name[],char* tickno,char* sr,char id[]){
struct ticket* new_ticket = (struct ticket*)malloc(sizeof(struct ticket));

if(name != NULL){new_ticket->visitor.Name = calloc(32,sizeof(char));
strcpy(new_ticket->visitor.Name, name);
new_ticket->visitor.ticketNo = calloc(32,sizeof(char));
strcpy(new_ticket->visitor.ticketNo, tickno);

new_ticket->visitor.SrNo= calloc(32,sizeof(char));
strcpy(new_ticket->visitor.SrNo, sr);
new_ticket->visitor.ID = calloc(32,sizeof(char));
strcpy(new_ticket->visitor.ID, id);

new_ticket->nextPtr = NULL;
FILE *out_file = fopen("Ticket.txt", "a");
fprintf(out_file, "%s  %s  %s  %s\n",sr,name,tickno,id);
fclose(out_file);
if(head == NULL) {

  head = new_ticket;
}
else{

  struct ticket* current = head;

  while (current->nextPtr != NULL) {
    current = current->nextPtr;
  }
  current->nextPtr = new_ticket;
}
number = number + 1;
}
FILE *fp = fopen("Ticket.txt","r");
FILE* fp_temp = tmpfile();
char buffer[1024];
fgets(buffer,1024,fp);
char buffer1[1024];
strcpy(buffer1,buffer);
printf("\n%s\n",buffer1);
sprintf(buffer,"Total visitor: %d",number);
printf("\n%s\n",buffer);
fprintf(fp_temp,"%s",buffer);
fseek(fp,0,SEEK_SET);
while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if(strcmp(buffer,buffer1) != 0){
        fputs(buffer, fp_temp);}
    }
fclose(fp_temp);
fclose(fp);
rename("Ticket.txt", "Ticket.tmp");
rename("Ticket.tmp", "Ticket.txt");

}

#define MAX_TOKENS 160
#define MAX_TOKEN_LENGTH 1024

void gettext()
{
    FILE* fl = fopen("Ticket.txt", "r");
    if (fl == NULL)
    {

        return;
    }


    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    for (int i = 0; i < MAX_TOKENS; i++)
    {
        tokens[i][0] = '\0';
    }


    char buffer[MAX_TOKEN_LENGTH];
    fgets(buffer, sizeof(buffer), fl);
    if(buffer[0] != '0'){
    fgets(buffer, sizeof(buffer), fl);


    char* token = strtok(buffer, "  ");
    int o = 0;
    while (token != NULL && o < MAX_TOKENS && token != "")
    {
        strncpy(tokens[o], token, MAX_TOKEN_LENGTH - 1);
        tokens[o][MAX_TOKEN_LENGTH - 1] = '\0';
        token = strtok(NULL, "  ");
        o++;
    }

    for (int r = 0; r < o; r += 4)
    {
        if (tokens[r][0] != '\0')
        {
            char* sr = tokens[r];
            char name[MAX_TOKEN_LENGTH];
            strncpy(name, tokens[r + 1], MAX_TOKEN_LENGTH - 1);
            name[MAX_TOKEN_LENGTH - 1] = '\0';
            char* tickno = tokens[r + 2];
            char id[MAX_TOKEN_LENGTH];
            strncpy(id, tokens[r + 3], MAX_TOKEN_LENGTH - 1);
            id[MAX_TOKEN_LENGTH - 1] = '\0';
            add_ticket(name,tickno,sr,id);

        }
    }

    }
    fclose(fl);
}


int main(void)
{
    puts("\n\n\n\n\n=========================================================");
    puts("\n\n\n\n\n=========================================================");
    puts("\n\n\n\n\n              Hello! Welcome To Our Theme Park           ");
    puts("\n\n\n\n\n=========================================================");
    puts("\n\n\n\n\n=========================================================");

    FILE* in_file = NULL;
    in_file = fopen("Ticket.txt","r");
    if(in_file == NULL){
        Exit(exitkey);
    }
    char checker[2];
    fscanf(in_file,"%s",checker);
    if(strcmp(checker,"") == 0){
        fclose(in_file);
        FILE* out_file = NULL;
        out_file = fopen("Ticket.txt","w");
        int num = 0;
        if(out_file == NULL){
            Exit(exitkey);
        }
        else{
        fprintf(out_file,"%d\n",num);
        fclose(out_file);}


    }
    else{
        fseek(in_file,0,SEEK_SET);
        fscanf(in_file,"%d",&number);
        fprintf("%d",number);
        fclose(in_file);
        avasr = number + 1;

    }
    gettext();
    functionswitcher(exitkey);
    printf("=================================");
    printf("            THANK YOU            ");
    printf("=================================");
    return 0;}




void addvisitor(){
    puts("\nplease enter your full name:");
    scanf("%c",&name);
    gets(name);
    int b = 0;

    while(name[b] != '\0')
    {
        if(name[b]==' ')
        {
            name[b]='_';
        }
        b++;
    }
    int idtype = 0;
    do {
    printf("\nplease enter 1 for local and 2 for international only:");
    scanf("%d",&idtype);
    }while ((idtype != 1) && (idtype != 2));

    puts("please enter your ID number (IC for local and Passport No. for international):");

    char idno[32];
    scanf("%s",idno);

    if(idtype == 1){
        sprintf(id,"IC%s",idno);
    }

    else if(idtype == 2){
        sprintf(id,"PASS%s",idno)  ;
    }

    sr= retrievesr();
    retrievetickno(name);
    tickno = temper;
    add_ticket(name,tickno,sr,id);
    functionswitcher(exitkey);}
void functionswitcher(exitkey){
    puts("\n\n\n If you want to add a new ticket enter 1");
    puts("\n If you would like to delete a visitor enter 2");
    puts("\n if you would like to search for a ticket enter 3");
    puts("\n if you would like to print all tickets enter 4");
    puts("\nif you would like to exit enter 0\n:");
    scanf("%d",&exitkey);

    while(exitkey != 0 && exitkey != 1 && exitkey != 2 && exitkey != 3 && exitkey != 4){
        puts("\n\n\n If you want to add a new ticket enter 1");
    puts("\n If you would like to delete a visitor enter 2");
    puts("\n if you would like to search for a ticket enter 3");
    puts("\n if you would like to search for a ticket enter 4");
    puts("if you would like to exit enter 0/n:");
    puts("You entered an invalid number, re-enter");
    scanf("%d",&exitkey);
    }
    if(exitkey == 1){
        addvisitor();
    }
    if(exitkey == 2){
        puts("--------DELETE FUNCTION----------");
        deletevisitor();
    }
    if(exitkey == 3){
        puts("-------SEARCH FUNCTION-----------");
        searchvisitor();
        functionswitcher(exitkey);
    }
    if(exitkey == 4){
        puts("-------List---------");
        print_tickets();
    }
    if(exitkey == 0){

        return;
    }
}


char* retrievesr(){
    int retsr = avasr;
    avasr++;
    char *withzero;
    if(retsr <= 9)
    {
        sprintf(withzero,"0%d",retsr);
    }
    else
    {
       sprintf(withzero,"%d",retsr);
    }
    return withzero;
}

int retrievetickno(char name[]){
    char namecode[100] = "";
    char *temp1;
    int namelen;
    for(char* e = name;*e;e++){
        if(*e != '_'){
            namelen++;
        }
    }
    int indexticket = 0;
    char* p = name;
    if(namelen < 6){
        for(int i = namelen; i<6; i++){
            strcat(namecode,"32");
        }
    int w = namelen;
        for(int w = 0; w <= 6 ; w++);
    {
         if(*p != "_"){
            sprintf(namecode,"%s%d",namecode, *p);}
        else{w = w - 1;}
        p++;

    }

        }

    else{
        for(int i = 0; i <= 6; i++){
            if(*p != "_"){
            sprintf(namecode,"%s%d",namecode, *p);}
            else{i--;}
            p++;
        }
    }

    strcat(namecode,sr);
    strcpy(temper,namecode);
    return 0;

    }

char* searchvisitor(){
     char push[100];
     puts("\ntype 1 to use name, 2 for ticket number and 3 for id\n :");
     scanf("%s",&push);
     while(push[0] != '1' && push[0] != '2' && push[0] != '3'){
        puts("\nonly from the chooses provided please");
        scanf("%s",&push);
     }
     int success = 0;
     struct visitData data = head->visitor;
     struct ticket *temp3 = head;
     struct ticket *temp4 = NULL;
    if(push[0] == '1'){
        puts("\ntype the name please");
        scanf("%c",&push);
        gets(push);
        int a = 0;
         while(push[a]!='\0')
    {
        if(push[a]==' ')
        {
            push[a]='_';
        }
        a++;}
        printf("%s",push);
        while (temp3 != NULL){
            if(strcmp(data.Name,push) == 0){
                printf("\n%s  %s  %s  %s",data.SrNo, data.Name, data.ticketNo, data.ID);
                success = 1;
                return temp3,temp4;
            }
            else{
                data = temp3->visitor;
                temp4 = temp3;
                temp3 = temp3->nextPtr;}

            }
            if(success == 0){
                puts("\n no data found");
            }


    }
    if(push[0] == '2'){
        puts("\ntype the ticket number please");
        scanf("%s",&push);
        while (temp3 != NULL){
            if(strcmp(data.ticketNo,push) == 0){
                printf("%s  %s  %s  %s",data.SrNo, data.Name, data.ticketNo, data.ID);
                success = 1;
                return temp3,temp4;
            }
            else{
                data = temp3->visitor;
                temp4 = temp3;
                temp3 = temp3->nextPtr;
            }
            if(success == 0){
                puts("\nno data found");
            }
}
    }
    if(push[0] == '3'){
        puts("\ntype 1 if its a local and 2 if its a international");
        scanf("%s",&push);
        while((push[0]!= '1') && (push[0] !='2')){
           puts("\ntype 1 if its a local and 2 if its a international");
            scanf("%s",&push);
        }
      if(push[0] == '1'){
      puts("\ntype the id number please");
        scanf("%s",&push);
        sprintf(push,"IC%s",push);
        }
        if(push[0] == '2'){
          puts("\ntype the id number please");
        char idnum[100];
        scanf("%s",&idnum);
        sprintf(push,"PASS%s",idnum);
        }
        while (temp3 != NULL){
            if(strcmp(data.ID,push) == 0){
                printf("\n%s  %s  %s  %s",data.SrNo, data.Name, data.ticketNo, data.ID);
                success = 1;
                return temp3,temp4;
            }
            else{
                data = temp3->visitor;
                temp4 = temp3;
                temp3 = temp3->nextPtr;
            }
            if(success == 0){
                puts("\n no data found");


    }
}
    }
functionswitcher(exit);
}

void deletevisitor(){
struct ticket *deletenode,*prevnode = searchvisitor();
if(deletenode == head){
    if(prevnode->nextPtr == NULL){
        head = NULL;
        puts("\n\nempty list\n\n");
    }
    else{
        head = deletenode->nextPtr;
        puts("\n\nfirst item removed\n\n");
    }
}
else{
if(deletenode->nextPtr = NULL){
    prevnode->nextPtr = NULL;
    puts("\n\nlast item removed\n\n");
}
else{
printf("%s %s",prevnode->visitor.Name,deletenode->visitor.Name);
prevnode->nextPtr = deletenode->nextPtr;
puts("\n\ndata deleted\n\n");}
functionswitcher(exit);
}}
void Exit(exitkey){}
