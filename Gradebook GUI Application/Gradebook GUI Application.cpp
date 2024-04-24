#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#define Max 100

// Global Variables//
int Password;
char* username;
static GtkWidget* PASSWORD;
static GtkWidget* USERNAME;

// structure declaration//
struct Database
{
    char name[50];
    int password;
    float grades[6][3];
};

void take_inputs(GtkWidget* Take_inputs, gpointer data)
{

    username = (char*)gtk_entry_get_text(GTK_ENTRY(USERNAME));
    Password = atoi((char*)gtk_entry_get_text(GTK_ENTRY(PASSWORD)));
}

// recursion//
float TOTAL_MARK_calculator(struct Database* database, int m, int iter, int location)
{
    if (iter == 0)
        return database[location].grades[m][iter];
    else
        return database[location].grades[m][iter] + TOTAL_MARK_calculator(database, m, iter - 1, location);
}

int main(int argc, char** argv)
{

    GtkWidget* TOTAL;
    GtkWidget* TOTAL1;
    GtkWidget* TOTAL2;
    GtkWidget* TOTAL3;
    GtkWidget* TOTAL4;
    GtkWidget* TOTAL5;
    GtkWidget* TOTAL6;
    GtkWidget* label1;
    GtkWidget* label2;
    GtkWidget* subject1;
    GtkWidget* subject2;
    GtkWidget* subject3;
    GtkWidget* subject4;
    GtkWidget* subject5;
    GtkWidget* subject6;
    GtkWidget* _7th;
    GtkWidget* _12th;
    GtkWidget* final;
    GtkWidget* grade1;
    GtkWidget* grade2;
    GtkWidget* grade3;
    GtkWidget* grade4;
    GtkWidget* grade5;
    GtkWidget* grade6;
    GtkWidget* grade7;
    GtkWidget* grade8;
    GtkWidget* grade9;
    GtkWidget* grade10;
    GtkWidget* grade11;
    GtkWidget* grade12;
    GtkWidget* grade13;
    GtkWidget* grade14;
    GtkWidget* grade15;
    GtkWidget* grade16;
    GtkWidget* grade17;
    GtkWidget* grade18;
    struct Database* database = (struct Database*)malloc(Max * sizeof(struct Database));
    GtkWidget* window, * grid, * window2, * grid2, * Take_inputs;
    int counter = 0, read = 0, i = 0, j = 0, location = -1, m = 0, n = 0;
    char Grades[25][10];
    FILE* pointer = fopen("Database.csv", "r");

    // read the file beginning//
    if (ferror(pointer))
    {

        printf("Failure opening file");
        return 1;
    }
    else
    {
        while (!feof(pointer))
        {
            read = fscanf(pointer, "%49[^,],%d,", database[counter].name, &database[counter].password);

            for (i = 0; i < 6; i++)
                for (j = 0; j < 3; j++)
                {
                    if (j == 2 && i == 5)
                        read += fscanf(pointer, "%f\n", &database[counter].grades[i][j]);

                    else
                        read += fscanf(pointer, "%f,", &database[counter].grades[i][j]);
                }

            if (read == 20)
                counter++;

            else
            {

                printf("error in file format");
                return 1;
            }
        }
    }
    fclose(pointer);
    // read the file ending//
    database = realloc(database, sizeof(struct Database) * counter); // reallocate struct size//

    // checking credntials beginning//
    gtk_init(&argc, &argv);
    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window2), 500, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    grid2 = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window2), grid2);
    USERNAME = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), USERNAME, 5, 1, 1, 1);
    PASSWORD = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), PASSWORD, 5, 10, 1, 1);
    label1 = gtk_label_new("Username");
    gtk_grid_attach(GTK_GRID(grid2), label1, 1, 1, 1, 1);
    label2 = gtk_label_new("Password");
    gtk_grid_attach(GTK_GRID(grid2), label2, 1, 10, 1, 1);
    Take_inputs = gtk_button_new_with_label("Login");
    g_signal_connect(Take_inputs, "clicked", G_CALLBACK(take_inputs), NULL);
    g_signal_connect(Take_inputs, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_grid_attach(GTK_GRID(grid2), Take_inputs, 10, 50, 1, 1);
    gtk_widget_show_all(window2);
    gtk_main();

    for (i = 0; i < counter; i++)
    {
        int c = strcmp(username, database[i].name);
        if (c == 0)
        {
            location = i;
            break;
        }
    }
    if (i == counter)
    {
        printf("Wrong username or password");
        return 1;
    }

    if (Password != database[location].password)
    {
        printf("wrong username or password");
        return 1;
    }

    // display grades//
    else
    {
        // change grade to string to show in gui//
        for (j = 0; j < 6; j++)
            for (m = 0; m < 3; m++)
            {
                gcvt(database[i].grades[j][m], 4, Grades[n]);
                n++;
            }

        // calculate individuals total using recursion//
        float total1 = TOTAL_MARK_calculator(database, 0, 2, location);
        float total2 = TOTAL_MARK_calculator(database, 1, 2, location);
        float total3 = TOTAL_MARK_calculator(database, 2, 2, location);
        float total4 = TOTAL_MARK_calculator(database, 3, 2, location);
        float total5 = TOTAL_MARK_calculator(database, 4, 2, location);
        float total6 = TOTAL_MARK_calculator(database, 5, 2, location);
        free(database); // free database allocated memory//

        gcvt(total1, 4, Grades[18]);
        gcvt(total2, 4, Grades[19]);
        gcvt(total3, 4, Grades[20]);
        gcvt(total4, 4, Grades[21]);
        gcvt(total5, 4, Grades[22]);
        gcvt(total6, 4, Grades[23]);

        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
        grid = gtk_grid_new();
        gtk_container_add(GTK_CONTAINER(window), grid);
        subject1 = gtk_label_new("Subject1 : ");
        gtk_grid_attach(GTK_GRID(grid), subject1, 0, 2, 1, 1);
        subject2 = gtk_label_new("Subject2 : ");
        gtk_grid_attach(GTK_GRID(grid), subject2, 0, 3, 1, 1);
        subject3 = gtk_label_new("Subject3 : ");
        gtk_grid_attach(GTK_GRID(grid), subject3, 0, 4, 1, 1);
        subject4 = gtk_label_new("Subject4 : ");
        gtk_grid_attach(GTK_GRID(grid), subject4, 0, 5, 1, 1);
        subject5 = gtk_label_new("Subject5 : ");
        gtk_grid_attach(GTK_GRID(grid), subject5, 0, 6, 1, 1);
        subject6 = gtk_label_new("Subject6 : ");
        gtk_grid_attach(GTK_GRID(grid), subject6, 0, 7, 1, 1);
        _7th = gtk_label_new(" 7th ");
        gtk_grid_attach(GTK_GRID(grid), _7th, 1, 1, 1, 1);
        _12th = gtk_label_new(" 12th ");
        gtk_grid_attach(GTK_GRID(grid), _12th, 2, 1, 1, 1);
        final = gtk_label_new(" final ");
        gtk_grid_attach(GTK_GRID(grid), final, 3, 1, 1, 1);
        TOTAL = gtk_label_new(" TOTAL ");
        gtk_grid_attach(GTK_GRID(grid), TOTAL, 4, 1, 1, 1);

        grade1 = gtk_label_new(Grades[0]);
        gtk_grid_attach(GTK_GRID(grid), grade1, 1, 2, 1, 1);
        grade2 = gtk_label_new(Grades[1]);
        gtk_grid_attach(GTK_GRID(grid), grade2, 2, 2, 1, 1);
        grade3 = gtk_label_new(Grades[2]);
        gtk_grid_attach(GTK_GRID(grid), grade3, 3, 2, 1, 1);
        TOTAL1 = gtk_label_new(Grades[18]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL1, 4, 2, 1, 1);

        grade4 = gtk_label_new(Grades[3]);
        gtk_grid_attach(GTK_GRID(grid), grade4, 1, 3, 1, 1);
        grade5 = gtk_label_new(Grades[4]);
        gtk_grid_attach(GTK_GRID(grid), grade5, 2, 3, 1, 1);
        grade6 = gtk_label_new(Grades[5]);
        gtk_grid_attach(GTK_GRID(grid), grade6, 3, 3, 1, 1);
        TOTAL2 = gtk_label_new(Grades[19]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL2, 4, 3, 1, 1);

        grade7 = gtk_label_new(Grades[6]);
        gtk_grid_attach(GTK_GRID(grid), grade7, 1, 4, 1, 1);
        grade8 = gtk_label_new(Grades[7]);
        gtk_grid_attach(GTK_GRID(grid), grade8, 2, 4, 1, 1);
        grade9 = gtk_label_new(Grades[8]);
        TOTAL6 = gtk_label_new(Grades[23]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL6, 4, 7, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), grade9, 3, 4, 1, 1);
        TOTAL3 = gtk_label_new(Grades[20]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL3, 4, 4, 1, 1);

        grade10 = gtk_label_new(Grades[9]);
        gtk_grid_attach(GTK_GRID(grid), grade10, 1, 5, 1, 1);
        grade11 = gtk_label_new(Grades[10]);
        gtk_grid_attach(GTK_GRID(grid), grade11, 2, 5, 1, 1);
        grade12 = gtk_label_new(Grades[11]);
        gtk_grid_attach(GTK_GRID(grid), grade12, 3, 5, 1, 1);
        TOTAL4 = gtk_label_new(Grades[21]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL4, 4, 5, 1, 1);

        grade13 = gtk_label_new(Grades[12]);
        gtk_grid_attach(GTK_GRID(grid), grade13, 1, 6, 1, 1);
        grade14 = gtk_label_new(Grades[13]);
        gtk_grid_attach(GTK_GRID(grid), grade14, 2, 6, 1, 1);
        grade15 = gtk_label_new(Grades[14]);
        gtk_grid_attach(GTK_GRID(grid), grade15, 3, 6, 1, 1);
        TOTAL5 = gtk_label_new(Grades[22]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL5, 4, 6, 1, 1);

        grade16 = gtk_label_new(Grades[15]);
        gtk_grid_attach(GTK_GRID(grid), grade16, 1, 7, 1, 1);
        grade17 = gtk_label_new(Grades[16]);
        gtk_grid_attach(GTK_GRID(grid), grade17, 2, 7, 1, 1);
        grade18 = gtk_label_new(Grades[17]);
        gtk_grid_attach(GTK_GRID(grid), grade18, 3, 7, 1, 1);
        TOTAL6 = gtk_label_new(Grades[23]);
        gtk_grid_attach(GTK_GRID(grid), TOTAL6, 4, 7, 1, 1);
        gtk_widget_show_all(window);
        gtk_main();

        return 0;
    }
}