//Vargas Linares Adrian
//Zetina Hernandez Issac
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	int hash;
	int i,opc,clave;
	
	
	cout<<"Cuantos numeros se quieren: \n";
	cin>>hash;
	//hash = 5;
	int **arr=(int **)malloc(hash*sizeof(int *));
	int *arr_tam = (int *) malloc(hash*sizeof(int));
	int *ale = (int *)malloc(hash*sizeof(int));
	
	//---------------Numeros Aleatorios-------------
		for(i=0;i<hash;i++){
			ale[i]=rand()%200;
		}
	
	//---------------Burbuja-------------------------
		int aux=0,j=0;
		do{
		int i=0;
   			for(i;i<hash-1;i++){	
        		if(ale[i]>ale[i+1]){
          	 	 	aux=ale[i];
          		  	ale[i]=ale[i+1];
          	 	 	ale[i+1]=aux;    
        		}
    		}
    		j++;
		}while(j!=5);
	
	
	
	//-------------------------Ordenamiento Hash---------------------------------------
		for(i=0;i<hash;i++){
			arr_tam[i]=0;
			*(arr+i)=(int *) malloc(sizeof(int));
		}
	
		int indice_hash;
		int tam;
		for(i=0;i<hash;i++){

			indice_hash = ale[i] % hash;
			arr_tam[indice_hash]+=1;
			tam = arr_tam[indice_hash];
			arr[indice_hash]=(int *)realloc(*(arr+indice_hash),tam*sizeof(int));
			arr[indice_hash][tam-1]=ale[i];
		}
	
	do{
	//---------------------Opciones----------------------
		cout<<"\nQue desea hacer:\n1)Imprmir tabla hash\n2)Buscar algun valor dentro de la tabla hash\n0)Salir\nRespuesta: ";
		cin>>opc;
		cout<<"\n";
	//--------------------------------------Imprimir------------------------------	
		if(opc==1){
			int j;
	
			for(i=0;i<hash;i++){
				printf("Renglon %d: ",i);
				for(j=0;j<arr_tam[i];j++){
					printf("%d  ",arr[i][j]);
			
				}
				printf("\n");
			}
		}

	
	//--------------Busqueda Binaria-----------
		else if(opc==2){
			int hash2;
			cout<<"Que valor desea encontrar: ";
			cin>>clave;
			cout<<"\n";
			hash2 = clave % hash;
			//arr[hash2][j]	
			int elemntoMinimo=0,elemntoMaximo= arr_tam[hash2] - 1;
				//while (elemntoMinimo <= elemntoMaximo) {
        			int i = elemntoMinimo + (elemntoMaximo - elemntoMinimo) / 2;
  	
        			if (arr[hash2][i] == clave)
            			printf("El elemento se encontro en el renglon: %d y posicion: %d\n",hash2,i);
 
        			 if (arr[hash2][i] < clave){
						printf("El elemento se encontro en el renglon: %d y posicion: %d\n",hash2,i+1);
            		//	elemntoMinimo = i + 1;
					}
					
					
						if(arr[hash2][i] > clave){
							if(i>0){
							
								printf("El elemento se encontro en el renglon: %d y posicion: %d\n",hash2,i-1);
								//elemntoMaximo = i - 1;
        					}
        					else{
        						printf("No se encontro el valor\n");
        					}
        				}		
    			//}	
		}
		
	}while(opc!=0);
	
	//---------------Final---------------------
		//system("pause");
		return 0;
	
}


