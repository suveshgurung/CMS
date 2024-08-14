#ifndef IMAGESLIDER_H
#define IMAGESLIDER_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QStringList>

class ImageSlider : public QObject {
    Q_OBJECT

public:
    ImageSlider(QLabel* imageLabel, QPushButton* leftButton, QPushButton* rightButton, const QStringList& images, QObject* parent = nullptr);

private slots:
    void showNextImage();
    void showPreviousImage();

private:
    QLabel* imageLabel;
    QPushButton* leftButton;
    QPushButton* rightButton;
    QStringList images;
    int currentIndex;
};

#endif // IMAGESLIDER_H
