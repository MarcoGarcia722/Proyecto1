#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>

// Definicion de Struct  

struct hora_clase
{
 	char nombre_materia[50], nombre_semestre[50];
   char dia_semana[3];
   char hora_inicio[5], hora_fin[5];
};

//  Funciones de Sistema Modular
bool validarNombre(char nombre[50])
{
	bool resultado =  false;
      if ( strlen(nombre)!=0)
      {
         resultado =  true;
      }
      
	return resultado;
}

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
      printf("Por favor ingrese los siguientes datos:");
      do
		{
  			printf("\n Nombre de la Materia:");
      	gets(hora.nombre_materia);
		} while (!validarNombre(hora.nombre_materia));
       do
		{
      	printf("\n Nombre del Semestre:");
      	gets(hora.nombre_semestre);
      } while (!validarNombre(hora.nombre_semestre));
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


// Programa Principal donde llamamos a las funciones definidas arriba
main()
{
 int opcion, subOpcion,h,s;

 clrscr();
 opcion = menu();
 switch(opcion){
  case 1:       // Ingreso de una nueva hora de clases
       struct hora_clase item;
       item = ingresarHoraClase();
       printf("%s",item.nombre_materia);     // prueba de ingreso
       break;
  case 2:   // Ver Horario de Hoy

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
