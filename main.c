#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"
#include <gtk/gtk.h>




int main(int argc, char** argv)
{
	int status;


	gtk_init(&argc, &argv);

	myWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_position(GTK_WINDOW(myWindow), GTK_WIN_POS_CENTER);
  	gtk_window_set_default_size(GTK_WINDOW(myWindow), 480, 272);
  	gtk_window_set_title(GTK_WINDOW(myWindow), "Atividade Academica - ED2");

  	g_signal_connect(G_OBJECT(myWindow), "destroy",
  	G_CALLBACK(gtk_main_quit), NULL);

  	gtk_widget_show_all(myWindow);
  	gtk_main();


	return status;
}