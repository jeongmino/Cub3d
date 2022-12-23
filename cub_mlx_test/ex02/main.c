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

int main(void)
{
  void *mlx;
  void *mlx_2;
  void *win;
  void *img;
  void *img_2;

  int img_width;
  int img_height;
  int img_width_2;
  int img_height_2;

  mlx = mlx_init();
  mlx_2 = mlx_init();
  mlx = mlx_init();
  win = mlx_new_window(mlx, 500, 500, "my_mlx");
  img = mlx_xpm_file_to_image(mlx, "../textures/wall_w.xpm", &img_width, &img_height);
  img_2 = mlx_xpm_file_to_image(mlx_2, "../textures/wall_n.xpm", &img_width_2, &img_height_2);
  mlx_put_image_to_window(mlx, win, img, 300, 300);
  mlx_put_image_to_window(mlx_2, win, img_2, 0, 0);
  printf("img_width_2 : %d, img_height_2 : %d\n", img_width_2, img_height_2);
  mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press_esc, NULL);
  mlx_loop(mlx);
  return (0);
}
