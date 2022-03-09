import cv2
import numpy as np

# 在图像上绘制图像，放置文本

# 建立全零的矩阵，全零表示图像为黑色
img = np.zeros((512, 512, 3), np.uint8)

# 绘制图像
cv2.line(img, (0, 0), (300, 300), (0, 255, 0), 3)
cv2.rectangle(img, (0, 0), (250, 350), (0, 0, 255), 2)
cv2.circle(img, (400, 50), 30, (255, 255, 0), 5)
# 在图像上放置文本
cv2.putText(img, "Opencv", (300, 100), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 150, 0), 1)

cv2.imshow("Image", img)
cv2.waitKey(0)
