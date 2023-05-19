/*Zetina Hernandez Issac
Integrar un reporte de práctica en formato pdf y el archivo.c con el 
nombre (miCatalogoDeProductos.c) donde se observe el manejo de un catálogo 
de productos, en donde mediante el uso de estructuras, punteros, funciones y 
manejos de archivos de texto podemos realizar lo siguiente:
Solicitar al usuario productos a agregar con los siguientes elementos:
idProducto, nombreProducto, descripcionProducto y costoUnitarioProducto.
Desarrollar las siguientes funciones:
• Agregar un producto mediante la terminal. Los datos de cada producto deberán de 
almacenarse en un arreglo de estructuras dinámico y al finalizar (cuando ya no se 
requieran registrar más productos por pare del usuario), se deberán de almacenar todos 
los productos en un archivo de texto denominado catProductos.txt.
• Finalmente se debe de imprimir en terminal el contenido del archivo catProductos.txt.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct producto
{

  int idProducto;
  char nombreProducto[20];
  char descProducto[100];
  float costoU;

} producto;

void AgregarProducto (int num, producto * productos);

int main ()
{


  FILE *fichero;
  struct producto *productos;
  int num;
  printf ("\t\tCat%clogo de productos\n\n",160);
  printf ("%cCuantos productos tendra el cat%clogo?\n",168,160);
  scanf("%d",&num);
  fflush (stdin);
  //num = 2; 
  productos = (struct producto *) calloc (num, sizeof (struct producto));

	
	AgregarProducto (num, productos);
	
	


  return 0;
}

void AgregarProducto (int num, producto * productos)
{
	FILE *fichero;
  int i = 0, x = 1;
 

  printf ("\t\tAgregar un producto\n\n");
  printf ("-----------------------------------\n\n");
  fichero = fopen ("catProductos.dat", "wt");	//Abre el archvio txt
  fprintf (fichero, "%s %c", "\t\tProductos", '\n');

	for (i = 0; i < num; i++)
    {				//ciclo para introducir datos del producto
	
	  printf("Escribe el id del producto:\n",productos[i].idProducto);
	  scanf ("%d", &productos[i].idProducto);
	  fflush (stdin);
	  
      printf ("Escribe el nombre del producto:\n");
      scanf ("%[^\n]", productos[i].nombreProducto);
      fflush (stdin);
	  
	  printf ("Escribe la descipci%cn del producto:\n",162);
      scanf ("%[^\n]", productos[i].descProducto);
      fflush (stdin);
	  
	  printf("Ingrese el precio:");
	  scanf("%f",&productos[i].costoU);
	  fflush (stdin);
	  
	  fprintf (fichero,"Id: %d %c",productos[i].idProducto, '\n');
	  fprintf (fichero,"Nombre: %s %c",productos[i].nombreProducto, '\n');
	  fprintf (fichero,"Descripcion: %s %c",productos[i].descProducto, '\n');
	  fprintf(fichero,"Precio unitario: $%.2f %c",productos[i].costoU, '\n');
		printf ("-----------------------------------\n\n");
		
	}

     

	printf("\t\tProductos\n");
  for (i = 0; i < num; i++){//ciclo para imprimir los productos
	  printf ("Id: %d\n",productos[i].idProducto);
      printf ("Nombre: %s\n",productos[i].nombreProducto);
	  printf ("Descripcion: %s\n",productos[i].descProducto);
      printf ("Precio: $%.2f\n",productos[i].costoU);
      
    } 
	printf ("-----------------------------------\n\n");
	fclose(fichero);
}