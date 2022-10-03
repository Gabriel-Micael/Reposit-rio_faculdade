void bubble_sort(int *v){
    int aux;
    for(int *p = v + 9; p > v;  p--){
        for( int *q = v; q < p; q++){
            if(*q > *(q + 1)){
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux; 
            }
        }
    }
}

void insertion_sort(int *v){
 int *p, *q, aux;
  
 for(p = v + 1; p < v + 10; p++)
 {
  aux = *p;
  for(q = p-1; q >= v && aux < *q; q--)
  {
   *(q+1) = *q;
  }
  *(q+1) = aux;
 }
}

void selection_sort (int *v) {
  int *p, *q, *min, aux;
  for (p = v; p < v + 9; p++) {
    min = p;
    for (q = p + 1; q < v + 10; q++) {
      if (*q < *min) {
        min = q;
      }
    }
    if (p != min) {
      aux = *p;
      *p = *min;
      *min = aux;
    }
  }
}