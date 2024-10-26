/* ---- Searching for the End of a String ---- */

size_t strlen(const char *s)
{
    size_t n;
    
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

// condense form (idiom)

while (*s)
    s++;

//or 

while (*s++)
    ;


/* ---- Copying a String ---- */

char *strcat (char *s1, const char *s2)
{
    char *p = s1;

    while (*p != '\0')
        p++;
    while (*s2 != '\0'){
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;

}

// idiom

while(*p++ = *s2++)
    ;