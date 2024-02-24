#include <gtk/gtk.h>

static void print_hello(GtkWidget* widget, gpointer data) {
    g_print("Hello World\n");
}

static void activate(GtkApplication* app, gpointer user_data) {
    // define pointers for widgets in the application
    GtkWidget* window;
    GtkWidget* button;
    GtkWidget* box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Create a box that will contain the button
    // The first parameter indicates whether the button is horizontal
    // or vertical
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // Set the horizontal alignment of the button
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    // Set the vertical alignment of the button
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    // add the box widget to the window widget
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Button pointer is initialized with a label
    button = gtk_button_new_with_label("Hello World");

    // Add Functionality to the button by running print_hello() when clicked
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);

    // Button is added to the box widget
    gtk_box_append(GTK_BOX(box), button);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv) {
    GtkApplication* app;
    int             status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
