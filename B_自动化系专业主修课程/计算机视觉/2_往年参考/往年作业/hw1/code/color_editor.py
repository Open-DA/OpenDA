"""
# File       : color_editor.py
# Time       ：2023/4/6 21:06
# Author     ：Peng Cheng
# Description：cv hw 3.1 color balance
# ChatGPT used in this project
"""

import cv2
import numpy as np

def color_twist():
    # 加载图像
    image = cv2.imread("image/kion.png")

    # 定义颜色乘子的初始值
    red_multiplier = 1.0
    green_multiplier = 1.0
    blue_multiplier = 1.0

    # 创建滑动条回调函数
    def update_image(*args):
        global red_multiplier, green_multiplier, blue_multiplier

        # 获取滑动条的值
        red_value = cv2.getTrackbarPos("Red", "Color Balance") / 10
        green_value = cv2.getTrackbarPos("Green", "Color Balance") / 10
        blue_value = cv2.getTrackbarPos("Blue", "Color Balance") / 10

        # 更新当前的乘子值
        red_multiplier = red_value
        green_multiplier = green_value
        blue_multiplier = blue_value

        # 将每个像素的颜色值乘以对应的乘子
        adjusted_image = image.copy()
        adjusted_image[:, :, 0] = adjusted_image[:, :, 0] * blue_multiplier
        adjusted_image[:, :, 1] = adjusted_image[:, :, 1] * green_multiplier
        adjusted_image[:, :, 2] = adjusted_image[:, :, 2] * red_multiplier

        # 在图像中显示当前的乘子值
        red_text = "Red: {:.1f}".format(red_multiplier)
        green_text = "Green: {:.1f}".format(green_multiplier)
        blue_text = "Blue: {:.1f}".format(blue_multiplier)
        cv2.putText(adjusted_image, red_text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        cv2.putText(adjusted_image, green_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        cv2.putText(adjusted_image, blue_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)

        # 显示调整后的图像
        cv2.imshow("Color Balance", adjusted_image)

    # 创建窗口
    cv2.namedWindow("Color Balance", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("Color Balance", 600, 600)
    # 创建滑动条
    cv2.createTrackbar("Red", "Color Balance", 10, 20, update_image)
    cv2.createTrackbar("Green", "Color Balance", 10, 20, update_image)
    cv2.createTrackbar("Blue", "Color Balance", 10, 20, update_image)

    # 显示初始图像和调整后的图像
    cv2.imshow("Color Balance", image)

    # 进入GUI循环
    while True:
        # 检查键盘输入，如果是ESC键则退出循环
        key = cv2.waitKey(1) & 0xFF
        if key == 27:
            break

        # 继续循环

    # 关闭窗口和释放资源
    cv2.destroyAllWindows()

if __name__ == '__main__':
    color_twist()