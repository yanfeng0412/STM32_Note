from PIL import Image
import os

# 设置bmp文件夹路径
bmp_dir = './twconv3'

# 获取bmp文件夹下的所有bmp文件名
bmp_files = [f for f in os.listdir(bmp_dir) if f.endswith('.bmp')]

# 设置OLED显示区域的宽和高（像素）
oled_width = 128
oled_height = 64

# 设置字模宽度和高度（像素）
font_width = 8
font_height = 16

# 循环遍历所有bmp文件
for bmp_file in bmp_files:
    # 打开bmp文件并将其转换为OLED显示区域大小的图像
    bmp_path = os.path.join(bmp_dir, bmp_file)
    img = Image.open(bmp_path)
    img = img.resize((oled_width, oled_height))

    # 创建一个空的字模列表
    font_data = []

    # 将图像转换为16进制字模数据
    for y in range(0, oled_height, font_height):
        for x in range(0, oled_width, font_width):
            # 创建一个新的字模，并将其初始化为0
            font = [0] * font_height

            # 遍历字模的每一行像素，将其转换为二进制，并存储到字模中
            for i in range(font_height):
                for j in range(font_width):
                    px = img.getpixel((x + j, y + i))
                    if sum(px) < 384:  # 如果像素的亮度低于384（即RGB值之和小于128），则将其视为黑色像素
                        font[i] |= 1 << (font_width - j - 1)

            # 将字模转换为16进制数据，并将其添加到字模列表中
            font_hex = ['{:02X}'.format(row) for row in font]
            font_data.append(','.join(font_hex))

    # 将字模数据写入hex文件
    font_file = os.path.splitext(bmp_file)[0] + '.hex'
    with open(font_file, 'w') as f:
        f.write('\n'.join(font_data))
    print(f"Converted {bmp_file} to {font_file}")
