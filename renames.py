import os
import re

path = 'E:\\feng\\lc\\'
files = os.listdir(path)

s = r'^\d'
for f in files:
    if re.match(s, f):#合法
        pass
       # print(f)
    # f不合法
    else:
        t = f.replace('_', ' ')

        titles = open(r'C:\Users\Feng\PycharmProjects\hello\problems.txt', 'r', encoding='utf-8',errors='ignore')
        number = '0'
        for name in titles:
            name = name.strip().lower()
            if t == (name + '.cpp'):  # 找到
                os.rename(path + f, path + number + '_' + f)
                print(f)

                break
            number = name
        titles.close()

        # os.rename(os.path.join(path, t), os.path.join(path, f))
        #print(f)






