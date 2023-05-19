#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Punto{
	int IdentificadorDePunto;
	float valorEnX;
	float valorEnY;
	float modulo;
	float angulo;
}Punto;

typedef struct Distancia{
	
	int punto1;
	int punto2;
	float distanciaEntre;
	
}Distancia;

int DefPuntos(int num);
float numAle(float ale);
void PuntosAle(int num,Punto *punto);
void PuntosManual(int num,Punto *punto);
float modulo (int i, Punto *punto);
float angulo (int i, Punto *punto);
void Imprimir(int num,Punto *punto);
void suma (Punto *punto,int p2, int p1);
void resta (Punto *punto,int p2, int p1);
void producto(Punto *punto,int p2, int p1);
void division(Punto *punto,int p2, int p1);
void disPuntos (Punto *punto,int p2, int p1);
void menDistancia(Punto *punto,int num);
void puntCercano(Punto *punto,int num);
void MenorDis(int num,Punto *punto,int p2, int p1,Distancia *dis);
void Menu(int num,Punto *punto,Distancia *dis);


int introPuntos1();
int introPuntos2();
int main(){
	//Variables de el struct Punto
	struct Punto *punto;
	//Variables enteras
	int num;
	//Variables flotantes
	float ale;
	printf("Cuantos puntos habra: ");
	num=DefPuntos(num);//Aqui se introducen cuantos puntos habra
	printf("\n");
	punto = (struct Punto *) calloc (num, sizeof (struct Punto));//Arreglo dinamico de structs
	struct Distancia *dis;
	dis = (struct Distancia *) calloc (num, sizeof (struct Distancia));
	
	int opc;

	puts("Como quieres generar los puntos?");
	printf("1.- Genera lista de puntos aleatoriamente \n2.- Genera lista de puntos manualmente\n3.- Salir\n");
	printf("Respuesta: ");
	scanf("%d",&opc);
	printf("\n");
	switch(opc){
		case 1:
			PuntosAle( num, punto);
			Menu(num,punto,dis);
		break;
		case 2:
			PuntosManual(num,punto);
			Menu(num,punto,dis);
		break;
	default:
		printf("\nHasta pronto\n");	
	break;

	}	


/*	struct Distancia *dis;
	dis = (struct Distancia *) calloc (num, sizeof (struct Distancia));

	Menu( num,punto,dis);

	free(punto);
	free(dis);*/
	
	
	return 0;
}
//----
//Definir puntos
int DefPuntos(int num){
	scanf("%d",&num);
	fflush(stdin);
	return num;
}

//Numeros Aleatorios
float numAle(float ale){
	
    ale=-200+rand()%(200-(-200)+1);
    
	float y,a = 5.0;
   
    y=(((float)rand())/(float)(10000)*a);
	ale=ale+y;
	return ale;
}

//Generar puntos aleatorios
void PuntosAle(int num,Punto *punto){
	FILE *fichero;
	float ale,y;
	

	fichero = fopen ("compendioDePuntos.txt", "wt");
	 fprintf (fichero, "%s %c %s %c %s %c %s %c %s %c","IdentificadorDePunto",'\t',"valorEnX",'\t',"valorEnY",'\t',"modulo",'\t',"angulo",'\n');
	if(fichero==NULL){printf("Fallo");}//Condicion para validar archivo


	for(int i=0;i<num;i++){//Ciclo para asignar valores al numero de puntos especificados
		punto[i].IdentificadorDePunto=i+1;
		printf("ID: %d\n",punto[i].IdentificadorDePunto);
		fflush(stdin);
	
		punto[i].valorEnX=numAle(ale);
		printf("X: %.2f\n",punto[i].valorEnX);
		punto[i].valorEnY=numAle(ale);
		printf("Y: %.2f\n",punto[i].valorEnY);

		punto[i].modulo= modulo (i,punto);
		printf("Modulo: %.2f\n",punto[i].modulo);
		punto[i].angulo=angulo(i,punto);
		printf("Angulo: %.2f grados\n\n",punto[i].angulo);
	
		fprintf (fichero,"%d",punto[i].IdentificadorDePunto);
		fprintf(fichero,"\t\t%c %c %c %c %.2f",'\t','\t','\t','\t',punto[i].valorEnX);
		fprintf(fichero,"\t\t%.2f",punto[i].valorEnY);
		fprintf(fichero,"\t\t%.2f",punto[i].modulo);
	  	fprintf(fichero,"\t\t%.2f grados %c",punto[i].angulo,'\n');
	}

	
	fclose(fichero);

}

// Generar puntos manuales
void PuntosManual(int num,Punto *punto){
	
	FILE *fichero;
	float x,y;
	

	fichero = fopen ("compendioDePuntos.txt", "wt");
	fprintf (fichero, "%s %c %s %c %s %c %s %c %s %c","IdentificadorDePunto",'\t',"valorEnX",'\t',"valorEnY",'\t',"modulo",'\t',"angulo",'\n');
	if(fichero==NULL){printf("Fallo");}//Condicion para validar archivo
	
	for(int i=0;i<num;i++){//Ciclo para especificar las caracteristicas de los puntos
		printf("Introduzca el identificador del punto: ");
		scanf("%d",&punto[i].IdentificadorDePunto);
		fflush(stdin);
		
		printf("Introduzca el valor en X: ");
		scanf("%f",&punto[i].valorEnX);
		fflush(stdin);
	
		printf("Introduzca el valor en Y: ");
		scanf("%f",&punto[i].valorEnY);
		fflush(stdin);

		punto[i].modulo= modulo (i,punto);
		printf("Modulo: %.2f\n",punto[i].modulo);
		punto[i].angulo=angulo(i,punto);
		printf("Angulo: %.2f grados\n\n",punto[i].angulo);
	
		fprintf (fichero,"%d",punto[i].IdentificadorDePunto);
		fprintf(fichero,"\t\t\t\t\t\t%.2f",punto[i].valorEnX);
		fprintf(fichero,"\t\t%.2f",punto[i].valorEnY);
		fprintf(fichero,"\t\t%.2f",punto[i].modulo);
		fprintf(fichero,"\t\t%.2f grados%c",punto[i].angulo,'\n');
	}

	
	fclose(fichero);
	
	
}

//Modulo
float modulo(int i, Punto *punto){
		float x,y,result;
	
		x=pow(punto[i].valorEnX,2.0);
		y=pow(punto[i].valorEnY,2.0);
		result= x + y;
	//	d=sqrt(z);
	
	return sqrt(result);
}

//Angulo
float angulo(int i, Punto *punto){
	
	float z,tan,anres,res;
	
	z=punto[i].valorEnY/punto[i].valorEnX;
	tan= atan(z);
	res=tan * 180 / 3.1416;
	if (punto[i].valorEnY<0 || punto[i].valorEnX<0){
	anres= res + 180;
	}
	else{
		anres= res;
	}
	
	return anres;
}

//Imprimir punto
void Imprimir(int num,Punto *punto){
	
		int i;
		
		printf("\nCual es el punto que quieres ver: ");
		scanf("%d",&i);
		fflush(stdin);
		
		printf("\nID: %d \n",punto[i-1].IdentificadorDePunto);
		printf("X: %.2f \n",punto[i-1].valorEnX);
		printf("Y: %.2f \n",punto[i-1].valorEnY);
		printf("Modulo: %.2f \n",punto[i-1].modulo);
		printf("Angulo: %.2f grados\n",punto[i-1].angulo);
	
	
}



//Suma de puntos
void suma (Punto *punto,int p2, int p1){
	float sX,sY;
	sX= (punto[p1-1].valorEnX /*X1*/+ punto[p2-1].valorEnX/*X2*/);
	sY=(punto[p1-1].valorEnY/*Y1*/ + punto[p2-1].valorEnY/*Y2*/);
	printf("Suma de (%.2f + %.2f)+i(%.2f + %.2f) = %.2f + i%.2f",punto[p1-1].valorEnX,punto[p2-1].valorEnX,punto[p1-1].valorEnY, punto[p2-1].valorEnY,sX,sY);
	
}

//Resta de puntos
void resta (Punto *punto,int p2, int p1){
	
	float rX,rY;
	rX= (punto[p1-1].valorEnX /*X1*/- punto[p2-1].valorEnX/*X2*/);
	rY=(punto[p1-1].valorEnY/*Y1*/ - punto[p2-1].valorEnY/*Y2*/);
	printf("\nResta de (%.2f - %.2f)+i(%.2f - %.2f) = %.2f + i%.2f",punto[p1-1].valorEnX,punto[p2-1].valorEnX,punto[p1-1].valorEnY, punto[p2-1].valorEnY,rX,rY);
	
}

//Producto de puntos
void producto(Punto *punto,int p2, int p1){
	float pM,pA;
	
	pM= (punto[p1-1].modulo /*R1*/* punto[p2-1].modulo/*R2*/);
	pA = (punto[p1-1].angulo + punto[p2-1].angulo);
	printf("\nProducto de (%.2f * %.2f) (%.2f grados + %.2f grados) = %.2f, %.2f grados ",punto[p1-1].modulo, punto[p2-1].modulo, punto[p1-1].angulo, punto[p2-1].angulo, pM,pA);
	
}

//Division de puntos
void division(Punto *punto,int p2, int p1){
	float dM, dA;

	dM= (punto[p1-1].modulo /*R1*// punto[p2-1].modulo/*R2*/);
	dA = (punto[p1-1].angulo - punto[p2-1].angulo);
	printf("\nDivision de (%.2f / %.2f) (%.2f grados - %.2f grados) = %.2f, %.2f grados",punto[p1-1].modulo, punto[p2-1].modulo, punto[p1-1].angulo, punto[p2-1].angulo, dM,dA);
	
}

//Distancia entre puntos
void disPuntos (Punto *punto,int p2, int p1){
	

	float x,y,z,DP;


	x=pow(punto[p2-1].valorEnX-punto[p1-1].valorEnX,2.0);
	y=pow(punto[p2-1].valorEnY-punto[p1-1].valorEnY,2.0);
	z= x + y;
	DP=sqrt(z);

	printf("\nLa distancia entre el punto %d y %d es %.2f ",punto[p1-1].IdentificadorDePunto,punto[p2-1].IdentificadorDePunto,DP );
	
	
}

//Menor Distancia
void menDistancia(Punto *punto,int num){
	int a,b,i,j,k,x,d,p1,p2,conta=0,np;
	float *distancias,aux,aux1;
	
	distancias=(float*)malloc(1*sizeof(float));
	
	for(i=0;i<num;i++){
		for(k=0;k<num;k++){
			if(k>i){
			distancias[conta]=sqrt(pow(punto[i].valorEnX-punto[k].valorEnX,2)+pow(punto[i].valorEnY-punto[k].valorEnY,2));
			conta++;
			np=conta+1;
			distancias=(float*)realloc((distancias),np*sizeof(float));
			}
		}
	}
	
	np--;
	
	for(i=1;i<np;i++){
		j=i;
		aux = distancias[i];
		while(j>0 && aux<distancias[j-1]){
			distancias[j]=distancias[j-1];
			j--;
		}
		distancias[j]=aux;
	}
	
	aux=distancias[0];
	
	for(i=0;i<num;i++){
		for(k=0;k<num;k++){
			if(k>i){
			aux1=sqrt(pow(punto[i].valorEnX-punto[k].valorEnX,2)+pow(punto[i].valorEnY-punto[k].valorEnY,2));
			}if(aux==aux1){
			p1=i;
			p2=k;}
		}	
	}
	
	printf("La menor distancia es de d=%.2f, la cual encuentra entre los puntos: \n",distancias[0]);
	printf("Punto 1 \n ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f \n\n",punto[p1].IdentificadorDePunto,punto[p1].valorEnX,punto[p1].valorEnY,punto[p1].modulo,punto[p1].angulo);
	printf("Punto 2 \n ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f \n",punto[p2].IdentificadorDePunto,punto[p2].valorEnX,punto[p2].valorEnY,punto[p2].modulo,punto[p2].angulo);
	
	FILE* archivo;	
	archivo = fopen("resultadosDeDistancias.txt","wt");
				fprintf(archivo,"- Menor distancia -");
			    fprintf(archivo, "\nLa menor distancia es de d=%.2f, la cual encuentra entre los puntos: \n",distancias[0]);
	            fprintf(archivo, "Punto 1 \n ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f \n\n",punto[p1].IdentificadorDePunto,punto[p1].valorEnX,punto[p1].valorEnY,punto[p1].modulo,punto[p1].angulo);
	            fprintf(archivo, "Punto 2 \n ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f \n",punto[p2].IdentificadorDePunto,punto[p2].valorEnX,punto[p2].valorEnY,punto[p2].modulo,punto[p2].angulo);
				fprintf(archivo,"\n \n");
				fprintf(archivo, "El resultado de las demas distancias esta ordenado de manera ascendente:\n \n");
				for(i=1;i<np;i++){
				fprintf(archivo,"-d%d=%.2f \n",i,distancias[i]);
				}		
	fclose(archivo);
	free(distancias);
	printf("Proceso de escritura en archivo txt terminado.\n\n");
}


void puntCercano(Punto *punto,int num){
	int a,b,i,j,k,x,d,p1,p2,conta=0,np=0;
	float *distancias,aux,aux1;
	
	distancias=(float*)malloc(1*sizeof(float));
	
		printf("Por favor ingrese el Id del punto sobre el cual se va a trabajar: \n");
		scanf("%d",&a);
	
	for(i=0;i<num;i++){
		if(a==punto[i].IdentificadorDePunto){
			p1=i;	}
	}
	
	printf("\nDatos del punto:");
	printf("\nID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f grados \n\n",punto[p1].IdentificadorDePunto,punto[p1].valorEnX,punto[p1].valorEnY,punto[p1].modulo,punto[p1].angulo);
	
	for(i=0;i<num;i++){
		
		if(p1==i){i=i+1;}
		
		distancias[conta]=sqrt(pow(punto[p1].valorEnX-punto[i].valorEnX,2)+pow(punto[p1].valorEnY-punto[i].valorEnY,2));
		conta++;
		np=conta+1;
		distancias=(float*)realloc((distancias),np*sizeof(float));
	}
	
	np--;	
	
	for(i=1;i<np;i++){
		j=i;
		aux = distancias[i];
		while(j>0 && aux<distancias[j-1]){
			distancias[j]=distancias[j-1];
			j--;
		}
		distancias[j]=aux;
	}
	
	aux=distancias[0];
	
	for(i=0;i<num;i++){
		if(p1==i){i=i+1;}
		aux1=sqrt(pow(punto[p1].valorEnX-punto[i].valorEnX,2)+pow(punto[p1].valorEnY-punto[i].valorEnY,2));
		if(aux==aux1){
			p2=i;
		}
	}
	
	printf("Los datos de el punto vecino mas cercano son: \n");
	printf("ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f grados \n",punto[p2].IdentificadorDePunto,punto[p2].valorEnX,punto[p2].valorEnY,punto[p2].modulo,punto[p2].angulo);
	printf("La distancia estre estos 2 puntos es de: d=%.2f \n\n",distancias[0]);
	
	FILE* archivo;	
	archivo = fopen("vecinoMasCercano.txt","wt");
				fprintf(archivo,"- Vecino mas cercano -");
				fprintf(archivo,"\nDatos del punto ingresado por el usuario:");
				fprintf(archivo,"\nID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2fgrados \n\n",punto[p1].IdentificadorDePunto,punto[p1].valorEnX,punto[p1].valorEnY,punto[p1].modulo,punto[p1].angulo);
			    fprintf(archivo, "Los datos de el punto vecino mas cercano son: \n");
	            fprintf(archivo, "ID: %d  X: %.2f  Y: %.2f  Modulo: %.2f   Angulo: %.2f grados \n",punto[p2].IdentificadorDePunto,punto[p2].valorEnX,punto[p2].valorEnY,punto[p2].modulo,punto[p2].angulo);
	            fprintf(archivo, "La distancia estre estos 2 puntos es de: d=%.2f \n\n",distancias[0]);
				fprintf(archivo,"\n \n");
				fprintf(archivo, "El resultado de las demas distancias esta ordenado de manera ascendente:\n \n");
				for(i=1;i<np;i++){
				fprintf(archivo,"-d%d=%.2f \n",i,distancias[i]);
				}		
	fclose(archivo);
	free(distancias);
	printf("Proceso de escritura en archivo txt terminado.\n\n");
	
}


//Menu
void Menu(int num,Punto *punto,Distancia *dis){
	int opc=0;	
	do{
		printf("\n\t\tMenu\nQue quieres hacer?\n");
		printf("1.- Suma puntos \n2.- Resta puntos \n3.- Multiplica puntos \n4.- Divide puntos \n5.- Determina distancia entre puntos \n6.- Determina la menor distancia entre puntos \n7.- Encontrar el punto mas cercano\n8.- Imprime detalles de puntos \n9.- Salir");

		printf("\nEliga una opcion: ");
		scanf("%d",&opc);

		switch(opc){

			case 1:
				suma (punto, introPuntos2(),introPuntos1());
			break;
			case 2:
				resta (punto,introPuntos2(), introPuntos1());
			break;
			case 3:
				producto(punto,introPuntos2(), introPuntos1());
			break;
			case 4:
				division(punto,introPuntos2(), introPuntos1());
			break;
			case 5:
				disPuntos (punto,introPuntos2(), introPuntos1());
			break;
			case 6:
				menDistancia(punto,num);
			break;
			case 7:
				puntCercano(punto,num);
			break;
			case 8:
				Imprimir(num,punto);
			break;

		default:
			printf("\nHasta pronto\n");
		break;

		}
	}while(opc!=9);
}

int introPuntos1(){
	int p1,p2;

	printf("\nCual es el primer punto que quieres utilizar: ");
	scanf("%d",&p1);


	return p1;
}

int introPuntos2(){
	int p2;

	printf("Cual es el segundo punto que quieres utilizar: ");
	scanf("%d",&p2);

	return p2;
}
