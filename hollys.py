import urllib.request
from selenium import webdriver

url = 'https://www.op.gg/summoners/kr/%EC%A0%80%EB%A7%90%EA%B3%A0%EB%8F%84%EA%B5%AC%EB%95%8C%EB%A0%A4%EC%9A%94'
#content-container > div.css-150oaqg.e1shm8tx0 > div.css-164r41r.e1r5v5160 > li:nth-child(1)

driver = webdriver.Chrome("./chromedriver")
driver.get(url)
driver.implicitly_wait(20)
driver.quit()

