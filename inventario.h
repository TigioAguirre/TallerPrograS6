#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50


float calcularTotal(float precios[], int cantidad);
float calcularPromedio(float precios[], int cantidad);
int encontrarMasCaro(float precios[], int cantidad);
int encontrarMasBarato(float precios[], int cantidad);
int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int cantidad, char nombreBuscado[]);