# 编写Python程序实现功能：使用字典记录同学的姓名及对应身高，输入任意同学的姓名，查找并显示所有高于此身高的同学信息

height = {"Mike": 170, "Cook": 175, "Pony": 180,
          "Jack": 168, "Lily": 165, "Amy": 156, "Mary": 182}


# find studnet height
def find_height(name, height):

    # create a empty dict
    higher_stu = {}

    for key in height:
        if height[key] > height[name]:
            higher_stu.update({key: height[key]})

    return higher_stu


# Get user input
ss_name = input("Enter the student's name to get the height: ")

result = find_height(ss_name, height)

print(f"\nThese students' height is higher than {ss_name}")
print(result)
