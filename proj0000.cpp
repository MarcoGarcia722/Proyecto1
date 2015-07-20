#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>
#include <time.h>
#include <dos.h>

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
bool validarHorasDia(DatosHoraClase hora, DatosHoraClase horas[100], int numeroHoras );
void IngresarHorariodeClases(DatosHoraClase horas[100], int numeroHoras);

int obtenerDiaActual();
int obtenerHoraActual(int dia);
int obtenerHorarioArchivo(DatosHoraClase horas[100]);
int obtenerHorarioDadoDia(DatosHoraClase horas[100], int numeroHoras,DatosHoraClase horasHoy[50], int numeroDia );
void ordenarHorario(DatosHoraClase horas[100], int numeroHoras);
void imprimir(DatosHoraClase horas[100], int numeroHoras, int horaActual);

void VerHorarioHoy();
void VerHorariodelaSemana();
//Funcion Principal
int main ()
{
 int opcion;
 struct DatosHoraClase horas[100];
 int numeroHoras;

 opcion = Menu();

 if(opcion!=4)
 {
   numeroHoras = obtenerHorarioArchivo(horas);
 }

 while (opcion!=4)
 {
  switch(opcion)
  {
   case 1:
          IngresarHorariodeClases(horas,numeroHoras);
          numeroHoras = obtenerHorarioArchivo(horas);
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

bool validarHorasDia(DatosHoraClase hora, DatosHoraClase horas[100], int numeroHoras )
{
	struct DatosHoraClase horasHoy[50];
   bool resultado = true;
   int i;
   i = 0;
   int numeroHorasHoy = obtenerHorarioDadoDia(horas,numeroHoras,horasHoy,hora.Orden);

   int horaInicioAlmacenada, horaInicio = hora.MinutoInicio + (hora.HoraInicio * 60);
   int horaFinAlmacenada, horaFin = hora.MinutoFin + (hora.HoraFin * 60);
   while(i<=numeroHorasHoy){
      horaInicioAlmacenada = horasHoy[i].MinutoInicio + (horasHoy[i].HoraInicio * 60);
      horaFinAlmacenada =  horasHoy[i].MinutoFin + (horasHoy[i].HoraFin * 60);
      if((horaInicio < horaFinAlmacenada)&&(horaFin > horaInicioAlmacenada)){
         resultado = false;
      }
      i = i + 1;
   }
   if(!resultado)
   {
      printf("\n Ya existe una hora registrada en el horario, en la hora ingresada.\n");
   }
   return resultado;
}


void IngresarHorariodeClases(DatosHoraClase horas[100], int numeroHoras)
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
      // Validar Hora de Clase        
      } while(!validarHorasDia(hora, horas, numeroHoras));

      quitarEspacios(hora.NombreMateria,nombreMateria);
      strcpy(hora.NombreMateria,"");
      strcpy(hora.NombreMateria,nombreMateria);

      strcpy(nombreSemestre,"");
      quitarEspacios(hora.NombreSemestre,nombreSemestre);
      strcpy(hora.NombreSemestre,"");
      strcpy(hora.NombreSemestre,nombreSemestre);

      cambioEspaciosNombres(hora.NombreMateria,buscar,reemplazar);
      cambioEspaciosNombres(hora.NombreSemestre,buscar,reemplazar);

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
      	horario<<hora.NombreMateria<<" "<<hora.NombreSemestre<<" "<<hora.NombreDia<<" "<<hora.HoraInicio<<" "<<hora.MinutoInicio<<" "<<hora.HoraFin<<" "<<hora.MinutoFin<<" "<<hora.Orden<<endl;
			horario.close();
      }
     // Salir
}

// leer Archivos

int obtenerDiaActual()
{
	int numerodia;
   struct dosdate_t diadelasemana;
   _dos_getdate(&diadelasemana);
   numerodia=diadelasemana.dayofweek;
   return numerodia;
}

int obtenerHoraActual(int dia)
{
   int hora,minutos;
	struct time t;
	gettime(&t);
	hora=t.ti_hour;
	minutos=t.ti_min;
	return minutos + (hora * 60) + (dia * 24 * 60);
}

int obtenerHorarioArchivo(DatosHoraClase horas[100])
{
 ifstream lectura;
 int contador = 0;
 char buscar[2] = "_";
 char reemplazar[2] = " ";
 lectura.open("horario.txt",ios::in);

 if(!lectura.fail()){

 lectura>>horas[contador].NombreMateria;
 while(!lectura.fail())
 {
   lectura>>horas[contador].NombreSemestre;
   lectura>>horas[contador].NombreDia;
   lectura>>horas[contador].HoraInicio;
   lectura>>horas[contador].MinutoInicio;
   lectura>>horas[contador].HoraFin;
   lectura>>horas[contador].MinutoFin;
   lectura>>horas[contador].Orden;
   cambioEspaciosNombres(horas[contador].NombreMateria,buscar,reemplazar);
   cambioEspaciosNombres(horas[contador].NombreSemestre,buscar,reemplazar);
   contador =  contador + 1;
   lectura>>horas[contador].NombreMateria;
   fflush(stdin);
 }

 }
 lectura.close();
 fflush(stdin);

 ordenarHorario(horas, contador - 1);
 return contador - 1;

}

void ordenarHorario(DatosHoraClase horas[100], int numeroHoras)
{
	int i,j;
   struct DatosHoraClase hora;
   i = 0;            // Ordena los dias
   while(i<=numeroHoras){
   	j = 0;
      while(j<=numeroHoras){
         if(horas[i].Orden < horas[j].Orden){
           hora = horas[i];
           horas[i] =  horas[j];
           horas[j] = hora;
         }
         j =  j + 1;
      }
      i = i + 1;
   }

   i = j = 0;                  // Ordena las Horas
   int fechaInicio, fechaInicio1;
   while(i<=numeroHoras){
   	j = 0;
      while(j<=numeroHoras){
         if(horas[i].Orden == horas[j].Orden){
            fechaInicio = horas[i].MinutoInicio + (horas[i].HoraInicio * 60);
            fechaInicio1 = horas[j].MinutoInicio + (horas[j].HoraInicio * 60);
         	if(fechaInicio < fechaInicio1) {
           		hora = horas[i];
           		horas[i] =  horas[j];
           		horas[j] = hora;
            }
         }
         j =  j + 1;
      }
      i = i + 1;
   }

}

void imprimir(DatosHoraClase horas[100], int numeroHoras, int horaActual)
{
 int contador = 0;
 int horaFin;
 printf("Listado de Horario \n");
 printf("____________________________\n\n");
 while(contador <= numeroHoras)
 {
 	horaFin = horas[contador].MinutoFin + (horas[contador].HoraFin * 60) + (horas[contador].Orden * 24 * 60);
   if(horaFin >= horaActual)
   {
   	printf("%s: %02dH%02d - %02dH%02d \n\n",horas[contador].NombreDia,horas[contador].HoraInicio,horas[contador].MinutoInicio,horas[contador].HoraFin,horas[contador].MinutoFin);
      printf("%s \n",horas[contador].NombreSemestre);
      printf("%s \n",horas[contador].NombreMateria);
  		printf("____________________________\n\n");
  } 
  contador = contador + 1;
 }
}

int obtenerHorarioDadoDia(DatosHoraClase horas[100], int numeroHoras,DatosHoraClase horasHoy[50], int numeroDia )
{
	int i, j;
   i = 0;
   j = 0;
   while(i<=numeroHoras){
      if(horas[i].Orden == numeroDia){
      	horasHoy[j] = horas[i];
         j = j + 1;
      }
      i = i + 1;
   }
   return j - 1;
}

