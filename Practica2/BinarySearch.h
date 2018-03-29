#include <math.h>
int current_thread=0, encontrado = 0,size=0, threads=0,key;
int* Data;

int BinarySearch(int* data, int key,int left, int right){
  if (left==right) {
    if (left==key) {
      return 1;
    } else {
      return 0;
    }
  } else {
    int mid=left+(right-left)/2;
    if(data[mid]==key){
      return 1;
    }else if(data[mid]>key) {
      return BinarySearch(data,key,left,mid-1);
    }else{
      return BinarySearch(data,key,mid+1,right);
    }
  }

}
void* SequentialSearch(void* args){
  int num = current_thread++;
  int SectionStart=num*(size / threads);
  int SectionEnd=((num+1)*(size / threads));
  encontrado = BinarySearch(Data,key,SectionStart,SectionEnd);
}
