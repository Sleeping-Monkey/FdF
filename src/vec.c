#include "fdf.h"

t_vec			*v_get(int n)
{
	t_vec	*vec;

	if ((vec = NEW(t_vec)) == NULL)
		return (NULL);
	vec->n = n;
	if ((vec->e = NEW_S(t_real, n)) == NULL)
	{
		free(vec);
		return (NULL);
	}
	return (vec);
}
