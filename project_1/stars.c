#include <stdio.h>
#include <gtk/gtk.h> 
#include <stdlib.h> 

#include "star.h"

#define NUMBER_OF_STARS 10
  
//static void print_hello() {
//    printf("Hello World\n");
//    return;
//}

int width = 400;
int height = 400;
struct Star *stars;

void create_random_star(int width, int height, Star *star) {
    star->x = rand() % (width + 1); 
    star->y = rand() % (height + 1);
    star->z = rand() % (width + 1); 
}

void activate(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Project 1");
    gtk_window_set_default_size (GTK_WINDOW (window), width, height);

    stars = (struct Star*)malloc(NUMBER_OF_STARS * sizeof(struct Star));
    if (stars == NULL) exit(ERROR);

    for (int i = 0; i < NUMBER_OF_STARS; i++)
    {
        create_random_star(width, height, &stars[i]);
    }

/*
    GtkWidget *grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    g_signal_connect(button1, "clicked", G_CALLBACK(print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);
    // gtk_grid_attach(GtkGrid*, GtkWidget*, left, top, width, height);

    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    g_signal_connect(button2, "clicked", G_CALLBACK(print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);

    GtkWidget *button3 = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button3, "clicked", G_CALLBACK(gtk_window_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), button3, 0, 1, 2, 1);

    GtkWidget *label = gtk_label_new("\nHello World\n");
    gtk_label_set_selectable(GTK_LABEL(label), TRUE);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 2, 1);
*/

    gtk_widget_set_visible(window, true);
}

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    free(stars);
    return status;
}