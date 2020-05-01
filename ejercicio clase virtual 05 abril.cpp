/*
EJERCICIO CLASER VIRTUAL 05 ABRIL 2020
Una empresa necesita llevar el control de los datos personales de sus 10 empleados contratados,
por la motivo la empresa lo ha contratado para la implementación de este proyecto,
los datoa a almacenar son:

codigo empleado
nombre empleado
puesto
departamento
salario

Exiten tres departamentos,1 Gerencia, 2 Administración y 3 producción.
El programa deberá desplegar la lista dde empleados almacenados y el total de la planilla
*/
//importación de librerias
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// declaracion de estructura
struct empleado{
	int codigo;
	string nombre;
	string puesto;
	string depto;
	float salario;
};

void empresa(){  // void= cuando no retornan ningun valor, cuando se retorna algun valor establece el tipo ej. int, float, bool, etc...
	//declaracion de puntero tipo estructura
	//estructura *putnero
	empleado *punteroempleado;	//para hacer dinamica la esctructura y poder llenar nuevos datos 
	
	//asignacion de espacio a puntero.
	int j, opcion;
	float total_planilla= 0.00;
	cout<<"ingrese el numero de empleados a registrar"<<endl; // nunmero de empleados a registrar.
	cin>>j;
	punteroempleado= new empleado[j]; //aparta espacios para ingresar datos
	
	// registro de empleados, asignar datos a variables
	for(int i=0;i<j;i++){
		system("CLS");
		fflush(stdin);
		cin.clear();
	
		//ingreso de datas a estrucura punteroempleado
		cout<<"ingrese codigo del empleado #"<<i+1<<": "<<endl;
		cin>> punteroempleado[i].codigo;
		cin.ignore();
		
		cout<<"ingrese nombre del empleado #"<<i+1<<": "<<endl;
		getline(cin,punteroempleado[i].nombre);
		cin.ignore();	
		
		cout<<"ingrese puesto del empleado #"<<i+1<<": "<<endl;
		getline(cin,punteroempleado[i].puesto);
		cin.ignore();
		
		//menu para seleccionar departamento
		cout<<"--------SELECCION DE DEPARTAMENTO---------"<<endl;
		cout<<"1.- Gerencia "<<endl;
		cout<<"2.- Administración"<<endl;
		cout<<"3.- Produccion "<<endl;
		cout<<"SELECCIONE UN DEPARTAMENTO: "<<endl;
		cin>>opcion;
		
		if (opcion==1){
			punteroempleado[i].depto="gerencia";
		}
		else if(opcion==2){
			punteroempleado[i].depto="Administracion";
		}
		else if(opcion==3){
			punteroempleado[i].depto="produccion";
		}
		else {
			cout<<" OPCION INVALIDA. El empleado # "<<i+1<<" N/A"<<endl;
			punteroempleado[i].depto = "sin departameto asignado";
		}
		cout<<"ingrese el salario del empleado #"<<i+1<<": " <<endl;
		cin>> punteroempleado[i].salario;
		cin.ignore();	
		
		//haciendo la sumatoria de salario de todos los empleadsos registrados
		total_planilla += punteroempleado[i].salario;
		cout<<"EMPLEADO REGISTRADO..."<<endl;
		system("pause");
	}
	system("CLS");
	//mostrar reporte ciclo for para mostrar todos los registro en el puntero estructura

	for(int i=0; i<j;i++){
		cout<<"--------------------------EMPLEADO #"<<i+1<<"----------------------"<<endl;
		cout<<"CODIGO       : "<< punteroempleado[i].codigo<<endl;
		cout<<"NOMBRE       : "<< punteroempleado[i].nombre<<endl;
		cout<<"PUESTO       : "<< punteroempleado[i].puesto<<endl;
		cout<<"DEPARTAMENTO : "<< punteroempleado[i].depto<<endl;
		cout<<"SALARIO      : "<< punteroempleado[i].salario<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
	}
	//mostrar total en planilla
	cout<<"-----------------------------------------------------------"<<endl;
	cout<< "\n\n EL TOTAL A PAGAR EN PLANILLA ES DE: Q."<<total_planilla<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
}
int main(){
	//mandar a llamar a la función
	empresa();
	
}
