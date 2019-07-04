#include "fdf.h"
#include <assert.h>

static void put_m4(t_mat4 *m)
{
    int j;
    int i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            printf("%.2f ", m->r[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

static void put_v3(t_vec3 *v)
{
    int i = -1;
    while (++i < 3)
    {
        printf("%.2f ", v->v[i]);
    }
    printf("\n\n");
}

int main()
{
    t_mat4 m41 = (t_mat4){{{1, 2, 3, 0}, {5, 6, 7, 0}, {9, 10, 11, 0}, {12, 13, 14, 1}}};
    t_mat4 m42 = (t_mat4){{{1, 2, 3, 0}, {5, 6, 7, 0}, {9, 10, 11, 0}, {12, 13, 14, 1}}};
    t_mat4 m43 = {};

	m4_mul(&m41, &m42, &m43);
	put_m4(&m43);

    t_vec3 v = (t_vec3){{1, 1, 1}};
    t_vec3 v1 = {};
	m4v3_mul(&m41, &v, &v1);
	put_v3(&v1);

    printf("mag: %f\n", v3_mag(&(t_vec3) {{1, 1, 1}}));
	put_v3(v3_add(&(t_vec3) {{1, 1, 1}}, &(t_vec3) {{1, 1, 1}}, NULL));
	put_v3(v3_sub(&(t_vec3) {{1, 1, 1}}, &(t_vec3) {{1, 1, 1}}, NULL));
    printf("norm mag: %f\n", v3_mag(v3_norm(&(t_vec3) {{1, 1, 1}}, NULL)));
	put_v3(v3_cross(&(t_vec3) {{1, 0, 0}}, &(t_vec3) {{0, 1, 0}}, NULL));
	put_v3(v3s_mull(&(t_vec3) {{1, 2, 3}}, 2, NULL));

	t_mat4 mRot;
	m4_setRotation(&mRot, &VEC(0, 45, 45));
	//mRot = *m4_rotate(&mRot, &VEC(0, 45, 45), NULL);
	put_m4(&mRot);
	m4_identity(&mRot);
	m4_rotate(&mRot, &VEC(0, 45, 45));
	put_m4(&mRot);
    return (0);
}
