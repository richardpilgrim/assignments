#include <string.h>
#include "data.h"

int sortbyName(void* name1, void* name2){
/*char *a = ((Entry*)(name1))->title;
char *b = ((Entry*)(name2))->title;*/
//The above did not work and was not allocated the memory for a and b. I am a bit confused by this.

//compares the strings and returns which is larger.
int comp = strcmp((((Entry*)(name1))->title),(((Entry*)(name2))->title));
return comp;
}

int sortbyTime(void* time1, void* time2){
char *a = ((Entry*)(time1))->time;
char *b = ((Entry*)(time2))->time;

//Due to the numbers being taken as ints then they can be compared using strcmp()
int comp = strcmp(a,b);
return comp;
}
