from PIL import Image
import os

merged_Dir = "/Users/nicode./Desktop/MergedDataSet/cardboard/"
resized_Dir = "/Users/nicode./Desktop/ResizedDataSet/cardboard/"
categori_name = 'cardboard'
count = 1

files = os.listdir(merged_Dir)

for filename in files:
    img = Image.open(merged_Dir + filename)
    resized_img = img.resize((224, 224))
    #resized_img = resized_img.convert("RGB")
    resized_img.save(resized_Dir + categori_name + str(count) + '.jpg')
    count += 1

# for file_name in files:
#     os.rename(dir_path + '/' + file_name, dir_path+'/' +)

# img = Image.open('/Users/nicode./Desktop/plastic1.jpg')

# new_img = img.resize((256,256))
# new_img.save('/Users/nicode./Desktop/new_plastic1.jpg')


# dir_path = '/Users/nicode./Desktop/temp'
# files = os.listdir(dir_path)

# count = 892

# for old_name in files:
#     # 파일 이름 변경
#     new_name = 'cardboard' + str(count) + '.jpg'
#     os.rename(os.path.join(dir_path, old_name), os.path.join(dir_path, new_name))
#     count += 1
