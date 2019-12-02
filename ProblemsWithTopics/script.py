import requests
from bs4 import BeautifulSoup
import csv

link = "https://codeforces.com/blog/entry/55274"
req = requests.get(link)
soup = BeautifulSoup(req.content, 'html5lib')
required = soup.find('div', attrs={'class': 'ttypography'})
ultra_req = required.find_all('div', attrs={'class': 'spoiler'})

filename = 'problemsOnVariousTypes.csv'
problem_list = []
p = 1
with open(filename, 'w') as f:
    w = csv.DictWriter(f, ['Problem_number', 'Catogery', 'Problem_details'])
    w.writeheader()
    for row in ultra_req:
        cat_type = row.find('b', attrs={'class': 'spoiler-title'})
        problems = row.find('div', attrs={'class': 'spoiler-content'})
        problems = row.find_all('p')
        for problem in problems:
            push = {}
            push['Problem_number'] = p
            push['Catogery'] = cat_type.text
            push['Problem_details'] = problem.text
            w.writerow(push)
            p = p + 1
