import cv2
import numpy as np

# 生成红绿蓝三色通道
# 蓝色通道
blue = np.zeros((300, 300, 3), dtype=np.uint8)
blue[:, :, 0] = 255
print("blue=\n", blue)
cv2.imshow("blue", blue)
# 绿色通道
green = np.zeros((300, 300, 3), dtype=np.uint8)
green[:, :, 1] = 255
print("green=\n", green)
cv2.imshow("green", green)
# 红色通道
red = np.zeros((300, 300, 3), dtype=np.uint8)
red[:, :, 2] = 255
print("red=\n", red)
cv2.imshow("red", red)
# 生成三色通道
img = np.zeros((300, 300, 3), dtype=np.uint8)
img[:, 0:100, 0] = 255
img[:, 100:200, 1] = 255
img[:, 200:300, 2] = 255
print("img=\n", img)
cv2.imshow("img", img)

cv2.waitKey(0)
cv2.destroyWindow('car')
