//Alejandro Hidalgo Badillo
//Lun 22 de agosto 2022
//Actividad 1.2 Implementacion de la tecnica de programacion "Programacion dinamica" y "algoritmos avaros"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;

//se declaran los vectores implementados en el programa
std::vector<double> arreglo;
std::vector<double> residue;




void merge(double array[], int const left, int const mid,
           int const right)
{
	//Merge tiene una complejidad lineal, cuenta con ciclos for y while pero no estan anidados para generar una complejidad superior
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Se crean los arreglos temporales
    auto *arrayIzq = new double[subArrayOne],
         *arrayDer = new double[subArrayTwo];
 
    // Copiar datos a arreglos temporales
    for (auto i = 0; i < subArrayOne; i++)
        arrayIzq[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        arrayDer[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne=0,indexOfSubArrayTwo=0;
    int indexOfMergedArray=left; 
 
  //se comparan los indices de izquiera y derecha 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (arrayIzq[indexOfSubArrayOne]
            >= arrayDer[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                =  arrayIzq[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = arrayDer[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
   //se copian los elementos sobrantes de la izquierda
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            =  arrayIzq[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // se copian los elementos sobrantes de la derecha
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = arrayDer[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] arrayIzq; //se limpean los arreglos
    delete[] arrayDer;
}
 

void mergeSort(double array[], int const inicio, int const final)
{
	//la funcion mergeSort tiene una complejidad logaritmica debido a la recusividad que tiene O(log n)
    if (inicio >= final)
        return; //recursividad
 
    auto mitad = inicio + (final - inicio) / 2;
    mergeSort(array, inicio, mitad); //recursion
    mergeSort(array, mitad + 1, final); //recursion
    merge(array, inicio, mitad, final);
}
 

// Imprimir Arreglo
void printArray(double arr[], int size)
{
		cout<<"-->"<<endl;
    for (auto i = 0; i < size; i++){
			 cout << arr[i] << " / ";
		}
		cout<<endl;
}
//dispensador del total de cambio y los billetes, monedas utilizados
void coinMenu(double arr[], int size, int q, int p){
	//p = producte price
	//q = money given
	//inicio condicionales de seguridad para no hacer operaciones imposibles
	int cont = 0;
	auto change = q - p;
	if (change < 0){
		cout<<"Insufficient money"<<endl;
		return;
	}
	if (change == 0){
		cout<<"Exact quantity of money"<<endl;
		return;
	}
	//fin de condiciones de seguridad
	
	for(auto i = 0; i < size; i++){
	//coinMenu tiene una complejidad de O(n*n) debido a que tiene un while anidado dentro de un for

//coinMenu busca dar los billetes o el cambio de mayor a menor posible
		while(change-arr[i]>=0){
			
			if(change-arr[i]==0){ //se compara el valor y si su reslutante es cero para sumar la cantidad correcta y desplegar los resultados correctos
			change=change-arr[i];
			cont++;
			}
			if(change-arr[i]<=0 ){
				break;
			}
			change=change-arr[i];
			cont++;
			if(change-arr[i]==0){ //se compara el valor y si su reslutante es cero para sumar la cantidad correcta y desplegar los resultados correctos
			change=change-arr[i];
			cont++;
			}
			
		} //fin del while
		if(cont>0){
			cout<<cont<<" "<<arr[i]<<endl;
			cont=0;
		}
		
			if (change == 0){
				break;  //romper el for cuando ya se haya dado el cambio exacto
			}
	} //fin del for
	//cout<<"change given: ";
	//for (auto a = 0; a<cont;a++){
	//	cout<<residue[a]<<" /";
	//}
	//cout<<endl;
}

void AlgoritmoAvaro(double array[], int N,int q,int p){ 
	//el algoritmo Avaro busca al menor todo el tiempo, para almacenarlo en la variable temp, y de esta reasignarla en array

	//el algoritmo avaro tiene una complejidad de O(n*n) debido a que tiene dos for anidados

	
        double Temp; 
         for(int i=0;i<N;i++) 
                for(int q=0;q<N-1;q++) 
                    if(array[q]<array[q+1]){
                        Temp=array[q]; 
                        array[q]=array[q+1]; 
                        array[q+1]=Temp;} 

										 // for(int i=0;i< N;i++) 
                    //cout<<array[i]<<endl; 
                        
				coinMenu(array,N,q, p);          
    //despues de ordenar los datos de monedas de manera avara, se llama a la funcion para regresarnos el cambio completo
                        
						} 

//en el main se llaman todas las funciones definidas en la parte superior

int main()
{
	
 
	
	int num;
	int n;
	int qp = 0,q = 0,p = 0;
	//cout<<"Escribe N: "<<endl;
	cin>>n;
	
	//cout<<"Escribe los valores de moneda: "<<endl;
	for(int i = 0; i<n;i++){
		cin>>num;
		arreglo.push_back(num);
		
	}
	
	//cout<<"ingresa p: "<<endl;
	cin>>p;
	//cout<<"ingresa q:"<<endl;
	cin>>q;
		
		
		double arr[n];
		for (int a = 0; a<n;a++ ){
			arr[a]=arreglo[a];
		}

		//cout<<"<==========>"<<endl;
    
    auto size = sizeof(arr) / sizeof(arr[0]);
 		//toda la implementacion del merge sort para ordenar los valores de mayor a menor de los tipos de billetes y monedas de cambio
	
    //cout << "Coin values: " << endl;
    //printArray(arr, size);
 		//cout<<endl;
    mergeSort(arr, 0, size - 1); //se llama la funcion del mergeSort
 
    //cout << "Sorted coin values: " << endl;
    //printArray(arr, size);
		//cout<<endl;
		//cout<<"<==============>"<<endl;
		coinMenu(arr,size,q,p);

		cout<<endl;
		AlgoritmoAvaro(arr,n,q,p);
//Complejidad general del programa 
	//el programa en general tiene una complejidad de O(logn) debido a la recursion generara en el mergeSort
    return 0;
}
//la complejidad general del programa es O logn debido a que mergeSort tiene una recursion implementada 