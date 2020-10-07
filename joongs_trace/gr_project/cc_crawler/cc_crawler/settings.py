# -*- coding: utf-8 -*-

# Scrapy settings for cc_crawler project
#
# For simplicity, this file contains only settings considered important or
# commonly used. You can find more settings consulting the documentation:
#
#     https://docs.scrapy.org/en/latest/topics/settings.html
#     https://docs.scrapy.org/en/latest/topics/downloader-middleware.html
#     https://docs.scrapy.org/en/latest/topics/spider-middleware.html

BOT_NAME = 'cc_crawler'

SPIDER_MODULES = ['cc_crawler.spiders']
NEWSPIDER_MODULE = 'cc_crawler.spiders'


# Crawl responsibly by identifying yourself (and your website) on the user-agent
#USER_AGENT = 'cc_crawler (+http://www.yourdomain.com)'

# Obey robots.txt rules
ROBOTSTXT_OBEY = False 
FEED_EXPORT_ENCODING = 'utf-8'
# Configure maximum concurrent requests performed by Scrapy (default: 16)
#CONCURRENT_REQUESTS = 32

# Configure a delay for requests for the same website (default: 0)
# See https://docs.scrapy.org/en/latest/topics/settings.html#download-delay
# See also autothrottle settings and docs
DOWNLOAD_DELAY = 3
# The download delay setting will honor only one of:
#CONCURRENT_REQUESTS_PER_DOMAIN = 16
#CONCURRENT_REQUESTS_PER_IP = 16

# Disable cookies (enabled by default)
#COOKIES_ENABLED = False

# Disable Telnet Console (enabled by default)
#TELNETCONSOLE_ENABLED = False

# Override the default request headers:
#DEFAULT_REQUEST_HEADERS = {
#   'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
#   'Accept-Language': 'en',
#}

# Enable or disable spider middlewares
# See https://docs.scrapy.org/en/latest/topics/spider-middleware.html
#SPLASH_URL = 'http://localhost:8050/'

SPIDER_MIDDLEWARES = {
#      'scrapy_splash.SplashDeduplicateArgsMiddleware': 100,
    'cc_crawler.middlewares.CcCrawlerSpiderMiddleware': 543,
    
}

# Enable or disable downloader middlewares
# See https://docs.scrapy.org/en/latest/topics/downloader-middleware.html
DOWNLOADER_MIDDLEWARES = {
#        'scrapy_splash.SplashCookiesMiddleware' : 723,
#        'scrapy_splash.SplashMiddleware' : 725
#    'scrapy.downloadermiddlewares.httpcompression.HttpCompressionMiddleware' : 810,
    'cc_crawler.middlewares.CcCrawlerDownloaderMiddleware': 543,
}

#DUPEFILTER_CLASS = 'scrapy_splash.SplashAwareDupeFilter'
#HTTPCACHE_STORAGE = 'scrapy_splash.SplashAwareFSCacheStorage'
#SPLASH_COOKIES_DEBUG = True
# Enable or disable extensions
# See https://docs.scrapy.org/en/latest/topics/extensions.html
#EXTENSIONS = {
#    'scrapy.extensions.telnet.TelnetConsole': None,
#}

# Configure item pipelines
# See https://docs.scrapy.org/en/latest/topics/item-pipeline.html
ITEM_PIPELINES = {
    'cc_crawler.pipelines.ValidationPipeline' : 300,
    'cc_crawler.pipelines.MySQLPipeline' : 800,
}

MYSQL_HOST = 'localhost'
MYSQL_DATABASE = 'cc_db'
MYSQL_USER = 'joongh0113'
MYSQL_PASSWORD = 'Wndgus2023!@'
MYSQL_CHARSET = 'utf8mb4'
MYSQL_TABLE = 'cc_tb'


# Enable and configure the AutoThrottle extension (disabled by default)
# See https://docs.scrapy.org/en/latest/topics/autothrottle.html
#AUTOTHROTTLE_ENABLED = True
# The initial download delay
#AUTOTHROTTLE_START_DELAY = 5
# The maximum download delay to be set in case of high latencies
#AUTOTHROTTLE_MAX_DELAY = 60
# The average number of requests Scrapy should be sending in parallel to
# each remote server
#AUTOTHROTTLE_TARGET_CONCURRENCY = 1.0
# Enable showing throttling stats for every response received:
#AUTOTHROTTLE_DEBUG = False

# Enable and configure HTTP caching (disabled by default)
# See https://docs.scrapy.org/en/latest/topics/downloader-middleware.html#httpcache-middleware-settings
#HTTPCACHE_ENABLED = True
#HTTPCACHE_EXPIRATION_SECS = 0
#HTTPCACHE_DIR = 'httpcache'
#HTTPCACHE_IGNORE_HTTP_CODES = []
#HTTPCACHE_STORAGE = 'scrapy.extensions.httpcache.FilesystemCacheStorage'
