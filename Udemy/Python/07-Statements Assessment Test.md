# Statements Assessment Test
Let's test your knowledge!

_____
**Use <code>for</code>, .split(), and <code>if</code> to create a Statement that will print out words that start with 's':**


```python
st = 'Print only the words that start with s in this sentence'
```


```python
#Code here
#Use lowercase() if need
for i in st.split():
    if i.startswith('s'):
        print(i)  
```

    start
    s
    sentence


______
**Use range() to print all the even numbers from 0 to 10.**


```python
#Code Here
for i in range(0,10):
    if i%2 != 0:
        print(i)
```

    1
    3
    5
    7
    9


___
**Use a List Comprehension to create a list of all numbers between 1 and 50 that are divisible by 3.**


```python
#Code in this cell
mylist = []
for i in range(1,50):
    if i%3 == 0:
        mylist.append(i)
mylist
```




    [3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48]



____
**Go through the string below and if the length of a word is even print "even!"**


```python
st = 'Print every word in this sentence that has an even number of letters'
```


```python
#Code in this cell
splitedlist = st.split()
for word in splitedlist:
    if len(word)%2 == 0:
        print("{}      \t'even!'" .format(word))
```

    word      	'even!'
    in      	'even!'
    this      	'even!'
    sentence      	'even!'
    that      	'even!'
    an      	'even!'
    even      	'even!'
    number      	'even!'
    of      	'even!'


____
**Write a program that prints the integers from 1 to 100. But for multiples of three print "Fizz" instead of the number, and for the multiples of five print "Buzz". For numbers which are multiples of both three and five print "FizzBuzz".**


```python
#Code in this cell
for i in range(1,101):
    if i%15 == 0:
        print('FizzBuzz')
    elif i%3 == 0:
        print('Fizz')
        continue
    elif i%5 == 0:
         print('Buzz')
    else:
         print('{}'.format(i))
```

    1
    2
    Fizz
    4
    Buzz
    Fizz
    7
    8
    Fizz
    Buzz
    11
    Fizz
    13
    14
    FizzBuzz
    16
    17
    Fizz
    19
    Buzz
    Fizz
    22
    23
    Fizz
    Buzz
    26
    Fizz
    28
    29
    FizzBuzz
    31
    32
    Fizz
    34
    Buzz
    Fizz
    37
    38
    Fizz
    Buzz
    41
    Fizz
    43
    44
    FizzBuzz
    46
    47
    Fizz
    49
    Buzz
    Fizz
    52
    53
    Fizz
    Buzz
    56
    Fizz
    58
    59
    FizzBuzz
    61
    62
    Fizz
    64
    Buzz
    Fizz
    67
    68
    Fizz
    Buzz
    71
    Fizz
    73
    74
    FizzBuzz
    76
    77
    Fizz
    79
    Buzz
    Fizz
    82
    83
    Fizz
    Buzz
    86
    Fizz
    88
    89
    FizzBuzz
    91
    92
    Fizz
    94
    Buzz
    Fizz
    97
    98
    Fizz
    Buzz


____
**Use List Comprehension to create a list of the first letters of every word in the string below:**


```python
st = 'Create a list of the first letters of every word in this string'
```


```python
#Code in this cell
[i[0] for i in st.split()]
```




    ['C', 'a', 'l', 'o', 't', 'f', 'l', 'o', 'e', 'w', 'i', 't', 's']



### Great Job!
