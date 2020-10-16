import os
import requests
from bs4 import BeautifulSoup

for year in range(2014, 2020+1):

    # Request web pages
    res = requests.get(f'http://www.gov.cn/guowuyuan/{year}zfgzbg.htm')
    res.encoding = 'utf-8'
    soup = BeautifulSoup(res.text, 'lxml')

    # Select the text
    text = soup.select('.conlun2_box_text')

    # Create new dictionary in current dictionary
    current_directory = os.getcwd()
    final_directory = os.path.join(current_directory, r'reports')
    if not os.path.exists(final_directory):
        os.makedirs(final_directory)

    # Save to files
    with open(f'{final_directory}/{year}_gov_report.txt', 'w') as f:
        f.write(str(text))


# 历年工作报告存档 https://web.archive.org/web/20170831162744/http://www.gov.cn/guoqing/2006-02/16/content_2616810.htm
# 2017 正文 http://www.gov.cn/premier/2017-03/16/content_5177940.htm
# 2016 正文 http://www.gov.cn/guowuyuan/2016-03/05/content_5049372.htm
# 2010 正文 http://www.gov.cn/2010lh/content_1555767.htm
