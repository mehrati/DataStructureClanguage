#include <stdio.h>
#include <string.h>

struct spec{
int id;
char name[10];

};
int b=77;
void func(struct spec *p);
int main(){

struct spec ss;


func(&ss);





printf("func func %d\n",ss.id);
printf("main func %s\n",ss.name);
 
return 0;
}

void func(struct spec *p){

p->id=32;
strcpy(p->name,"mahdi");





}
