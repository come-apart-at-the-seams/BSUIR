
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int num;
  struct list *next, *prev;
} list;
typedef struct DblList {
    size_t size;
    list *head;
    list*tail;
} DblList;

void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->num); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}


void add(DblList *lst, int number);
//void izi(int izi_arr[]);
int division(DblList *lst);
DblList* createDblList(void);
void deleteDblList(DblList **lst);
void printInt(int value);
void printDblList(DblList *lst, void (*fun)(int));
void popFront(DblList *lst);



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Enter num: ");
    int q,i=0;
    char str[10000];
    scanf("%s",str);
    DblList *lst = createDblList();
    for (i = 0; str[i] != '\0'; i++){
        q=str[i]-'0';
        printf("%d\n",q);
            add(lst, q);
        
    }
    printDblList(lst, printInt);
    division(lst);
    return 0;
}






void add(DblList *lst, int number)
{
    list *tmp = (list*)malloc(sizeof(list));
    if(tmp==NULL) printf("ERROR. x00911");
    tmp->num = number;
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


int division(DblList *lst){
    list *p=lst->head;
    int n=0,k=2;
    while(p!=lst->tail || p->num!=1){
        k=2;
        do {
            if(p == NULL && n!=0) {
                n=0;
                k++;
                p=lst->head;
            }
            
            n+=p->num;
            if(n<k){
                n*=10;
            }
            else{
                n%=k;
                n*=10;
            }
            p = p->next;
        } while (p != NULL || n!=0);
        n=0;
        p=lst->head;
        do {
            n+=p->num;
            if(n<k){
                n*=10;
                p->num=0;
                if(p==lst->head) popFront(lst);
            }
            else{
                p->num=n/k;
                n%=k;
                n*=10;
            }
            p = p->next;
        } while (p != NULL);
        printf("%d ", k);
        p=lst->head;
    }
    printf(" <- Answer\n");
    return k;
}

void popFront(DblList *lst) {
    list *prev;
    if (lst->head == NULL) {
        exit(2);
    }
 
    prev = lst->head;
    lst->head = lst->head->next;
    if (lst->head) {
        lst->head->prev = NULL;
    }
    if (prev == lst->tail) {
        lst->tail = NULL;
    }
    free(prev);
    lst->size--;
}
DblList* createDblList() {
    DblList *tmp = (DblList*) malloc(sizeof(DblList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void deleteDblList(DblList **lst) {
    list *tmp = (*lst)->head;
    list *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*lst);
    (*lst) = NULL;
}


void printDblList(DblList *lst, void (*fun)(int)) {
    list *tmp = lst->head;
    while (tmp) {
        fun(tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
}

void printInt(int value) {
    printf("%d ", value);
}
