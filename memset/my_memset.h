#include<stdio.h>
#include<assert.h>
void *my_memset(void *dst, int val , size_t count)
{
        assert(dst );
        void *ret = dst ;
        while (count --)
       {
              *( char*)dst = (char) val;
               dst = (char *)dst + 1;
       }
        return ret;
}
