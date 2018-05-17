#include <iostream>
#include <utility>
#include <float.h>
#include <stdlib.h>
#include <math.h>

//Representacion de los puntos
struct Point{
  float x,y;
};

// Funciones para ordenar
int compareX(const void* a, const void* b){
    Point *p1=(Point*)a,  *p2=(Point*)b;
    return (p1->x-p2->x);
}

int compareY(const void* a, const void* b){
    Point *p1=(Point*)a,  *p2=(Point*)b;
    return (p1->y-p2->y);
}

/*Solamente se necesida comparar los cuadrados, en vez de las distancias reales,
asi se evita el uso del sqrt todas las veces*/

float sqrDistance(Point p1, Point p2){
    return pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2);
}

//Fuerza bruta, sólo aplicada a partes pequeñas del arreglo
float bruteForce(Point P[], int n){
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i){
      for (int j = i+1; j < n; ++j){
        if (sqrDistance(P[i], P[j]) < min){
          min = sqrDistance(P[i], P[j]);
        }
      }
    }
    return min;
}

/*Encuentra la distancia minima entre un arreglo ordenado de acuerdo a Y
de los puntos mas cercanos al centro con una desviacion (tolerancia) d, la cual,
gracias al resto del programa, es la distancia minima encontrada en la parte
derecha e izquierda del arreglo/espacio*/
float closestCenter(Point strip[], int size, float d){
    float min = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i){//Buscar una distancia menor a d
      for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j){
        if (sqrDistance(strip[i],strip[j]) < min){
          min = sqrDistance(strip[i], strip[j]);
        }
      }
    }
    return min;
}

/* Partir el arreglo en partes mas pequeñas (2), y evaluar los minimos de cada
parte y buscar una distancia menor entre puntos de ambas partes */
float closestDnC(Point P[], int n){
    if (n <= 3){
      return bruteForce(P, n);
    }else{
      int mid = n/2;
      Point midPoint = P[mid];
      //Encuentra el menor de ambas partes
      float d = std::min(closestDnC(P, mid), closestDnC(P + mid, n-mid));
      //Arreglo con los puntos al rededor del centro con tolerancia de d
      Point Center[n];
      int size = 0;
      for (int i = 0; i < n; i++){
        if (abs(P[i].x - midPoint.x) < d){
          Center[size] = P[i], size++;
        }
      }

      return std::min(d, closestCenter(Center, size, d));
    }
}


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  Point Data[n];
  for (int i = 0; i < n; i++) {
    std::cin >> Data[i].x >> Data[i].y;
  }
  qsort(Data, n, sizeof(Point), compareX);
  std::cout << sqrt(closestDnC(Data, n)) << '\n';
  return 0;
}
