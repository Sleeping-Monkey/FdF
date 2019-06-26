#include "fdf.h"
#include <assert.h>

static void put_m4(t_mat4 *m)
{
	int j;
	int i = -1;
	if (!m)
	{
		printf("(null)\n");
		return;
	}
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			printf(" <i:%d>:%f", (i == j), m->r[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static void put_v4(t_vec4 *v)
{
	int i = -1;
	while (++i < 3)
	{
		printf("%.2f ", v->v[i]);
	}
	printf("\n");
}

int main()
{
	t_mat4 out;
	t_mat4 mat = (t_mat4){{
		  { 0.95 , -0.12 , -0.27 , 0.0 , },
		  { -0.24 , 0.26 , -0.94 , 0.0 , },
		  { 0.18 , 0.96 , 0.22 , 0.0 , },
		  { 0.0 , 1.0 , 1.0 , 1.0 , }
	}};
	t_mat4 inv;
	put_m4(m4_inv(&mat, &inv));
	put_m4(m4_mul(&inv, &mat, &out));
	assert(m4_is_identity(&out));
	return (0);
}
