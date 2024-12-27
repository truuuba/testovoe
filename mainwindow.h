#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString free_color;
    QStringList colors;
    int cnt_click = 0;

private slots:
    void on_but11_clicked();
    void on_but12_clicked();
    void on_but13_clicked();
    void on_but21_clicked();
    void on_but22_clicked();
    void on_but23_clicked();
    void on_but31_clicked();
    void on_but32_clicked();
    void on_but33_clicked();
    void on_update_data_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
