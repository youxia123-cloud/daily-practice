import cv2
import numpy as np
img = cv2.imread("Resources/car.jpg")

# 定义内核
kernel = np.ones((5, 5), np.uint8)


# 对图像进行灰度转换
# 在opencv中图像的惯例通道为BGR
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
# 对图像进行模糊处理,第二个参数表示内核大小
imgBlur = cv2.GaussianBlur(imgGray, (7, 7), 0)
# 对图像进行检测,可以识别图像的边缘
imgCanny = cv2.Canny(img, 100, 100)
# 对图像检测进行扩张,第二个参数是定义内核，第三个参数是表示迭代的次数
imgDialation = cv2.dilate(imgCanny, kernel, iterations=1)


# 图像腐蚀
imgEroded = cv2.erode(imgDialation, kernel, iterations=1)
# 第一个参数是窗口的名称
cv2.imshow("Gray Image", imgGray)
cv2.imshow("Blur Image", imgBlur)
cv2.imshow("Canny Image", imgCanny)
cv2.imshow("Dialation Image", imgDialation)
cv2.imshow("Eroded Image", imgEroded)
cv2.waitKey(0)  