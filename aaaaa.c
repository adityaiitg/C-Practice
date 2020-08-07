#include<stdio.h>
#include<math.h>
struct point{
    float x,y;
    };
typedef struct point point;
float distance(point a,point b){
return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    point p1,p2;
    scanf("%f %f",&p1.x,&p1.y);
    scanf("%f %f",&p2.x,&p2.y);
    printf("%f",distance(p1,p2));
    return 0;
}

