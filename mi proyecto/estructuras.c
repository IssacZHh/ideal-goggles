#include <stdio.h>
//Structs
typedef struct agend{//Estructura de datos de contacto
	int id;
	char name[20];
	char surname1[20];
	char surname2[20];
	char address[30];
	char RFC[20];
	char numM[11];
	char numF[11];
	char email[30];
	char fb[20];
	char tw[20];
}agend;//Estructura de datos de contacto

//Functions------------------------------------------------------------
void vEspacioNuevo();

void impContact(agend contacts[],int num);
void nContact(agend contacts[],int num);
void bContact(int num,char searchN[],char searchS1[],char searchS2[], agend contacts[]);
void eContact(int num,agend contacts[]);
void eliContact(int num,char searchN[],char searchS1[],char searchS2[],agend contacts[]);
void FunOp(int num,char searchN[],char searchS1[],char searchS2[],agend contacts[]);

//End Functions------------------------------------------------------------

int main()//Inicio de Main
{
//Declaracion de variables--------------------------------------------------------
	struct agend contacts[101];
	int i,num,h=0,o=0;
	char searchN[20],searchS1[20],searchS2[20];
	 

//Salida--------------------------------------------------------------------------
	printf("\t\t Agenda Personal");
	printf("\n\n");
	
	

	
	//FunOp(num,searchN,searchS1,searchS2,contacts);

	
	
		
		printf("Numero de contacto(hasta 100 contactos)\n");
		scanf("%d",&num);
		i=num;
		
		
		while(h!=5){
		printf("\t\t Opciones\n");
		printf("1)Nuevo contacto\n2)Buscar contacto\n3)Editar contacto\n4)Eliminar contacto\n5)Salir\n");
		scanf("%d",&h);
		fflush(stdin);
		printf("\n");
		if(h==1)
		{
			vEspacioNuevo();
			nContact(contacts,num);
			printf("\n");
		}
		else if(h==2){
			bContact(num,searchN,searchS1,searchS2,contacts);
			printf("\n");
		}
		else if(h==3){
			eContact(num,contacts);
			printf("\n");
		}
		else if(h==4){
			eliContact(num,searchN,searchS1,searchS2,contacts);
			printf("\n");
		}
		printf("Quieres salir? oprime 5\n");
		scanf("%d",&h);
		};		
		//printf("Quieres salir? oprime 5\n");
		//scanf("%d",&h);
	
	
	
	
	
	
	return 0;
}//Fin de Main
//Functions------------------------------------------------------------------------ 

void vEspacioNuevo()
{
    printf("\n-------------------------------------------------------------------\n");
}

void impContact(agend contacts[],int num)//Funcion para imprimir el contacto (1)
{
	int i;
	i=num;
		
	vEspacioNuevo();
	printf("Contacto %d \n%s %s %s \nDirecci%cn: %s \nRFC: %s \nCelular: %s \nTel%cfono: %s\nEmail: %s \nFacebook: %s \nTwitter: %s",
	contacts[i].id,contacts[i].name,contacts[i].surname1,contacts[i].surname2,162,contacts[i].address,contacts[i].RFC,
	contacts[i].numM,130,contacts[i].numF,contacts[i].email,contacts[i].fb,contacts[i].tw);
	vEspacioNuevo();

	//printf("%d",i);
}


void nContact(agend contacts[],int num)//Nuevo Contacto (2)
{	
	int i;
	i=num;
	
	//printf("Numero de contacto\n");
	//scanf("%i",&i);
	//scanf("%i",&contacts[i].id);
	fflush(stdin);
	contacts[i].id=num;
	
	
	
	printf("Introduzca el nombre del contacto\n");
	scanf("%[^\n]",&contacts[i].name);
	fflush(stdin);
	
	printf("Introduzca el primer apellido\n");
	scanf("%[^\n]",&contacts[i].surname1);
	fflush(stdin);
	
	printf("Introduzca el segundo apellido\n");
	scanf("%[^\n]",&contacts[i].surname2);
	fflush(stdin);
	
	printf("Introduzca la direcci%cn del contacto\n",162);
	scanf("%[^\n]",&contacts[i].address);
	fflush(stdin);
	
	printf("Introduzca el RFC del contacto\n");
	scanf("%[^\n]",&contacts[i].RFC);
	fflush(stdin);
	
	printf("Introduzca el celular del contacto\n");
	scanf("%[^\n]",&contacts[i].numM);
	fflush(stdin);
	
	printf("Introduzca el tel%cfono del contacto\n",130);
	scanf("%[^\n]",&contacts[i].numF);
	fflush(stdin);
	
	printf("Introduzca el Email del contacto\n");
	scanf("%[^\n]",&contacts[i].email);
	fflush(stdin);
	
	printf("Introduzca el nombre del perfil en Facebook del contacto\n");
	scanf("%[^\n]",&contacts[i].fb);
	fflush(stdin);
	
	printf("Introduzca el nombre del perfil en Twitter del contacto\n");
	scanf("%[^\n]",&contacts[i].tw);
	fflush(stdin);
	
	
	impContact(contacts,num);
}


void bContact(int num,char searchN[],char searchS1[],char searchS2[], agend contacts[])//Buscar Contacto (3)
{
	int a=0,i;
	i=num;
	printf("\t\tBusqueda de contacto:\n");
	printf("Introduzca el nombre del contacto:\n");
	scanf("%[^\n]",searchN);
	fflush(stdin);
	printf("Introduzca el primer apellido del contacto:\n");
	scanf("%[^\n]",searchS1);
	fflush(stdin);
	printf("Introduzca el segundo apellido del contacto:\n");
	scanf("%[^\n]",searchS2);
	fflush(stdin);
	
	
		for(a;a=='\0';a++)
		{
			if (searchN[a]==contacts[i].name[a])
			{
				if(searchS1[a]==contacts[i].surname1[a])
				{
					if(searchS2[a]==contacts[i].surname2[a])
					{
						impContact(contacts,num);
					}
					else
					{
						printf("No se encontro coincidencia");
					}	
				}
				else
				{
					printf("No se encontro coincidencia");
				}	
			}
			else
			{
				printf("No se encontro coincidencia");
			}
		}
}


void eContact(int num,agend contacts[])//Editar Contacto (4) 
{
	int i,op=0;
	i=num;
	
	do{
	printf("Introduzca la letra de la opci%cn que quiera editar:\n",162);
	printf("\nContacto %d \n0) Salir  \n1) Nombre \n2) Primer apellido \n3) Segundo apellido \n4) Direcci%cn \n5) RFC \n6) Celular \n7) Tel%cfono \n8) Email \n9) Facebook \n10) Twitter\n",contacts[i].id,162,130);
	printf("Opci%cn\n",162);
	scanf("%d",&op);
	fflush(stdin);
		if(op==1)
		{
			printf("El nombre actual es: %s\n",contacts[i].name);
			printf("%cCu%cl es el nuevo nombre?:\n",168,160);
			scanf("%[^\n]",&contacts[i].name);
			fflush(stdin);
			printf("El nuevo nombre es: %s\n",contacts[i].name);
		}
		else
		{
			if(op==2)
			{
				printf("El apellido actual es: %s\n",contacts[i].surname1);
				printf("%cCu%cl es el nuevo apellido?:\n",168,160);
				scanf("%[^\n]",&contacts[i].surname1);
				fflush(stdin);
				printf("El nuevo apellido es: %s\n",contacts[i].surname1);
			}
			else
			{
				if(op==3)
				{
					printf("El apellido actual es: %s\n",contacts[i].surname2);
					printf("%cCu%cl es el nuevo apellido?:\n",168,160);
					scanf("%[^\n]",&contacts[i].surname2);
					fflush(stdin);
					printf("El nuevo apellido es: %s\n",contacts[i].surname2);
				}
				else
				{
					if(op==4)
					{
						printf("La direcci%cn actual es: %s\n",162,contacts[i].address);
						printf("%cCu%cl es la nueva direcci%cn?:\n",168,160,162);
						scanf("%[^\n]",&contacts[i].address);
						fflush(stdin);
						printf("La nueva direcci%cn es: %s\n",162,contacts[i].address);
					}
					else
					{
						if(op==5)
						{
							printf("El RFC actual es: %s\n",contacts[i].RFC);
							printf("%cCu%cl es el nuevo RFC?:\n",168,160);
							scanf("%[^\n]",&contacts[i].RFC);
							fflush(stdin);
							printf("El nuevo RFC es: %s\n",contacts[i].RFC);
						}
						else
						{
							if(op==6)
							{
								printf("El n%cmero de celular actual es: %s\n",163,contacts[i].numM);
								printf("%cCu%cl es el nuevo n%cmero de celular?:\n",168,160,163);
								scanf("%[^\n]",&contacts[i].numM);
								fflush(stdin);
								printf("El nuevo n%cmero de celular es: %s\n",163,contacts[i].numM);
							}
							else
							{
								if(op==7)
								{
									printf("El n%cmero de tel%cfono actual es: %s\n",163,130,contacts[i].numF);
									printf("%cCu%cl es el nuevo n%cmero de tel%cfono?:\n",168,160,163,130);
									scanf("%[^\n]",&contacts[i].numF);
									fflush(stdin);
									printf("El nuevo n%cmero de tel%cfono es: %s\n",163,130,contacts[i].numF);
								}
								else
								{
									if(op==8)
									{
										printf("El email actual es: %s\n",contacts[i].email);
										printf("%cCu%cl es el nuevo email?:\n",168,160);
										scanf("%[^\n]",&contacts[i].email);
										fflush(stdin);
										printf("El nuevo email es: %s\n",contacts[i].email);
									}
									else
									{
										if(op==9)
										{
											printf("El usuario de Facebook actual es: %s\n",contacts[i].fb);
											printf("%cCu%cl es el nuevo usuario de Facebook?:\n",168,160);
											scanf("%[^\n]",&contacts[i].fb);
											fflush(stdin);
											printf("El nuevo usuario de Facebook es: %s\n",contacts[i].fb);
										}
										else
										{
											if(op==10)
											{
												printf("El usuario de Twitter actual es: %s\n",contacts[i].tw);
												printf("%cCu%cl es el nuevo usuario de Twitter?:\n",168,160);
												scanf("%[^\n]",&contacts[i].tw);
												fflush(stdin);
												printf("El nuevo usuario de Twitter es: %s\n",contacts[i].tw);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	vEspacioNuevo();
	}while(op!=0);
	
	impContact(contacts,num);
	
	
	
}


void eliContact(int num,char searchN[],char searchS1[],char searchS2[],agend contacts[])//Eliminar Contacto (5) 
{
	int i,opc=0,z=0,t=0;
	i=num;
	do{
	printf("\t\tEliminar contactos\n");
	bContact(num,searchN,searchS1,searchS2,contacts);
	do{
	printf("\nQuieres eliminar este contacto\n1)SI\n2)NO\n");
	scanf("%d",&opc);
	
	if(opc==1)
	{
		for(z;z<20;z++){
		contacts[i].name[z]='\0';
		contacts[i].surname1[z]='\0';
		contacts[i].surname2[z]='\0';
		contacts[i].RFC[z]='\0';
		contacts[i].fb[z]='\0';
		contacts[i].tw[z]='\0';
		}
		z=0;
		for(z;z<11;z++)
		{
			contacts[i].numM[z]='\0';
			contacts[i].numF[z]='\0';
		}
		z=0;
		for(z;z<30;z++)
		{
			contacts[i].address[z]='\0';
			contacts[i].email[z]='\0';
		}
		
		impContact(contacts,num);
		
		printf("\nQuieres eliminar otro contacto contacto\n1)SI\n2)NO\n");
		scanf("%d",&opc);
	
	}
	
	}while(opc!=2);
	printf("\nQuieres salir\n1)SI\n2)NO\n");
			scanf("%d",&t);
		
	}while(t!=1);
	
}


void FunOp(int num,char searchN[],char searchS1[],char searchS2[],agend contacts[])//Opciones de Contacto (6) 
{
	int i,h=0,o=0;
	i=num;
	do{
		printf("\t\t Opciones\n");
		printf("1)Nuevo contacto\n2)Buscar contacto\n3)Editar contacto\n4)Eliminar contacto\n5)Salir\n");
		scanf("%d",&h);
		fflush(stdin);
		printf("\n");
		
		if(h==1)
		{
			vEspacioNuevo();
			nContact(contacts,num);
			printf("\n");
		}
		else if(h==2){
			bContact(num,searchN,searchS1,searchS2,contacts);
			printf("\n");
		}
		else if(h==3){
			eContact(num,contacts);
			printf("\n");
		}
		else if(h==4){
			eliContact(num,searchN,searchS1,searchS2,contacts);
			printf("\n");
		}
		
				
		
	}while(h!=5);
}





