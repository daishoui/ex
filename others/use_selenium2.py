from selenium import webdriver
import selenium
import time


# JD
options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-automation'])
browser = webdriver.Chrome(options=options, executable_path='/home/z/Downloads/chromedriver')
urls = ['https://item.jd.com/100007259554.html', 'https://item.jd.com/100004224963.html']

# for url in urls:
browser.get(urls[0])
for i in range(1, 15):
    #print(i)
    try:
        table = browser.find_element_by_xpath('//*[@id="choose-attr-1"]/div[2]/div[{}]'.format(i))
        table.click()
        #all_pages = browser.window_handles  # 获得所有窗口句柄
        #browser.switch_to.window(all_pages[-1])  # 切换至最后一个窗口
        table = browser.find_element_by_xpath('//*[@id="choose-attr-1"]/div[2]/div[{}]'.format(i))
        print(browser.find_element_by_xpath('/html/body/div[6]/div/div[2]/div[4]/div/div[1]/div[2]/span[1]/span[2]').text)
        print(table.get_attribute('title'))
    except selenium.common.exceptions.NoSuchElementException:
        break
