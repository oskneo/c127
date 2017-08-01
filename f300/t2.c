#include <stdlib.h>

typedef struct point{
  int x,y,z;
  int color;
} point_t;

typedef struct {
  size_t len;
  point_t* points;
} point_array_t;


point_array_t* point_array_create(size_t len){
  point_array_t *pt=malloc(sizeof(point_array_t));
  if(!pt){
    return NULL;
  }
  pt->points=malloc(sizeof(point_t)*len);
  if(pt->points==NULL&&len>0){
    return NULL;
  }
  pt->len=len;
  int i;
  for(i=0;i<len;i++){
    pt->points[i].x=0;
    pt->points[i].y=0;
    pt->points[i].z=0;
    pt->points[i].color=0;
  }
  return pt;
}
