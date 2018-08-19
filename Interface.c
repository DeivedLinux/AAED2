#include "Interface.h"		
#include "Depedent.h"
#include "Employee.h"
#include "Exception.h"									
#include <stdio.h>
#include <gtk/gtk.h>


GtkWidget* myWindow;
GtkWidget* windowBox;
GtkWidget* windowGrid;
GtkWidget* comboBoxText;
GtkWidget* searchEntry;
GtkWidget* frame;
GtkTextBuffer* textBufferEmployee;
GtkTextBuffer* textBufferDepedent;
GtkWidget* textViewEmployee;
GtkWidget* textViewDepedent;
GtkWidget* labelEmployeeNote;
GtkWidget* labelDepedentNote;
GtkWidget* notebook;
GtkWidget* boxNotebook;
GtkWidget* scrollTextViewEmployee;
GtkWidget* scrollTextViewDepedent;

private FILE* EmployeeFile;
private FILE* DepedentFile;

void searchEntryFunction(GtkSearchEntry *entry, gpointer user_data)
{
	puts("kjskejse");
}


void InterfaceInit(void)
{
	windowBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	boxNotebook = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	windowGrid = gtk_grid_new();
	gtk_grid_insert_row(GTK_GRID(windowGrid), 0);
	gtk_grid_insert_row(GTK_GRID(windowGrid), 1);
	gtk_grid_insert_row(GTK_GRID(windowGrid), 2);
	gtk_box_pack_start(GTK_BOX(windowBox), windowGrid, TRUE, FALSE, 0);	

	comboBoxText = gtk_combo_box_text_new();
	searchEntry = gtk_search_entry_new();
	frame = gtk_frame_new("Resultados");
	textBufferDepedent = gtk_text_buffer_new(NULL);
	textBufferEmployee = gtk_text_buffer_new(NULL);
	textViewDepedent = gtk_text_view_new();
	textViewEmployee = gtk_text_view_new();
	notebook = gtk_notebook_new();
	labelEmployeeNote = gtk_label_new("Empregados");
	labelDepedentNote = gtk_label_new("Depedentes");
	scrollTextViewEmployee = gtk_scrolled_window_new(NULL, NULL);
	scrollTextViewDepedent = gtk_scrolled_window_new(NULL, NULL);

	gtk_text_view_set_buffer(GTK_TEXT_VIEW(textViewEmployee), textBufferEmployee);
	gtk_text_view_set_buffer(GTK_TEXT_VIEW(textViewDepedent), textBufferDepedent);

	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"0", "Nome");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"1", "Empregado com idade maior que...");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"2", "Empregado com mais de 1 depedente");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"3", "Depedentes do Empregado");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"4", "Depedente");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboBoxText),"5", "Depedende com idade menor que...");
	gtk_container_add(GTK_CONTAINER(scrollTextViewEmployee),textViewEmployee);
	gtk_container_add(GTK_CONTAINER(scrollTextViewDepedent),textViewDepedent);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),scrollTextViewEmployee,labelEmployeeNote);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),scrollTextViewDepedent,labelDepedentNote);
	gtk_container_add(GTK_CONTAINER(frame),notebook);
	gtk_box_pack_start(GTK_BOX(boxNotebook), frame, TRUE, TRUE, 0);	
	gtk_grid_set_row_spacing(GTK_GRID(windowGrid),40);
	gtk_grid_attach(GTK_GRID(windowGrid), comboBoxText,0,0,1,1);
	gtk_grid_attach(GTK_GRID(windowGrid), searchEntry,0,1,1,1);
	gtk_grid_attach(GTK_GRID(windowGrid), boxNotebook,0,2,1,1);

  	gtk_container_add(GTK_CONTAINER(myWindow),windowBox);
  	gtk_box_set_baseline_position(GTK_BOX(windowBox),GTK_BASELINE_POSITION_CENTER);
	g_signal_connect(G_OBJECT(searchEntry), "previous-match",
    G_CALLBACK(searchEntryFunction),NULL);
}



void __attribute__((destructor))Exit(void)
{
	FileClose(EmployeeFile);
	FileClose(DepedentFile);
}