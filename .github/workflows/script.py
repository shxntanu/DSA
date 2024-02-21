import os

def convert_text(text):
    file_name = text.split('.')[0]
    capitalized = ' '.join(word.capitalize() for word in file_name.split('-'))
    return (file_name, capitalized)

def update_readme(directory):
    readme_path = os.path.join(directory, "README.md")
    files_and_folders = [f for f in os.listdir(directory) if f not in ('.git', '.github')]

    folder_links = {}
    root_files = []

    # Separate folders and root files
    for item in files_and_folders:
        item_path = os.path.join(directory, item)
        if os.path.isdir(item_path):
            folder_links[item] = [f for f in os.listdir(item_path) if os.path.isfile(os.path.join(item_path, f))]
        elif os.path.isfile(item_path) and item != "README.md":
            root_files.append(item)

    # Create folder and file links
    content = []
    for folder, files in folder_links.items():
        content.append(f"📁 {folder}\n\n")
        for file_name in files:
            link_text, filename = convert_text(file_name)
            file_link = f"- {filename} ([Link]({os.path.join(folder, file_name)}))\n\n"
            content.append(file_link)

    # Append root files
    if root_files:
        content.append("📁 Problems\n\n")
        for file_name in root_files:
            link_text, filename = convert_text(file_name)
            file_link = f"- {filename} ([LeetCode](https://leetcode.com/problems/{link_text})) ([Solution]({file_name}))\n\n"
            content.append(file_link)

    # Read existing README content
    with open(readme_path, "r") as readme_file:
        readme_content = readme_file.readlines()

    marker = "## DSA\n"
    if marker in readme_content:
        marker_index = readme_content.index(marker) + 1
    else:
        marker_index = len(readme_content)

    readme_file.close()

    # Combine existing content with updated content
    existing_readme = open("README.md", 'r')
    updated_content = [existing_readme.read()] + content
    print(updated_content)

    # Write updated content to README file
    with open(readme_path, "w") as readme_file:
        readme_file.writelines(updated_content)

directory_path = "../../../DSA"
update_readme(directory_path)
