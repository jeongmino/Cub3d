#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS     2
#define X_EVENT_KEY_RELASE   3
#define X_EVENT_KEY_EXIT      17

#define KEY_ESC               53
#define KEY_Q                 12
#define KEY_W                 13
#define KEY_E                 14
#define KEY_R                 15
#define KEY_A                 0
#define KEY_S                 1
#define KEY_D                 2


typedef struct s_param{
  int   x;
  int
  char  str[3];
}               t_param;
