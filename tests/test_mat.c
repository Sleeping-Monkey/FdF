#include "fdf.h"
#include "assert.h"
#include <stdio.h>

static	void put_m(t_mat *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->m)
	{
		j =0;
		while (j < m->n)
		{
			printf("%f ", m->r[i][j++]);
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

static	void put_v(t_vec *v)
{
	int i;

	i = 0;
	while (i < v->n)
	{
		printf("%f ", v->e[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	t_mat	*m1;
	t_mat	*m2;
	t_mat	*m3;
	t_vec	*v;

	m1 = m_get(3, 3);
	m_identity(m1);
	assert(m1->r[0][0] == 1);
	assert(m1->r[1][1] == 1);
	assert(m1->r[2][2] == 1);
	m2 = m_get(3, 1);
	m_identity(m2);
	M3_SET(m1,
			111, 2, 3,
			4, 500, 6,
			7, 8, 999
	);
	V3_SET(m2, 10, 11, 12);
	m3 = m_mul(m1, m2, NULL);
	put_m(m1);
	put_m(m2);
	put_m(m3);
	assert(m3->n == 1);
	assert(m3->m == 3);
	v = v_get(3);
	V3_SET(v, 2, 2, 2);
	v = mv_mul(m1,v, NULL);
	put_v(v);
	t_mat	*m4;
	m4 = m_get(4, 4);
	M4_SET(m4,
			1, 33, 33, 4,
			0, 1, 0, 4,
			55, 55, 1, 4,
			0, 0, 0, 1
			);
	t_vec	*v4;
	put_m(m4);
	v4 = v_get(4);
	V4_SET(v4, 1, 1, 1, 1);
	put_v(v4);
	v4 = mv_mul(m4, v4, NULL);
	put_v(v4);
    return (0);
}
