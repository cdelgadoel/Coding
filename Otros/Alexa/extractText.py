from bs4 import BeautifulSoup
import requests
from html import unescape


# List of webpage URLs
urls = [
    "https://www.suin-juriscol.gov.co/viewDocument.asp?ruta=Decretos/30019935"
]

# Dictionary to store all paragraphs for each URL
content_by_url = {}

# Loop through each URL
for url in urls:
    try:
        # Send a GET request to fetch the HTML content
        response = requests.get(url, verify=False)
        response.raise_for_status()  
        response.encoding = 'ISO-8859-1'

        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Extract all paragraphs
        paragraphs = soup.find_all('p')
        
        # Combine all paragraph text into a single string
        all_text = "\n".join(unescape(p.get_text(strip=True)) for p in paragraphs)
        
        # Store in the dictionary
        content_by_url[url] = all_text
    
    except requests.RequestException as e:
        # Handle connection errors or invalid URLs
        content_by_url[url] = f"Error fetching the URL: {e}"

# Display the results
for url, content in content_by_url.items():
    print(f"URL: {url}")
    print("Content:")
    print(content)
    print("\n" + "-"*80 + "\n")
