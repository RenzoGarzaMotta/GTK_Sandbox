#include <gtk/gtk.h>

static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget *window;

  //Create a new window pointer
  window = gtk_application_window_new(app);
  //Define the title of the window.
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  //Define the size of the window to be displayed
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  //Dispaly the set up window
  gtk_window_present (GTK_WINDOW (window));
}


//In a GTK application, the purpose of the main() function is to 
//create a GtkApplication object and run it.
int main (int argc, char **argv){
  GtkApplication *app;  //Create a GTK app object
  int status;

  //Initialize the GTP app object
  //The parameters to gtk_application_new include:
  //    Application ID:
  //        In GTK (GIMP Toolkit), an application ID is a unique 
  //        identifier associated with your application. It helps 
  //        in distinguishing your application from others and is 
  //        particularly useful for certain desktop environments 
  //        and systems that use D-Bus for inter-process communication.
  //
  //        Rules for application IDs
  //            - the application ID must be composed of two or more elements 
  //              separated by a period (‘.’) character.
  //            - each element must contain one or more of the alphanumeric 
  //              characters (A-Z, a-z, 0-9) plus underscore (‘_’) and hyphen 
  //              (‘-’) and must not start with a digit.
  //            - the empty string is not a valid element (ie: your application 
  //              ID may not start or end with a period and it is not valid to 
  //              have two periods in a row).
  //            - the entire ID must be less than 255 characters in length.
  //    Application Flags:
  //        Flags are used to define the behaviour of a GApplication.
  app = gtk_application_new("RenzoGarzaMotta.gtkBasics", G_APPLICATION_DEFAULT_FLAGS);

  //Next the activate signal is connected to the activate() function 
  //above the main() function. The activate signal will be emitted 
  //when your application is launched with g_application_run() on the
  //line below.
  g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);

  //The g_application_run() call also takes as arguments the command 
  //line arguments (the argc count and the argv string array). Your 
  //application can override the command line handling, e.g. to open 
  //files passed on the commandline.

  //When you close the window, by (for example) pressing the X button,
  //the g_application_run() call returns with a number which is saved 
  //inside an integer variable named status. Afterwards, the 
  //GtkApplication object is freed from memory with g_object_unref(). 
  //Finally the status integer is returned and the application exits.
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref(app);

  //While the program is running, GTK is receiving events. These are 
  //typically input events caused by the user interacting with your 
  //program, but also things like messages from the window manager 
  //or other applications. GTK processes these and as a result, 
  //signals may be emitted on your widgets. Connecting handlers for 
  //these signals is how you normally make your program do something 
  //in response to user input.
  return status;
}
