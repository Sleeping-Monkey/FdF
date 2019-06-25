#include "fdf.h"

t_mat			*m_get(int m, int n)
{
	t_mat	*mat;
	int 	i;

	if ((mat = NEW(t_mat)) == NULL)
		return (NULL);
	mat->m = m;
	mat->n = n;
	if ((mat->e = NEW_S(t_real, m * n)) == NULL)
	{
		free(mat);
		return (NULL);
	}
	if ((mat->r = NEW_S(t_real*, m)) == NULL)
	{
		free(mat->e);
		free(mat);
		return (NULL);
	}
	i = 0;
	while (i < m)
	{
		mat->r[i] = &(mat->e[i * n]);
		i++;
	}
	return (mat);
}

#include <stdio.h>
t_mat			*m_mul(t_mat *a, t_mat *b, t_mat *out)
{
	int r;
	int c;
	int i;

	if (!a || !b || a->n != b->m)
		return (NULL);
	if ((!out && !(out = m_get(a->m, b->n)))
		|| out->m != a->m || out->n != b->n || a == out || b == out)
		return (NULL);
	r = a->m;
	while (r--)
	{
		c = b->n;
		while (c--)
		{
			i = a->n;
			while (i--)
			{
				if (a->r[r][i])
					out->r[r][c] += a->r[r][i] * b->r[i][c];
			}
		}
	}
	return (out);
}

t_vec			*mv_mul(t_mat *m, t_vec *v, t_vec *out)
{
	int r;
	int c;

	if (!m || !v || m->n != v->n)
		return (NULL);
	if ((!out && !(out = v_get(m->m)))
		|| out->n != m->m || v == out)
		return (NULL);
	r = m->m;
	while (r--)
	{
		c = m->n;
		while (c--)
		{
			if (m->r[r][c])
				out->e[r] += m->r[r][c] * v->e[r];
		}
	}
	return (out);
}

void			m_identity(t_mat *m)
{
	int	i;
	int	j;

	i = m->m;
	while (i--)
	{
		j = m->n;
		while (j--)
			m->r[i][j] = i == j;
	}
}

void			m_free(t_mat **m)
{
	ft_memdel((void**)&(*m)->e);
	ft_memdel((void**)m);
}