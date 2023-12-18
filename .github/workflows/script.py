import os

def convert_text(text):
    file_name = text.split('.')[0]
    capitalized = ' '.join(word.capitalize() for word in file_name.split('-'))
    return (file_name, capitalized)

def update_readme(directory):
    readme_path = os.path.join(directory, "README.md")
    files_and_folders = [f for f in os.listdir(directory)]

    file_links = []
    folder_links = []

    for item in files_and_folders:
        item_path = os.path.join(directory, item)
        if os.path.isfile(item_path):
            if item == "README.md":
                continue
            
            link_text, filename = convert_text(item)
            file_link = f"- {filename} ([LeetCode](https://leetcode.com/problems/{link_text})) ([Solution]({item}))\n"
            file_links.append(file_link)
        elif os.path.isdir(item_path):
            folder_links.append(f"📁 {item}\n")
            folder_files = [f for f in os.listdir(item_path) if os.path.isfile(os.path.join(item_path, f))]
            for file_name in folder_files:
                link_text, filename = convert_text(file_name)
                file_link = f"    - {filename} ([LeetCode](https://leetcode.com/problems/{link_text})) ([Solution]({os.path.join(item, file_name)}))\n"
                file_links.append(file_link)

    with open(readme_path, "r") as readme_file:
        readme_content = readme_file.readlines()

    marker = "## DSA\n"
    if marker in readme_content:
        marker_index = readme_content.index(marker) + 1
    else:
        marker_index = len(readme_content)

    readme_file.close()

    updated_content = ["## DSA\n\nCollection of DSA Problems from LeetCode and other sources (not as likely) and solved mostly in C.\n\nProblems:\n\n"] + folder_links + file_links
    print(updated_content)

    with open(readme_path, "w") as readme_file:
        readme_file.writelines(updated_content)

directory_path = "../../../DSA"
update_readme(directory_path)
