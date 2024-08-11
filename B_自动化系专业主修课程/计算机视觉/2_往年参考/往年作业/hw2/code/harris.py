"""
# File       : harris.py
# Time       ：2023/5/2 19:40
# Author     ：Peng Cheng
# Description：
"""

import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


# Harris corner detection
def Harris_corner(img):
    ## Grayscale
    def BGR2GRAY(img):
        gray = 0.2126 * img[..., 2] + 0.7152 * img[..., 1] + 0.0722 * img[..., 0]
        gray = gray.astype(np.uint8)
        return gray

    ## Sobel
    def Sobel_filtering(gray):
        # get shape
        H, W = gray.shape

        # sobel kernel
        sobely = np.array(((1, 2, 1),
                           (0, 0, 0),
                           (-1, -2, -1)), dtype=np.float32)

        sobelx = np.array(((1, 0, -1),
                           (2, 0, -2),
                           (1, 0, -1)), dtype=np.float32)

        # padding
        tmp = np.pad(gray, (1, 1), 'edge')

        # prepare
        Ix = np.zeros_like(gray, dtype=np.float32)
        Iy = np.zeros_like(gray, dtype=np.float32)

        # get differential
        for y in range(H):
            for x in range(W):
                Ix[y, x] = np.mean(tmp[y: y + 3, x: x + 3] * sobelx)
                Iy[y, x] = np.mean(tmp[y: y + 3, x: x + 3] * sobely)

        Ix2 = Ix ** 2
        Iy2 = Iy ** 2
        Ixy = Ix * Iy

        return Ix2, Iy2, Ixy

    # gaussian filtering
    def gaussian_filtering(I, K_size=3, sigma=3):
        # get shape
        H, W = I.shape

        ## gaussian
        I_t = np.pad(I, (K_size // 2, K_size // 2), 'edge')

        # gaussian kernel
        K = np.zeros((K_size, K_size), dtype=np.float)
        for x in range(K_size):
            for y in range(K_size):
                _x = x - K_size // 2
                _y = y - K_size // 2
                K[y, x] = np.exp(-(_x ** 2 + _y ** 2) / (2 * (sigma ** 2)))
        K /= (sigma * np.sqrt(2 * np.pi))
        K /= K.sum()

        # filtering
        for y in range(H):
            for x in range(W):
                I[y, x] = np.sum(I_t[y: y + K_size, x: x + K_size] * K)

        return I

    # corner detect
    def corner_detect(gray, Ix2, Iy2, Ixy, k=0.04, th=0.1):
        # prepare output image
        out = np.array((gray, gray, gray))
        out = np.transpose(out, (1, 2, 0))

        # get R
        R = (Ix2 * Iy2 - Ixy ** 2) - k * ((Ix2 + Iy2) ** 2)

        # detect corner
        out[R >= np.max(R) * th] = [255, 0, 0]

        out = out.astype(np.uint8)

        return out

    # 1. grayscale
    gray = BGR2GRAY(img)

    # 2. get difference image
    Ix2, Iy2, Ixy = Sobel_filtering(gray)

    # 3. gaussian filtering
    Ix2 = gaussian_filtering(Ix2, K_size=3, sigma=3)
    Iy2 = gaussian_filtering(Iy2, K_size=3, sigma=3)
    Ixy = gaussian_filtering(Ixy, K_size=3, sigma=3)

    # 4. corner detect
    out = corner_detect(gray, Ix2, Iy2, Ixy)

    return out


# Read image
img = cv.imread("./data/test.jpeg").astype(np.float32)

# Harris corner detection
out = Harris_corner(img)

cv.imwrite("out.jpg", out)
cv.imshow("result", out)
cv.waitKey(0)
cv.destroyAllWindows()

