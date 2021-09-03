# !/usr/bin/env python
# -*- coding:utf-8 -*-

import argparse
import cv2
import numpy as np

def color_encode(color):
    if color == 'red':
        return (0,0,255)
    elif color == 'blue':
        return (255,0,0)
    elif color == 'green':
        return (0,255,0)
    elif color == 'yellow':
        return (0,255,255)
    elif color == 'black':
        return (0,0,0)
    else:
        return (255,255,255)

def main():
    parser = argparse.ArgumentParser(epilog="example to use: python3 -picture_path picture_path.jpg -to_color red")
    parser.add_argument('-picture_path')
    parser.add_argument('-to_color', choices=['white', 'blue','red','black','yellow','green'], default='white')
    parser.add_argument('-save_path', default='change_bg_color.png')
    parser.add_argument('-erode_num',type=int, default=2, help='腐蚀迭代次数 默认值 2')
    parser.add_argument('-dilate_num',type=int, default=3, help='膨胀迭代次数 默认值 3')
    
    opt = parser.parse_args()
    
    if opt.picture_path == None:
        parser.print_help()
        exit(1)
    
    to_color = color_encode(opt.to_color)
    # step1:读取照片
    img = cv2.imread(opt.picture_path)

    # step1.2:缩放图片()
    img = cv2.resize(img, None, fx=1.5, fy=1.5)
    rows, cols, channels = img.shape
    # 展示图片
    #cv2.imshow("original...", img)

    # step2.1 图片转换为灰度图并显示
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # :图片的二值化处理
    # 将在两个阈值内的像素值设置为白色（255），
    # 而不在阈值区间内的像素值设置为黑色（0）

    lower_red = np.array([0, 125, 125])
    upper_red = np.array([255, 255, 255])
    mask = cv2.inRange(hsv, lower_red, upper_red)

    # step2.3:腐蚀膨胀 若是腐蚀膨胀后仍有白色噪点，可以增加iterations的值
    erode = cv2.erode(mask, None, iterations=opt.erode_num)
    # cv2.imshow('erode', erode)
    dilate = cv2.dilate(erode, None, iterations=opt.dilate_num)

    # step3遍历每个像素点，进行颜色的替换
    for i in range(rows):
        for j in range(cols):
            if dilate[i, j] == 255:  # 像素点255表示白色,180为灰度
                img[i, j] = to_color  # 此处替换颜色，为BGR通道，不是RGB通道

    # step4 保存图片
    cv2.imwrite(opt.save_path, img)
    
    #res = cv2.imread(opt.save_path)
    #cv2.imshow('result...', res)
    # 窗口等待的命令，0表示无限等待
    #cv2.waitKey(0)


if __name__ == '__main__':
    main()
