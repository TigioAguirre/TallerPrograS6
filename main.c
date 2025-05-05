//INTEGRANTES: AGUIRRE REMIGIO - HIDALGO MATEO - MACIAS ISAAC
//CODIGO PARA EL INVENTARIO DE UNA TIENDA


//Librerias y Funciones
#include <stdio.h>
#include <string.h>
#include "inventario.h"


// Implementación de funciones 

//Calcular el total del inventario
float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i]; // Sumar cada precio al total
    }
    return total;
}

//Calcular el promedio total del inventario
float calcularPromedio(float precios[], int cantidad) {
    float total = calcularTotal(precios, cantidad);  // Se usa la función calcularTotal
    return total / cantidad;  // Divide el total por la cantidad de productos
}

//Encontrar el producto mas caro
int encontrarMasCaro(float precios[], int cantidad) {
    int indice = 0; //Se supone que el primer producto es el mas caro
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indice]) {
            indice = i; //Actualiza la variable si hay un producto mayor
        }
    }
    return indice;
}

//Encontrar el producto mas barato
int encontrarMasBarato(float precios[], int cantidad) {
    int indice = 0; //Se supone que el primer producto es el mas caro
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indice]) {
            indice = i; //Actualiza la variable si hay un producto menor
        }
    }
    return indice;
}

//Buscar un producto del inventario
int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int cantidad, char nombreBuscado[]) {
    for (int i = 0; i < cantidad; i++) {
        
    //Se usa la funcion strcmp para comparar cadenas de caracteres 
        if (strcmp(nombres[i], nombreBuscado) == 0) { //Comparacion si las dos cadenas son exactamente iguales
            printf("Producto encontrado: %s - Precio: %.2f\n", nombres[i], precios[i]);
            return 1; //La funcion devuelve 1 si encontro el producto
        }
    }
    printf("Producto no encontrado\n");
    return 0; //La funcion devuelve 0 si no se encontro el producto
}


// Función principal
int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE]; //Arreglo para almacenar los nombres
    float precios[MAX_PRODUCTOS];            //Arreglo para almacenar los precios
    int cantidad = 0;                        //Cantidad total de productos
    int opcion;                              //Opciones del menu
    char nombreBuscado[MAX_NOMBRE];          //Arreglo para buscar un producto 

    // Solicitar la cantidad de productos a ingresar (maximo = 10)
    int n;
    printf("¿Cuántos productos desea ingresar? (máx %d): ", MAX_PRODUCTOS);
    scanf("%d", &n);
    while (n < 1 || n > MAX_PRODUCTOS) {
        printf("Cantidad inválida. Intente de nuevo: "); //Validacion
        scanf("%d", &n);
    }

   // Ingreso de los nombres y precios de los productos
    for (int i = 0; i < n; i++) {
        printf("Producto %d - Nombre: ", i + 1);
        scanf(" %[^\n]", nombres[i]); //Leer cadenas con espacios (Si los tiene)
        printf("Producto %d - Precio: ", i + 1);
        A:
        scanf("%f", &precios[i]);
        if (precios[i]<=0){
            printf("Valor Inválido, ingrese denuevo\n");
            printf("Producto %d - Precio: ", i + 1);
            goto A;
        }
    }
    cantidad = n;

    do {
    // Mostrar menú 
        printf("\n------------ INVENTARIO ------------\n");
        printf("1. Calcular total del inventario\n");
        printf("2. Calcular precio promedio\n");
        printf("3. Producto más caro\n");
        printf("4. Producto más barato\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

   // Ejecutar el codigo según la opción elegida
        switch (opcion) {
            case 1:
                printf("Total del inventario: %.2f\n", calcularTotal(precios, cantidad));
                break;
            case 2:
                printf("Precio promedio: %.2f\n", calcularPromedio(precios, cantidad));
                break;
            case 3: {
                int encontrar = encontrarMasCaro(precios, cantidad);
                printf("Producto más caro: %s - Precio: %.2f\n", nombres[encontrar], precios[encontrar]);
                break;
            }
            case 4: {
                int encontrar = encontrarMasBarato(precios, cantidad);
                printf("Producto más barato: %s - Precio: %.2f\n", nombres[encontrar], precios[encontrar]);
                break;
            }
            case 5:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf(" %[^\n]]", nombreBuscado); 
                buscarProducto(nombres, precios, cantidad, nombreBuscado);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != 6);

    return 0;
}
