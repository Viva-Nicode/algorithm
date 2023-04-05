import os
import sys
import urllib.request
from selenium import webdriver
client_id = "FSVA686XU5QtPu1fj340"
client_secret = "eP_ItYrn60"
encText = urllib.parse.quote("wastepaper")
url = "https://openapi.naver.com/v1/search/image?query=" + encText # JSON 결과
# url = "https://openapi.naver.com/v1/search/blog.xml?query=" + encText # XML 결과
request = urllib.request.Request(url)
request.add_header("X-Naver-Client-Id",client_id)
request.add_header("X-Naver-Client-Secret",client_secret)
response = urllib.request.urlopen(request)
rescode = response.getcode()
if(rescode==200):
    response_body = response.read()
    print(response_body.decode('utf-8'))
else:
    print("Error Code:" + rescode)

driver = webdriver.Chrome("./chromedriver")
driver.get("https:\/\/static.zarahome.net\/8\/photos4\/2022\/V\/4\/1\/p\/9595\/743\/733\/9595743733_2_1_2.jpg?t=1636964059239")
driver.implicitly_wait(20)
driver.quit()
