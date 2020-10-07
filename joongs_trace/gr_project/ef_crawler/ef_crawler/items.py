import scrapy

class EfCrawlerItem(scrapy.Item):
    name = scrapy.Field()
    location = scrapy.Field()
    start_day = scrapy.Field()
    end_day = scrapy.Field()
