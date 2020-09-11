# Spreadsheets Puzzle Exercise

You will need to work with two files for this exercise and solve the following tasks:

Task: Use Python to extract the Google Drive link from the .csv file. (Hint: Its along the diagonal from top left to bottom right).


```python
import csv

with open('Exercise_Files\\find_the_link.csv') as f:
    f_csv = csv.reader(f)

    link_str = ''
    for counter, item in enumerate(f_csv):
        link_str += item[counter]

    print(link_str)
```

```txt
# Output
https://drive.google.com/open?id=1G6SEgg018UB4_4xsAJJ5TdzrhmXipr4Q
```


