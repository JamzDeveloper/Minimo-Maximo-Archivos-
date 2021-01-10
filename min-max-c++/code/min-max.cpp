/*si se desea leer mas numeros cambiar el tamaño del arreglo
en la linea 16 y el nombre del archivo en la linea 70*/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <chrono>
#include <locale.h>
using namespace std;

int mayor(int[], int, int);
int menor(int[], int, int);
void leer();
FILE *fd;
int arreglo[1600];
int tamanioArreglo = sizeof(arreglo);
int aux = sizeof(int);

int main()
{
    int opc;
    tamanioArreglo /= aux;
   
    float tiempoEjecucion = 0.0;

    do
    {
        cout << "\n1.ver arreglo";
        cout << "\n2.ver Maximo y Minimo";
        cout << "\n3.salir";
        cout << "\nopc: ";
        cin >> opc;
        switch (opc)
        {

        case 1:
            cout << "ARREGLO\n";

            leer();
            for (int i; i < tamanioArreglo; i++)
                cout << arreglo[i] << endl;
            break;
        case 2:
            leer();
            //EMPESAMOS A CONTROLAR EL TIEMPO
            auto start = std::chrono::system_clock::now();
            cout << "\n\nel mayor es: ";
            cout << mayor(arreglo, 0, tamanioArreglo - 1);
            cout << "\nel minimo es: ";
            cout << menor(arreglo, 0, tamanioArreglo - 1);

            //TERMINAMOS DE CONTROLAR EL TIEMPO
            auto end = std::chrono::system_clock::now();

            tiempoEjecucion = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            cout << "\ntiempo de ejecucion: " << tiempoEjecucion<<" nanosegundo" << endl;
            break;
        }

    } while (opc != 3);

    return 0;
}
void leer()
{

    char k[4];
    char aux;
    char text[16] = "1600numeros.txt";
    string cadenaNumeros = "";
    int i = 0, j = 0;

    if ((fd = fopen(text, "rt")) != NULL)
    {
        while (!feof(fd))
        {

            aux = fgetc(fd);
            if (aux == '\n')
            {
                continue;
            }
            k[i] = aux;

            i++;
            if (i == 4)
            {
                cadenaNumeros = k;
                i = 0;
                
                arreglo[j] = atoi(cadenaNumeros.c_str());
                j++;
            }
        }
    }
}
int mayor(int arreglo[], int inicio, int fin)
{
    int maxIzquierda, maxderecha, medio;

    if (inicio == fin)
    {
        return arreglo[inicio];
    }
    else
    {
        medio = ((inicio + fin) / 2);
        //busca el maximo valo de lado izquierdo
        maxIzquierda = mayor(arreglo, inicio, medio);
        //buca el maximo valor de lado derecho
        maxderecha = mayor(arreglo, medio + 1, fin);

        //compara y devuelve el maximo valor
        if (maxIzquierda > maxderecha)
        {
            return maxIzquierda;
        }
        else
        {
            return maxderecha;
        }
    }
}

int menor(int arreglo[], int inicio, int fin)
{
    int minIzquierda, minderecha, medio;
    if (inicio == fin)
    {
        return arreglo[inicio];
    }
    else
    {
        medio = (int)((inicio + fin) / 2);
        //busca el minimo valo de lado izquierdo
        minIzquierda = menor(arreglo, inicio, medio);
        //busca el minimo valo de lado izquierdo
        minderecha = menor(arreglo, medio + 1, fin);

        //compara y devuelve el menor valor
        if (minIzquierda < minderecha)
        {
            return minIzquierda;
        }
        else
        {
            return minderecha;
        }
    }
}