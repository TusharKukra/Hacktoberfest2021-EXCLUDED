import turtle

def paint_board(i, j):
    turtle.ondrag(None)
    turtle.setheading(turtle.towards(i, j))
    turtle.goto(i, j)
    turtle.ondrag(paint_board)

turtle.speed(10)

sc = turtle.Screen()
sc.setup(600, 600)

turtle.ondrag(paint_board)

sc.mainloop()
