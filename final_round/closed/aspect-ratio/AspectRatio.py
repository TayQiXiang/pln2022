import math
from typing import Final

aspect_ratio_list: Final = ['1:1', '3:2', '4:3', '16:9', '16:10']


def check_aspect_ratio(resolution):
    resolution_arr = list(map(int, resolution.split("x")))
    HCF_result = HCF(resolution_arr[0], resolution_arr[1])
    width = int(math.floor(resolution_arr[0]/HCF_result))
    height = int(math.floor(resolution_arr[1]/HCF_result))

    actual_width = max(height, width)
    actual_height = min(height, width)

    aspect_ratio_result = str(actual_width) + ":" + str(actual_height)
    result = ''
    for i in aspect_ratio_list:
        if aspect_ratio_result == '8:5':
            result = aspect_ratio_list[-1]
            break

        if aspect_ratio_result == i:
            result = i
            break
        else:
            result = 'No'

    print(result)


def HCF(num1, num2):
    if num2 == 0:
        return num1

    return HCF(num2, num1%num2)

num = int(input())

for i in range(num):
    resolution = input()
    check_aspect_ratio(resolution)





