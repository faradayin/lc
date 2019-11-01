import os
import re
path = 'E:\\feng\\lc'
files = os.listdir(path);

s = r'\d*'
for f in files:
    if re.match(s, f):
        print(f)
    else:
        t = f
        f.replace('_', ' ')
        titles = open('C:\\Users\\Feng\\Desktop\\problems.txt')
        line = titles.readline()
        while True:
            last = line
            line = titles.readline()
            if f == (line+'.cpp'):
                f = last + f
                #print(f)
                break
            if len(line)==0: 
                break
        titles.close()
        #os.rename(os.path.join(path, t), os.path.join(path, f))
        print(f)
        
                
            
            
            

