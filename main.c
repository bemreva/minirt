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

    y = 0;
    while (y < 900)
    {
        x = 0;
        while (x < 1600)
        {
            // Calculate the memory offset for this specific pixel
            char *dst = canvas.addr + (y * canvas.size_line + x * (canvas.bits_per_pixel / 8));
            
            // Set the color (0x00RRGGBB) -> 0x000000FF is Blue
            *(unsigned int*)dst = 0x000000FF; 
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