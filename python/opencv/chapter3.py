import cv2
import numpy as np

# 调整图像的大小

img = cv2.imread("Resources/car.jpg")
print(img.shape)  # (177,284,3),宽高和通道数
imgResize = cv2.resize(img, (500, 300))
print(imgResize.shape)
# 裁剪图像
imgCropped = img[0:100, 100:200]
cv2.imshow("Image", img)
cv2.imshow("ImageResize", imgResize)
cv2.imshow("ImageCropped", imgCropped)
cv2.waitKey(0)