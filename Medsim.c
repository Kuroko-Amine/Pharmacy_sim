#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<time.h>
int flag =1 ;
int tab[30] ;
void clearScreen() {
    system("cls");
}

void draw(){
printf("\033[1;32m"); // Activer la couleur verte 
    printf("           .........           \n");
    printf("       .:-+***++++++=-:.       \n");
    printf("     .-***-.........-+++-..    \n");
    printf("   .:+*=...:+++++++:...-++:.   \n");
    printf("  .-*+..   :+++++++:.  ..=+-.  \n");
    printf(" .-*=..    :+++++++:.    .-+-. \n");
    printf("..++.:======+++++++======:.=+:.\n");
    printf(".-+-.-+++++++++++++++++++=.:+=.\n");
    printf(".-+:.-+++++++++++++++++++=.:+=.\n");
    printf(".-*-.-+++++++++++++++++++=.:*=.\n");
    printf(".:*=.:+++++++++++++++++++-.=*:.\n");
    printf(" .-*-......:+++++++:......-*=.. \n");
    printf("  .-+=.    :+++++++:.   .=*=.   \n");
    printf("   .:++:.. :+++++++:...-**-..   \n");
    printf("    ..-+*+:.........-+**=..     \n");
    printf("      ..:=+***+++****=:..       \n");
    printf("          ....:::....           \n");
printf("\033[0m"); // Désactiver la couleur
    printf("\n\n");
}


void dire(const char *message) {
    int i = 0;
    while (message[i] != '\0') {
        putchar(message[i]);
        fflush(stdout); // Pour forcer l'affichage immédiat du caractère
        usleep(60000);
        i++;
    }
}


typedef struct{
    int d,m,y ;
}date;


typedef struct{
    char medn[50],medbr[50],info[256] ;
    int qunt , pr ;
    date manufact , ex ;
}medic ;


void verif(date ajd,int *flag){
    if(ajd.y<1900){*flag=0;}
if(ajd.m<1 || ajd.m > 12){*flag=0;}
 else switch (ajd.m){
    case 1: case 3 : case 5: case  7 : case 8 : case 10 : case 12 : if(ajd.d>31 || ajd.d<1){*flag = 0 ;}
    break ;
    case 2 : if(ajd.y%4==0){
        if(ajd.d>29 || ajd.d<1){*flag = 0 ;}
    }else {if(ajd.d<1 || ajd.d >28){*flag=0;}}
    break ;
    case 4 : case 6 : case 9 : case 11 : if(ajd.d<1 || ajd.d>30){*flag = 0 ;}
 }
}


void add(medic *A,int *n,date ajd){
char c ;
int i,j ;
int flig =1 ;
int flog =1 ;
int flg=1 ;
for(i=0;i<*n;i++){
    
    printf("\033[1;36m");
    do {
        flg=1;
        flig= 1 ;
        flog =1 ;
        flg =1 ;
        printf("enter the date of manufacture year then month then days of the product number%d \n",i+1) ;
        printf("yy : ") ;
        scanf("%d",&A[i].manufact.y) ;
        printf("mm : ");
        scanf("%d",&A[i].manufact.m) ;
        printf("dd : ");
        scanf("%d",&A[i].manufact.d) ;
        verif(A[i].manufact,&flig);
        if(flig==0){printf("ERROR \n");}
if(flig!=0){
    dire("enter the perumption date year month and day in this order \n");
    printf("yy : ") ;
    scanf("%d",&A[i].ex.y);
    printf("mm : ") ;
    scanf("%d",&A[i].ex.m);
    printf("dd : ") ;
    scanf("%d",&A[i].ex.d);
    verif(A[i].ex,&flog) ;
    if(flog==0){ printf("ERROR \n");}
    if(flog!=0){
        if(A[i].ex.y<ajd.y){flg = 0 ; printf("ERROR \n");}
        if(A[i].ex.y==ajd.y && A[i].ex.m<ajd.m){flg=0;printf("ERROR \n");}
        if(A[i].ex.y==ajd.y && A[i].ex.m==ajd.m && A[i].ex.d<ajd.d ){flg=0;printf("ERROR \n");}

        if(A[i].manufact.y>ajd.y){flg=0;printf("ERROR\n");}
        if(A[i].manufact.y==ajd.y && A[i].manufact.m>ajd.m){flg=0;printf("ERROR \n");}
        if(A[i].manufact.y==ajd.y && A[i].manufact.m==ajd.m && A[i].manufact.d>ajd.d){flg=0;printf("ERROR\n");}

        if(A[i].manufact.y>A[i].ex.y){flg=0;}
        if(A[i].manufact.y==A[i].ex.y && A[i].manufact.m>A[i].ex.m){flg=0;}
        if(A[i].manufact.y==A[i].ex.y && A[i].manufact.m==A[i].ex.m && A[i].manufact.d>A[i].ex.d){flg=0;}
    }
}
    }while(flg==0 || flog==0||flig==0) ;
    scanf("%c",&c);
dire("enter the name of your product: \n");
gets(A[i].medn) ;
dire("enter the brand of your product: \n");
gets(A[i].medbr) ;
dire("enter the price in DA of your product: \n");
scanf("%d",&A[i].pr);
dire("enter the quantity of your product: \n");
scanf("%d",&A[i].qunt);
printf("\033[0m");
printf("\033[1;31m"); // Change la couleur du texte en rouge
dire("Do you want to enter information about this product? \n");
printf("1:Yes \n2:no\n");

int ch ;
do{
    scanf("%d",&ch);
    if(ch<1 || ch >2 ) {printf("Please enter a number that corresponds to one of the options \n");}
}while(ch<1 || ch>2);
printf("\033[0m");
if(ch==1){
    scanf("%c",&c);
    printf("enter medication information\n");
    gets(A[i].info);
}else{
    strcpy(A[i].info, "your medicine does not have any information");
}

}

for(i=0;i<*n;i++){
    for(j=i+1;j<*n;j++){
        if(strcmp(A[i].medn,A[j].medn)==0 && strcmp(A[i].medbr,A[j].medbr)==0 && A[i].pr==A[j].pr){
            A[i].qunt=A[j].qunt+A[i].qunt ;
            for(int k=j;k<*n;k++) {
                A[k]=A[k+1];
            }
        (*n)--;
        j--;
    A=(medic*)realloc(A,(*n) * sizeof(medic)) ;
    if(A==NULL){
        printf("error realloc");
        exit(1);
    }
    }
    }

}

}


void one(date ajd,medic **A,int *n) {
    medic m ;
    char c;
    int flig = 1;
    int flog = 1;
    int flg = 1;
    
    do {
        printf("\033[1;36m");
        flig = 1;
        flog = 1;
        flg = 1;
        dire("Enter the date of manufacture year, then month, then days of the product: ");
        printf("\n");
        printf("yy : ") ;
        scanf("%d", &(m.manufact.y));
        printf("mm : ") ;
        scanf("%d", &(m.manufact.m));
        printf("dd : ") ;
        scanf("%d", &(m.manufact.d));
        
        verif(m.manufact, &flig);
        if (flig == 0) {
            printf("Error\n");
        }
if(flig!=0){
        dire("Enter the expiration date year, month and day in this order :");
        printf("\n");
        printf("yy : ") ;
        scanf("%d", &(m.ex.y));
        printf("mm : ") ;
        scanf("%d", &(m.ex.m));
        printf("dd : ") ;
        scanf("%d", &(m.ex.d));
        
        verif(m.ex, &flog);
        if (flog == 0) {
            printf("ERROR\n");
        }
    if(flog!=0){
        if (m.ex.y < ajd.y) {
            flg = 0;
            printf("ERROR\n");
        }
        if (m.ex.y == ajd.y && m.ex.m < ajd.m) {
            flg = 0;
            printf("ERROR\n");
        }
        if (m.ex.y == ajd.y && m.ex.m == ajd.m && m.ex.d < ajd.d) {
            flg = 0;
            printf("ERROR\n");
        }
        
         if(m.manufact.y>ajd.y){flg=0;printf("ERROR \n");}
        if(m.manufact.y==ajd.y && m.manufact.m>ajd.m){flg=0;printf("ERROR \n");}
        if(m.manufact.y==m.ex.y && m.manufact.m==ajd.m && m.manufact.d>ajd.d){flg=0;printf("ERROR \n");}



        if (m.manufact.y > m.ex.y) {
            flg = 0;
        }
        if (m.manufact.y == m.ex.y && m.manufact.m > m.ex.m) {
            flg = 0;
        }
        if (m.manufact.y == m.ex.y && m.manufact.m == m.ex.m && m.manufact.d > m.ex.d) {
            flg = 0;
        }
    }
}
    } while (flg == 0 || flog == 0 || flig == 0);
    
    // Consommer le caractère de nouvelle ligne restant dans le tampon d'entrée
    scanf("%c", &c);
    dire("Enter the name of your product: ");
    printf("\n");
    gets(m.medn);
    dire("Enter the brand of your product:");
    printf("\n");
    gets(m.medbr);
    dire("Enter the price in DA of your product: ");
    printf("\n");
    scanf("%d", &(m.pr));
    dire("Enter the quantity of your product:");
    printf("\n");
    scanf("%d", &(m.qunt));
printf("\033[0m");
printf("\033[1;31m"); // Change la couleur du texte en rouge
dire("Do you want to enter information about this product? ");
printf("\n");
printf("1:yes \n2:no\n");
int ch ;
do{
    scanf("%d",&ch);
    if(ch<1 || ch >2 ) {printf("be sure to enter a number that matches one of the options \n");}
}while(ch<1 || ch>2);
printf("\033[0m");
if(ch==1){
    scanf("%c",&c);
    dire("enter the medication information: ");
    printf("\n");
    gets(m.info);
}else{
    strcpy(m.info, "your medicine does not have any information");
}
    (*n)++ ;
*A = (medic*)realloc(*A,(*n)*sizeof(medic));
if(*A==NULL){
    printf("ERORR REALLOC");
    exit(1);
}
(*A)[*n - 1]=m;
int i , j ;
for(i=0;i < *n;i++){
    for(j=i+1;j < *n;j++){
        if(strcmp((*A)[i].medn,(*A)[j].medn)==0 && strcmp((*A)[i].medbr,(*A)[j].medbr)==0 && (*A)[i].pr==(*A)[j].pr){
            (*A)[i].qunt=(*A)[j].qunt+(*A)[i].qunt ;
            for(int k=j;k<*n;k++) {
                A[k]=A[k+1];
            }
        (*n)--;
        j--;
    *A=(medic*)realloc(*A,(*n) * sizeof(medic)) ;
    if(*A==NULL){
        printf("error realloc");
        exit(1);
    }
        }
    }
}
}

void display(medic *A , int n,date ajd){
    int i ;
     printf("--------------------------------------------------------------\n");
     if(n==0){
        printf("no medic left \n");
     }
else{
for(i=0;i<n;i++){
    printf("product num [ %d ] : \n",i+1);
    printf("the name of the product: [ %s ] \n",A[i].medn);
    printf("the name of the product brand: [ %s ] \n",A[i].medbr);
    printf("the price of the product: [%d DA] \n",A[i].pr) ;
    printf("the quantity of the product: [%d] \n",A[i].qunt) ;
    printf("the date of manufacture of the product: %d/%d/%d \n",A[i].manufact.y,A[i].manufact.m,A[i].manufact.d);
    printf("the expiration date of the product: %d/%d/%d \n",A[i].ex.y,A[i].ex.m,A[i].ex.d);
    if(A[i].ex.m==ajd.m  && A[i].ex.y==ajd.y && A[i].ex.d-ajd.d<5){
    printf("\033[0;31m"); 
    printf("This product doesn't have much left and is out of date.\n");
    printf("\033[0m");
    }
    printf("--------------------------------------------------------------\n");
}
}
}


void search(medic *A,int n,char *h,int sr,int *fi,int *k){
int i ;
int j=0 ;
*k=0;
int cmpt ;
for(i=0;i<n;i++){
    cmpt=0 ;
  for(j=0;j<sr;j++){
    if(h[j]==A[i].medn[j]){cmpt++ ;}
  }
    if(cmpt==sr){
        tab[*k]=i ;
        (*k)++;
    }
}
if(*k==0){printf("no medic start with this character \n");*fi=0;}
else {dire("here are the drugs found :"); printf("\n"); *fi=1;
for(i=0;i<*k;i++){
    printf("medic num [ %d ] : %s \n",i+1,A[tab[i]].medn);
}
} 
}

void upquant(medic *A ,int choix1 ,int quantiter,int vch,int *n){
    if(vch==1){
        A[choix1].qunt += quantiter ;}
    else if (vch==2){
        A[choix1].qunt = A[choix1].qunt - quantiter ;
        if(A[choix1].qunt==0){
            for(int k = choix1;k<*n-1;k++){
                A[k]=A[k+1];
            }
            (*n)--;
        }
    }
}

void delete(medic *A , int *n , int choix1){
 for(int k = choix1;k<*n-1;k++){
                A[k]=A[k+1];
            }
        (*n)--;

}

int main() {
draw();
medic *A;
FILE *fic ;
char c ;
int fi=0 ;
int n , choix,choix2,choix3,quantit ,save;
date ajd ;
int k=0;
dire("enter the date year then month then today's day");
printf("\n");
do{
    printf("yy : ") ;
    scanf("%d",&ajd.y);
    printf("mm : ") ;
    scanf("%d",&ajd.m);
    printf("dd : ") ;
    scanf("%d",&ajd.d) ;
    verif(ajd,&flag) ;
    if(flag==0){printf("error Date \n");}
    }while(flag==0) ;

printf("\033[1;31m"); 
dire("Do you want to load the old backup or start a new one?");
printf("\n");
printf("1: load Save \n2: Start New \n");
do{
scanf("%d",&save);
}while(save!=1 && save !=2 );
printf("\033[0m");
int ran=1;
while(ran){
    if(save ==2 ){
        printf("enter the number of medics you want \n");
        do{
            scanf("%d",&n);
        }while(n<=0) ;
        A = (medic*)malloc(n*sizeof(medic)) ;
        clearScreen();
        clearScreen();
        add(A,&n,ajd);
  
        display(A,n,ajd) ;
        ran=0;
    }
    else if(save ==1 ){
        fic=fopen("save.txt","r");
        if(fic==NULL) {printf("ERROR FILE OPENING");
                    exit(1);}
        if(fscanf(fic,"%d",&n)!=EOF){
            int i =0 ;
            medic temp;
            A = (medic*)malloc(n*sizeof(medic)) ;
            if(A==NULL){
                printf("ERROR ALLOCATION");
                exit(1);
            }
            int sah ;
        while(i<n && !feof(fic)){
            fscanf(fic,"%s %s %d %d %d %d %d %d %d %d",temp.medn,temp.medbr,&temp.qunt,&temp.pr,&temp.manufact.y,&temp.manufact.m,&temp.manufact.d,&temp.ex.y,&temp.ex.m,&temp.ex.d);
            fgets(temp.info,255,fic);
            if(temp.ex.y<ajd.y || temp.ex.y==ajd.y && temp.ex.m<ajd.m ||temp.ex.y==ajd.y && temp.ex.m==ajd.m && temp.ex.d<ajd.d){
                printf("the product [%s] has expired, do you still want to charge it?\n",temp.medn);
                printf("1 : yes \n2 : no \n") ;
                do{
                    scanf("%d",&sah);
                }while(sah!=1 && sah!=2 ) ;
                if(sah==1){
                     A[i]=temp;
                     i++;
            }else{n--;}
        }else{ A[i]=temp;
                i++;}          
        }
        ran=0;
        }else{printf("you did not save any information before \n");save=2;}
        
        fclose(fic) ;
}
}
int run = 1 ;
clearScreen();
while(run){
printf("\033[1;35m"); 
printf("\n---------------------------*MENU*--------------------------------------\n\n");
printf("1: search for a medicine \n2: ADD medication \n3: display medications \n4: clear the interface \n5: exit the program\n");
printf("\n----------------------------*MENU*--------------------------------------\n\n");
int sh ;
do{
    printf("choix : ");
scanf("%d",&sh);
if(sh<1 || sh>5){
    printf("please choose a number between 1 and 5");
}
}while(sh<1 || sh>5) ;
printf("\033[0m");
if(sh==1){
    clearScreen();
    clearScreen();
    printf("how many characters you want to enter to search for your product : \n");
    int sr ;
do{
    scanf("%d",&sr);
    if(sr<=0){
        printf("try entering the number of characters : \n");}
}while(sr <=0 ) ;
    char h[sr+1];
    h[sr+1]='\0';
    scanf("%c",&c);
    printf("enter your %d character \n",sr);
    gets(h);
    search(A,n,h,sr,&fi,&k);
if(fi==1){
    printf("--------------------------------------------------\n");
    printf("choose the medication you want to change : \n");
    do{
    scanf("%d",&choix);
    if(choix>k || choix<0){
        printf("Error!\n");
    }
    }while(choix>k);
    printf("\033[1;35m"); 
    printf("---------------------------------------------------\n");
    printf("what do you want to do ? \n");
    printf("1 : change the quantity of a med  \n");
    printf("2 : Remove medication \n");
    printf("3 : display medication information\n");
    printf("4: Go back to menu\n");
    printf("---------------------------------------------------\n");
    printf("\033[0m");
    do{
        printf("choice : ");
    scanf("%d",&choix2);
    if(choix2<1 || choix2 >4){
        printf("please choose between 1 and 2 and 3\n");
    }
    }while(choix2<1 || choix2>4);
    if(choix2==1){
        printf("want to increase or decrease the quantity? \n") ;
        printf("1: increase \n2: decrease \n ");
        do{
        scanf("%d",&choix3);
        }while(choix3<1 || choix3>2);
        if(choix3==1)
            {printf("give the quantity to add \n");
            do{
                scanf("%d",&quantit);
                }while(quantit<=0);
            }
        else{
            printf("enter the quantity to remove  \n");
            do{
                scanf("%d",&quantit);
            }while(quantit>A[tab[choix-1]].qunt||quantit<1);
        }
        upquant(A,tab[choix-1],quantit,choix3,&n);
    }else if(choix2==2){
        delete(A,&n,tab[choix-1]);}
    else if(choix2==3){
        printf("\033[1;32m");
        printf("\nHere is the information on the medication : \n");
        printf("%s\n",A[tab[choix-1]].info);
        printf("\n");
        printf("\033[0m");
    }    
        }
}else if(sh==3){
clearScreen();
clearScreen();
display(A,n,ajd);
}else{ if(sh==2){
    clearScreen();
    clearScreen();
    one(ajd,&A,&n);
   
    display(A,n,ajd); 
}}
if(sh==4){
    clearScreen();
    clearScreen();
     draw();
}
if(sh==5){
printf("\ndo you want to save ? 1: yes || 2: no \n");
int choix17;
scanf("%d",&choix17);
if(choix17==1){
fic=fopen("save.txt","w+");
if(fic==NULL){
    printf("\nERROR OPENING FILE\n");
    exit(1);
}
fprintf(fic,"%d\n",n);
for(int i=0 ; i<n ; i++){
fprintf(fic,"%s %s %d %d %d %d %d %d %d %d %s\n",A[i].medn,A[i].medbr,A[i].qunt,A[i].pr,A[i].manufact.y,A[i].manufact.m,A[i].manufact.d,A[i].ex.y,A[i].ex.m,A[i].ex.d,A[i].info);
}
}
    run=0;
}
}
free(A);

printf("projet fait par : Mohamed Amine Cherfaoui\n");
printf("Section A\n");
printf("Grp 4\n");

return 0;
}
