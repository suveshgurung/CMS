#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

class LogoWidget : public QWidget {
    Q_OBJECT

public:
    explicit LogoWidget(QWidget *parent = nullptr);

private:
    QLabel *verticalFrame;
};

#endif // LOGOWIDGET_H
