#include <math.h>
int current_thread=0, encontrado = 0,size=0, threads=0,key;
int* Data;

int BinarySearch(int* data, int key,int left, int right){
  if (right<left) {
    return 0;
  } else {
    int mid=(right+left)/2;
    if(data[mid]==key){
      return 1;
    }else if(data[mid]>key) {
      return BinarySearch(data,key,left,mid-1);
    }else{
      return BinarySearch(data,key,mid+1,right);
    }
  }

}
void* BinarySearchDriver(void* args){
  int SectionStart=current_thread*(size / threads);
  current_thread++;
  int SectionEnd=current_thread*(size / threads);
  if (encontrado==0) {
    encontrado = BinarySearch(Data,key,SectionStart,SectionEnd);
  }
}
