#include <QImage>
#include <QMap>
#include <QRgb>

int main(int argc, char *argv[])
{
    QImage inputImage("D:/lena.png");
    QImage resultImage(inputImage.size(), QImage::Format_ARGB32);
    QMap<QRgb, int> histogram;

    // Histogram creation
    for (int x = 0; x < inputImage.width(); x++)
    {
        for (int y = 0; y < inputImage.height(); y++)
        {
            QRgb color = inputImage.pixel(x,y);

            if (histogram.contains(color))
            {
                int number = histogram.value(color) + 1;

                histogram.insert(color, number);
            }
            else
            {
                histogram.insert(color, 1);
            }
        }
    }

    // Result render

    resultImage.save("D:/result.png");
}
