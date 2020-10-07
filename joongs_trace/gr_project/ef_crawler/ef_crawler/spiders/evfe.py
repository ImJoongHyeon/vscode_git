import re
import scrapy
from scrapy.spiders import CrawlSpider, Rule
from scrapy.linkextractors import LinkExtractor
from ef_crawler.items import EfCrawlerItem 


class EvfeSpider(CrawlSpider):
    name = 'evfe'
    allowed_domains = ["gep.or.kr"]
    start_urls = ['http://www.gep.or.kr/domestic-exhibition/exhibitions?pageIndex=1']
    
    rules = [
            Rule(LinkExtractor(allow=r'/exhibitions\?pageIndex=[1-25]'), callback='parse_item', follow = True)
    ]
    
    def parse_item(self, response):
        name = response.xpath('//*[@id="print_container"]/form[1]/div[5]/table/tbody/tr/td[2]/a/text()').extract()
        location = response.xpath('//*[@id="print_container"]/form[1]/div[5]/table/tbody/tr/td[4]/text()').extract()
        date = response.xpath('//*[@id="print_container"]/form[1]/div[5]/table/tbody/tr/td[3]/p/text()').extract()

        for item in zip(name, date, location):
            temp = item[2].strip()
            start_day, end_day = temp.split(' ~ ')

            x = start_day.split('-')
            if(int(x[0]) < 2019):
               continue 
            scraped_info = {
                'name' : item[0].strip(),
                'location' : item[1].strip(),
                'start_day' : start_day,
                'end_day' : end_day,
            }
            yield scraped_info
