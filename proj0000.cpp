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
   char NombreMateria[50];
   char NombreSemestre[50];
   char NombreDia[10];
   char DiaSemana[4];
   int HoraInicio;
   int MinutoInicio;
   int HoraFin;
   int MinutoFin;
   int Orden;
  };



//PROTOTIPO DE FUNCIONES

int Menu();
void cambioEspaciosNombres(char cadena[50], char buscar[2], char reemplazar[2]);
void quitarEspacios(char entrada[50], char salida[50]);
bool validarNombre(char nombre[50]);
bool obtenerDiaSemana(DatosHoraClase &hora);
bool validarHoras(DatosHoraClase hora);
void IngresarHorariodeClases();

void VerHorarioHoy();
void VerhHorariodelaSemana();

//Funcion Principal
int main ()
{
 int opcion;
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

//  Funciones de Sistema Modular
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

void cambioEspaciosNombres(char cadena[50], char buscar[2], char reemplazar[2]){

char * puntero;
puntero = strstr (cadena,buscar);
while(puntero != NULL){
  strncpy (puntero,reemplazar,1);
  puntero = strstr (cadena,buscar);
}

}

void quitarEspacios(char entrada[50], char salida[50])
{
    int inicio_pos;
    int longitud;
    int actual_pos = 0;
    //Avanza en la cadena hasta que detecta un caracter valido
    while(entrada[actual_pos] == ' ' || entrada[actual_pos] == '\n' || entrada[actual_pos] == '\t')
    {
        actual_pos ++;
    }
    inicio_pos = actual_pos;

    //Retrocede en la cadena hasta encontrar un caracter valido
    actual_pos = strlen(entrada) - 1;
    while(entrada[actual_pos] == ' ' || entrada[actual_pos] == '\n' || entrada[actual_pos] == '\t')
    {
        actual_pos --;
    }
    longitud = actual_pos - inicio_pos + 1;
	 strncpy(salida, entrada + inicio_pos, longitud);
}

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
bool obtenerDiaSemana(DatosHoraClase &hora)
{
   bool resultado = false;
	if (strcmp(hora.DiaSemana,"LUN")==0 || strcmp(hora.DiaSemana,"Lun")==0 || strcmp(hora.DiaSemana,"lun")==0) {
   	strcpy(hora.NombreDia,"Lunes");
      hora.Orden = 1;
      resultado = true;
  	}
   if (strcmp(hora.DiaSemana,"MAR")==0 || strcmp(hora.DiaSemana,"Mar")==0 || strcmp(hora.DiaSemana,"mar")==0) {
   	strcpy(hora.NombreDia,"Martes");
      hora.Orden = 2;
      resultado = true;
  	}
   if (strcmp(hora.DiaSemana,"MIE")==0 || strcmp(hora.DiaSemana,"Mie")==0 || strcmp(hora.DiaSemana,"mie")==0) {
   	strcpy(hora.NombreDia,"Miercoles");
      hora.Orden = 3;
      resultado = true;
  	}
   if (strcmp(hora.DiaSemana,"JUE")==0 || strcmp(hora.DiaSemana,"Jue")==0 || strcmp(hora.DiaSemana,"jue")==0) {
   	strcpy(hora.NombreDia,"Jueves");
      hora.Orden = 4;
      resultado = true;
  	}
   if (strcmp(hora.DiaSemana,"VIE")==0 || strcmp(hora.DiaSemana,"Vie")==0 || strcmp(hora.DiaSemana,"vie")==0) {
   	strcpy(hora.NombreDia,"Viernes");
      hora.Orden = 5;
      resultado = true;
  	}
   return resultado;
}

bool validarHoras(DatosHoraClase hora)
{

	bool resultado = false;
   int hora_inicio = hora.MinutoInicio + (hora.HoraInicio * 60);
   int hora_fin = hora.MinutoFin + (hora.HoraFin * 60);
   if(hora_inicio < hora_fin){
        resultado = true;
   } else {
    	printf("\n La hora de Inicio debe ser Menor que la hora Fin \n");
   }
   return resultado;
}

void IngresarHorariodeClases()
{
      struct DatosHoraClase hora;
      char buscar[2] = " ";
		char reemplazar[2] = "_";
      char nombreMateria[50] = "";
      char nombreSemestre[50] = "";

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
       do
		{
      	printf("\n Dia de la Semana: ");
      	gets(hora.DiaSemana);
         fflush(stdin);
      } while(!obtenerDiaSemana(hora));

      do
      {
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
      } while(!validarHoras(hora));


      quitarEspacios(hora.NombreMateria,nombreMateria);
      strcpy(hora.NombreMateria,"");
      strcpy(hora.NombreMateria,nombreMateria);

      strcpy(nombreSemestre,"");
      quitarEspacios(hora.NombreSemestre,nombreSemestre);
      strcpy(hora.NombreSemestre,"");
      strcpy(hora.NombreSemestre,nombreSemestre);

      cambioEspaciosNombres(hora.NombreMateria,buscar,reemplazar);
      cambioEspaciosNombres(hora.NombreSemestre,buscar,reemplazar);


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
      	horario<<hora.NombreMateria<<" "<<hora.NombreSemestre<<" "<<hora.NombreDia<<" "<<hora.HoraInicio<<" "<<hora.MinutoInicio<<" "<<hora.HoraFin<<" "<<hora.HoraFin<<" "<<hora.Orden<<endl;
			horario.close();
      }
     // Salir
}



