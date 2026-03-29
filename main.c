#include <math.h>
#include <stdio.h>
#include	"mlx.h"
#include <stdlib.h>
#include "vector.h"

int	handle_keypress(int keysym, void *data)
{
	// 65307 is the code for the ESC key
	if (keysym == 65307)
	{
		exit(0);
	}
	return (0);
}

int    main(void)
{
    void    *mlx;
    void    *win1;
    t_object canvas;

    mlx = mlx_init();
    if (mlx == NULL)
    {
        return 1;
    }

    
    win1 = mlx_new_window(mlx, 1600, 900, "sikis ustadi");
    if (win1 == NULL)
    {
        mlx_destroy_display(mlx);
        return 1;
    }

    canvas.img = mlx_new_image(mlx, 1600, 900);
    canvas.addr = mlx_get_data_addr(canvas.img, &canvas.bits_per_pixel, &canvas.size_line, &canvas.endian);
    int x;
    int y;
    t_ray ray;
    double r_val, g_val, b_val;
    int color = ((int)(r_val * 255) << 16) | ((int)(g_val * 255) << 8) | (int)(b_val * 255);

    y = 0;
    while (y < 900)
    {
        x = 0;
        while (x < 1600)
        {
            double u = ((2*(x / 1600.0)) - 1) * (16.0 / 9.0); // Map x to [-aspect_ratio, aspect_ratio]
            double v = (1 - (2*(y / 900.0))) * 1.0; // Map y to [-1, 1]

            ray.p0 = (t_vec3){0, 0, 0}; // Camera position
            ray.dir = (t_vec3){u, v, -1}; // Ray direction

            if (u * u + v * v < 0.25) // Equation of a disk: x^2 + y^2 < r^2
            {
                color = 0x00FF0000;   // Red
            }
            else if (v == 0) // Equation of a line: y = 0
            {
                color = 0x0000FF00;   // Green
            }
            else if (u == 0) // Equation of a line: x = 0
            {
                color = 0x000000FF;   // Blue
            }
            else
            {
                color = 0x00000000;   // Black
            }

            char *dst = canvas.addr + (y * canvas.size_line + x * (canvas.bits_per_pixel / 8));
            *(unsigned int*)dst = color; 
            x++;
        }
        y++;
    }

    // CRITICAL: This is the command that actually sends your drawing to the window
    mlx_put_image_to_window(mlx, win1, canvas.img, 0, 0);

    mlx_key_hook(win1, handle_keypress, NULL);
    mlx_loop(mlx);

    return 0;
}