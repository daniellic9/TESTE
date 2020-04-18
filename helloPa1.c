#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}
int main(){
double inicio = MyClock();
  #pragma omp parallel
  {
    int ID =omp_get_thread_num() ;
    printf("hello(%d) ", ID);
    printf("world(%d) ", ID);
  }
  double tempoPar = (MyClock()-inicio)/CLOCKS_PER_SEC;
  printf("Tempo: %.5lf", tempoPar);
  return 0;
}
