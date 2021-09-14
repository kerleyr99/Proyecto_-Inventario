#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int validar_numero(char numero[]);
int validar_letras(char numero[]);
void actualizar();
int op,j=1,i=0;
char op1[2];
int contaUsu=1,contaPro=1;
void ingresoproductos(int idpro );
void ingresoUso (int id);
void login();
void entradas();
void salida();
void eliminar();
FILE *usuarios;
void cargar();
void cargar1();
int g=0;
  char cedula[10],telefono[10],N,M;
  char clave[10],usu[10];
 
int l=1;

typedef struct crearUsuario{
  int id;
  int cedula;
  char nombreu[10];
  char apellido[10];
  int telf;
}crearUsuario;

crearUsuario crear(int IdU);
crearUsuario informacion[100];

typedef struct productoEstructura{
int id;
char nomPro[100];
char lote[10];
float precio;
int cantidad;
float total;
}productoEstructura;

productoEstructura ingresoPro(int idp);
productoEstructura bodega[100];
int main(void) {
  system("clear");
  cargar();
  cargar1();
    while (op!=3){
    system("clear");
    printf("\n\t\t\t\t***** MENU PRINCIPAL *****");
    printf("\n\t---------------------------------------------");
    printf("\n\n\t\t1.-Crear usuario");
    printf("\n\t\t2.-Ingresar al Sistema");
    printf("\n\t\t3.-Salir\n");
    printf("\n\t---------------------------------------------");
    do{
    printf("\n\t\tIngrese su eleccion: ");
    
    scanf("%s",op1);
    
    N=validar_numero(op1);
    }while(N==0);
    op=atoi(op1);
    switch(op){
      case 1:{
        system("clear");
        printf("\n\t\t\t\t***** NUEVO USUARIO *****");
        printf("\n\t---------------------------------------------");
        informacion[l]=crear(l);
        
        l++;
        break;
      }
      case 2:{
        printf("\n\t\t\t\t***** Inicio de sesion *****");
        login();
        break;
      }
      case 3:{
        system("clear");
        printf("\n\t\t\t ***** HASTA PRONTO *****");
        break;
      }
      default:{
        printf("\n\t\t\t\t***** Opcion incorrecta *****");
      }
    }
 
  }
  return 0;
}


 void login(){
   FILE *ingreso;
   int bencontro=0,intento=1,ac;
   char  password[10];
   char usuario[10];
   char lineausuario[100],lineapasword[100];
   char codUsu[10];
   
   int codU;
   do{
     system("clear");
     
     printf("\n\t---------------------------------------------");
     printf("\n\t\tIntento numero: %d",intento);
     printf("\n\t\tIngrese su nombre de usuario: ");
     scanf("%s",usuario);
     printf("\n\t\tIngrese su clave: ");
     scanf("%s",password);
     if ((ingreso= fopen("Datos/nuevoUsu.txt","r"))==NULL){
      printf("\nEL USUARIO NO EXISTE");
       
     }
    
     while(!feof(ingreso)){
       fgets(codUsu,10,ingreso);
       if(fgets(lineausuario,100,ingreso)!=NULL){
         if(fgets(lineapasword,100,ingreso)!=NULL){
           strcpy(codUsu,strtok(codUsu,"\n"));
           strcpy(lineausuario,strtok(lineausuario,"\n"));
           strcpy(lineapasword,strtok(lineapasword,"\n"));
           if(strcmp(usuario,lineausuario)==0 && strcmp(password,lineapasword)==0){
             codU=atoi(codUsu);
             bencontro=-1;
             break;
           }
         }
        else{
          printf("\nLa clave no existe");
        }
       }
       else{
         //printf("\n El usuario no existe");
       }
     }
     fclose(ingreso);
     if(bencontro){
       
       do{
         char ac1[10];
         int ac=0;
         system("clear");
         printf("\n\t\t\t***** BIENVENIDO %s *****",
         informacion[codU].nombreu);
          printf("\n\t---------------------------------------------");
         printf("\n\t\t\tBIENVENIDO AL SISTEMA DE INVENTARIOS");
         printf("\n\t1.-Ingreso de Productos");
         printf("\n\t2.-Reporte de Productos");
         printf("\n\t3.-Entradas y Salidas");
         printf("\n\t4.-Busqueda de Productos");
         printf("\n\t5.-Eliminar Producto");
         printf("\n\t6.-Mostrar usuarios");
         printf("\n\t7.-Salir");
         printf("\n\t---------------------------------------------");
         do{
         printf("\n\tIngrese su eleccion: ");
         scanf("%s",ac1);
         N=validar_numero(ac1);
         }while(N==0);
         ac=atoi(ac1);
         switch(ac){
           case 1:{
             system("clear");
             printf("\n\t\t\t\t***** INGRESO DE PRODUCTOS *****");
             printf("\n\t---------------------------------------------");
             bodega[j]=ingresoPro(j);

             j++;
             break;
           }
           case 2:{
             float tot=0;
             system("clear");
             printf("\n\t\t*****PRODUCTOS EXISTENTES EN BODEGA*****");
              printf("\n\t-----------------------------------------------------------------");
             printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
             printf("\n\t-----------------------------------------------------------------");
             for(i=1;i<j;i++){
             printf("\n\t%d\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[i].id,bodega[i].nomPro,bodega[i].lote,bodega[i].cantidad,bodega[i].precio,bodega[i].total);
             tot=tot+bodega[i].total;
             }
             printf("\n\t-----------------------------------------------------------------");
             printf("\n\t\t\t\t\t\t\t\t\t\tTotal en bodega: %.2f$",tot);
             printf("\n\t-----------------------------------------------------------------");
             printf("\n\t\tDesea regresar al menu anterior?");
             printf("\n\t1.-SI: ");
             int y;
             scanf("%d",&y);
             if(y==1){
             break;
             }else{
               break;
             }
           }
           case 3:{
             int sal;
             char en[10];
             system("clear");
             printf("\n\t\t***** ENTRADAS  Y SALIDAS DE PRODUCTOS *****");
             printf("\n\t---------------------------------------------");
             printf("\n\t1.-Ingresar cantidad");
             printf("\n\t2.-Restar cantidad");
             printf("\n\t---------------------------------------------");
             do{
             printf("\n\tSelecciones una opcion: ");
             scanf("%s",en);
             N=validar_numero(en);
             }while(N==0);
             sal=atoi(en);
             if(sal==1){
             entradas();}
             else if(sal==2){
                salida();
             }
             else{
               printf("\n\t\t\t ***** La opcion no existe ****");
               break;
             }
             break;
           }
           case 4:{
            int busqueda;
            int codb=0;
             system("clear");
             printf("\n\t\t ***** BUSQUEDA DE PRODUCTOS *****");
             printf("\n\t-----------------------------------------------------------------");
             printf("\n\tIngrese el codigo del Producto: ");
             scanf("%d",&busqueda);
              for(i=1;i<j;i++){
                if(busqueda==bodega[i].id){
                codb=i;
              } 
              }
              if(codb==0){
                printf("\n\t\t\t ¡El producto no existe!");
                break;
              }else{
              printf("\n\t-----------------------------------------------------------------");
              printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
              printf("\n\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[codb].id,bodega[codb].nomPro,bodega[codb].lote,bodega[codb].cantidad,bodega[codb].precio,bodega[codb].total);
              printf("\n\t-----------------------------------------------------------------");
            printf("\n\t\tDesea regresar al menu anterior?");
             printf("\n\t1.-SI: ");
             int y;
             scanf("%d",&y);
             if(y==1){
             break;
             }else{
               break;
             }
             }
           }
           case 5:{
             if(informacion[codU].id==1){
             eliminar();
             break;}else{
               
               printf("\n\t\t\t*** ¡No tiene permisos! ***");
               
             break;}
           }
           case 6:{
             system("clear");
             if(informacion[codU].id==1){
             printf("\n\t\t\t***** Usuarios del Sistema *****");
             printf("\n\t------------------------------------------------");
             printf("\n\tNOMBRE\t\t\t\tCEDULA\t\t\tTELEFONO");
             printf("\n\t------------------------------------------------");
             for(i=1;i<l;i++){
               printf("\n\t%s %s\t\t\t%d\t\t%d",informacion[i].nombreu,informacion[i].apellido,informacion[i].cedula,informacion[i].telf);
             }
             printf("\n\t------------------------------------------------");
             printf("\n\t\tDesea regresar al menu anterior?");
             printf("\n\t1.-SI: ");
             int y;
             scanf("%d",&y);
             if(y==1){
             break;}else{
               break;
             }
             }else{
               printf("\n\t\t\t *** ¡No tiene permisos! ***");
               break;
             }
           }
           case 7:{
             system("clear");
             printf("\n\t\t\t***** HASTA PRONTO *****");
             exit(0);
             break;
           }
           default:printf("\n\t\t ***** La opcion no existe *****");
         }
         intento=4;
       }
       while(ac!=7);
     }
     else{
       system("clear");
       printf("\n\t\t\t\tUsuario y clave incorretos");
       intento++;
       if (intento>3){
         printf("\n\t\t-----Has superado el numero de intentos-----");
          exit(0);
       }
     }
     
   }
   
   while (intento<=3);
 }

crearUsuario crear(int IdU){
crearUsuario informacion;
FILE *datosusuario;
  usuarios=fopen("Datos/nuevoUsu.txt","a");
  datosusuario=fopen("Datos/datosus.txt","a");
  informacion.id=IdU;
  printf("\n\t\tIngrese la siguiente informacion");
  do{
  printf("\n\tIngrese su cedula: ");
  scanf("%s",cedula);
  N=validar_numero(cedula);
  }
  while(N==0);
  informacion.cedula=atoi(cedula);
  do{
    printf("\n\tIngrese solo Letras");
  printf("\n\tIngrese su Nombre: ");
  scanf("%s",informacion.nombreu);
  M=validar_letras(informacion.nombreu);
  }while(M==0);
  do{
  printf("\n\tIngrese solo letras");
  printf("\n\tIngrese su Apellido: ");
  scanf("%s",informacion.apellido);
  M=validar_letras(informacion.apellido);
  }while(M==0);
  do
  
  {
  printf("\n\tIngrese su Telefono:");
  scanf("%s",telefono);
  N=validar_numero(telefono);
  }
  while(N==0);
  informacion.telf=atoi(telefono);
  fprintf(datosusuario,"\n%d %d %s %s %d",informacion.id,informacion.cedula,informacion.nombreu,informacion.apellido,informacion.telf);
  fclose(datosusuario);
  fprintf(usuarios,"%d\n",IdU);
  printf("\n\tIngrese un nombre de Usuario: ");
  scanf("%s",usu);
  fprintf(usuarios,"%s\n",usu);
  printf("\n\tIngrese una contraseña unica: ");
  scanf("%s",clave);
  fprintf(usuarios,"%s\n",clave);
  fclose(usuarios);
return(informacion);
}

 productoEstructura ingresoPro(int idp){
  productoEstructura bodega;
  char ca[10];
  FILE *Inventario;
  FILE *InventarioFinal;
  InventarioFinal=fopen("Datos/InventarioFinal.txt","a");
  Inventario=fopen("Datos/inventario.txt","a");
  bodega.id=idp;
  printf("\n\t\tIngrese los siguientes datos del producto");
  printf("\n\t\tPRODUCTO:");
  while(getchar()!='\n');
  fgets(bodega.nomPro,100,stdin);
  strcpy(bodega.nomPro,strtok(bodega.nomPro,"\n"));
  printf("\n\t\tLOTE: ");scanf("%s",bodega.lote);
  do{
  printf("\n\t\tSTOCK: "),scanf("%s",ca);
  N=validar_numero(ca);
  }while(N==0);
  bodega.cantidad=atoi(ca);
  printf("\n\t\tPRECIO DE COMPRA: ");scanf("%f",&bodega.precio);
  bodega.total=bodega.cantidad*bodega.precio;
  fprintf(Inventario,"\n%d %s\n%d %f %f %s",bodega.id,bodega.nomPro,bodega.cantidad,bodega.precio,bodega.total,bodega.lote);
  
  fprintf(InventarioFinal,"\n%d %s %s %d %f %f",bodega.id,bodega.nomPro,bodega.lote,bodega.cantidad,bodega.precio,bodega.total);
  fclose(InventarioFinal);
  fclose(Inventario);
  return bodega;
 }
void cargar(){
  FILE *abrir;
  abrir=fopen("Datos/inventario.txt","r");
 if (abrir!=NULL){

  while(feof(abrir)==0){
    fscanf(abrir,"%d",&bodega[j].id);
    
    //fscanf(abrir,"%s",bodega[j].nomPro);
    fgets(bodega[j].nomPro,100,abrir);
    strcpy(bodega[j].nomPro,strtok(bodega[j].nomPro,"\n"));
    fscanf(abrir,"%d",&bodega[j].cantidad);
    fscanf(abrir,"%f",&bodega[j].precio);
    fscanf(abrir,"%f",&bodega[j].total);
    fscanf(abrir,"%s",bodega[j].lote);
    
    j++;
  }
  fclose(abrir);
} 
}
void cargar1(){
FILE *cargarU;
cargarU=fopen("Datos/datosus.txt","r");
if(cargarU!=NULL){
while(feof(cargarU)==0){
    fscanf(cargarU,"%d",&informacion[l].id);
    fscanf(cargarU,"%d",&informacion[l].cedula);
    fscanf(cargarU,"%s",informacion[l].nombreu);
    fscanf(cargarU,"%s",informacion[l].apellido);
    fscanf(cargarU,"%d",&informacion[l].telf);
    l++;
    
  }
  fclose(cargarU);
}
}

void entradas(){
  int c;
  char nu[10];
  FILE *entrada;
  system("clear");
   printf("\n\t\t\t***** PRODUCTOS EXISTENTES EN BODEGA *****");
  printf("\n\t-----------------------------------------------------------------");
  printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
  for(i=1;i<j;i++){
  printf("\n\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[i].id,bodega[i].nomPro,bodega[i].lote,bodega[i].cantidad,bodega[i].precio,bodega[i].total);
  }
  printf("\n\t-----------------------------------------------------------------");
 
  
  printf("\n\t\tIngrese el codigo del Producto a agregar stock: ");
  scanf("%d",&c);
  printf("\n\t\tProducto seleccionado: %s",bodega[c].nomPro);
  do{
  printf("\n\t\tIngrese la cantidad a agregar: ");
  scanf("%s",nu);
  N=validar_numero(nu);
  }while(N==0);
  bodega[c].cantidad=bodega[c].cantidad+atoi(nu);
  bodega[c].total=bodega[c].cantidad*bodega[c].precio;
  actualizar();

}


void salida(){
  int c;
  char nu[10];
  FILE *salidas;
  system("clear");
   printf("\n\t\t*****PRODUCTOS EXISTENTES EN BODEGA*****");
  printf("\n\t-----------------------------------------------------------------");
  printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
  for(i=1;i<j;i++){
  printf("\n\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[i].id,bodega[i].nomPro,bodega[i].lote,bodega[i].cantidad,bodega[i].precio,bodega[i].total);
  }
  printf("\n\t-----------------------------------------------------------------");
  
  
  printf("\n\t\tIngrese el codigo del Producto a restar stock: ");
  scanf("%d",&c);
  printf("\n\t\tProducto seleccionado: %s",bodega[c].nomPro);
  do{
  printf("\n\t\tIngrese la cantidad a restar: ");
  scanf("%s",nu);
  N=validar_numero(nu);
  }while(N==0);
  bodega[c].cantidad=bodega[c].cantidad-atoi(nu);
  bodega[c].total=bodega[c].cantidad*bodega[c].precio;
  actualizar();

}


int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("\n\t¡Ingresa solo Numeros!\n");
         
            return 0;
        }
    }
    return 1;
}


int validar_letras(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
         
            return 1;
        }
    }
    return 0;
}

void actualizar(){
int a;
FILE *actual;
FILE *actualizarInventario;

if(remove("Datos/inventario.txt")==0){
actual=fopen("Datos/inventario.txt","a");
remove("Datos/InventarioFinal.txt");
actualizarInventario=fopen("Datos/InventarioFinal.txt","a");
for(a=1;a<j;a++){
  fprintf(actual," %d %s\n%d %f %f %s",bodega[a].id,bodega[a].nomPro,bodega[a].cantidad,bodega[a].precio,bodega[a].total,bodega[a].lote);
  fprintf(actualizarInventario,"\n%d %s %s %d %f %f",bodega[a].id,bodega[a].nomPro,bodega[a].lote,bodega[a].cantidad,bodega[a].precio,bodega[a].total);
}}
fclose(actualizarInventario);
fclose(actual);
}

void eliminar(){
int a,n,t;
printf("\n\t\t\t***** PRODUCTOS EXISTENTES EN BODEGA *****");
printf("\n\t-----------------------------------------------------------------");
printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
for(i=1;i<j;i++){
printf("\n\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[i].id,bodega[i].nomPro,bodega[i].lote,bodega[i].cantidad,bodega[i].precio,bodega[i].total);
}
printf("\n\t-----------------------------------------------------------------");
printf("\n\tIngrese el codigo del producto a eliminar: ");
scanf("%d",&a);
printf("\n\tProducto seleccionado: %s",bodega[a].nomPro);
printf("\n\tEsta segudo de eliminar el producto? 1.-Si 2.-No: ");
scanf("%d",&t);
if(t==1){
int eliminar=bodega[a].id;
for(i=1;i<j;i++){
  if(i==a){
    while(i<=j-1){
      bodega[i].id=bodega[i].id;
      strcpy(bodega[i].nomPro,bodega[i+1].nomPro);
      bodega[i].cantidad=bodega[i+1].cantidad;
      bodega[i].total=bodega[i+1].total;
      strcpy(bodega[i].lote,bodega[i+1].lote);
      bodega[i].precio=bodega[i+1].precio;
      i++;
    }
    break;
  }
}
j=j-1;
printf("\n\t\t\t***** PRODUCTOS EXISTENTES EN BODEGA *****");
printf("\n\t-----------------------------------------------------------------");
printf("\n\tCOD\t\tPRODUCTO\t\tLOTE\t\tSTOCK\t\tPRECIO\t\tTOTAL");
for(i=1;i<j;i++){
printf("\n\t%d\t\t%s\t\t%s\t\t\t%d\t\t\t%.2f$\t\t%.2f$",bodega[i].id,bodega[i].nomPro,bodega[i].lote,bodega[i].cantidad,bodega[i].precio,bodega[i].total);
}
printf("\n\t-----------------------------------------------------------------");
}else{
  printf("\n\t\tNo se elimino el Producto");
}
actualizar();
}