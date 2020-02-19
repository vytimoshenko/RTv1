/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:02:14 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/04 22:30:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Основной метод теперь выглядит так:

O = <0, 0, 0>
for x in [-Cw/2, Cw/2] {
    for y in [-Ch/2, Ch/2] {
        D = CanvasToViewport(x, y)
        color = TraceRay(O, D, 1, inf)
        canvas.PutPixel(x, y, color)
    }
}

Функция CanvasToViewport очень проста:

CanvasToViewport(x, y) {
    return (x*Vw/Cw, y*Vh/Ch, d)
}

В этом фрагменте кода d — это расстояние до плоскости проекции.

Метод TraceRay вычисляет пересечение луча с каждой сферой, и возвращает цвет сферы в ближайшей точке пересечения, которая находится в требуемом интервале t:

TraceRay(O, D, t_min, t_max) {
    closest_t = inf
    closest_sphere = NULL
    for sphere in scene.Spheres {
        t1, t2 = IntersectRaySphere(O, D, sphere)
        if t1 in [t_min, t_max] and t1 < closest_t
            closest_t = t1
            closest_sphere = sphere
        if t2 in [t_min, t_max] and t2 < closest_t
            closest_t = t2
            closest_sphere = sphere
    }
    if closest_sphere == NULL
        return BACKGROUND_COLOR
    return closest_sphere.color
}

O в этом фрагменте кода — это исходная точка луча; хотя мы испускаем лучи из камеры, которая расположена в точке начала координат, на более поздних этапах она может быть расположена в другом месте, поэтому это значение должно быть параметром. То же относится к t_min и t_max.

Заметьте, что когда луч не пересекает сферу, то он всё равно должен возвращать какой-то цвет — в большинстве примеров я выбрал для этого белый.

И, наконец, IntersectRaySphere просто решает квадратное уравнение:

void    find_intersect_sphere()
{
    double k1;
    double k2;
    double k3;

    k3 = sphere.r * sphere.r;
}

IntersectRaySphere(O, D, sphere) {
    C = sphere.center
    r = sphere.radius
    oc = O - C

    k1 = dot(D, D)
    k2 = 2*dot(OC, D)
    k3 = dot(OC, OC) - r*r

    discriminant = k2*k2 - 4*k1*k3
    if discriminant < 0:
        return inf, inf

    t1 = (-k2 + sqrt(discriminant)) / (2*k1)
    t2 = (-k2 - sqrt(discriminant)) / (2*k1)
    return t1, t2
}