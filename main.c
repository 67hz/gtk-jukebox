#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>


static void sum(int array[static 9]) {
  int i;
  for (i = 0; i < 10; ++i) { printf("i: %d", array[i]);
  }

}

/* char values as indices */
/* static int whitespace[256] = { */
/*   [' ' ] = 1, */
/*   ['\t'] = 1, */
/*   ['\f'] = 1, */
/*   ['\n'] = 1, */
/*   ['\r'] = 1 */
/* }; */

enum colors {
  RED,
  GREEN,
  BLUE,
  MAGENTA,
  YELLOW
};

int goods[5] = { [RED] = 1, [MAGENTA] = 1 };

/* _t is POSIX compliant */
typedef unsigned short int mytype_t;


int main(int argc, char* argv[]) 
{
  GtkWidget *win;
  gtk_init(&argc, &argv);
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Jazz time");
  g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(win);
  gtk_main();

  char str[30] = "this is only a test";
  char *ptr;
  long ret;


  ret = strtol(str, &ptr, 10);
  printf("%s", ptr);
 
  /* int nums[10] = {1,2,3,4,5,6,7,8,9}; */

  int a[9] = { [5] = 20, [1] = 15};
  sum(a);
  return 0; 
}
