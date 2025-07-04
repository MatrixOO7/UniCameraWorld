import requests

url = "https://cache01.mojevideo.sk/securevideos69/253714.mp4?md5=4ffNfdySOU2ItsS7zBDWYg&expires=1751410200"
output_file = "video.mp4"

response = requests.get(url, stream=True)
if response.status_code == 200:
    with open(output_file, 'wb') as f:
        for chunk in response.iter_content(chunk_size=8192):
            if chunk:
                f.write(chunk)
    print(f"Video bylo staženo jako {output_file}")
else:
    print(f"Chyba při stahování: HTTP {response.status_code}")
