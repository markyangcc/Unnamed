from turtle import Screen, Turtle

screen = Screen()
turtle = Turtle()

# Set up pensize, pencolor, fillcolor
turtle.pensize(0.1)
turtle.pencolor("red")
turtle.fillcolor("red")

# Begin to fill color
turtle.begin_fill()

for _ in range(5):
    # set forward step
    turtle.forward(180)

    # set degree
    turtle.right(144)

# End up filling color
turtle.end_fill()

screen.mainloop()
