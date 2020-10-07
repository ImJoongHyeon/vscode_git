# -*- coding: utf-8 -*-
import scrapy
from tt_crawler.items import TtCrawlerItem
from scrapy.spiders import CrawlSpider, Rule, Spider
from scrapy.linkextractors import LinkExtractor
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from scrapy.selector import Selector


options = webdriver.ChromeOptions()
options.add_argument('headless')
options.add_argument('window-size=1920x1080')
options.add_argument("disable-gpu")

driver = webdriver.Chrome('/usr/bin/chromedriver', chrome_options=options)

class TheaterSpider(scrapy.Spider):
    name = 'theater'
    allowed_domains = ['ticket.yes24.com']
    start_urls = ['http://ticket.yes24.com/New/Genre/GenreList.aspx?genretype=1&genre=15458']




    def parse(self, response):
        driver.get(response.url)
        time.sleep(5)

        last_height = driver.execute_script("return document.body.scrollHeight")

        while True:
            driver.find_element_by_tag_name('body').send_keys(Keys.END)
            time.sleep(0.5)
            new_height = driver.execute_script("return document.body.scrollHeight")
            if new_height == last_height:
                break
            last_height = new_height



        html = driver.find_element_by_xpath('//*').get_attribute('outerHTML')
        time.sleep(5)
        selector = Selector(text=html)

        title = selector.xpath('/html/body/section/div/a/div/div/p[1]/text()').extract()
        location = selector.xpath('/html/body/section/div/a/div/div/p[3]/text()').extract()
        date = selector.xpath('/html/body/section/div/a/div/div/p[2]/text()').extract()

        for item in zip(title, location, date):
            temp = item[2].strip()
            start_day, end_day = temp.split(' ~ ')
            scraped_info = {
                    'title' : item[0].strip(),
                    'location' : item[1].strip(),
                    'start_day' : start_day,
                    'end_day' : end_day
            }
            yield scraped_info
        driver.close()
