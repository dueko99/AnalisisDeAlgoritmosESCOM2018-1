int current_thread=0, encontrado = 0,size=0, threads=0,key;
int* Data;

void* SequentialSearch(void* args){
  int num = current_thread++;
  int seccion=num*(size / threads);
  // se divide el arreglo y se empieza la busqueda
  for (int i = seccion;i < ((num+1)*(size / threads)); i++){
      if (Data[i] == key)
          encontrado =1 ;
  }
}
