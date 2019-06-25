#include "fdf.h"
#include <assert.h>

static void put_m3(t_mat3 *m)
{
    int j;
    int i = -1;
    while (++i < 3)
    {
        j = -1;
        while (++j < 3)
        {
            printf("%f ", m->r[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void put_v3(t_vec3 *v)
{
    int i = -1;
    while (++i < 3)
    {
        printf("%f ", v->v[i]);
    }
    printf("\n");
}

int main()
{
    t_mat3 m41 = (t_mat3){{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}}};
    t_mat3 m42 = (t_mat3){{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}}};
    t_mat3 m43;

    m3_mul(&m41, &m42, &m43);
    put_m3(&m43);

    t_vec3 v = (t_vec3){{1, 1, 1}};
    t_vec3 v1;
    m3v3_mul(&m41, &v, &v1);
    put_v3(&v1);

    printf("mag: %f\n", v3_mag(&(t_vec3){{1, 1, 1}}));
    put_v3(v3_add(&(t_vec3){{1, 1, 1}}, &(t_vec3){{1, 1, 1}}, NULL));
    put_v3(v3_sub(&(t_vec3){{1, 1, 1}}, &(t_vec3){{1, 1, 1}}, NULL));
    printf("norm mag: %f\n", v3_mag(v3_norm(&(t_vec3){{1, 1, 1}}, NULL)));
    put_v3(v3_cross(&(t_vec3){{1, 0, 0}}, &(t_vec3){{0, 1, 0}}, NULL));
    put_v3(v3s_mull(&(t_vec3){{1, 2, 3}}, 2, NULL));

    return (0);
}
