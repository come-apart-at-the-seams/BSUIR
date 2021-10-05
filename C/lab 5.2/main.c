
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    int i;
    struct _Node *next;
    struct _Node *prev;
} Node;
typedef struct _DblList {
    size_t size;
    Node *head;
    Node *tail;
} DblList;
typedef struct _Tree {
    int data;
    struct _Tree *left;
    struct _Tree *right;
    struct _Tree *parent;
} Tree;
typedef struct _ONode { 
    int i;
    Tree root;
    struct _ONode *next;
} ONode;



DblList* createDblList(void);
void pushBack(DblList *list, unsigned int n);
Tree* getTree(int value, Tree *parent);
int getMax(Tree *root);
void push(ONode **head, int data, Tree *root);
Node* getNth(DblList *list, size_t index);
void* deleteNth(DblList *list, size_t index);
void insert(Tree **head, int value);
void pop(ONode **head);



int main(int argc, const char * argv[]) {
    // insert code here...
    
    unsigned int n=0, l=0;
    printf("Enter the n: ");
    scanf("%u", &n);
    printf("Enter the length of the DdlList: ");
    scanf("%u", &l);
    DblList *list = createDblList();
    pushBack(list, n);
    for (unsigned int j = 0; j<l; j++) {
        pushBack(list, n);
    }
    
    ONode* head = NULL;
    
    for(int j=0; j<n;j++){
        
       // Tree *root= (Tree*) malloc(sizeof(Tree));
        Tree *root=NULL;
        Node *tmp = list->head;
        int o=0;
        while (tmp) {
            if(tmp->i==j){
                insert(&root, tmp->value);
                o++;
            }
            tmp = tmp->next;
        }
        if(o==0) insert(&root, 0);
        
        push(&head, j, root);
        
    }
    for (int j=0; j<n; j++) {
        pop(&head);
    }
    return 0;
}





DblList* createDblList() {
    DblList *tmp = (DblList*) malloc(sizeof(DblList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}
void pushBack(DblList *list, unsigned int n) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("ERROR");
    }
    tmp->value = rand()%1000;
    tmp->i = rand()%n;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}
Tree* getTree(int value, Tree *parent) {
    Tree* tmp = (Tree*) malloc(sizeof(Tree));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}
void insert(Tree **head, int value) {
    Tree *tmp = NULL;
    
    if (*head == NULL) {
        *head = getTree(value, NULL);
        return;
    }
     
    tmp = *head;
    while (tmp) {
        if (value>tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getTree(value, tmp);
                return;
            }
        } else if (value<tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getTree(value, tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}
int getMax(Tree *root) {
    //if(!root->right)return root->data;
    while (root->right) {
        root = root->right;
    }
    return root->data;
}
void push(ONode **head, int j, Tree *root ) {
   /* Tree *root= (Tree*) malloc(sizeof(Tree));
    Node *tm = list->head;
    int o=0;
    while (tm) {
        if(tm->i==j){
            insert(&root, tm->value);
            o++;
        }
        tm = tm->next;
    }
    if(o==0) insert(&root, 0);*/
    ONode *tmp = (ONode*) malloc(sizeof(ONode));
    
    tmp->i = j;
    
    tmp->root = *root;
    tmp->next = (*head);
    (*head) = tmp;
    
}
Node* getNth(DblList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;
 
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
 
    return tmp;
}
void* deleteNth(DblList *list, size_t index) {
    Node *elm = NULL;
    int *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = &elm->value;
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
    return tmp;
}
void popp(ONode **head) {
    ONode *pFwd = NULL;  //текущий узел
    ONode *pBwd = NULL;  //предыдущий узел
    //Получили NULL
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
     
    pFwd = *head;
    while (pFwd->next) {
        pBwd = pFwd;
        pFwd = pFwd->next;
    }
    
    if (pBwd == NULL) {
        pBwd=*head;
        int d =getMax(&pBwd->root);
        printf("%d\n", d);
        free(*head);
        *head = NULL;
    } else {
        int d =getMax(&pFwd->root);
        printf("%d\n", d);
        free(pFwd->next);
        pBwd->next = NULL;
    }
}
void popt(ONode **head){
    ONode *tmp = NULL;
    if (!head) {
        exit(-1);
    }
    //Список пуст
    if (!(*head)) {
        exit(-1);
    }
    tmp=*head;
    int d =getMax(&tmp->root);
    printf("%d\n", d);
    if(tmp->next){
        head=&tmp->next;
    }
    else head=NULL;
}

void pop(ONode **head) {
    ONode* prev = NULL;
    
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    int d =getMax(&prev->root);
    printf("%d\n", d);
    
    (*head) = (*head)->next;
    free(prev);
    
}
