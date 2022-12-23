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
  void *mlx;
  void *img;
  int img_w;
  int img_h;
}               t_param;

int main(void)
{
  t_param param_arr[100];
  void *win;
  int x = 0;
  int y = 0;

  param_arr[0].mlx = mlx_init();
  win = mlx_new_window(param_arr[0].mlx, 640, 640, "covering");
  for(int i = 0; i < 100; i++)
  {
    param_arr[i].mlx = mlx_init();
    param_arr[i].img = mlx_xpm_file_to_image(param_arr[i].mlx, "../textures/wall_e.xpm", \
        &param_arr[i].img_w, &param_arr[i].img_h);
    x = i / 10;
    y = i % 10;
    mlx_put_image_to_window(param_arr[i].mlx, win, param_arr[i].img, 64 * x, 64 * y);
    printf("img_w = %d, img_h = %d, x = %d, y = %d\n", param_arr[i].img_w, param_arr[i].img_h, x, y);
  }
  mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press_esc, NULL);
  for(int i = 0; i < 100; i++)
    mlx_loop(param_arr[i].mlx);
  return (0);
}
