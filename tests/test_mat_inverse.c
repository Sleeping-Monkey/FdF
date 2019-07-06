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
			printf(" %f",  m->r[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static void put_v3(t_vec3 *v)
{
	int i = -1;
	t_real *vv;
	vv = (t_real *)v;

	while (++i < 3)
	{
		printf("%f ", vv[i]);
	}
	printf("\n");
}

int main()
{
	t_mat4 out = {};
	t_mat4 mat = (t_mat4){{
		  { 0.95 , -0.12 , -0.27 , 0.0},
		  { -0.24 , 0.26 , -0.94 , 0.0},
		  { 0.18 , 0.96 , 0.22 , 0.0},
		  { 0.0 , 1.0 , 1.0 , 1.0}
	}};
	t_mat4 inv = {};

	printf("orig\n");
	put_m4(&mat);
	// Inverse matrix
	printf("inv\n");
	put_m4(m4_inv(&mat, &inv));
	// Check inverse works
	assert(m4_is_identity(m4_mul(&inv, &mat, &out)));
	printf("orig vector: ");
	t_vec3 v = {2.407, -0.7918, -1.8178};
	put_v3(&v);
	printf("inverse(matrix) * vector = ");
	put_v3(m4v3_mul(&inv, &v, NULL));
	return (0);
}
