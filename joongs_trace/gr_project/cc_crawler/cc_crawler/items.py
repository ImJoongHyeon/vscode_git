# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class CcCrawlerItem(scrapy.Item):
    title = scrapy.Field()
    location = scrapy.Field()
    start_day = scrapy.Field()
    end_day = scrapy.Field()
    pass
