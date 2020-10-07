# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


from scrapy.exceptions import DropItem
import MySQLdb




class ValidationPipeline(object):
    def process_item(self, item, spider):
        if not item['title']:
            raise DropItem('Missing title')
        return item

class MySQLPipeline(object):
    def open_spider(self, spider):
        settings = spider.settings
        params = {
                'host' : settings.get('MYSQL_HOST', 'localhost'),
                'db' : settings.get('MYSQL_DATABASE', 'tt_db'),
                'user' : settings.get('MYSQL_USER', 'joongh0113'),
                'passwd': settings.get('MYSQL_PASSWORD', 'Wndgus2023!@'),
                'charset': settings.get('MYSQL_CHARSET', 'utf8mb4'),
        }

        self.conn = MySQLdb.connect(**params)
        self.c = self.conn.cursor()
        self.c.execute('''
            CREATE TABLE IF NOT EXISTS tt_tb(
                title CHAR(200) NOT NULL,
                location CHAR(200) NOT NULL,
                start_day CHAR (30),
                end_day CHAR (30),
                PRIMARY KEY(title, location));
        ''')
        self.conn.commit()

    def close_spider(self, spider):
        self.conn.close()

    def process_item(self, item, spider):
        self.c.execute('INSERT INTO tt_tb (title, location, start_day, end_day) VALUES (%(title)s, %(location)s, %(start_day)s, %(end_day)s)', dict(item))
        self.conn.commit()
        return item
