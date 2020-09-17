# 将8位字符串转化为 year-month-day

def convent_date(st):

    year = st[0:4]
    month = st[4:6]
    day = st[6:8]

    return year, month, day


st = input("Enter a 8 lengthstring like '20200907': ")

year, month, day = convent_date(st)

print(f'The year is {year}\n\
The month is {month}\n\
The day is {day}')
