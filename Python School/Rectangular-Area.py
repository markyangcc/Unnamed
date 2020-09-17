# Define function
def rect_area(length, width):

    return length * width


# Get input
st = input(
    "Enter length and width of rectangular, so I will calc the area(space as delimiter): ")

x, y = st.split()

# Type conversion
x = float(x)
y = float(y)

# call func and print result
area = rect_area(x, y)
print(f"The area of rectangular is {area}")
