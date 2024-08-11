"""
# File       : utils.py
# Time       ：2023/4/6 22:35
# Author     ：Peng Cheng
# Description：utils
"""
import cv2
import numpy as np
import matplotlib.pyplot as plt
import math

def plot2_1():
    f = 100  # 镜头的焦距
    delta_z = np.linspace(0, -200, 1000)  # 物体到焦距的差值
    z_i = f - delta_z  # 物体到镜头的距离
    z_o = 1 / (1 / f - 1 / z_i)  # 聚焦距离

    plt.plot(delta_z, z_o)
    plt.xlabel('Δzi (mm)')
    plt.ylabel('zo (mm)')
    plt.title('Focus distance vs. delta_z')
    plt.show()


def plot2_3():
    # 定义变量
    c = 0.0003
    N0 = 3
    N1 = 5
    N2 = 7
    z_o = 5

    # 计算L和f的值
    f = np.linspace(0.15, 0.4, 100)
    L1 = 2 * f ** 2 * c * N1 * z_o ** 2 / (f ** 4 - (c * N1 * z_o) ** 2)
    L2 = 2 * f ** 2 * c * N2 * z_o ** 2 / (f ** 4 - (c * N2 * z_o) ** 2)
    L0 = 2 * f ** 2 * c * N0 * z_o ** 2 / (f ** 4 - (c * N0 * z_o) ** 2)

    # 绘制图形
    plt.plot(f, L1)
    plt.plot(f, L2)
    plt.plot(f, L0)
    # label
    plt.legend(['N=5', 'N=7', 'N=3'])

    plt.xlabel('f (m)')
    plt.ylabel('L (m)')
    plt.title('L and f Relationship')
    plt.show()


def plot3_1():
    # 3-1 对比
    scale = (0.8, 0.7, 0.6)
    gamma = 1.5

    img1 = cv2.imread('image/kion.png')
    img1 = color_balance(img1, scale)
    img1,img1_gamma = gamma_trans(img1, gamma)

    img2 = cv2.imread('image/kion.png')
    img2,img2_gamma = gamma_trans(img2, gamma)
    img2_gamma = color_balance(img2_gamma, scale)

    show2pics(img1_gamma,img2_gamma,'balance-gamma','gamma-balance')


def color_balance(img,scale):
    red_scale = scale[0]
    green_scale = scale[1]
    blue_scale = scale[2]
    adjusted_image = img.copy()
    adjusted_image[:, :, 0] = adjusted_image[:, :, 0] * blue_scale
    adjusted_image[:, :, 1] = adjusted_image[:, :, 1] * green_scale
    adjusted_image[:, :, 2] = adjusted_image[:, :, 2] * red_scale
    return adjusted_image


def gamma_trans(img, gamma):
    # 使用OpenCV的LUT函数进行Gamma变换
    invGamma = 1.0 / gamma
    table = np.array([((i / 255.0) ** invGamma) * 255 for i in np.arange(0, 256)])
    img_gamma = cv2.LUT(img, table.astype(np.uint8))

    return img,img_gamma

def show2pics(pic1,pic2,n1='Original',n2='Gamma Transformed'):
    # 给每张图像添加文本标签
    font = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 5
    thickness = 5
    pic1 = cv2.putText(pic1, n1, (100, 200), font, font_scale, (0, 0, 0), thickness, cv2.LINE_AA)
    pic2 = cv2.putText(pic2, n2, (100, 200), font, font_scale, (0, 0, 0), thickness,
                            cv2.LINE_AA)

    combined_img = cv2.hconcat([pic1, pic2])
    cv2.namedWindow("Combined Image", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("Combined Image", 1000, 600)
    cv2.imshow('Combined Image', combined_img)

    # 等待用户按下按键并退出程序
    cv2.waitKey(0)
    cv2.destroyAllWindows()


def luminance():
    # convert a pic to luminance
    img = cv2.imread('image/kion.png')
    img = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)
    img[:, :, 0] = img[:, :, 0] * 0.5
    img = cv2.cvtColor(img, cv2.COLOR_YUV2BGR)
    cv2.imshow('luminance', img)


def rgb2gray(image):
    b, g, r = np.int32(image[:,:, 0]), np.int32(image[:,:, 1]), np.int32(image[:,:, 2])
    gray = 0.299 * r + 0.587 * g + 0.114 * b
    # change the type of gray to int
    gray = np.uint8(gray)
    return gray


def histogram(image):
    # calculate the histogram of the image
    hist = np.zeros(256, dtype=np.int32)
    #hist[i] 为image值为i的像素个数，用np并行
    hist = np.bincount(image.ravel(), minlength=256)
    # for i in range(image.shape[0]):
    #     for j in range(image.shape[1]):
    #         hist[image[i, j]] += 1

    return hist

def cumulative_distribution(image):
    # calculate the cumulative distribution of the image
    h,w = image.shape
    hist = histogram(image)
    cdf = np.zeros(256, dtype=np.int32)
    cdf[0] = hist[0]
    for i in range(1, 256):
        cdf[i] = cdf[i - 1] + hist[i]
    cdf = cdf / (h * w)
    return cdf


def ctf(image,alpha,cdf = None):
    if cdf is None:
        cdf = cumulative_distribution(image)
    else:
        cdf = cdf
    ctf = np.zeros(256, dtype=np.int32)
    for i in range(256):
        ctf[i] = np.uint8(255 * (cdf[i] * alpha)+ i*(1-alpha))
    return ctf


def ctf_tranfer(image,ctf):
    # transfer the image by ctf
    h, w = image.shape
    new_image = np.zeros((h, w), dtype=np.uint8)
    # new_image[i, j] = ctf[image[i, j]]，用np并行
    new_image = ctf[image]

    return new_image


def plot_hist(r,g,b,gray):
    # plot the histogram
    plt.plot(r, 'r')
    plt.plot(g, 'g')
    plt.plot(b, 'b')
    plt.plot(gray, 'k')
    # 添加图示
    plt.legend(['r', 'g', 'b', 'gray'])

    # set label
    plt.xlabel('gray level')
    plt.ylabel('number of pixels')
    plt.title('histogram')
    plt.tight_layout()
    plt.show()


def plot_cdf(r,g,b,gray):
    # plot the cumulative distribution
    plt.plot(r, 'r')
    plt.plot(g, 'g')
    plt.plot(b, 'b')
    plt.plot(gray, 'k')
    # 添加图示
    plt.legend(['r', 'g', 'b', 'gray'])
    # set label
    plt.xlabel('gray level')
    plt.ylabel('possibility')
    plt.title('cumulative distribution')
    plt.tight_layout()
    plt.show()


def plot_ctf(r,g,b,gray,alpha):
    plt.plot(r, 'r')
    plt.plot(g, 'g')
    plt.plot(b, 'b')
    plt.plot(gray, 'k')
    # 添加图示
    plt.legend(['r', 'g', 'b', 'gray'])
    # set label
    plt.xlabel('gray level')
    plt.ylabel('tranfered gray level')
    plt.title(f'compensation transfer function, alpha={alpha}')
    plt.tight_layout()
    plt.show()


def punch(image):
    h,w = image.shape
    new_image = image.copy()
    # Calculate the histogram
    hist = cv2.calcHist([image], [0], None, [256], [0, 256])

    # Determine the intensity values corresponding to the 5% brightest and darkest pixels
    total_pixels = image.shape[0] * image.shape[1]
    num_pixels = int(total_pixels * 0.05)
    dark_threshold = np.argmax(np.cumsum(hist) >= num_pixels)
    bright_threshold = 255-np.argmax(np.cumsum(hist[::-1]) >= num_pixels)
    print(f"Dark threshold: {dark_threshold}, Bright threshold: {bright_threshold}")

    # Set the pixel values below the dark threshold to 0 and above the bright threshold to 255
    new_image[image < dark_threshold] = 0
    new_image[image > bright_threshold] = 255

    # Map the pixel values between the threshold values and 255 to the full range of 0-255
    new_image = np.interp(new_image, [dark_threshold, bright_threshold], [0, 255])

    return new_image


def limit_f(image,gamma,alpha):
    # calculate the cumulative distribution of the image
    h, w = image.shape
    hist = histogram(image)
    cdf = np.zeros(256, dtype=np.int32)
    cdf[0] = hist[0]
    thr = gamma*h*w
    for i in range(1, 256):
        if hist[i] > thr:
            cdf[i] = cdf[i - 1] + thr
        else:
            cdf[i] = cdf[i - 1] + hist[i]
    cdf = cdf / (h * w)

    ctf = np.zeros(256, dtype=np.int32)
    for i in range(256):
        ctf[i] = np.uint8(255 * (cdf[i] * alpha) + i * (1 - alpha))

    return ctf


def Histogram_equalization():
    # load img
    img = cv2.imread('image/kion.png')
    h,w, c = img.shape
    # get luminance
    gray_img = rgb2gray(img)
    # cv2.namedWindow("gray", cv2.WINDOW_NORMAL)
    # cv2.resizeWindow("gray", 600, 600)
    # cv2.imshow("gray",gray_img)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()
    # get histogram
    gray_hist = histogram(gray_img)
    b_hist = histogram(img[:, :, 0])
    g_hist = histogram(img[:, :, 1])
    r_hist = histogram(img[:, :, 2])
    plot_hist(r_hist, g_hist, b_hist, gray_hist)

    # get cumulative distribution
    gray_cdf = cumulative_distribution(gray_img)
    b_cdf = cumulative_distribution(img[:, :, 0])
    g_cdf = cumulative_distribution(img[:, :, 1])
    r_cdf = cumulative_distribution(img[:, :, 2])
    plot_cdf(r_cdf, g_cdf, b_cdf, gray_cdf)

    # get compensation tranfer function
    alpha = 0.5
    gray_ctf = ctf(gray_img, alpha)
    b_ctf = ctf(img[:, :, 0], alpha)
    g_ctf = ctf(img[:, :, 1], alpha)
    r_ctf = ctf(img[:, :, 2], alpha)
    plot_ctf(r_ctf, g_ctf, b_ctf, gray_ctf,alpha)

    # tranfer the image
    new_img = np.zeros((h, w, c), dtype=np.uint8)
    new_img[:, :, 0] = ctf_tranfer(img[:, :, 0], b_ctf)
    new_img[:, :, 1] = ctf_tranfer(img[:, :, 1], g_ctf)
    new_img[:, :, 2] = ctf_tranfer(img[:, :, 2], r_ctf)
    new_gray_img = rgb2gray(new_img)
    new_gray_hist = histogram(new_gray_img)
    new_b_hist = histogram(new_img[:, :, 0])
    new_g_hist = histogram(new_img[:, :, 1])
    new_r_hist = histogram(new_img[:, :, 2])
    plot_hist(new_r_hist, new_g_hist, new_b_hist, new_gray_hist)
    # 同时显示两个图片
    # show2pics(img, new_img, "old", "new")

    # increase punch
    punch_img = np.zeros((h, w, c), dtype=np.uint8)
    punch_img[:, :, 0] = punch(img[:, :, 0])
    punch_img[:, :, 1] = punch(img[:, :, 1])
    punch_img[:, :, 2] = punch(img[:, :, 2])
    # show2pics(img, punch_img, "old", "new")

    # limit f'
    gamma = 3/255
    alpha = 0.5
    gray_ctf = limit_f(gray_img, gamma, alpha)
    b_ctf = limit_f(img[:, :, 0], gamma, alpha)
    g_ctf = limit_f(img[:, :, 1], gamma, alpha)
    r_ctf = limit_f(img[:, :, 2], gamma, alpha)
    plot_ctf(r_ctf, g_ctf, b_ctf, gray_ctf, alpha)

    # use all the method to deal the image
    # 1. histogram equalization
    new_img = np.zeros((h, w, c), dtype=np.uint8)
    new_img[:, :, 0] = ctf_tranfer(img[:, :, 0], b_ctf)
    new_img[:, :, 1] = ctf_tranfer(img[:, :, 1], g_ctf)
    new_img[:, :, 2] = ctf_tranfer(img[:, :, 2], r_ctf)

    # 2. punch
    punch_img = np.zeros((h, w, c), dtype=np.uint8)
    punch_img[:, :, 0] = punch(new_img[:, :, 0])
    punch_img[:, :, 1] = punch(new_img[:, :, 1])
    punch_img[:, :, 2] = punch(new_img[:, :, 2])
    # 同时显示两个图片
    show2pics(img, punch_img, "old", "new")



    # get the cumulative histogram
    # # 3-2 直方图均衡化
    # img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # img = cv2.equalizeHist(img)
    # img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    return img


def histogram_equalization_pro():
    # load img
    img = cv2.imread('image/kion.png')
    h, w, c = img.shape
    # print(h, w, c)

    # 将图像分割成若干个patch
    patch_size = 256
    rows, cols, channels = img.shape
    patches = [img[i:i + patch_size, j:j + patch_size] for i in range(0, rows, patch_size) for j in
               range(0, cols, patch_size)]
    # print(len(patches))
    # print(patches[0].shape)

    # 计算每个patch的转换函数f
    b_trans_functions = [cumulative_distribution(patch[:,:,0]) for patch in patches]
    g_trans_functions = [cumulative_distribution(patch[:,:,1]) for patch in patches]
    r_trans_functions = [cumulative_distribution(patch[:,:,2]) for patch in patches]

    # 对于每个patch，要计算四个变换，然后利用这四个变换加权求和
    new_patches = []
    for i in range(0, rows, patch_size):
        for j in range(0, cols, patch_size):
            # get the patch from patches
            patch_idx = (i // patch_size) * (math.ceil(cols / patch_size ) )+ j // patch_size
            print(patch_idx)
            apatch = patches[patch_idx] # 取出这一块

            alpha = 0.5

            # 如果ij都到头了，边上的一小块就不做加权，直接输出
            if j + patch_size >= cols and i + patch_size >= rows:
                b_ctf = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx])
                g_ctf = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx])
                r_ctf = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx])
                new_patch = np.zeros(apatch.shape, dtype=np.uint8)
                new_patch[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf)
                new_patch[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf)
                new_patch[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf)
                # show2pics(apatch, new_patch, "old", "new")
                new_patches.append(new_patch)
                continue

            # 如果i到头了，只做j的加权
            if i + patch_size >= rows:
                b_ctf1 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx])
                g_ctf1 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx])
                r_ctf1 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx])
                new_patch1 = np.zeros(apatch.shape, dtype=np.uint8)
                new_patch1[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf1)
                new_patch1[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf1)
                new_patch1[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf1)

                b_ctf2 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx + 1])
                g_ctf2 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx + 1])
                r_ctf2 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx + 1])
                new_patch2 = np.zeros(apatch.shape, dtype=np.uint8)
                new_patch2[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf2)
                new_patch2[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf2)
                new_patch2[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf2)

                new_patch = np.zeros(apatch.shape, dtype=np.uint8)
                for s in range(apatch.shape[0]):
                    for t in range(apatch.shape[1]):
                        new_patch[s, t] = np.uint8(
                            (1 - s / patch_size) * (1 - t / patch_size) * new_patch1[s, t] + (1 - s / patch_size) * (
                                        t / patch_size) * new_patch2[s, t] + (s / patch_size) * (1 - t / patch_size) *
                            new_patch1[s, t] + (s / patch_size) * (t / patch_size) * new_patch2[s, t])
                new_patches.append(new_patch)
                continue
            # 如果j到头了，只做i的加权
            if j + patch_size >= cols:
                b_ctf1 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx])
                g_ctf1 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx])
                r_ctf1 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx])
                new_patch1 = np.zeros(apatch.shape, dtype=np.uint8)
                new_patch1[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf1)
                new_patch1[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf1)
                new_patch1[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf1)

                b_ctf3 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx + math.ceil(cols / patch_size)])
                g_ctf3 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx + math.ceil(cols / patch_size)])
                r_ctf3 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx + math.ceil(cols / patch_size)])
                new_patch3 = np.zeros(apatch.shape, dtype=np.uint8)
                new_patch3[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf3)
                new_patch3[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf3)
                new_patch3[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf3)

                new_patch = np.zeros(apatch.shape, dtype=np.uint8)
                for s in range(apatch.shape[0]):
                    for t in range(apatch.shape[1]):
                        new_patch[s, t] = np.uint8(
                            (1 - s / patch_size) * (1 - t / patch_size) * new_patch1[s, t] + (1 - s / patch_size) * (
                                    t / patch_size) * new_patch1[s, t] + (s / patch_size) * (1 - t / patch_size) *
                            new_patch3[s, t] + (s / patch_size) * (t / patch_size) * new_patch3[s, t])
                new_patches.append(new_patch)
                continue



            # 如果不是边上的一小块，就要用周围四块做加权
            b_ctf1 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx])
            g_ctf1 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx])
            r_ctf1 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx])
            new_patch1 = np.zeros(apatch.shape, dtype=np.uint8)
            new_patch1[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf1)
            new_patch1[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf1)
            new_patch1[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf1)

            b_ctf2 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx+1])
            g_ctf2 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx+1])
            r_ctf2 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx+1])
            new_patch2 = np.zeros(apatch.shape, dtype=np.uint8)
            new_patch2[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf2)
            new_patch2[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf2)
            new_patch2[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf2)

            b_ctf3 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx+ math.ceil(cols / patch_size )])
            g_ctf3 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx+ math.ceil(cols / patch_size )])
            r_ctf3 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx+ math.ceil(cols / patch_size )])
            new_patch3 = np.zeros(apatch.shape, dtype=np.uint8)
            new_patch3[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf3)
            new_patch3[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf3)
            new_patch3[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf3)

            b_ctf4 = ctf(apatch[:, :, 0], alpha, b_trans_functions[patch_idx + math.ceil(cols / patch_size)+1])
            g_ctf4 = ctf(apatch[:, :, 1], alpha, g_trans_functions[patch_idx + math.ceil(cols / patch_size)+1])
            r_ctf4 = ctf(apatch[:, :, 2], alpha, r_trans_functions[patch_idx + math.ceil(cols / patch_size)+1])
            new_patch4 = np.zeros(apatch.shape, dtype=np.uint8)
            new_patch4[:, :, 0] = ctf_tranfer(apatch[:, :, 0], b_ctf4)
            new_patch4[:, :, 1] = ctf_tranfer(apatch[:, :, 1], g_ctf4)
            new_patch4[:, :, 2] = ctf_tranfer(apatch[:, :, 2], r_ctf4)

            new_patch = np.zeros(apatch.shape, dtype=np.uint8)
            # for(s,t) in this patch,we want to do bilinear interpolation
            for s in range(patch_size):
                for t in range(patch_size):
                    new_patch[s,t] = np.uint8((1-s/patch_size)*(1-t/patch_size)*new_patch1[s,t] + (1-s/patch_size)*(t/patch_size)*new_patch2[s,t] + (s/patch_size)*(1-t/patch_size)*new_patch3[s,t] + (s/patch_size)*(t/patch_size)*new_patch4[s,t])


            #newpatch = np.uint8(new_patch1/4 + new_patch2/4 + new_patch3/4 + new_patch4/4)
            new_patches.append(new_patch)

    # print(new_patches)
    # 将所有的patch拼接起来
    img_corrected = np.zeros((rows, cols, channels), dtype=np.uint8)
    for i in range(0, rows, patch_size):
        for j in range(0, cols, patch_size):
            patch_idx = (i // patch_size) * (math.ceil(cols / patch_size ) )+ j // patch_size
            img_corrected[i:i + patch_size, j:j + patch_size] = new_patches[patch_idx]


    # 显示图像
    #bgr2rgb
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    img_corrected = cv2.cvtColor(img_corrected, cv2.COLOR_BGR2RGB)
    # 设置大小
    plt.figure(figsize=(10, 10))
    # 显示原图
    plt.subplot(1, 2, 1)
    plt.title('Original Image')
    plt.imshow(img)
    # 显示直方图均衡化后的图像
    plt.subplot(1, 2, 2)
    plt.title('Corrected Image')
    plt.imshow(img_corrected)
    plt.show()
    #
    # cv2.imshow('Original Image', img)
    # cv2.imshow('Corrected Image', img_corrected)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()