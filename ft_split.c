/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cserain <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 07:02:42 by cserain      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 16:15:30 by cserain     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_assign(char const *s, char c, int x, char *dest)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j != x)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			dest[k] = s[i];
			i++;
			k++;
		}
		j++;
	}
	dest[k] = '\0';
	return (dest);
}

int		ft_cmpt_caract(char const *s, char c, int x)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j != x)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			k++;
			i++;
		}
		j++;
	}
	return (k);
}

int		ft_cmpt_case(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				j++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_case;
	int		nb_caract;
	char	**result;

	i = 0;
	nb_case = ft_cmpt_case(s, c);
	if ((result = malloc(sizeof(char*) * (nb_case + 1))) == NULL)
		return (0);
	while (i < nb_case)
	{
		nb_caract = ft_cmpt_caract(s, c, i + 1);
		if ((result[i] = malloc(sizeof(char) * (nb_caract + 1))) == NULL)
			return (0);
		result[i] = ft_assign(s, c, i + 1, result[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
/*
int main()
{
	int i;
	i = 0;
	while (i < 26)
	{
		printf("%s\n",ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')[i]);
t remote add origin https://github.com/cserain/cserain.git
git push -u origin masteri++;
	}
} */
