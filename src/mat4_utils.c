#include "fdf.h"

t_mat4			*m4_identity(t_mat4 *m)
{
	int	i;
	int	j;

	if ((!m && !(m = NEW(t_mat4))))
		return (NULL);
	i = 4;
	while (i--)
	{
		j = 4;
		while (j--)
			m->r[i][j] = i == j;
	}
	return (m);
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

t_mat4			*m4_copy(t_mat4 *m, t_mat4 *out)
{
	if (!m)
		return (NULL);
	if ((!out && !(out = NEW(t_mat4))))
		return (NULL);
	ft_memmove(out, m, sizeof(t_mat4));
	return (out);
}
