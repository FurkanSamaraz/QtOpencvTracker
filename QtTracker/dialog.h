#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

cv::VideoCapture capWebcam;

cv::Mat matOriginal;
cv::Mat matProcessed;

QImage qimgOriginal;
QImage qimgProcesse;

std::vector<cv::Vec3f> vecCircles;
std::vector<cv::Vec3f>::iterator itrCircles;

QTimer *tmrTimer;

private:
    Ui::Dialog *ui;
public slots:
    void processFrameAndUpdateGUI();

private slots:
    void on_btnPause_clicked();
};
#endif // DIALOG_H
