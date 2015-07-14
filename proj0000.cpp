#include <stdio.h>
#include <conio.h>
<<<<<<< HEAD
void main(void)
{

 int op,d,h,s;
 clrscr();
 printf("\t Bienvenidos a si horario:");
 printf("\t \t \n Menu de opciones:");
 printf("\n 1.Ingresar una nueva hora de clases:");
 printf("\n 2.Ver el horario de hoy:");
 printf("\n 3.Horario de la semana:");
 printf("\n 4.Salir:");
 printf("\n Porfavor ingrese la opcion que desea:");
 scanf("%d",&op);

 switch(op)
 {
=======

// Definicion de Struct  

struct hora_clase
{
 	char nombre_materia[50], nombre_semestre[50];
   char dia_semana[3];
   char hora_inicio[5], hora_fin[5];
};

>>>>>>> origin/master
int menu()
{
	int opcion;
 	printf("\t Bienvenidos:");
 	printf("\t \t \n Menu de opciones:");
 	printf("\n 1.Ingresar una nueva hora de clases:");
 	printf("\n 2.Ver el horario de hoy:");
 	printf("\n 3.Horario de la semana:");
 	printf("\n 4.Salir:");
 	printf("\n Por favor seleccione la opcion que desea:\n");
 	scanf("%d",&opcion);
 	return opcion;
}

hora_clase ingresarHoraClase()
{
      struct hora_clase hora;
      printf("\t Por favor ingrese los siguientes datos:");
      printf("\n Nombre de la Materia:");
      scanf("%s",hora.nombre_materia);
      printf("\n Nombre del Semestre:");
      scanf("%s",hora.nombre_semestre);
      printf("\n Día de la Semana:");
      scanf("%s",hora.dia_semana);
      printf("\n Hora Inicio:");
      scanf("%s",hora.hora_inicio);
      printf("\n Hora Fin:");
      scanf("%s",hora.hora_fin);
      return hora;
}

int subMenuDiasSemana()
{
   int opcion;
	printf("\n horario:");
   printf("\n escoja el dia:");
   printf("\n 1.Lunes");
   printf("\n 2.Martes");
   printf("\n 3.Miercoles");
   printf("\n 4.Jueves");
   printf("\n 5.Viernes");
	printf("\n Ingrese la opcion porfavor:");
   scanf("%d",&opcion);
   return opcion;
}


 void main(void)
{
 int opcion, subOpcion,h,s;

 clrscr();
 opcion = menu();
 switch(opcion){
>>>>>>> origin/master
void main(void)
{
  case 1:
<<<<<<< HEAD
        printf("\n Ingrese una nueva hora de clases:");
        scanf("%c",&h);
        switch(h)
        {
         case 1:
         printf("07H00-08H00");
         break;
         case 2:
         printf("08H00-09H00");
         break;
         case 3:
         printf("09H00-10H00");
         break;
         case 4:
         printf("10H00-11H00");
         break;
         case 5:
         printf("11H00-12H00");
         break;
         case 6:
         printf("12H00-13H00");
         break;
         case 7:
         printf("13H00-14H00""ALMUERZO");
         break;
         case 8:
         printf("14H00-15H00");
         break;
         case 9:
         printf("15H00-16H00");
         break;

        }
      }

=======
       struct hora_clase item;
       item = ingresarHoraClase();
       printf("%s",item.nombre_materia);     // prueba de ingreso
       break;
>>>>>>> origin/master
  case 2:

       subOpcion = subMenuDiasSemana();
        switch(subOpcion)
        {
         case 1:
         		printf("\n\nLunes:\n\nQuimica\nMAtematicaI\FisicaI\nIngles\nMEtodologiaa\n\n");
               break;
         case 2:
         		printf("\n\nMArtes:\n\nIngles\nDeportes\nProgramacion\nFisica\nMatematicas\n\n");
               break;
         case 3:
         		printf("\n\nMiercoles:\n\nAlgebra\nQuimica\nMEtodologia\nProgramacion\nMatematicas\nFisica\n\n");
               break;
         case 4:
         		printf("\n\nJueves:\n\nMAtematica\nIngles\nAlgebra\nFisica\nQuimica \n\n");
               break;
         case 5:
         		printf("\n\nLunes:\n\n}PRogramacion\nAlgebra\nIngles\nMatematicas\nFisica\n\n");
               break;
        }
        printf("\n Sus semestres:");
        scanf("%d",&s);
        switch(s)
        {
         case 1:
              printf("\n PRIMER SEMESTRE:");
              break;
         case 2:
              printf("\n SEGUNDO SEMESTRE:");
              break;
         case 3:
              printf("\n TERCER SEMESTRE:");
              break;
         case 4:
              printf("\n CUARTO SEMESTRE:");
              break;
         case 5:
              printf("\n QUINTO SEMESTRE:");
              break;
         case 6:
              printf("\n SEXTO SEMESTRE:");
              break;
         case 7:
              printf("\n OCTAVO SEMESTRE:");
              break;
         case 9:
              printf("\n NOVENO SEMESTRE:");
              break;
         case 10:
              printf("\n DECIMO SEMESTRE:");
              break;
        }

  default:
  printf("No tiene ninguna opcion:");
 }
  getch();
}