import urllib.request

url = 'https://ssimeonoff.github.io/cards-list'
response = urllib.request.urlopen(url)
data = response.read()
text = data.decode('utf-8')

print(text)