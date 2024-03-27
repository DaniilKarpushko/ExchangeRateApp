#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>


#include "../include/Presentation/Widget/GraphicBuilderWidget.h"

#include <iostream>
#include <QVBoxLayout>
#include <QDateTime>


GraphicBuilderWidget::GraphicBuilderWidget(std::vector<std::pair<std::string, float>> data, QWidget* parent)
    : QWidget(parent)
{
    auto* series = new QLineSeries();
    for (auto& el : data)
    {
        series->append(QDateTime::fromString(QString::fromStdString(el.first), "yyyy-MM-dd").toSecsSinceEpoch(),
                       el.second);
        std::cout << el.first << " " << el.second << '\n';
    }

    auto* chart = new QChart();
    chart->setTitle("Currency in month");

    auto* axisX = new QDateTimeAxis();
    axisX->setTickCount(10);
    axisX->setFormat("yyyy-MM-dd");

    auto *axisY = new QValueAxis;
    axisY->setTickCount(10);

    chart->addSeries(series);

    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    auto* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    auto* layout = new QVBoxLayout();

    layout->addWidget(chartView);

    setLayout(layout);
}
