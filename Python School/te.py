dic = {"a": 160, "b": 170, "c": 180, "d": 190}  # 构造一个字典,键为名字，值为其身高
check = input("输入任意同学的姓名:")
for key in dic.keys():
    if dic[key] > dic[check]:
        print("姓名"+key+",身高"+str(dic[key]))  # 显示的是目标同学的全部信息。
