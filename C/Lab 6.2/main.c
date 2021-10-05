

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct list
{
    char Name[15], LastName[15], MatherName[15], BDay[11], PassNum[15], SocialNum[15], Education[30], Position[30],  DateOfEmployment[15], Salaru[10], NoteP[50], NoteM[50];
    struct list *next, *prev;
} list;
typedef struct DblList {
    size_t size;
    list *head;
    list*tail;
} DblList;

void add(DblList *lst, FILE *file);
DblList* createDblList(void);
void* popBack(DblList *lst);
void ex(DblList *lst, FILE *file);
void pFields(void);
void findFields(DblList *lst);
int mn(DblList *lst, FILE *file, char date_now[15]);
void Dismiss(DblList *lst);
void Recruit(DblList *lst);
void term(DblList *lst, char date_now[15]);
void OnVacation(DblList *lst, char date_now[15]);
void OnWork(DblList *lst, char date_now[15]);
void DismissP(DblList *lst, char date_now[15]);
void BD(DblList *lst, char date_now[15]);

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *file;
    struct tm *u;
    char date_now[15];
    time_t t=time(NULL);
    u=localtime(&t);
    strftime(date_now, 10, "%d.%m.%Y",u);
    if ((file = fopen("YOUR FILE LOCATION","r+")) == NULL){//FILE LOCATION
        printf("Error! opening file");
        return 0;
    }
    DblList *lst = createDblList();
    while(!feof(file)){
        add(lst, file);
    }
    
    while(mn(lst, file,date_now)!=0);
    
    
    return 0;
}

DblList* createDblList() {
    DblList *tmp = (DblList*) malloc(sizeof(DblList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}
void add(DblList *lst, FILE *file)
{
    list *tmp = (list*)malloc(sizeof(list));
    if(tmp==NULL) printf("ERROR. x00911");
    fscanf (file, "%s%s%s%s%s%s%s%s%s%s%s%s", tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
    tmp->next = NULL;
    tmp->prev = lst->tail;
    if (lst->tail) {
        lst->tail->next = tmp;
    }
    lst->tail = tmp;
    
    if (lst->head == NULL) {
           lst->head = tmp;
       }
       lst->size++;
}

void* popBack(DblList *lst) {
    list *next;
    void *tmp = NULL;//deleelle null
    if (lst->tail == NULL) {
        exit(4);
    }
 
    next = lst->tail;
    lst->tail = lst->tail->prev;
    if (lst->tail) {
        lst->tail->next = NULL;
    }
    if (next == lst->head) {
        lst->head = NULL;
    }
    //tmp = next->value;
    free(next);
 
    lst->size--;
    return tmp;
}

void ex(DblList *lst, FILE *file){
    list *tmp=lst->head;
    file = fopen("/Users/ignat/Documents/Lab 6.2/Untitled.txt","w");
    while(tmp){
        fprintf(file, "%s %s %s %s %s %s %s %s %s %s %s %s",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        tmp = tmp->next;
        if (tmp) fprintf(file, "\n");
    }
    
}
void findFields(DblList *lst){
    list *tmp=lst->head;
    char a[50];
    int f, ii=0;
    pFields();
    printf("\nWhat field is being searched: ");
    scanf("%d", &f);
    printf("\nWhat to find: ");
    scanf("%s", a);
    switch (f) {
        case 1:
            while(tmp){
            if(strcmp (a, tmp->Name)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 2:
            while(tmp){
            if(strcmp (a, tmp->LastName)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 3:
            while(tmp){
            if(strcmp (a, tmp->MatherName)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                    ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 4:
            while(tmp){
                if(strcmp (a, tmp->BDay)==0){
                    printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                    ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 5:
            while(tmp){
            if(strcmp (a, tmp->PassNum)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 6:
            while(tmp){
            if(strcmp (a, tmp->SocialNum)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 7:
            while(tmp){
            if(strcmp (a, tmp->Education)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 8:
            while(tmp){
            if(strcmp (a, tmp->Position)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 9:
            while(tmp){
            if(strcmp (a, tmp->Salaru)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 10:
            while(tmp){
            if(strcmp (a, tmp->DateOfEmployment)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 11:
            while(tmp){
            if(strcmp (a, tmp->NoteP)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            case 12:
            while(tmp){
            if(strcmp (a, tmp->NoteP)==0){
                printf("%s %s %s %s %s %s %s %s %s %s %s %s\n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
                ii++;
                }
                tmp = tmp->next;
            }
            break;
            
            
        default:
            findFields(lst);
            break;
    }
    if(ii==0) printf("Your search - %s - did not match any documents.", a);

}


void pFields(){
    printf("1. Name, 2. LastName, 3. MatherName, 4. BDay, 5. PassNum, 6. SocialNum, 7. Education, 8. Position, 9. Salaru, 10. DateOfEmployment, 11. NoteP, 12. NoteM.");
}


int mn(DblList *lst, FILE *file, char date_now[15]){
    int key=0;
    printf("\nMenu\n");
    printf("\t1. Find person; \n");
    printf("\t2. Dismiss; \n");
    printf("\t3. Recruit; \n");
    printf("\t4. Term of the work; \n");
    printf("\t5. On work & on vacation; \n");
    printf("\t6. BDay; \n");
    printf("\t7. DismissP; \n");
    printf("\t0. Exit; \n");
    scanf("%d", &key);
    switch (key) {
        case 0:
            ex(lst, file);
            fclose(file);
            break;
        case 1:
            findFields(lst);
            break;
        case 2:
            Dismiss(lst);
            break;
        case 3:
            Recruit(lst);
            break;
        case 4:
            term(lst, date_now);
            break;
        
        case 6:
            BD(lst, date_now);
        case 7:
            DismissP(lst, date_now);
            break;
        default:
            mn(lst, file, date_now);
            break;
    }
    return key;
}

void Dismiss(DblList *lst) {
    printf("\nDismiss\n\tEnter the full name & PassNum (Name LastName MatherName PassNum): ");
    char name[15], lastN[15], matherN[15], pass[15];
    scanf("%s %s %s %s", name, lastN, matherN, pass);
    list *tmp = lst->head;
    while (tmp) {
        if((strcmp (name, tmp->Name)==0)&& (strcmp(lastN, tmp->LastName)==0)&& (strcmp(matherN, tmp->MatherName)==0) && (strcmp(pass, tmp->PassNum)==0)){
            if (tmp->prev) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
            if (!tmp->prev) {
                lst->head = tmp->next;
            }
            if (!tmp->next) {
                lst->tail = tmp->prev;
            }
            free(tmp);
            lst->size--;
            printf("FARED");
        }
        tmp=tmp->next;
    }
    
}
void Recruit(DblList *lst)
{
    list *tmp = (list*)malloc(sizeof(list));
    if(tmp==NULL) printf("ERROR. x00911");
    printf("\nEnter\t");
    pFields();
    printf("\n");
    scanf ("%s %s %s %s %s %s %s %s %s %s %s %s", tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
    tmp->next = NULL;
    tmp->prev = lst->tail;
    if (lst->tail) {
        lst->tail->next = tmp;
    }
    lst->tail = tmp;
    
    if (lst->head == NULL) {
           lst->head = tmp;
       }
       lst->size++;
}


int dateToInt(char date[15]){
    int d,m,y;
    d=(date[0]-'0')*10+(date[1]-'0');
    m=((date[3]-'0')*10+(date[4]-'0'))*30;
    y=(1000*(date[6]-'0')+100*(date[7]-'0')+10*(date[8]-'0')+(date[9]-'0'))*365;
    return d+m+y;
}
void term(DblList *lst, char date_now[15]){
    printf("\tEnter the name & LastName (Name LastName): ");
    char name[15], lastN[15];
    scanf("%s %s", name, lastN);
    list *tmp = lst->head;
    while (tmp) {
        if((strcmp (name, tmp->Name)==0)&& (strcmp(lastN, tmp->LastName)==0)){
            printf("\n%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
            float termD;
            termD = dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
            int termDInt=dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
            
            if(termD<=0) printf("Employee on vacation");
            else {
                printf("Term of the work is %f days or %f m or %f y\n" , termD , termD/30 , termD/365);
                if(termD>=182) printf("Needs a vacation %d weeks", (termDInt)*2);
            }
            
        }
        tmp=tmp->next;
    }
}
void OnVacation(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD;
    printf("\nEmployee on vacation:");
    while (tmp) {
        termD = dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
        if(termD<=0)
            printf("\n\t%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        tmp=tmp->next;
    }
}
void OnWork(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD;
    printf("\nEmployee on work:");
    while (tmp) {
        termD = dateToInt(date_now)-dateToInt(tmp->DateOfEmployment);
        if(termD>0)
            printf("\n\t%s %s %s %s %s %s %s %s %s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName,tmp->BDay,tmp->PassNum,tmp->SocialNum,tmp->Education,tmp->Position,tmp->Salaru,tmp->DateOfEmployment,tmp->NoteP,tmp->NoteM);
        tmp=tmp->next;
    }
}
void BD(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD;
    while (tmp) {
        termD = dateToInt(date_now)-dateToInt(tmp->BDay);
        if(termD%365<=30)
            printf("\n\t%s %s %s %s \n",tmp->Name,tmp->LastName,tmp->MatherName, tmp->BDay);
        tmp=tmp->next;
    }
    printf(": birthday is coming!!!\n");
}
void DismissP(DblList *lst, char date_now[15]){
    list *tmp = lst->head;
    int termD;
    printf("Приказ на увольнение всех пенсионеров.\n\n");
    while (tmp) {
        termD = dateToInt(date_now)-dateToInt(tmp->BDay);
        if(termD/365>=60){
            printf("%s %s %s, " ,tmp->Name,tmp->LastName,tmp->MatherName);
            
        }
            
        tmp=tmp->next;
    }
    printf(" прошу уволить по статье № 228 ч3 Трудового кодекса РФССР. \n Подпись   (@&$H@)ˆ     Булочкин Роман Кандратьевич\n");
}
