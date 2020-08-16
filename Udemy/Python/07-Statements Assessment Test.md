# Statements Assessment Test
Let's test your knowledge!

_____
**Use <code>for</code>, .split(), and <code>if</code> to create a Statement that will print out words that start with 's':**


```python
st = 'Print only the words that start with s in this sentence'
```


```python
#Code here
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
        print('{} FizzBuzz'.format(i))
        continue
    if i%3 == 0:
        print('{} Fizz'.format(i))
        continue
    if i%5 == 0:
         print('{} Buzz'.format(i))
```

    3 Fizz
    5 Buzz
    6 Fizz
    9 Fizz
    10 Buzz
    12 Fizz
    15 FizzBuzz
    18 Fizz
    20 Buzz
    21 Fizz
    24 Fizz
    25 Buzz
    27 Fizz
    30 FizzBuzz
    33 Fizz
    35 Buzz
    36 Fizz
    39 Fizz
    40 Buzz
    42 Fizz
    45 FizzBuzz
    48 Fizz
    50 Buzz
    51 Fizz
    54 Fizz
    55 Buzz
    57 Fizz
    60 FizzBuzz
    63 Fizz
    65 Buzz
    66 Fizz
    69 Fizz
    70 Buzz
    72 Fizz
    75 FizzBuzz
    78 Fizz
    80 Buzz
    81 Fizz
    84 Fizz
    85 Buzz
    87 Fizz
    90 FizzBuzz
    93 Fizz
    95 Buzz
    96 Fizz
    99 Fizz
    100 Buzz


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
