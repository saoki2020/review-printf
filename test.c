#include "ft_printf.h"

int main(void)
{
int i,j;
char *s;

s = "NULL";
i =	ft_printf("[%10.0w]\n",s);
j = printf("[%10.0w]\n",s);
printf("%d\n",i-3);
printf("%d\n",j-3);

s = "NULL";
i =	ft_printf("[%.-1s]\n",s);
j = printf("[%.-1s]\n",s);
printf("%d\n",i-3);
printf("%d\n",j-3);

}
