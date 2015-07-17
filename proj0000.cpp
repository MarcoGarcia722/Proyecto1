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
   char DiaSemana[4];
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
char* obtenerDiaSemana(DatosHoraClase hora)
{
char resultado[10];
  if(strcmp(hora.DiaSemana, "LUN") == 0)
  {
     strcpy(resultado,"Lunes");
  } else {
  		if(strcmp(hora.DiaSemana, "MAR") == 0)
      {
         strcpy(resultado,"Martes");
      } else {
          if(strcmp(hora.DiaSemana, "MIE") == 0)
          {
          	strcpy(resultado,"Miercoles");
          } else {
					if(strcmp(hora.DiaSemana, "JUE") == 0)
      	       {
                  strcpy(resultado,"Jueves");
                } else {
                   if(strcmp(hora.DiaSemana, "VIE") == 0)
      				{
                    strcpy(resultado,"Viernes");
                	}else {
                  	strcpy(resultado,"");
                }
             }
          }
      }
  }

   return resultado;
}

void IngresarHorariodeClases()
{
      struct DatosHoraClase hora;
      printf("\n Por favor ingrese los siguientes datos: \n");
      fflush(stdin);
      do
		{
  			printf("\n Nombre de la Materia: ");
      	gets(hora.NombreMateria);
         fflush(stdin);
		} while (!validarNombre(hora.NombreMateria));
      do
		{
      	printf("\n Nombre del Semestre: ");
      	gets(hora.NombreSemestre);
         fflush(stdin);
      } while (!validarNombre(hora.NombreSemestre));
      char dia[10];
       do
		{
      	printf("\n Dia de la Semana: ");
         gets(hora.DiaSemana);
         strcpy(dia,obtenerDiaSemana(hora));
         fflush(stdin);
      } while(strlen(dia)==0);

      do
      {
      	printf("\n Hora Inicio: ");
      	scanf("%d",&hora.HoraInicio);
         fflush(stdin);
      } while(hora.HoraInicio>24);

      do
      {
      	printf("\n Minuto Inicio: ");
      	scanf("%d",&hora.MinutoInicio);
         fflush(stdin);
      } while(hora.MinutoInicio>60);

      do
      {
      	printf("\n Hora Fin: ");
      	scanf("%d",&hora.HoraFin);
         fflush(stdin);
      } while(hora.HoraFin>24);

      do
      {
      	printf("\n Minuto Fin: ");
      	scanf("%d",&hora.MinutoFin);
         fflush(stdin);
      } while(hora.MinutoFin>60);


      // Validar Hora de Clase

     // Guardar Hora de Clase
     	ofstream horario;
      horario.open("horario.txt",ios::out|ios::app);
		if (horario.fail())
      {
			cout<<"Ocurrio un error al abrir el archivo";
         getch ();
    	}
      else
      {
      	horario<<hora.NombreMateria<<" "<<hora.NombreSemestre<<" "<<hora.DiaSemana<<" "<<hora.HoraInicio<<" "<<hora.MinutoInicio<<" "<<hora.HoraFin<<" "<<hora.HoraFin<<"\n\n";
			horario.close();
      }
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
   fflush(stdin);
 	return opcion;
}

