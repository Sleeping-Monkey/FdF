#include "fdf.h"

void          	m4_identity(t_mat4 *m)
{
	int	i;
	int	j;

	i = 4;
	while (i--)
	{
		j = 4;
		while (j--)
			m->r[i][j] = i == j;
	}
}

int          	m4_is_identity(t_mat4 *m)
{
	int	i;
	int	j;

	i = 4;
	while (i--)
	{
		j = 4;
		while (j--)
		{
			if (R_ABS(m->r[i][j] - (t_real)(i == j)) > EPSILON)
				return (0);
		}
	}
	return (1);
}
