# 编写Python程序实现功能：从键盘输入若干同学的姓名，保存在字符串列表中。输入某个同学的名字，检索是否已保存列表中

def store_name(name_str):

    name_list = []
    name_list = name_str.split()

    return name_list


def get_name():

    x = input("Enter some sts' names: ")

    return x


def find_name(provided_name, name_list):

    for item in name_list:
        if (item == provided_name):
            return True
        elif item.lower() == provided_name.lower():
            return "Some_Hint"

    # default return False
    return False


# Get students names, type str
name_str = get_name()

# Store students names, type splited str
name_list = store_name(name_str)
print(name_list)

# Find students name
provided_name = input("Who do you want to find? Enter name here: ")
result = find_name(provided_name, name_list)

# print statements
if result == True:
    print("We found him/her!")
elif result == False:
    print("Sorry, we didn't found him/her, maybe you enter the wrong name.")
elif result == "Some_Hint":
    print("Yes, we found him/her name in lowercase.You may consider the lowercase and uppercase of names.")
else:
    print("Function Error.")
