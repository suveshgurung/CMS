#include "logowidget.h"

LogoWidget::LogoWidget(QWidget *parent) : QWidget(parent)
{
    // Create a QVBoxLayout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Load the image
    QPixmap pixmap("C:/Users/acer 5/Desktop/KU/1st year 2nd sem/Semester Project/CMS/CMS/CMS/LogoAI.png");
    verticalFrame->setStyleSheet(
        "QLabel { "
        "background-image: url(C:/Users/acer 5/Desktop/KU/1st year 2nd sem/Semester Project/CMS/CMS/CMS/LogoAI.png); "
        "background-size: contain; "
        "background-repeat: no-repeat; "
        "background-position: center; "
        "width: 71px; "
        "height: 71px; "
        "}");

    verticalFrame = new QLabel(this);

    // Set fixed dimensions using stylesheet
    verticalFrame->setStyleSheet("QLabel { width: 71px; height: 71px; }");

    // Scale the pixmap to fit the QLabel's dimensions
    QPixmap scaledPixmap = pixmap.scaled(71, 71, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    verticalFrame->setPixmap(scaledPixmap);

    // Add the QLabel to the layout
    layout->addWidget(verticalFrame);
}
