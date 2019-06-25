#include "fdf.h"

t_mat3           *m3_mul(   t_mat3 *a, t_mat3 *b, t_mat3 *out)
{
    int r;
    int c;
    int i;

    if (!a || !b)
        return (NULL);
    if ((!out && !(out = NEW(t_mat3))) || a == out || b == out)
        return (NULL);
    r = 3;
    while (r--)
    {
        c = 3;
        while (c--)
        {
            i = 3;
            while (i--)
            {
                if (a->r[r][i])
                    out->r[r][c] += a->r[r][i] * b->r[i][c];
            }
        }
    }
    return (out);
}

t_vec3          *m3v3_mul(t_mat3 *a, t_vec3 *b, t_vec3 *out)
{
    int r;
    int c;

    if (!a || !b)
        return (NULL);
    if ((!out && !(out = NEW(t_vec3))) || b == out)
        return (NULL);
    r = 3;
    while (r--)
    {
        c = 3;
        while (c--)
        {
            if (a->r[r][c])
                out->v[r] += a->r[r][c] * b->v[r];
        }
    }
    return (out);
}
