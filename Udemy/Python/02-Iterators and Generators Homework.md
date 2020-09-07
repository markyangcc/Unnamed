# Iterators and Generators Homework 

### Problem 1

Create a generator that generates the squares of numbers up to some number N.


```python
def gensquares(N):
    
    for num in range(N):
        yield num**2
    
```


```python
for x in gensquares(10):
    print(x)
```

    0
    1
    4
    9
    16
    25
    36
    49
    64
    81


### Problem 2

Create a generator that yields "n" random numbers between a low and high number (that are inputs). <br>Note: Use the random library. For example:


```python
import random

random.randint(1,10)
```




    9




```python
def rand_num(low,high,n):

    for num in range(n):
        yield random.randint(low,high)
```


```python
for num in rand_num(1,10,12):
    print(num)
```

    4
    4
    1
    3
    7
    6
    6
    3
    6
    10
    3
    1


### Problem 3

Use the iter() function to convert the string below into an iterator:



```python
s = 'hello'

#code here
y = iter(s)

# Drive Code here

print(next(y))
print(next(y))
print(next(y))
print(next(y))
print(next(y))

```

    h
    e
    l
    l
    o


### Problem 4
Explain a use case for a generator using a yield statement where you would not want to use a normal function with a return statement.



### Extra Credit!
Can you explain what *gencomp* is in the code below? (Note: We never covered this in lecture! You will have to do some Googling/Stack Overflowing!)


```python
my_list = [1,2,3,4,5]

gencomp = (item for item in my_list if item > 3)

for item in gencomp:
    print(item)
```

    4
    5


Hint: Google *generator comprehension*!

# Great Job!
