#include <stdio.h>
#include <conio.h>
main()
{
 int op,d;
 clrscr();
 printf("\t Bienvenidos:");
 printf("\t \t \n Menu de opciones:");
 printf("\n 1.Ingresar una nueva hora de clases:");
 printf("\n 2.Ver el horario de hoy:");
 printf("\n 3.Horario de la semana:");
 printf("\n 4.Salir:");
 printf("\n Porfavor ingrese la opcion que desea:");
 scanf("%d",&op);
 switch(op)
 {
  case 1:
        printf("\n Ingrese una nueva hora de clases:");

  case 2:

        printf("\n horario:");
        printf("\n escoja el dia:");
        printf("\n 1.Lunes");
        printf("\n 2.Martes");
        printf("\n 3.Miercoles");
        printf("\n 4.Jueves");
        printf("\n 5.Viernes");
        printf("\n Ingrese la opcion porfavor:");
        scanf("%d",&d);
        switch(d)
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

  default:
  printf("No tiene ninguna opcion:");
 }
  getch();
}