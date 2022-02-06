#include <stdlib.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main( void )
{
	char	s1[20];
	char	s2[] = "Hello world";
	ft_strlcpy(s1, s2, 12);
	return 0;
}
/*
	printf("%s\n", strnstr("0123456789", "567", 10));
	printf("%s", ft_strnstr("0123456789", "567", 10));
;}
*/
/*
{
	const char s2[9] = "012345678";
	char *s3;
	s3 = ft_strdup("I malloc so I am.");
	printf("%s\n", s3);
	free (s3);
}*/

/*
{
	char src[] = "coucou";
	char dest[10];
	int	i;

	i = ft_strlcpy(dest, src, 1);
	printf("%d\n", i);
	printf("%s", dest);	
}*/

/*int main ( void )
{
	char	*str1 = "";
	char 	*res;
	res = ft_strtrim(str1, "");
	if (res == NULL)
		printf("ERROR");
	else
		printf("%s\n", res);
	free (res);
}*/

/*int main(void)
{
	t_list	*list;
	t_list	*secondL;
	t_list	*p;
	t_list	k;
	char	*j = "take";


	k.content =  j;
	k.next = NULL;
	printf("%s\n", k.content);
	list = ft_lstnew("toto\n");
	list->next = ft_lstnew("tata\n");
	list->next->next = ft_lstnew("kuku\n");
	p = list;
	/*while (p->next != NULL)
	{
		printf("%s", p->content);
		p = p->next;
	}*/
}
