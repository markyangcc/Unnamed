import jieba
from wordcloud import WordCloud

# 排除词列表，剔除无效词语
excludes = {"div", "h5", "class", "h4", "h3",
            "h2", "h1", "conlun2_box_text", "p", "id"}
# 以只读模式打开刚爬取的txt文档
f = open('/home/mark/Documents/Code-insider/Unnamed/Udemy/Python/Grawl_analyse_report/reports/2014_gov_report.txt', 'r', encoding='utf-8')
txt = f.read()
f.close()

words = jieba.lcut(txt)  # 使用精确分词模式进行分词
newtxt = ''.join(words)  # 利用空格连接精确分词后的词语
# 对词云图参数进行设置,以newtxt文本生成词云
wordcloud = WordCloud(background_color="white",  # 设置图片背景颜色
                      width=800,  # 设置图片宽度
                      height=600,  # 设置图片高度
                      # 指定字体文件的完整路径，如果不设置可能显示不了中文
                      font_path="/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc",
                      max_words=100,  # 词云中最大词数
                      max_font_size=80,  # 词云中最大的字体号数
                      stopwords=excludes,  # 被排除的词列表
                      ).generate(newtxt)
wordcloud.to_file('Wordcloud_Analysis.png')
