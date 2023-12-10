import os

def convert_text(text):
    file_name = text.split('.')[0]
    capitalized = ' '.join(word.capitalize() for word in file_name.split('-'))
    return (file_name, capitalized)

def update_readme(directory):
    readme_path = os.path.join(directory, "README.md")
    files = [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

    file_links = []
    for file_name in files:
        if file_name == "README.md":
            continue
        
        link_text,file_name = convert_text(file_name)
        file_link = f"- [{file_name}](https://leetcode.com/problems/{link_text})\n"
        file_links.append(file_link)

    with open(readme_path, "r") as readme_file:
        readme_content = readme_file.readlines()

    marker = "## DSA\n"
    if marker in readme_content:
        marker_index = readme_content.index(marker) + 1
    else:
        marker_index = len(readme_content)

    updated_content = readme_content[:marker_index] + file_links + readme_content[marker_index:]

    with open(readme_path, "w") as readme_file:
        readme_file.writelines(updated_content)

directory_path = "../DSA"
update_readme(directory_path)
