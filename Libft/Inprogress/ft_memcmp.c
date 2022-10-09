 #include <string.h>
 
 int ft_memcmp(const void *s1, const void *s2, size_t n)
 {
	size_t              i;
	unsigned const char *buffer1;
	unsigned const char *buffer2;

    i = 0;
    if (n == 0)
        return (0);
    while (i < n)
    {
        if (buffer1[i] != buffer2[i])
            return (buffer1[i] - buffer2[i]);
        i++;
    }
    return (0);
 }