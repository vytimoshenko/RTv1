
#include <gtk/gtk.h>
#include <stdio.h>

// gcc gtk.c -o helloworld `pkg-config gtk+-3.0 --cflags pkg-config gtk+-3.0 --libs`

int main(int argc, char **argv) {
         GtkWidget *window;
         gtk_init(&argc, &argv);

         window =  gtk_window_new(GTK_WINDOW_TOPLEVEL);
         gtk_window_set_title(GTK_WINDOW(window), "Hello World");
         gtk_widget_show(window);

         gtk_main();
         return 0;
}