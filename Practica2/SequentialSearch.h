int current_thread=0, encontrado = 0,size=0, threads=0,key;
int* Data;

void* SequentialSearch(void* args){
  int SectionStart=current_thread*(size / threads);
  current_thread++;
  int SectionEnd=current_thread*(size / threads);
  // se divide el arreglo y se empieza la busqueda
  for (int i = SectionStart;i <SectionEnd; i++){
      if (Data[i] == key)
          encontrado = 1;
  }
}
