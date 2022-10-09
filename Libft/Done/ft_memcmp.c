<<<<<<< HEAD
 #include <string.h>
 
 int ft_memcmp(const void *s1, const void *s2, size_t n)
 {
    unsigned const char		*b1;
	unsigned const char		*b2;

	b1 = (unsigned const char *)s1;
	b2 = (unsigned const char *)s2;
    if (b1 == NULL || b2 == NULL)
        return (0);
    while (n > 0)
    {
        if (*b1 != *b2)
            return (*b1 - *b2);
        b1++;
        b2++;
        n--;
    }
    return (0);
=======
 #include <string.h>
 
 int ft_memcmp(const void *s1, const void *s2, size_t n)
 {
    unsigned const char		*b1;
	unsigned const char		*b2;

	b1 = (unsigned const char *)s1;
	b2 = (unsigned const char *)s2;
    if (b1 == NULL || b2 == NULL)
        return (0);
    while (n > 0)
    {
        if (*b1 != *b2)
            return (*b1 - *b2);
        b1++;
        b2++;
        n--;
    }
    return (0);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
 }