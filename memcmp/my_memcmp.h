int my_memcmp(const void * str1, const void * str2, size_t count )
{
        assert(str1 );
        assert(str2 );
        if (!count )
       {
               return 0;
       }
        while (--count &&*(char*) str1 == *(char *)str2)
       {
               str1 = (char *)str1 + 1;
               str2 = (char *)str2 + 1;
       }
        return ((unsigned char*) str1 - (unsigned char*)str2 );
}
