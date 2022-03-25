#include<stdio.h>
#include<string.h>
int main()
{
    char buf[200];
    while (fgets(buf, sizeof(buf), stdin)!=NULL)
    {
        buf[strlen(buf) - 1] = 0;
        int a=0, b=0, c=0, d=0;
        int len = strlen(buf);
        for (int i = 0; i < len; ++i)
        {
            if (buf[i] >= 'A' && buf[i] <= 'Z')
                ++a;
            else if (buf[i] >= 'a' && buf[i] <= 'z')
                ++b;
            else if (buf[i] >= '0' && buf[i] <= '9')
                ++c;
            else
                ++d;
        }
        printf("%d %d %d %d\n", b, a, c, d);
    }
 
}
