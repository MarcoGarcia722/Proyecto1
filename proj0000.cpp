#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>

// Definicion de Struct
const int TamanioLogico=5;
  struct DatosHoraClase
  {
   char NombreMateria[30];
   char NombreSemestre[20];
   char DiaSemana[3];
   int HoraInicio;
   int MinutoInicio;
   int HoraFin;
   int MinutoFin;
  };
   struct DatosHoraClase HoraClase[TamanioLogico];


//PROTOTIPO DE FUNCIONES
void Tiempo();
int Menu();
void IngresarHorariodeClases();
void VerHorarioHoy();
void VerhHorariodelaSemana();
void Salir();
void Congelar ();
//Funcion Principal
int main ()
{
 int opcion;
 Tiempo();
 opcion = Menu();
 while (opcion!=4)
 {
  switch(opcion)
  {
   case 1:
          IngresarHorariodeClases();
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
   opcion = Menu();
 }
 return(0);
}
 void Tiempo()
 {
  SYSTEMTIME hora;
  GetLocalTime(&hora);
 // printf("\t\t HORA DE INICIO:%02d:%02d:%02d\n",hora.WHour,hora.wMinute,hora.wSecond);   Genera error no compila
 }
 void Congelar()
 {
  system("PAUSE");
 }

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

void IngresarHorariodeClases()
{
      struct DatosHoraClase hora;
      printf("\n Por favor ingrese los siguientes datos: \n");

      do
		{
  			printf("\n Nombre de la Materia:");
      	gets(hora.NombreMateria);
		} while (!validarNombre(hora.NombreMateria));
        do
		{
      	printf("\n Nombre del Semestre:");
      	gets(hora.NombreSemestre);
      } while (!validarNombre(hora.NombreMateria));
      char dia[10];
       do
		{
      	printf("\n Día de la Semana:");
      	gets(hora.DiaSemana);
         strcpy(dia,hora.DiaSemana);
         strcpy(dia,obtenerDiaSemana(dia));
      } while(strlen(dia)==0);

      do
      {
      	printf("\n Hora Inicio:");
      	scanf("%d",&hora.HoraInicio);
      } while(hora.HoraInicio>24);

      do
      {
      	printf("\n Minuto Inicio:");
      	scanf("%d",&hora.MinutoInicio);
      } while(hora.MinutoInicio>60);

      do
      {
      	printf("\n Hora Fin:");
      	scanf("%d",&hora.HoraFin);
      } while(hora.HoraFin>24);

      do
      {
      	printf("\n Minuto Fin:");
      	scanf("%d",&hora.MinutoFin);
      } while(hora.MinutoFin>60);


      // Validar Hora de Clase
     // Guardar Hora de Clase
     // Salir
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


int Menu()
{
	int opcion;
 	printf("\t Bienvenidos:");
 	printf("\t \t \n Menu de opciones:");
 	printf("\n 1.Ingresar una nueva hora de clases:");
 	printf("\n 2.Ver el horario de hoy:");
 	printf("\n 3.Horario de la semana:");
 	printf("\n 4.Salir:");
 	printf("\n Por favor seleccione la opcion que desea:\n");
 	scanf("%d", &opcion);
 	return opcion;
}

