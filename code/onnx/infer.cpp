#include "infer.h"

using namespace cv;
using namespace std;

void infer::getResult(string fileName)
{
    Mat src = imread(fileName);
    Mat dst;
    cvtColor(src, src, COLOR_BGR2GRAY);
    blur(src, src, Size(3, 3));
    Canny(src, dst, 3, 9, 3);
    imwrite("./resources/inference/infer.jpg", dst);
    
}

