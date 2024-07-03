import os
import time

def delete_matching_files():
    script_directory = os.path.dirname(os.path.realpath(__file__))
    files = os.listdir(script_directory)
    cpp_files = {os.path.splitext(file)[0] for file in files if file.endswith('.c')}
    for file in files:
        filename, ext = os.path.splitext(file)
        if filename in cpp_files and ext != '.c':
            file_to_delete = os.path.join(script_directory, file)
            os.remove(file_to_delete)
            print(f'Deleted file: {file_to_delete}')

delete_matching_files()
