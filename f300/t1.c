


int identical(int a[],int b[],unsigned int len){
  int i;//,check=1;
  for(i=0;i<(int)len;i++){
    if(a[i]!=b[i]){
      return 0;
    }
  }
  return 1;
}
