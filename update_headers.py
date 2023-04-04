import os
from pathlib import Path
from git import Repo
from datetime import datetime

def get_git_author_and_date(repo):
    author = repo.config_reader().get_value("user", "name")
    date = repo.head.commit.committed_date
    date = datetime.fromtimestamp(date).strftime('%Y-%m-%d')
    return author, date

def update_headers(repo, author, date):
    for ext in ('*.cpp', '*.h'):
        for filepath in Path(repo.working_tree_dir).glob(f'**/{ext}'):
            with open(filepath, 'r', encoding='utf-8') as file:
                content = file.read()
            
            content = content.replace('AUTHOR_NAME', author)
            content = content.replace('DATE', date)

            with open(filepath, 'w', encoding='utf-8') as file:
                file.write(content)

def main():
    repo = Repo(os.getcwd())
    author, date = get_git_author_and_date(repo)
    update_headers(repo, author, date)

if __name__ == "__main__":
    main()