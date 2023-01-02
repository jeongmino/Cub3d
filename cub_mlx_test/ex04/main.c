#include <stdio.h>
#include "../mlx/mlx.h"
#include <stdlib.h>

#define KEY_ESC 53
#define X_EVENT_KEY_PRESS 2
 
typedef struct s_img
{
  void  *ptr;
  int   *data;
  int   width;
  int   height;
  int   size_l;
  int   bpp;
  int   endian;
}         t_img;

int key_press_esc(int keycode, void *msg)
{
  if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

int main(void)
{
  void *mlx;
  void *win;
  t_img img;
  int count_h;
  int count_w;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 500, 500, "my_mlx");
  img.ptr = mlx_xpm_file_to_image(mlx, "../textures/wall_s.xpm", &img.width, &img.height);
  img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

  count_h = -1;
  while (++count_h < img.height / 2)
  {
    count_w = -1;
    while (++count_w < img.width / 2)
    {
      if (count_w % 2)
        img.data[count_h * img.width + count_w] = 0xFFFFFF;
      else
        img.data[count_h * img.width + count_w] = 0xFF0000;
    }
  }
  mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
  mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press_esc, NULL);
  mlx_loop(mlx);
  return (0);
}
