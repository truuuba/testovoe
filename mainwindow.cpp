#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "counter.h"
#include <QString>
#include <string>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Настраиваем кнопки с цветами
    colors = found_colors_();
    ui->but11->setStyleSheet("background-color:" + colors[0]);
    QString txt = take_nazv_but(colors[0]);
    ui->but11->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but11->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but11->setPalette(palette);
    }

    ui->but12->setStyleSheet("background-color:" + colors[1]);
    txt = take_nazv_but(colors[1]);
    ui->but12->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but12->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but12->setPalette(palette);
    }

    ui->but13->setStyleSheet("background-color:" + colors[2]);
    txt = take_nazv_but(colors[2]);
    ui->but13->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but13->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but13->setPalette(palette);
    }

    ui->but21->setStyleSheet("background-color:" + colors[3]);
    txt = take_nazv_but(colors[3]);
    ui->but21->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but21->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but21->setPalette(palette);
    }

    ui->but22->setStyleSheet("background-color:" + colors[4]);
    txt = take_nazv_but(colors[4]);
    ui->but22->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but22->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but22->setPalette(palette);
    }

    ui->but23->setStyleSheet("background-color:" + colors[5]);
    txt = take_nazv_but(colors[5]);
    ui->but23->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but23->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but23->setPalette(palette);
    }

    ui->but31->setStyleSheet("background-color:" + colors[6]);
    txt = take_nazv_but(colors[6]);
    ui->but31->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but31->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but31->setPalette(palette);
    }

    ui->but32->setStyleSheet("background-color:" + colors[7]);
    txt = take_nazv_but(colors[7]);
    ui->but32->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but32->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but32->setPalette(palette);
    }

    ui->but33->setStyleSheet("background-color:" + colors[8]);
    txt = take_nazv_but(colors[8]);
    ui->but33->setText(txt);
    if (prov_black(txt)){
        QPalette palette = ui->but33->palette();
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
        ui->but33->setPalette(palette);
    }
    free_color = colors[9];

    //Настраиваем время
    ui->time_line->setTime(QTime::currentTime());

    //Настраиваем погоду
    std::string city = "Moscow";  // Город для запроса
    std::string apiKey = "2f827867bb1425cd2e8ada8c1ea3b522";
    double temperature = get_temp(city, apiKey);
    ui->line_temp->setText("Текущая температура в Москве: " + QString::number(temperature));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_but11_clicked()
{
    //меняем цвет кнопки
    QString temp = colors[0];
    ui->but11->setStyleSheet("background-color:" + free_color);
    //меняем название
    QString txt = take_nazv_but(free_color);
    ui->but11->setText(txt);
    //меняем цвет текста в зависимости от фона
    QPalette palette = ui->but11->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but11->setPalette(palette);

    colors[0] = free_color;
    free_color = temp;

    //Изменяем счетчик
    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but12_clicked()
{
    QString temp = colors[1];
    ui->but12->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but12->setText(txt);
    QPalette palette = ui->but12->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but12->setPalette(palette);
    colors[1] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but13_clicked()
{
    QString temp = colors[2];
    ui->but13->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but13->setText(txt);
    QPalette palette = ui->but13->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but13->setPalette(palette);
    colors[2] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but21_clicked()
{
    QString temp = colors[3];
    ui->but21->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but21->setText(txt);
    QPalette palette = ui->but21->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but21->setPalette(palette);
    colors[3] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but22_clicked()
{
    QString temp = colors[4];
    ui->but22->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but22->setText(txt);
    QPalette palette = ui->but22->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but22->setPalette(palette);
    colors[4] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but23_clicked()
{
    QString temp = colors[5];
    ui->but23->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but23->setText(txt);
    QPalette palette = ui->but23->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but23->setPalette(palette);
    colors[5] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but31_clicked()
{
    QString temp = colors[6];
    ui->but31->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but31->setText(txt);
    QPalette palette = ui->but31->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but31->setPalette(palette);
    colors[6] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but32_clicked()
{
    QString temp = colors[7];
    ui->but32->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but32->setText(txt);
    QPalette palette = ui->but32->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but32->setPalette(palette);
    colors[7] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_but33_clicked()
{
    QString temp = colors[8];
    ui->but33->setStyleSheet("background-color:" + free_color);
    QString txt = take_nazv_but(free_color);
    ui->but33->setText(txt);
    QPalette palette = ui->but33->palette();
    if (prov_black(txt))
        palette.setColor(QPalette::ButtonText, QColor("#ffffff"));
    else
        palette.setColor(QPalette::ButtonText, QColor("#000000"));
    ui->but33->setPalette(palette);
    colors[8] = free_color;
    free_color = temp;

    cnt_click++;
    ui->label_2->setText("Количество нажатий: " + QString::number(cnt_click));
}

void MainWindow::on_update_data_clicked()
{
    ui->time_line->setTime(QTime::currentTime());
    std::string city = "Moscow";  // Город для запроса
    std::string apiKey = "2d5bcb00c4d23e270c48783e49ca3388";
    double temperature = get_temp(city, apiKey);
    ui->line_temp->setText("Текущая температура в Москве: " + QString::number(temperature));
}

