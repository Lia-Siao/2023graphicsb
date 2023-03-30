#include <opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("image.jpg");
    cvShowImage("week07",img);
    cvWaitKey(0);
}
