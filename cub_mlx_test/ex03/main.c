#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define KEY_ESC 53
#define X_EVENT_KEY_PRESS 2
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define IMG_WIDTH 400
#define IMG_HEIGHT 300


int key_press_esc(int keycode, void * msg)
{
  if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

typedef struct s_img
{
  void *img_ptr;
  int   *data;
  int   size_l;
  int   bpp;
  int   endian;
}             t_img;

typedef struct s_mlx 
{
   void   *mlx_ptr;
   void   *win;
}               t_mlx;

int main(void)
{
  t_mlx   *mlx;
  int     count_w;
  int     count_h;
  t_img   img;

  mlx->mlx_ptr = mlx_init();
  mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
  img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
  img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
  mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press_esc, NULL);
  count_h = -1;
  while (++count_h < IMG_HEIGHT)
  {
    count_w = -1;
    while (++count_w < IMG_WIDTH)
    {
      if (count_w % 3 == 1)
        img.data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
      else if (count_w % 3 == 2)
        img.data[count_h * IMG_WIDTH + count_w] = 0xFFFF00;
      else
        img.data[count_h * IMG_WIDTH + count_w] = 0xFF0000;
    }
  }
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
  mlx_loop(mlx->mlx_ptr);
  return (0);
}
