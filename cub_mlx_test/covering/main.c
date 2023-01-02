#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define KEY_ESC 53
#define X_EVENT_KEY_PRESS 2

int key_press_esc(int keycode, void* msg)
{
  if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

typedef struct s_param {
  void *img;
  int img_w;
  int img_h;
}               t_param;

int main(void)
{
  t_param param_arr[100];
  void *mlx;
  void *win;
  int x = 0;
  int y = 0;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 640, 640, "covering");
  for(int i = 0; i < 100; i++)
  {
    param_arr[i].img = mlx_xpm_file_to_image(mlx, "../textures/wall_e.xpm", \
        &param_arr[i].img_w, &param_arr[i].img_h);
    x = i / 10;
    y = i % 10;
    mlx_put_image_to_window(mlx, win, param_arr[i].img, 64 * x, 64 * y);
    printf("img_w = %d, img_h = %d, x = %d, y = %d\n", param_arr[i].img_w, param_arr[i].img_h, x, y);
  }
  mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press_esc, NULL);
  mlx_loop(mlx);
  return (0);
}
