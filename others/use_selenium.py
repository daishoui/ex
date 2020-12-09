#-*- coding:utf-8 -*-
from selenium import webdriver
import selenium 
import time
import random

browser = webdriver.Chrome('/home/z/Downloads/chromedriver')

browser.get('http://www.sse.com.cn/disclosure/credibility/supervision/measures/')
i = 1
outlines = []
while i <= 169:
    flag = True
    while flag:
        try:
            ht_input = browser.find_element_by_id('ht_codeinput')
            btn_more = browser.find_element_by_id('pagebutton')
            flag = False
        except selenium.common.exceptions.NoSuchElementException:
            time.sleep(random.randint(1,3))
    ht_input.clear()
    ht_input.send_keys(str(i))
    btn_more.click()
    flag = True
    while flag:
        try:
            table = browser.find_element_by_id('panel-1')
            lines = table.find_elements_by_tag_name('tr')
            for j in range(1,len(lines)):
                print(lines[j].text)
                outlines.append(lines[j].text)
            flag = False
        except selenium.common.exceptions.NoSuchElementException:
            time.sleep(random.randint(1,3))
        except selenium.common.exceptions.StaleElementReferenceException:
            time.sleep(random.randint(1,3))
    i += 1
    print(i)

#browser.quit()

with open('out.txt','w') as f:
    for line in outlines:
        f.write(line + '\n')
