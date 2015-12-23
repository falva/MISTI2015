#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funciones.c"

typedef struct _nodo {
   char socio[7];
   char sapat[30];
   char samat[30];
   char snombs[90];
   char sfnd[3];
   char sfnm[3];
   char sfna[5];
   char cgen[2];
   char sdcalle[30];
   char sdcnum[20];
   char sdcol[30];
   char sddmu[30];
   char sdedo[30];
   char sdcp[7];
   char stel[15];

   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

typedef struct _nodop {
   char cvepel[10];
   char stitulo[80];
   char sprot[90];
   char sdir[90];
   char sgen[30];
   char sdur[10];
   struct _nodop *sigpel;
} nodoPel;

typedef nodoPel *pelNodo;
typedef nodoPel *ListaPel;

Lista lista = NULL;
ListaPel listapel = NULL;

// Funciones con listas de asociados:
void insertara(Lista *lista);
void fLeeasoc(Lista *lista);
void Borrar();
void BorrarLista(Lista *);
void MostrarListaa();
void fConsA();
// Funciones con listas de Peliculas:
void insertarp(ListaPel *listapel);
void fLeepeli(ListaPel *listapel);
void Borrarpel(ListaPel *listapel);
void BorrarLPel(ListaPel *);
void MostrarListap();
void fConsP();

//Funciones genericas
void clscr();
void menup();
void menur();
void menua();
void menue();

int verifile(char sfile[12]);
int fValidas(char *s,int nTam);
int fValidasn(char *s,int nTam);
int bisiesto(int naeval);
int ftoup(char *s);
int fisvocal(char c);
void fvoltea(char* cini, char* cter);
int ias(int nval, char *strs);
void myfunc();

//void fvfilepeli();
//void fvfilemovs();

int main()
{
 //  Lista lista = NULL;
   pNodo p;
   int dato,i;
   char opcion;
   i=verifile("asoc.vdb");
   if(i!=0)
   {
      fLeeasoc(&lista);
     // MostrarListaa(lista);
     // getch();
   }else{return 0;}
   i=verifile("pelis.vdb");
   if(i!=0)
   {
      fLeepeli(&listapel);
     // MostrarListaa(lista);
     // getch();
   }else{return 0;}
   verifile("movs.vdb");
  // fvfilepeli();
  // fvfilemovs();
   while(1)
   {
      do
      {
          clscr();
          menup();
          opcion = toupper(getche());
      }while(opcion != 'R' && opcion != 'A' && opcion != 'P' && opcion != 'S');
      switch(opcion)
        {
         case 'R':
            menur();
            break;
         case 'A':
            menua(&lista);
            break;
          case 'P':
            menue();
            break;
        case 'S':
            clscr();
            printf("\n\n\n\n\t\t\t\t Gracias por tu visita, Vuelve pronto \n");
            getch();
            clscr();
            exit(0);

        default:
            printf("\n Opcion incorrecta, por favor utiliza R, A, P o S \n");
            getch();
            break;

        }

   }
   free(lista);
   return 0;
}

void menup()
{
    printf("\n\t    Menu Principal\n");
    printf("\t===================\n");
    printf("\n\t   [R]entas\n");
    printf("\n\t   [A]sociados\n");
    printf("\n\t   [P]eliculas\n");
    printf("\n\t   [S]alir\n");
    printf("\t===================\n");
    printf("\n\t    Selecciona una opcion (R, A, P, S):");
}

void menur()
{
    char orenta='R';
    while(orenta!='S')
    {
        do{
           clscr();
           printf("\n\t    Menu de Rentas\n");
           printf("\t===================\n");
           printf("\n\t   [R]entar\n");
           printf("\n\t   [D]evolver\n");
           printf("\n\t   [C]onsultar\n");
           printf("\n\t   [A]ltas\n");
           printf("\n\t   [S]alir (Regresar)\n");
           printf("\t===================\n");
           printf("\n\t    Selecciona una opcion (R, D, C, A, S):");
           orenta = toupper(getche());
        }while(orenta != 'R' && orenta != 'D' && orenta != 'C' && orenta != 'A' && orenta != 'S');
        switch(orenta)
        {
         case 'R':
            printf("\n Funcion de Renta en construccion \n");
            getch();;
            break;
         case 'D':
            printf("\n Funcion de Devolver en construccion \n");
            getch();
            break;
          case 'C':
            printf("\n Funcion de Consultar en construccion \n");
            getch();
            break;
          case 'A':
            printf("\n Funcion de Altas en construccion \n");
            getch();
            break;
          case 'S':
            printf("\n Regreso al menu principal \n");
            getch();
            break;
        default:
            printf("\n Opcion incorrecta, por favor utiliza R, D, P, A o S \n");
            getch();
            break;
        }
    }
}

void menua()
{
   // Lista lista = NULL;
    char oasoci='R';
    while(oasoci!='S')
    {
        do{
           clscr();
           printf("\n\t    Menu de Asociados\n");
           printf("\t===================\n");
           printf("\n\t   [A]ltas\n");
           printf("\n\t   [B]ajas\n");
           printf("\n\t   [C]ambios\n");
           printf("\n\t   c[O]nsultas\n");
           printf("\n\t   [L]ista de asociados\n");
           printf("\n\t   [S]alir (Regresar)\n");
           printf("\t===================\n");
           printf("\n\t    Selecciona una opcion (A, B, C, O, L, S):");
           oasoci = toupper(getche());
        }while(oasoci != 'A' && oasoci != 'B' && oasoci != 'C' && oasoci != 'L' && oasoci != 'O' && oasoci != 'S');
        switch(oasoci)
        {
         case 'A':
            printf("\n Alta de Asociados\n------------------------\n");
            insertara(&lista);
            break;
         case 'B':
            printf("\n Baja de Asociados\n------------------------\n");
            Borrar();
            break;
          case 'C':
            printf("\n Funcion de Cambios en construccion \n");
            getch();
            break;
          case 'O':
            printf("\n Consultas\n------------------------\n");
            fConsA();
            getch();
            break;
          case 'L':
            printf("\n Listado de Socios:\n------------------------\n");
            MostrarListaa();
            getch();
            break;
          case 'S':
            printf("\n Regreso al menu principal \n");
            getch();
            break;
        default:
            printf("\n Opcion incorrecta, por favor utiliza A, B, C, D o O \n");
            getch();
            break;
        }
    }
}

void menue()
{
    char opeli='R';
    while(opeli!='S')
    {
        do{
           clscr();
           printf("\n\t    Menu de Peliculas\n");
           printf("\t===================\n");
           printf("\n\t   [A]ltas\n");
           printf("\n\t   [B]ajas\n");
           printf("\n\t   [C]ambios\n");
           printf("\n\t   c[O]nsultar\n");
           printf("\n\t   [L]ista\n");
           printf("\n\t   [S]alir (Regresar)\n");
           printf("\t===================\n");
           printf("\n\t    Selecciona una opcion (A, B, C, O, L, S):");
           opeli = toupper(getche());
        }while(opeli != 'A' && opeli != 'B' && opeli != 'C' && opeli != 'O' && opeli != 'L' && opeli != 'S');
        switch(opeli)
        {
         case 'A':
            printf("\n Alta de Peliculas \n------------------------\n");
            insertarp(&listapel);
            break;
         case 'B':
            printf("\n Baja de Peliculas\n------------------------\n");
            Borrarpel(&listapel);
            break;
          case 'C':
            printf("\n Funcion de Cambios en construccion \n");
            getch();
            break;
          case 'O':
            printf("\n Consulta de Peliculas\n------------------------\n");
            fConsP();
            getch();
            break;
           case 'L':
            printf("\n Lista de Peliculas\n------------------------\n");
            MostrarListap();
            getch();
            break;
          case 'S':
            printf("\n Regreso al menu principal (oprima una tecla)\n");
            getch();
            break;
        default:
            printf("\n Opcion incorrecta, por favor utiliza A, B, C, D, L o O \n");
            getch();
            break;
        }
    }
}

int verifile(char sfile[12])
{
    int nex;
    FILE *fa;
    fa=fopen(sfile,"r");
    nex=1;
    if(fa==NULL)
    {
        printf("Error al abrir el archivo %s, se creara uno nuevo \n",sfile);
        fa=fopen(sfile,"w");
        getch();
        nex=0;
    }
    fclose(fa);
    return(nex);
}

void fLeeasoc(Lista *lista)
{
    pNodo nodo;
    char sclaf[7];
    char sNomf[50];
    char saPatf[30];
    char saMatf[30];
    char sFndf[3];
    char sFnmf[3];
    char sFnaf[5];
    int nGenf;
    char saCallef[30];
    char saNumf[30];
    char saColf[30];
    char saDmuf[30];
    char saEdof[30];
    char saCpf[7];
    char saTelf[15];
    char cGenf[3];
    FILE *fa;
    printf("Leyendo datos del archivo\n");
    fa=fopen("asoc.vdb","r");
    if(fa){
        rewind(fa);
        while(!feof(fa)){
           fscanf(fa," %[^\n]",sclaf);
           fscanf(fa," %[^\n]",saPatf);
           fscanf(fa," %[^\n]",saMatf);
           fscanf(fa," %[^\n]",sNomf);
           fscanf(fa," %[^\n]",sFndf);
           fscanf(fa," %[^\n]",sFnmf);
           fscanf(fa," %[^\n]",sFnaf);
           fscanf(fa," %[^\n]",cGenf);
           fscanf(fa," %[^\n]",saCallef);
           fscanf(fa," %[^\n]",saNumf);
           fscanf(fa," %[^\n]",saColf);
           fscanf(fa," %[^\n]",saDmuf);
           fscanf(fa," %[^\n]",saEdof);
           fscanf(fa," %[^\n]",saCpf);
           fscanf(fa," %[^\n]",saTelf);
           // Si la lista está vacía, la lista será el nuevo nodo
           //se crea un nodo para cada valor

           nodo = (pNodo)malloc(sizeof(tipoNodo));
           strcpy(nodo->socio,sclaf);
           strcpy(nodo->sapat,saPatf);
           strcpy(nodo->samat,saMatf);
           strcpy(nodo->snombs,sNomf);
           strcpy(nodo->sfnd,sFndf);
           strcpy(nodo->sfnm,sFnmf);
           strcpy(nodo->sfna,sFnaf);
           strcpy(nodo->cgen,cGenf);
           strcpy(nodo->sdcalle,saCallef);
           strcpy(nodo->sdcnum,saNumf);
           strcpy(nodo->sdcol,saColf);
           strcpy(nodo->sddmu,saDmuf);
           strcpy(nodo->sdedo,saEdof);
           strcpy(nodo->sdcp,saCpf);
           strcpy(nodo->stel,saTelf);
//         fread(&nodo,sizeof(tipoNodo),1,fa);
           if(*lista == NULL){
              *lista = nodo;
           }else{
              nodo->siguiente = (*lista)->siguiente;
           }
           // En cualquier caso, cerramos la lista circular
           (*lista)->siguiente = nodo;
        }
        printf("\n");
        fclose(fa);
     }else{
        printf("No se pudieron leer los datos, error al abrir el archivo!!!\n");
        getch();
        fclose(fa);
     }
}

void insertara(Lista *lista)
{
   pNodo nodo;

//-------------------------------------------------
    char scla[7];
    char sNombres[50];
    char saPat[30];
    char saMat[30];
    char sfn[11];
    int nGen;
    char saCalle[30];
    char saNum[30];
    char saCol[30];
    char saDmu[30];
    char saEdo[20];
    char sedo[20];
    char saCp[7];
    char saTel[15];
    int adm[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int i,j;
    int nfnd,nfnm,nfna;
    int nbrf,nbis,nfaa;
    int nfam,nfad,na;
    int nEst,nec;
    char cGen[3];
    char cECi;
    char cAux;
    char cFnd[3]; char cFnm[3]; char cFna[5];
    char sTel[20], sTelf[20];
    char sLnac;
    time_t fecnac;
    int lV,lC,lR,nB;
    FILE *fa;
    struct tm *tiempo;
    time_t fecha_sis;
    time(&fecha_sis);
    tiempo=localtime(&fecha_sis);
    nfaa=tiempo->tm_year+1900;
    nfam=tiempo->tm_mon+1;
    nfad=tiempo->tm_mday;

    //Comenzamos introduciendo datos
    //solicita el nombre de la persona
    do
    {
       printf("Alta de Socios\n\n\n");
       lR=0;
      do //clave de socio
      {
         printf("Asigne una clave (1 letra y 4 numeros) : ");
         lR=fValidasn(scla,7);
         if(lR==0)
         {
            printf("Error: no se ingreso la clave de socio!!! \n");
         }else{
            ftoup(scla);
         }
      }while(lR==0);
       lR=0;
       do //Apellido Paterno
       {
          printf("Dame el Apellido Paterno: ");
          lR=fValidas(saPat,30);
          if(lR==0)
          {
             printf("Error: no se ingreso el Apellido Paterno!!! \n");
          }else{
              ftoup(saPat);
          }
       }while(lR==0);
       lR=0;
       do //apellido materno
       {
          printf("Dame el Apellido Materno: ");
          lR=fValidas(saMat,30);
          if(lR==0)
          {
             printf("Error: no se ingreso el Apellido Materno!!! \n");
          }else{
              ftoup(saMat);
          }
       }while(lR==0);
       lR=0;
       do //Nombre
       {
          printf("Dame el(los) nombre(s) de la persona: ");
          lR=fValidas(sNombres,50);
          if(lR==0)
          {
             printf("Error: no se ingreso el (los) Nombre(s)!!! \n");
          }else{
              ftoup(sNombres);
          }
       }while(lR==0);

       lR=0;
       //2.- Se solicita y valida la fecha de nacimiento:
         do
        {

        printf("Introduce la fecha de nacimiento\n");
        do
        {
            do
            {
                printf("Dia (dd): ");
                scanf("%i",&nfnd);
                if((nfnd<1)||(nfnd>31))
                {
                    printf("error!!!: los dias del mes no pueden ser mayores de 31 ni menores de 1\n");
                }
            }
            while((nfnd<1)||(nfnd>31));
            do
            {
                printf("Mes (mm): ");
                scanf("%i",&nfnm);
                if((nfnm<1)||(nfnm>12))
                {
                    printf("error!!!: Los meses van de 1 (enero) a 12 (diciembre) favor de corregir\n");
                }
            }
            while((nfnm<1)||(nfnm>12));
            nbis=0;
            if(nfnm==2)
            {
                if(nfnd>29)
                {
                    nbis=1;
                    printf("error!!!: El mes 02 no puede tener mas de 29 dias, favor de corregir\n");
                }
            }
            else
            {
                if(nfnd>adm[nfnm-1])
                {
                    printf("error!!!: El mes %i no puede tener mas de %i dias, favor de corregir\n",nfnm,adm[nfnm-1]);
                    nbis=1;
                }
            }

        }while(nbis==1);

        printf("Anio (aaaa): ");
        scanf("%i",&nfna);
        if(nfna<10){nfna+=2000;}
        if(nfna<100){nfna+=1900;}
        if(nfna>nfaa)
        {
            printf("Error!!!, el anio de nacimiento no puede ser mayor al actual!!!!\n");
        }
        else
        {
            if(nfna==nfaa)
            {
                na=nfna;
                if(nfnm>nfam)
                {
                    printf("Error!!!, si nacio en este anio, deberia nacer antes de este mes!!!\n ");
                }
                else
                {
                    if(nfnm==nfam)
                    {
                        if(nfnd>nfad)
                        {
                            printf("Error, si nacio en este anio y mes, debería haber nacido antes de hoy!!!\n ");
                        }
                        else
                        {
                            nbrf=1;
                        }
                    }
                    else
                    {
                        nbrf=1;
                    }
                }
            }
            else
            {
                nbrf=1;
            }
        }
        /*Revisa si efectivamente es bisiesto*/
        if((nfnd==29)&&(nfnm==2)&&(bisiesto(nfna)==0))
        {
            nbrf=0;
            printf("error!!!: El anio seleccionado no es bisiesto,\n por lo que el mes 2 no puede tener 29 dias\n");

        }
        if((nfnd==29)&&(nfnm==2)&&(bisiesto(nfna)==1))
        {
            lR++;
            nfnd--;
        }
    }while(nbrf==0);
    printf("Fecha de Nacimiento: ");

    if(nfna>1900)
    {
       nfna-=1900;
    }
    na=nfna;
    ias(na,cFna);
    ias(nfnm,cFnm);
    ias(nfnd,cFnd);
    printf("Dia: %s",&cFnd);
    printf(" Mes: %s",&cFnm);
    printf(" Anio: %s\n",&cFna);
    sfn[0]=' ';
    strcat(sfn,cFnd);strcat(sfn,"/");strcat(sfn,cFnm);strcat(sfn,"/");strcat(sfn,cFna);
    printf(" %s \n",&sfn);
    i=0;
    do{ //Genero
       printf("Genero (1-Hombre, 2-Mujer): ");
       scanf("%i",&nGen);
       if(nGen==1){
           i=1;
           strcpy(cGen,"1");
       }else{
           if(nGen==2){
              i=1;
              strcpy(cGen,"2");
           }else{
               printf("Por favor, selecciona 1 para hombre o 2 para mujer \n");
           }
       }
     }while(i==0);
     printf("Domicilio: \n");
     lR=0;
     do //calle
     {
        printf("Calle: ");
        lR=fValidasn(saCalle,30);
        if(lR==0)
        {
           printf("Error: no se ingreso la calle!!! \n");
        }else{
           ftoup(saCalle);
        }
      }while(lR==0);
     lR=0;
     do //Numero
     {
       printf("Numero: ");
       lR=fValidasn(saNum,30);
       if(lR==0)
       {
          printf("Error: no se ingreso el numero!!! \n");
       }else{
          ftoup(saNum);
       }
      }while(lR==0);
      lR=0;
      do //Colonia
      {
         printf("Colonia: ");
         lR=fValidasn(saCol,30);
         if(lR==0)
         {
            printf("Error: no se ingreso la colonia!!! \n");
         }else{
            ftoup(saCol);
         }
      }while(lR==0);
      lR=0;
      do //del municipio
      {
         printf("Delegacion o Municipio: ");
         lR=fValidas(saDmu,30);
         if(lR==0)
         {
            printf("Error: no se ingreso la Delegacion o Municipio!!! \n");
         }else{
            ftoup(saDmu);
         }
      }while(lR==0);
      lR=0;
      do //Estado
      {
         printf("Estado: ");
         lR=fValidas(saEdo,20);
         if(lR==0)
         {
            printf("Error: no se ingreso el Estado!!! \n");
         }else{
            ftoup(saEdo);
         }
      }while(lR==0);
      strcpy(sedo,saEdo);
      lR=0;
      do //CP
      {
         printf("Codigo Postal: ");
         lR=fValidasn(saCp,5);
         if(lR==0)
         {
            printf("Error: no se ingreso el Codigo Postal!!! \n");
         }else{
            ftoup(saCp);
         }
      }while(lR==0);
      lR=0;
      do //Telefono
      {
         printf("Telefono: ");
         lR=fValidasn(saTel,15);
         if(lR==0)
         {
            printf("Error: no se ingreso el numero telefonico!!! \n");
         }else{
            ftoup(saTel);
         }
      }while(lR==0);
   strcpy(saEdo,sedo);
   }while (lR==1);  //Controla la repe

//-------------------------------------------------

   //lee nodos del archivo:
   printf("Escribiendo datos al archivo\n");
   fa=fopen("asoc.vdb","a");
   if(fa){
      fprintf(fa,"%s\n",scla);    fprintf(fa,"%s\n",saPat); fprintf(fa,"%s\n",saMat); fprintf(fa,"%s\n",sNombres);
      fprintf(fa,"%s\n",cFnd);    fprintf(fa,"%s\n",cFnm);  fprintf(fa,"%s\n",cFna);  fprintf(fa,"%c\n",cGen);
      fprintf(fa,"%s\n",saCalle); fprintf(fa,"%s\n",saNum);fprintf(fa,"%s\n",saCol); fprintf(fa,"%s\n",saDmu);
      fprintf(fa,"%s\n",saEdo);   fprintf(fa,"%s\n",saCp); fprintf(fa,"%s\n",saTel);


      // Si la lista está vacía, la lista será el nuevo nodo
      //se crea un nodo para cada valor
      nodo = (pNodo)malloc(sizeof(tipoNodo));
      strcpy(nodo->socio,scla);
      strcpy(nodo->sapat,saPat);
      strcpy(nodo->samat,saMat);
      strcpy(nodo->snombs,sNombres);
      strcpy(nodo->sfnd,cFnd);
      strcpy(nodo->sfnm,cFnm);
      strcpy(nodo->sfna,cFna);
      strcpy(nodo->cgen,cGen);
      strcpy(nodo->sdcalle,saCalle);
      strcpy(nodo->sdcnum,saNum);
      strcpy(nodo->sdcol,saCol);
      strcpy(nodo->sddmu,saDmu);
      strcpy(nodo->sdedo,saEdo);
      strcpy(nodo->sdcp,saCp);
      strcpy(nodo->stel,saTel);
      if(*lista == NULL){
         *lista = nodo;
      }else{
          nodo->siguiente = (*lista)->siguiente;
      }
      // En cualquier caso, cerramos la lista circular
      (*lista)->siguiente = nodo;
      printf("\n");
      fclose(fa);
     }else{
       printf("No se pudieron escribir los datos, error al abrir el archivo!!!\n");
       getch();
       fclose(fa);
   }


}

void Borrar(Lista *lista)
{
   pNodo nodo;
   char scla[8];
   int lR;
   nodo = *lista;

   lR=0;
   do //clave de socio
   {
       printf("Clave de Asociado: ");
       lR=fValidasn(scla,7);
       if(lR==0)
       {
          printf("Error: Favor de ingresar la clave del socio!!! \n");
       }else{
          ftoup(scla);
       }
   }while(lR==0);

   // Hacer que lista apunte al nodo anterior al de socio scla
   do {
      if(strcmp((*lista)->siguiente->socio,scla)) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->socio != scla && *lista != nodo);
   // Si existe un nodo con el socio v:
   if(!strcmp((*lista)->siguiente->socio,scla)) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo de socio
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void Borraras(Lista *lista)
{
   pNodo nodo;

   nodo = lista;
   char scla[8];
   int lR;
   lR=0;
   do //clave de socio
   {
       printf("Clave de Asociado: ");
       lR=fValidasn(scla,7);
       if(lR==0)
       {
          printf("Error: Favor de ingresar la clave del socio!!! \n");
       }else{
          ftoup(scla);
       }
   }while(lR==0);

   // Hacer que lista apunte al nodo anterior al de socio v
   do {
      if((*lista)->siguiente->socio != scla) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->socio != scla && *lista != nodo);
   // Si existe un nodo con el socio v:
   if((*lista)->siguiente->socio == scla) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de socio v
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista)
{
   pNodo nodo;

   // Mientras la lista tenga más de un nodo
   while((*lista)->siguiente != *lista) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   // Y borrar el último nodo
   free(*lista);
   *lista = NULL;
}

void MostrarListaa()
{
   pNodo nodo = lista;

   do {
      printf("Socio: %s  ", &nodo->socio);
      printf("Nombre: %s %s %s \n",&nodo->snombs,&nodo->sapat,&nodo->samat);
      printf("Fecha de nacimiento: %s/%s/%s ",&nodo->sfnd,&nodo->sfnm,&nodo->sfna);
      printf("Genero: ");
      if(strcmp(&nodo->cgen,"1"))
      {
          printf("Mujer\n");
      }else{printf("Hombre\n");}
      printf("Direccion:\t%s ",&nodo->sdcalle);
      printf("%s  ",&nodo->sdcnum);
      printf("%s\n ",&nodo->sdcol);
      printf("\t\t%s ",&nodo->sddmu);
      printf("%s ",&nodo->sdedo);
      printf("%s \n",&nodo->sdcp);
      printf("Telefono: %s\n\n",&nodo->stel);
      nodo = nodo->siguiente;
   } while(nodo != lista);
   printf("\n");
}

void fConsA()
{
   pNodo nodo = lista;
   char scla[8];
   int lR;
   lR=0;
   do //clave de socio
   {
       printf("Clave de Asociado: ");
       lR=fValidasn(scla,7);
       if(lR==0)
       {
          printf("Error: Favor de ingresar la clave del socio!!! \n");
       }else{
          ftoup(scla);
       }
   }while(lR==0);
   lR=0;
   do {
      if(!(strcmp(scla,nodo->socio))){
         printf("Socio: %s  ", &nodo->socio);
         printf("Nombre: %s %s %s \n",&nodo->snombs,&nodo->sapat,&nodo->samat);
         printf("Fecha de nacimiento: %s/%s/%s ",&nodo->sfnd,&nodo->sfnm,&nodo->sfna);
         printf("Genero: ");
         if(strcmp(&nodo->cgen,"1"))
         {
            printf("Mujer\n");
         }else{
            printf("Hombre\n");
         }
         printf("Direccion:\t%s ",&nodo->sdcalle);
         printf("%s  ",&nodo->sdcnum);
         printf("%s\n ",&nodo->sdcol);
         printf("\t\t%s ",&nodo->sddmu);
         printf("%s ",&nodo->sdedo);
         printf("%s \n",&nodo->sdcp);
         printf("Telefono: %s\n\n",&nodo->stel);
         lR=1;
      }
      nodo = nodo->siguiente;
   }while(nodo != lista);
   if(lR==0)
   {
      printf("Asociado no encontrado!!!");
   }
   printf("Oprima una tecla para continuar\n");
}
//------------------------------ Funciones de Pelis ----------------------------------
void fLeepeli(ListaPel *listapel)
{
    pelNodo nodop;
    char scpelf[11];
    char sTitf[80];
    char sProtf[90];
    char sDirf[90];
    char sGenf[30];
    char sDurf[10];
    FILE *fp;
    printf("Leyendo datos del archivo\n");
    fp=fopen("pelis.vdb","r");
    if(fp){
        rewind(fp);
        while(!feof(fp)){
           fscanf(fp," %[^\n]",scpelf);
           fscanf(fp," %[^\n]",sTitf);
           fscanf(fp," %[^\n]",sProtf);
           fscanf(fp," %[^\n]",sDirf);
           fscanf(fp," %[^\n]",sGenf);
           fscanf(fp," %[^\n]",sDurf);

           // Si la lista está vacía, la lista será el nuevo nodo
           //se crea un nodo para cada valor

           nodop = (pelNodo)malloc(sizeof(nodoPel));
           strcpy(nodop->cvepel,scpelf);
           strcpy(nodop->stitulo,sTitf);
           strcpy(nodop->sprot,sProtf);
           strcpy(nodop->sdir,sDirf);
           strcpy(nodop->sgen,sGenf);
           strcpy(nodop->sdur,sDurf);

//         fread(&nodo,sizeof(tipoNodo),1,fa);
           if(*listapel == NULL){
              *listapel = nodop;
           }else{
              nodop->sigpel = (*listapel)->sigpel;
           }
           // En cualquier caso, cerramos la lista circular
           (*listapel)->sigpel = nodop;
        }
        printf("\n");
        fclose(fp);
     }else{
        printf("No se pudieron leer los datos, error al abrir el archivo!!!\n");
        getch();
        fclose(fp);
     }
}

void insertarp(ListaPel *listapel)
{
    pelNodo nodop;
    char scPel[12];
    char sTit[80];
    char sProt[90];
    char sDir[90];
    char sGen[30];
    char sDur[10];
    int i,j;
    int lR;
    FILE *fp;

    //Comenzamos introduciendo datos
    //Datos de la pelicula
    do
    {
       printf("Alta de Peliculas\n\n\n");
       lR=0;
      do //clave de Pelicula
      {
         printf("Asigne una clave (3 letras y 5 numeros): ");
         lR=fValidasn(scPel,8);
         if(lR==0)
         {
            printf("Error: no se ingreso la clave de la pelicula!!! \n");
         }else{
            ftoup(scPel);
         }
      }while(lR==0);
       lR=0;
       do //Titulo
       {
          printf("Escribe el Titulo: ");
          lR=fValidasn(sTit,78);
          if(lR==0)
          {
             printf("Error: no se ingreso el Titulo!!! \n");
          }else{
              ftoup(sTit);
          }
       }while(lR==0);
       lR=0;
       do //Protagonistas
       {
          printf("Escribe el nombre del(os) Protagonistas (es): ");
          lR=fValidasn(sProt,90);
          if(lR==0)
          {
             printf("Error: no se ingreso el nombre de los protagonistas!!! \n");
          }else{
              ftoup(sProt);
          }
       }while(lR==0);
       lR=0;
       do //Nombre del director
       {
          printf("Dame el(los) nombre(s) del (los) Director(es): ");
          lR=fValidasn(sDir,90);
          if(lR==0)
          {
             printf("Error: no se ingreso el Nombre del (los) director(es)!!! \n");
          }else{
              ftoup(sDir);
          }
       }while(lR==0);

    lR=0;
    do{ //Genero
       printf("Genero de la pelicula (ej. Terror, Accion, etc): ");
       lR=fValidasn(sGen,30);
       if(lR==0)
          {
             printf("Error: no se ingreso el Genero de la pelicula!!! \n");
          }else{
              ftoup(sGen);
          }
     }while(lR==0);
     lR=0;
     do //Duracion
     {
        printf("Duracion (minutos): ");
        lR=fValidasn(sDur,10);
        if(lR==0)
        {
           printf("Error: no se ingreso la duracion!!! \n");
        }else{
           ftoup(sDur);
        }
      }while(lR==0);
   }while (lR==1);  //Controla la repe

//-------------------------------------------------

   //lee nodos del archivo:
   printf("Escribiendo datos al archivo\n");
   fp=fopen("pelis.vdb","a");
   if(fp){
      fprintf(fp,"%s\n",scPel);
      fprintf(fp,"%s\n",sTit);
      fprintf(fp,"%s\n",sProt);
      fprintf(fp,"%s\n",sDir);
      fprintf(fp,"%s\n",sGen);
      fprintf(fp,"%s\n",sDur);

      // Si la lista está vacía, la lista será el nuevo nodo
      //se crea un nodo para cada valor
      nodop = (pelNodo)malloc(sizeof(nodoPel));
      strcpy(nodop->cvepel,scPel);
      strcpy(nodop->stitulo,sTit);
      strcpy(nodop->sprot,sProt);
      strcpy(nodop->sdir,sDir);
      strcpy(nodop->sgen,sGen);
      strcpy(nodop->sdur,sDur);

      if(*listapel == NULL){
         *listapel = nodop;
      }else{
          nodop->sigpel = (*listapel)->sigpel;
      }
      // En cualquier caso, cerramos la lista circular
      (*listapel)->sigpel = nodop;
      printf("\n");
      fclose(fp);
     }else{
       printf("No se pudieron escribir los datos, error al abrir el archivo!!!\n");
       getch();
       fclose(fp);
   }


}

void Borrarpel(ListaPel *listapel)
{
   pelNodo nodop;
   char scla[10];
   int lR;
   nodop = *listapel;

   lR=0;
   do //clave de pelicula
   {
       printf("Clave de Pelicula: ");
       lR=fValidasn(scla,8);
       if(lR==0)
       {
          printf("Error: Favor de ingresar la clave de la pelicula!!! \n");
       }else{
          ftoup(scla);
       }
   }while(lR==0);

   // Hacer que lista apunte al nodo anterior al de socio scla
   do {
      if(strcmp((*listapel)->sigpel->cvepel,scla)) *listapel = (*listapel)->sigpel;
   } while((*listapel)->sigpel->cvepel != scla && *listapel != nodop);
   // Si existe un nodo con el socio v:
   if(!strcmp((*listapel)->sigpel->cvepel,scla)) {
      // Y si la lista sólo tiene un nodo
      if(*listapel == (*listapel)->sigpel) {
         // Borrar toda la lista
         free(*listapel);
         *listapel = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo de socio
         nodop = (*listapel)->sigpel;
         (*listapel)->sigpel = nodop->sigpel;
         free(nodop);
      }
   }
}

void BorrarLPel(ListaPel *listapel)
{
   pelNodo nodop;;

   // Mientras la lista tenga más de un nodo
   while((*listapel)->sigpel != *listapel) {
      // Borrar el nodo siguiente al apuntado por lista
      nodop = (*listapel)->sigpel;
      (*listapel)->sigpel = nodop->sigpel;
      free(nodop);
   }
   // Y borrar el último nodo
   free(*listapel);
   *listapel = NULL;
}

void MostrarListap()
{
   pelNodo nodop = listapel;

   do {
      printf("Clave: %s  ", &nodop->cvepel);
      printf("Titulo: %s  \n", &nodop->stitulo);
      printf("Protagonistas: %s \n ", &nodop->sprot);
      printf("Director: %s  \n", &nodop->sdir);
      printf("Genero: %s \n", &nodop->sgen);
      printf("Duracion: %s minutos \n", &nodop->sdur);
      nodop = nodop->sigpel;
   } while(nodop != listapel);
   printf("\n");
}

void fConsP()
{
   pelNodo nodop = listapel;
   char scla[10];
   int lR;
   lR=0;
   do //clave de la pelicula
   {
       printf("Clave de la Pelicula: ");
       lR=fValidasn(scla,8);
       if(lR==0)
       {
          printf("Error: Favor de ingresar la clave de la pelicula!!! \n");
       }else{
          ftoup(scla);
       }
   }while(lR==0);
   lR=0;
   do {
      if(!(strcmp(scla,nodop->cvepel))){
         printf("Clave: %s  ", &nodop->cvepel);
         printf("Titulo: %s  \n", &nodop->stitulo);
         printf("Protagonistas: %s \n ", &nodop->sprot);
         printf("Director: %s  \n", &nodop->sdir);
         printf("Genero: %s \n", &nodop->sgen);
         printf("Duracion: %s minutos \n", &nodop->sdur);
         lR=1;
      }
      nodop = nodop->sigpel;
   }while(nodop != listapel);
   if(lR==0)
   {
      printf("Pelicula no encontrada!!!");
   }
   printf("Oprima una tecla para continuar\n");
}
//-------------------------------- Termina Funciones de pelis ---------------------------

void clscr()
{
   system("cls");

}

int fValidas(char *s,int nTam)
{
    int i,j,nR;
    int nInd;
    char cTec;
    s[0]='\0';
    j=0;
    nR=0;
    do
    {
        cTec=getch();
        if(j>0 && cTec==8)
        {
            printf("\b \b");
            j--;
            s[j] = '\0';
        }else
        {
            if((cTec>=65 && cTec<=95)||(cTec>=97 &&cTec<=122)||(cTec==32))
            {
                if(cTec>=97 && cTec<=122){
                   cTec-=32;
                }
                printf("%c",cTec);
                s[j]=cTec;
                j++;
            }
        }
    }while (cTec!=13 && j<nTam);
    //|| s[0]=='\0') && j<nTam);

    s[j]='\0';
    printf("%c \n",s[j]);
    nR=j;
    return (nR);
}

int fValidasn(char *s,int nTam)
{
    int i,j,nR;
    int nInd;
    char cTec;
    s[0]='\0';
    j=0;
    nR=0;
    do
    {
        cTec=getch();
        if(j>0 && cTec==8)
        {
            printf("\b \b");
            j--;
            s[j] = '\0';
        }else
        {
            if((cTec>=65 && cTec<=95)||(cTec>=97 &&cTec<=122)||(cTec>=32 && cTec<=57))
            {
                if(cTec>=97 && cTec<=122){
                   cTec-=32;
                }
                printf("%c",cTec);
                s[j]=cTec;
                j++;
            }
        }
    }while (cTec!=13 && j<nTam);
    //|| s[0]=='\0') && j<nTam);

    s[j]='\0';
    printf("%c \n",s[j]);
    nR=j;
    return (nR);
}
int bisiesto(int naeval)
{
    int nbis=0;
    if(((naeval%4==0) && !(naeval%100==0))|| (naeval%400==0))
    {
        nbis=1;
    }
    return nbis;
}

int ftoup(char *s)
{
   int tl=0;
   int j=0;
   char cC;
   do
   {
       cC=s[j];
       if((cC>=97)&&(cC<=122))
          {
              cC-=32;
              s[j]=cC;
          }
       j++;
   }while( cC!='\0');
   if(j>0){tl=j;}
return (tl);
}


int fisvocal(char c)
{
    int nIv=0;
    int i=0;
    char cVoc[]={'A','E','I','O','U'};
    for(i=0;i<6;i++)
    {
        if(c==cVoc[i]){
            nIv=1;
        }
    }
    return (nIv);
}


void fvoltea(char* cini, char* cter)
{
    char caux;
    while(cter>cini)
        caux=*cter, *cter--=*cini, *cini++=caux;
}


int ias(int nval, char *strs)
{
    char* wstr=strs;
    int sign,nmd;
    div_t res;
    nmd=nval;
    if(nval<10)
    if ((sign=nval) < 0) nval = -nval;

    do {
      *wstr++ = (nval%10)+'0';
    }while(nval=nval/10);
   /* if(nmd<10) *wstr++='0';*/
    if(sign<0) *wstr++='-';
    *wstr='\0';

    fvoltea(strs,wstr-1);
    free(wstr);

    return 0;
}
