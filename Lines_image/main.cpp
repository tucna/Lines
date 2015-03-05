#include <QImage>
#include <QMap>
#include <QRgb>

int main(int argc, char *argv[])
{
    QImage inputImage("lena.png");
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
    int pixelCount = inputImage.width() * inputImage.height();
    int startPosition = 0;
    float finalCheck = 0.0f;

    foreach(QRgb color, histogram.keys())
    {
        float currentColor = (float)histogram.value(color) / pixelCount * inputImage.width();
        int widthColumn = qRound(currentColor);

        finalCheck += currentColor;

        for (int i = startPosition; i < (startPosition + widthColumn); i++)
        {
            for (int o = 0; o < resultImage.height(); o++)
            {
                resultImage.setPixel(i, o, color);
            }
        }        

        startPosition += widthColumn;
    };

    resultImage.save("result.png");
}
