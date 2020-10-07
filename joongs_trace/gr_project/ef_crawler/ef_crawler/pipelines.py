# -*- coding: utf-8 -*-

from scrapy.exceptions import DropItem
import MySQLdb

class ValidationPipeline(object):
    def process_item(self, item, spider):
        if not item['name']:
            raise DropItem('Missing Title')
        return item



class MySQLPipeline(object):
    def open_spider(self, spider):
        settings = spider.settings
        params = {
            'host' : settings.get('MYSQL_HOST', 'localhost'),
            'db' : settings.get('MYSQL_DATABASE', 'ef_db'),
            'user' : settings.get('MYSQL_USER', 'joongh0113'),
            'passwd': settings.get('MYSQL_PASSWORD', 'Wndgus2023!@'),
            'charset': settings.get('MYSQL_CHARSET', 'utf8mb4'),
        }
        self.conn = MySQLdb.connect(**params)
        self.c = self.conn.cursor()
        self.c.execute('''
            CREATE TABLE IF NOT EXISTS ef_tb(
                name CHAR(100) NOT NULL,
                location CHAR(100) NOT NULL,
                start_day CHAR(20),
                end_day CHAR(20),
                PRIMARY KEY(name, location));
        ''')
        self.conn.commit()

    def close_spider(self, spider):
        self.conn.close()

    def process_item(self, item, spider):
        self.c.execute('INSERT INTO ef_tb (name, location, start_day, end_day) VALUES (%(name)s, %(location)s ,%(start_day)s, %(end_day)s)', dict(item))
        self.conn.commit()
        return item

