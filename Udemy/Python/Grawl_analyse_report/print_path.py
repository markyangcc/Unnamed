import os

g = os.walk(r'/home/mark/Documents/Code-insider/Python/reports')

for path, dicrt, files in g:
    for file_name in files:
        full_path = os.path.join(path, file_name)
        print(full_path)
