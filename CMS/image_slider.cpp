#include "image_slider.h"
#include <QPixmap>
#include <QDebug>

ImageSlider::ImageSlider(QLabel *imageLabel, QPushButton *leftButton, QPushButton *rightButton, const QStringList &images, QObject *parent)
    : QObject(parent), imageLabel(imageLabel), leftButton(leftButton), rightButton(rightButton), images(images), currentIndex(0)
{
    currentIndex=0;
    if (!images.isEmpty())
    {
        imageLabel->setPixmap(QPixmap(images[currentIndex]));
        imageLabel->setScaledContents(true);
    }
    else
    {
        qDebug() << "No images to display.";
    }

    connect(leftButton, &QPushButton::clicked, this, &ImageSlider::showPreviousImage);
    connect(rightButton, &QPushButton::clicked, this, &ImageSlider::showNextImage);
}

void ImageSlider::showNextImage()
{
    if (!images.isEmpty())
    {
        currentIndex = (currentIndex + 1) % images.size();
        imageLabel->setPixmap(QPixmap(images[currentIndex]));
        qDebug()<<"next clicked";
    }
    else
    {
        qDebug() << "No images to display.";
    }
}

void ImageSlider::showPreviousImage()
{
    if (!images.isEmpty())
    {
        currentIndex = (currentIndex - 1 + images.size()) % images.size();
        imageLabel->setPixmap(QPixmap(images[currentIndex]));
         qDebug()<<"prev clicked";
    }
    else
    {
        qDebug() << "No images to display.";
    }
}
