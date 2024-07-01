#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QMoveEvent>
#include <QResizeEvent>
#include <QShowEvent>

class Window : public QWidget {
private:
    QVector<QWidget*> _pQWidgetsMove;
    int _x, _y;
    bool _updateXY = true;

public:
    Window(QWidget *pQParent = nullptr) : QWidget(pQParent) { }
    virtual ~Window() = default;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void setMoveWidgets(QVector<QWidget*> pQWidgetsMove) {
        _pQWidgetsMove = pQWidgetsMove;
    }

protected:
    virtual void showEvent(QShowEvent *pQEvent) override {
        QWidget::showEvent(pQEvent);
        _x = x();
        _y = y();
    }

    virtual void resizeEvent(QResizeEvent *pQEvent) override {
        QWidget::resizeEvent(pQEvent);
        _updateXY = false;
        QTimer::singleShot(0, this, [this, x = x(), y = y()]() {
            for (QWidget* pQWidget : _pQWidgetsMove) {
                pQWidget->move(pQWidget->x() + _x - x, pQWidget->y() + _y - y);
            }
            _x = x;
            _y = y;
            _updateXY = true;
        });
    }

    virtual void moveEvent(QMoveEvent *pQEvent) override {
        QWidget::moveEvent(pQEvent);
        if (_updateXY) {
            _x += pQEvent->pos().x() - pQEvent->oldPos().x();
            _y += pQEvent->pos().y() - pQEvent->oldPos().y();
        }
    }
};

#endif // WINDOW_H
