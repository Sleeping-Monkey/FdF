#include "fdf.h"
#include <assert.h>

static void put_m4(t_mat4 *m)
{
    int j;
    int i = -1;
    while (++i < 3)
    {
        j = -1;
        while (++j < 3)
        {
            printf("%.2f ", m->r[i][j]);
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
    t_mat4 m41 = (t_mat4){{{1, 2, 3, 0}, {5, 6, 7, 0}, {9, 10, 11, 0}, {12, 13, 14, 1}}};
    t_mat4 m42 = (t_mat4){{{1, 2, 3, 0}, {5, 6, 7, 0}, {9, 10, 11, 0}, {12, 13, 14, 1}}};
    t_mat4 m43 = {};

	m4_mul(&m41, &m42, &m43);
	put_m4(&m43);

    t_vec4 v = (t_vec4){{1, 1, 1}};
    t_vec4 v1 = {};
	m4v4_mul(&m41, &v, &v1);
	put_v4(&v1);

    printf("mag: %f\n", v4_mag(&(t_vec4) {{1, 1, 1}}));
	put_v4(v4_add(&(t_vec4) {{1, 1, 1}}, &(t_vec4) {{1, 1, 1}}, NULL));
	put_v4(v4_sub(&(t_vec4) {{1, 1, 1}}, &(t_vec4) {{1, 1, 1}}, NULL));
    printf("norm mag: %f\n", v4_mag(v4_norm(&(t_vec4) {{1, 1, 1}}, NULL)));
	put_v4(v4_cross(&(t_vec4) {{1, 0, 0}}, &(t_vec4) {{0, 1, 0}}, NULL));
	put_v4(v4s_mull(&(t_vec4) {{1, 2, 3}}, 2, NULL));

    return (0);
}
