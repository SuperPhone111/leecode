#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isValid(char * s){

    char *q = s;
    char *p;
    char *a;

    for(p=s;*p;p++)
    {
        printf("[%d]*p=%c,p:%p\n",__LINE__ ,*p,p);
        printf("[%d]*q=%c,q:%p\n",__LINE__ ,*q,q);
        switch(*p)
        {
            case '(': *q++ = ')'; a=q;printf("*q++=%c,q:%p\n",*--a,q);continue;
            case '{': *q++ = '}'; a=q;printf("*q++=%c,q:%p\n",*--a,q);continue;
            case '[': *q++ = ']'; a=q;printf("*q++=%c,q:%p\n",*--a,q);continue;
            default:
                      printf("[%d]*p=%c,p:%p\n",__LINE__ ,*p,p);
                      printf("[%d]*q=%c,q:%p\n",__LINE__ ,*q,q);
                  if (q==s || *p != *--q)
                  { 
                      printf("[%d]*p=%c,p:%p\n",__LINE__ ,*p,p);
                      printf("[%d]*q=%c,q:%p\n",__LINE__ ,*q,q);
                      return false;
                  }
        }
    }
    return q==s;
}

int main()
{
    char str[10]={"()[]"};
    char str1[10]={"()[}"};
    bool ret = 0;
    
    ret = isValid(str);
    printf("ret:%d\n",ret);
    ret = isValid(str1);
    printf("ret:%d\n",ret);

    return 0;
}    
