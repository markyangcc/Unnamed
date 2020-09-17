# 编写程序，输入两个集合setA和seta，分别输出它们的交集、并集和差集(set_A - set_a)。

x = input("Enter set A: ")
y = input("Enter set a: ")

# Maping str to int
set_A = set(map(int, x.split()))
set_a = set(map(int, y.split()))

# Calc intersection, union, subtraction
set_intersection = set_A.intersection(set_a)
set_union = set_A.union(set_a)
set_subtraction = set_A - set_a

# Print results
print("\n")
print(f'Intersection:\t\t{set_intersection}\n\
Union:\t\t\t{set_union}\n\
Subtraction(A-a):\t{set_subtraction}')
