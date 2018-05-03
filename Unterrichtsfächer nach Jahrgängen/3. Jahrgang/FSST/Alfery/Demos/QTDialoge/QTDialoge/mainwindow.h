#ifndef MAINWINDOW_H
#define MAINWINDOW_H

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_FileOpenButton_clicked();

    void on_FileSaveAsButton_clicked();

    void on_MessageButton_clicked();

    void on_InputBox_clicked();

    void on_exitButton_clicked();

    void on_ColorDialogButton_clicked();


    void on_FontDialogButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
