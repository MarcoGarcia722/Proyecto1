#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>

//PROTOTIPO DE FUNCIONES
void Tiempo();
int Menu ();
void IngresarHorariodeClases();
void VerHorarioHoy();
void VerhHorariodelaSemana();
Void Salir();
void Congelar ();
//Funcion Principal
int main ()
{
 int opcion;
 Tiempo();
 opcion)Menu();
 while (opcion!=4)
 {
  switch(opcion)
  {
   case 1:
          IngresarHoraiodeClases();
          break;
   case 2:
         //Ver EL HORARIO DE HOY
         //VERHORARIOhOY();
         break;
   case 3:
         //Ver el horario de la semana
         //verHorarioSeman();
         break;
  }
  opcion=Menu();
 }
 return(0);
}
 void Tiempo()
 {
  SYSTEMTIME hora;
  GetLocalTime(&hora);
  printf("\t\t HORA DE INICIO:%02d:%02d:%02d\n",hora.WHour,hora.wMinute,hora.wSecond);
 }
 void Congelar()
 {
  system("PAUSE");
 }
 void IngresarHorrarioDeClase()
 {
  int indice;
  //temaño logico para cinco digitos
  const int TamañoLogico=5;
  struct DatosHoraClase
  {
   char NombreMateria[30];
   char NombreSemestre[20];
   char DiaSemana[4];
   int HoraInicio;
   int HoraFin;
  };
   struct DatosHoraClase HoraClase[TamañoLogico];

// Definicion de Struct

struct hora_clase
{
 	char nombre_materia[50], nombre_semestre[50];
   char dia_semana[3];
   char hora_inicio[5], hora_fin[5];
};

//  Funciones de Sistema Modular

// Validar nombre no vacio
bool validarNombre(char nombre[50])
{
	bool resultado =  false;
      if(strlen(nombre)!=0)
      {
         resultado =  true;
      }

	return resultado;
}

// Validar y Obtener El dia de la Semana
char* obtenerDiaSemana(char dia[10])
{
  if(strcmp(dia, "LUN") == 0)
  {
     dia = "Lunes";
  } else {
  		if(strcmp(dia, "MAR") == 0)
      {
         dia = "Martes";
      } else {
          if(strcmp(dia, "MIE") == 0)
          {
          	dia = "Miercoles";
          } else {
					if(strcmp(dia, "JUE") == 0)
      	       {
                  dia = "Jueves";
                } else {
                   if(strcmp(dia, "VIE") == 0)
      				{
                    dia = "Viernes";
                	}else {
                  	dia = "";
                }
             }
          }
      }
  }

   return dia;
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
      char dia[10];
       do
		{
      	printf("\n Día de la Semana:");
      	gets(dia);
         strcpy(dia,obtenerDiaSemana(dia));
      } while(strlen(dia)==0);
      strcpy(hora.dia_semana,dia);
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
        }

  default:
  printf("No tiene ninguna opcion:");
 }
  getch();
}
